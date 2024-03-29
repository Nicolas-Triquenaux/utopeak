/*
 * self_count.c - example of a simple self monitoring using mmapped page
 *
 * Copyright (c) 2009 Google, Inc
 * Contributed by Stephane Eranian <eranian@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of libpfm, a performance monitoring support library for
 * applications on Linux.
 */

#include <sys/types.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <err.h>

#include "perf_util.h"

static const char *gen_events[]={
	"cycles",
	NULL
};

static volatile int quit;
void sig_handler(int n)
{
	quit = 1;
}

#if defined(__x86_64__) || defined(__i386__)

#ifdef __x86_64__
#define DECLARE_ARGS(val, low, high)	unsigned low, high
#define EAX_EDX_VAL(val, low, high)	((low) | ((uint64_t )(high) << 32))
#define EAX_EDX_ARGS(val, low, high)	"a" (low), "d" (high)
#define EAX_EDX_RET(val, low, high)	"=a" (low), "=d" (high)
#else
#define DECLARE_ARGS(val, low, high)	unsigned long long val
#define EAX_EDX_VAL(val, low, high)	(val)
#define EAX_EDX_ARGS(val, low, high)	"A" (val)
#define EAX_EDX_RET(val, low, high)	"=A" (val)
#endif

#define barrier() __asm__ __volatile__("": : :"memory")

static inline int rdpmc(struct perf_event_mmap_page *hdr, uint64_t *value)
{
	int counter = hdr->index - 1;
	DECLARE_ARGS(val, low, high);

	if (counter < 0)
		return -1;

	asm volatile("rdpmc" : EAX_EDX_RET(val, low, high) : "c" (counter));
	*value = EAX_EDX_VAL(val, low, high);
	return 0;
}
#else
/*
 *  Default barrier macro.
 *  Given this is architecture specific, it must be defined when
 *  libpfm is ported to new architecture. The default macro below
 *  simply does nothing.
 */
#define barrier() {}

/*
 *  Default function to read counter directly from user level mode.
 *  Given this is architecture specific, it must be defined when
 *  libpfm is ported to new architecture. The default routine below
 *  simply fails and the caller falls backs to syscall.
 */
static inline int rdpmc(struct perf_event_mmap_page *hdr, uint64_t *value)
{
	int counter = hdr->index - 1;

	if (counter < 0)
		return -1;

	printf("your architecture does not have a way to read counters from user mode\n");
	return -1;
}
#endif

/*
 * our test code (function cannot be made static otherwise it is optimized away)
 */
unsigned long 
fib(unsigned long n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 2;
	return fib(n-1)+fib(n-2);
}

uint64_t
read_count(perf_event_desc_t *fds)
{
	struct perf_event_mmap_page *hdr;
	uint64_t values[3];
	uint64_t offset = 0;
	uint64_t val;
	unsigned int seq;
#if 0
	double ratio;
#endif
	ssize_t ret;
	int idx;

	hdr = fds->buf;

	do {
		seq = hdr->lock;
		barrier();

		/* try reading directly from user mode */
		if (!rdpmc(hdr, &values[0])) {
			offset = hdr->offset;
			values[1] = hdr->time_enabled;
			values[2] = hdr->time_running;
			ret = 0;
		} else {
			offset = 0;
			idx = -1;
			ret = read(fds->fd, values, sizeof(values));
			if (ret < (ssize_t)sizeof(values))
				errx(1, "cannot read values");
			break;
		}
		barrier();
	} while (hdr->lock != seq);

	printf("raw=0x%"PRIx64 " offset=0x%"PRIx64", ena=%"PRIu64 " run=%"PRIu64" idx=%d\n",
		values[0],
		offset,
		values[1],
		values[2],
		idx);

	values[0] += offset;

	val   = perf_scale(values);
#if 0
	ratio = perf_scale_ratio(values);

	if (ratio == 1.0)
		printf("%20"PRIu64" %s (%s)\n", val, fds->name, offset == -1 ? "syscall" : "rdpmc");
	else
		if (ratio == 0.0)
			printf("%20"PRIu64" %s (did not run: incompatible events, too many events in a group, competing session)\n", val, fds->name);
		else
			printf("%20"PRIu64" %s (scaled from %.2f%% of time)\n", val, fds->name, ratio*100.0);
#endif
	return val;
}

int
main(int argc, char **argv)
{
	perf_event_desc_t *fds = NULL;
	long lret;
	size_t pgsz;
	uint64_t val;
	int i, ret, num_fds = 0;
	int n = 30;

	lret = sysconf(_SC_PAGESIZE);
	if (lret < 0)
		err(1, "cannot get page size");

	pgsz = (size_t)lret;

	/*
	 * Initialize pfm library (required before we can use it)
	 */
	ret = pfm_initialize();
	if (ret != PFM_SUCCESS)
		errx(1, "Cannot initialize library: %s", pfm_strerror(ret));

	ret = perf_setup_argv_events(argc > 1 ? (const char **)argv+1 : gen_events, &fds, &num_fds);
	if (ret || !num_fds)
		errx(1, "cannot setup events");

	fds[0].fd = -1;
	for(i=0; i < num_fds; i++) {
		/* request timing information necesaary for scaling */
		fds[i].hw.read_format = PERF_FORMAT_SCALE;
		fds[i].hw.disabled = 0;
		//fds[i].fd = perf_event_open(&fds[i].hw, 0, -1, fds[0].fd, 0);
		fds[i].fd = perf_event_open(&fds[i].hw, 0, -1, -1, 0);
		if (fds[i].fd == -1)
			err(1, "cannot open event %d", i);

		fds[i].buf = mmap(NULL, pgsz, PROT_READ, MAP_SHARED, fds[i].fd, 0);
		if (fds[i].buf == MAP_FAILED)
			err(1, "cannot mmap page");

	}
	signal(SIGALRM, sig_handler);

	/*
	 * enable all counters attached to this thread
	 */
	ioctl(fds[0].fd, PERF_EVENT_IOC_ENABLE, 0);

	alarm(10);

	for(;quit == 0;) {

		for (i=0; i < num_fds; i++) {
			val = read_count(&fds[i]);
			printf("%20"PRIu64" %s\n", val, fds[i].name);
		}
		fib(n);
		n += 5;
		if (n > 35)
			n = 30;
	}
	/*
	 * disable all counters attached to this thread
	 */
	ioctl(fds[0].fd, PERF_EVENT_IOC_DISABLE, 0);

	for (i=0; i < num_fds; i++) {
		munmap(fds[i].buf, pgsz);
		close(fds[i].fd);
	}
	perf_free_fds(fds, num_fds);

	/* free libpfm resources cleanly */
	pfm_terminate();

	return 0;
}

