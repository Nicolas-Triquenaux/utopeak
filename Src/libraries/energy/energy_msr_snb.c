/*
Copyright (C) 2013 UVSQ

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 3
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
===============================================================================

This code was heavily inspired from the Likwid project, also under GPL V3 Licence.
You may find the Likwid project here:

http://code.google.com/p/likwid/

Likwid stands for Like I knew what I am doing. This project contributes easy to use 
command line tools for Linux to support programmers in developing high performance 
multi threaded programs.

It contains the following tools:

likwid-topology: Show the thread and cache topology
likwid-perfctr: Measure hardware performance counters on Intel and AMD processors
likwid-features: Show and Toggle hardware prefetch control bits on Intel Core 2 processors
likwid-pin: Pin your threaded application without touching your code (supports pthreads, Intel OpenMP and gcc OpenMP)
likwid-bench: Benchmarking framework allowing rapid prototyping of threaded assembly kernels
likwid-mpirun: Script enabling simple and flexible pinning of MPI and MPI/threaded hybrid applications
likwid-perfscope: Frontend for likwid-perfctr timeline mode. Allows live plotting of performance metrics.
likwid-powermeter: Tool for accessing RAPL counters and query Turbo mode steps on Intel processor.
likwid-memsweeper: Tool to cleanup ccNUMA memory domains.
*/

#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "includes/registers.h"
#include "includes/msr.h"
#include "msr_snb.h"

typedef struct sPowerOverflow
{
	uint32_t lastRead;
	uint32_t numOverflows;
	pthread_mutex_t * volatile powerThreadLock;
	int volatile * volatile signal;
} SPowerOverflow;

/** Extract the desired field from an unsigned 32 bit integer
 */
static uint32_t 
extractBitField(uint32_t inField, uint32_t width, uint32_t offset)
{
    uint32_t bitMask;
    uint32_t outField;

    if ((offset+width) == 32) 
    {
        bitMask = (0xFFFFFFFF<<offset);
    }
    else 
    {
        bitMask = (0xFFFFFFFF<<offset) ^ (0xFFFFFFFF<<(offset+width));

    }

    outField = (inField & bitMask) >> offset;
    return outField;
}

void checkOverflows(SPowerOverflow* counter)
{
	uint32_t temp=extractBitField (msr_read (0, MSR_PKG_ENERGY_STATUS),32,0);
	counter->numOverflows=(counter->lastRead > temp)?counter->numOverflows+1:counter->numOverflows;
	
	counter->lastRead=temp;
}

void * checkerThread ( void * timerPtr)
{
	volatile int Signal=1;
	pthread_mutex_t myLock;
	SPowerOverflow * timer=timerPtr;
	
	pthread_mutex_init(&myLock, NULL);
	pthread_mutex_lock(&myLock);
	timer->powerThreadLock=&myLock;
	timer->signal=&Signal;
	while(Signal)
	{
		checkOverflows(timer);
		pthread_mutex_unlock(&myLock);
		sleep(POWER_POLLING_INTERVAL);//good night!
		pthread_mutex_lock(&myLock);
	}
	//there is no clean up because contexts are free'd by main thread and all other memory is in thread's stack
	return NULL;

}
       
/**
 * @brief Return the current value of the power counter
 * @return A double containing the power counter value in Joules	
 */
static __inline__ double getenergy(SPowerOverflow * timerContext)
{
   	double ret;
	double energy_unit;
	double energy;

	//guard the context from my checker thread
	pthread_mutex_lock(timerContext->powerThreadLock);
	checkOverflows(timerContext);
	/** Calculate value of the power counter */
	energy = timerContext->lastRead;
	energy+= timerContext->numOverflows * 4294967296.0; // 2^32 in float because the power counter is uint32_t
	pthread_mutex_unlock(timerContext->powerThreadLock);

	/** Measurement unit */
	energy_unit = pow(0.5,(double) extractBitField(msr_read(0, MSR_RAPL_POWER_UNIT),5,8));
	
	/** "Apply" the measurement unit on the extracted power value */
  	ret = energy * energy_unit; 

   	return ret;
}

/**
 * @brief Initialization of the measure
 * @return A void * which has a timer context
 */
void *evaluationInit() 
{ 
	void * ret;
	SPowerOverflow * ptr;
	pthread_t dummy;

	msr_init();

	ptr=malloc(sizeof(* ptr));
	ptr->lastRead=0;
	ptr->numOverflows=0;
	ptr->powerThreadLock = NULL;
	ptr->signal = NULL;
	pthread_create(&dummy,NULL,checkerThread,ptr);
	while(ptr->powerThreadLock == NULL || ptr->signal == NULL) {}; //poll for other thread to init
	ret=ptr;

	return ret; 
}

/**
 * @brief Close of the measure
 * @return An integer which means close success or fail
 */
int evaluationClose( void * timer) 
{ 
	SPowerOverflow * context=timer;

	msr_finalize();

	pthread_mutex_lock(context->powerThreadLock);
	*context->signal=0;
	pthread_mutex_unlock(context->powerThreadLock);
	free(context);

	return EXIT_SUCCESS;
}

/**
 * @brief Return the power measure before the run(s)
 * @return A double containing the power counter value in Joules
 */
double evaluationStart (void * timer)
{ 
	SPowerOverflow * context=timer;

	return  getenergy(context); 
}

/**
 * @brief Return the power measure after the run(s)
 * @return A double containing the power counter value in Joules
 */
double evaluationStop(void * timer) 
{ 
	SPowerOverflow * context=timer;

	return  getenergy(context); 
}


