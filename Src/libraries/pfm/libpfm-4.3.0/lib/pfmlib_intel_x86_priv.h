/*
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
#ifndef __PFMLIB_INTEL_X86_PRIV_H__
#define __PFMLIB_INTEL_X86_PRIV_H__

/*
 * This file contains the definitions used for all Intel X86 processors
 */


/*
 * maximum number of unit masks groups per event
 */
#define INTEL_X86_NUM_GRP	8

/*
 * unit mask description
 */
typedef struct {
	const char		*uname; /* unit mask name */
	const char		*udesc; /* unit umask description */
	const char		*uequiv;/* name of event from which this one is derived, NULL if none */
	uint64_t		ucntmsk;/* supported counters for umask (if set, supersedes cntmsk) */
	uint64_t		ucode;  /* unit mask code */
	unsigned int		uflags;	/* unit mask flags */
	unsigned int		umodel; /* only available on this PMU model */
	unsigned int		grpid;	/* unit mask group id */
	unsigned int		modhw;	/* hardwired modifiers, cannot be changed */
} intel_x86_umask_t;

#define INTEL_X86_MAX_GRPID	(~0U)

/*
 * event-specific encoder (optional)
 */
typedef int (*intel_x86_encoder_t)(void *this, pfmlib_event_desc_t *e);

/*
 * event description
 */
typedef struct {
	const char			*name;	/* event name */
	const char			*desc;	/* event description */
	const char			*equiv;	/* name of event from which this one is derived, NULL if none */
	uint64_t			cntmsk;	/* supported counters */
	unsigned int			code; 	/* event code */
	unsigned int			numasks;/* number of umasks */
	unsigned int			flags;	/* flags */
	unsigned int			modmsk;	/* bitmask of modifiers for this event */
	unsigned int			ngrp;	/* number of unit masks groups */
	intel_x86_encoder_t		encoder; /* event-specific encoder (optional) */
	const intel_x86_umask_t		*umasks; /* umask desc */
} intel_x86_entry_t;

/*
 * pme_flags value (event and unit mask)
 */
#define INTEL_X86_NCOMBO		0x01	/* unit masks within group cannot be combined */
#define INTEL_X86_FALLBACK_GEN		0x02	/* fallback from fixed to generic counter possible */
#define INTEL_X86_PEBS			0x04 	/* event supports PEBS or at least one umask supports PEBS */
#define INTEL_X86_ENCODER		0x08 	/* event requires model-specific encoding */
#define INTEL_X86_DFL			0x10	/* unit mask is default choice */
#define INTEL_X86_GRP_EXCL		0x20	/* only one unit mask group can be selected */
#define INTEL_X86_NHM_OFFCORE		0x40	/* Nehalem/Westmere offcore_response */
#define INTEL_X86_EXCL_GRP_GT		0x80	/* exclude use of grp with id > own grp */
#define INTEL_X86_FIXED			0x100	/* fixed counter only event */

typedef union pfm_intel_x86_reg {
	unsigned long long val;			/* complete register value */
	struct {
		unsigned long sel_event_select:8;	/* event mask */
		unsigned long sel_unit_mask:8;		/* unit mask */
		unsigned long sel_usr:1;		/* user level */
		unsigned long sel_os:1;			/* system level */
		unsigned long sel_edge:1;		/* edge detec */
		unsigned long sel_pc:1;			/* pin control */
		unsigned long sel_int:1;		/* enable APIC intr */
		unsigned long sel_anythr:1;		/* measure any thread */
		unsigned long sel_en:1;			/* enable */
		unsigned long sel_inv:1;		/* invert counter mask */
		unsigned long sel_cnt_mask:8;		/* counter mask */
		unsigned long sel_res2:32;
	} perfevtsel;

	struct {
		unsigned long usel_event:8;	/* event select */
		unsigned long usel_umask:8;	/* event unit mask */
		unsigned long usel_res1:1;	/* reserved */
		unsigned long usel_occ:1;	/* occupancy reset */
		unsigned long usel_edge:1;	/* edge detection */
		unsigned long usel_res2:1;	/* reserved */
		unsigned long usel_int:1;	/* PMI enable */
		unsigned long usel_res3:1;	/* reserved */
		unsigned long usel_en:1;	/* enable */
		unsigned long usel_inv:1;	/* invert */
		unsigned long usel_cnt_mask:8;	/* counter mask */
		unsigned long usel_res4:32;	/* reserved */
	} nhm_unc;

	struct {
		unsigned long usel_en:1;	/* enable */
		unsigned long usel_res1:1;
		unsigned long usel_int:1;	/* PMI enable */
		unsigned long usel_res2:32;
		unsigned long usel_res3:29;
	} nhm_unc_fixed;

	struct {
		unsigned long cpl_eq0:1;	/* filter out branches at pl0 */
		unsigned long cpl_neq0:1;	/* filter out branches at pl1-pl3 */
		unsigned long jcc:1;		/* filter out condition branches */
		unsigned long near_rel_call:1;	/* filter out near relative calls */
		unsigned long near_ind_call:1;	/* filter out near indirect calls */
		unsigned long near_ret:1;	/* filter out near returns */
		unsigned long near_ind_jmp:1;	/* filter out near unconditional jmp/calls */
		unsigned long near_rel_jmp:1;	/* filter out near uncoditional relative jmp */
		unsigned long far_branch:1;	/* filter out far branches */ 
		unsigned long reserved1:23;	/* reserved */
		unsigned long reserved2:32;	/* reserved */
	} nhm_lbr_select;
} pfm_intel_x86_reg_t;
#define INTEL_X86_ATTR_K	0 /* kernel (0) */
#define INTEL_X86_ATTR_U	1 /* user (1, 2, 3) */
#define INTEL_X86_ATTR_E	2 /* edge */
#define INTEL_X86_ATTR_I	3 /* invert */
#define INTEL_X86_ATTR_C	4 /* counter mask */
#define INTEL_X86_ATTR_T	5 /* any thread */

#define _INTEL_X86_ATTR_U  (1 << INTEL_X86_ATTR_U)
#define _INTEL_X86_ATTR_K  (1 << INTEL_X86_ATTR_K)
#define _INTEL_X86_ATTR_I  (1 << INTEL_X86_ATTR_I)
#define _INTEL_X86_ATTR_E  (1 << INTEL_X86_ATTR_E)
#define _INTEL_X86_ATTR_C  (1 << INTEL_X86_ATTR_C)
#define _INTEL_X86_ATTR_T  (1 << INTEL_X86_ATTR_T)

#define INTEL_X86_ATTRS \
	(_INTEL_X86_ATTR_I|_INTEL_X86_ATTR_E|_INTEL_X86_ATTR_C|_INTEL_X86_ATTR_U|_INTEL_X86_ATTR_K)

#define INTEL_V1_ATTRS 		INTEL_X86_ATTRS
#define INTEL_V2_ATTRS 		INTEL_X86_ATTRS
#define INTEL_FIXED2_ATTRS	(_INTEL_X86_ATTR_U|_INTEL_X86_ATTR_K)
#define INTEL_FIXED3_ATTRS	(INTEL_FIXED2_ATTRS|_INTEL_X86_ATTR_T)
#define INTEL_V3_ATTRS 		(INTEL_V2_ATTRS|_INTEL_X86_ATTR_T)

/* let's define some handy shortcuts! */
#define sel_event_select perfevtsel.sel_event_select
#define sel_unit_mask	 perfevtsel.sel_unit_mask
#define sel_usr		 perfevtsel.sel_usr
#define sel_os		 perfevtsel.sel_os
#define sel_edge	 perfevtsel.sel_edge
#define sel_pc		 perfevtsel.sel_pc
#define sel_int		 perfevtsel.sel_int
#define sel_en		 perfevtsel.sel_en
#define sel_inv		 perfevtsel.sel_inv
#define sel_cnt_mask	 perfevtsel.sel_cnt_mask
#define sel_anythr	 perfevtsel.sel_anythr

/*
 * shift relative to start of register
 */
#define INTEL_X86_EDGE_BIT	18
#define INTEL_X86_ANY_BIT	21
#define INTEL_X86_INV_BIT	23
#define INTEL_X86_CMASK_BIT	24

#define INTEL_X86_MOD_EDGE	(1 << INTEL_X86_EDGE_BIT)
#define INTEL_X86_MOD_ANY	(1 << INTEL_X86_ANY_BIT)
#define INTEL_X86_MOD_INV	(1 << INTEL_X86_INV_BIT)

/* intel x86 core PMU supported plm */
#define INTEL_X86_PLM	(PFM_PLM0|PFM_PLM3)

/*
 * Intel x86 specific pmu flags (pmu->flags 16 MSB)
 */
#define INTEL_X86_PMU_FL_ECMASK 0x10000	/* edge requires cmask >=1 */

typedef struct {
	unsigned int version:8;
	unsigned int num_cnt:8;
	unsigned int cnt_width:8;
	unsigned int ebx_length:8;
} intel_x86_pmu_eax_t;

typedef struct {
	unsigned int num_cnt:6;
	unsigned int cnt_width:6;
	unsigned int reserved:20;
} intel_x86_pmu_edx_t;

typedef struct {
	unsigned int no_core_cycle:1;
	unsigned int no_inst_retired:1;
	unsigned int no_ref_cycle:1;
	unsigned int no_llc_ref:1;
	unsigned int no_llc_miss:1;
	unsigned int no_br_retired:1;
	unsigned int no_br_mispred_retired:1;
	unsigned int reserved:25;
} intel_x86_pmu_ebx_t;

typedef struct {
	int model;
	int family; /* 0 means nothing detected yet */
	int arch_version;
} pfm_intel_x86_config_t;

extern pfm_intel_x86_config_t pfm_intel_x86_cfg;

extern const pfmlib_attr_desc_t intel_x86_mods[];

static inline int
intel_x86_eflag(void *this, int idx, int flag)
{
	const intel_x86_entry_t *pe = this_pe(this);
	return !!(pe[idx].flags & flag);
}

static inline int
intel_x86_uflag(void *this, int idx, int attr, int flag)
{
	const intel_x86_entry_t *pe = this_pe(this);
	return !!(pe[idx].umasks[attr].uflags & flag);
}

extern int pfm_intel_x86_detect(void);
extern int pfm_intel_x86_add_defaults(void *this, pfmlib_event_desc_t *e, unsigned int msk, uint64_t *umask, unsigned int max_grpid);

extern int pfm_intel_x86_event_is_valid(void *this, int pidx);
extern int pfm_intel_x86_get_encoding(void *this, pfmlib_event_desc_t *e);
extern int pfm_intel_x86_get_event_first(void *this);
extern int pfm_intel_x86_get_event_next(void *this, int idx);
extern int pfm_intel_x86_get_event_umask_first(void *this, int idx);
extern int pfm_intel_x86_get_event_umask_next(void *this, int idx, int attr);
extern int pfm_intel_x86_validate_table(void *this, FILE *fp);
extern int pfm_intel_x86_get_event_attr_info(void *this, int idx, int attr_idx, pfm_event_attr_info_t *info);
extern int pfm_intel_x86_get_event_info(void *this, int idx, pfm_event_info_t *info);
extern int pfm_intel_x86_valid_pebs(pfmlib_event_desc_t *e);
extern int pfm_intel_x86_perf_event_encoding(pfmlib_event_desc_t *e, void *data);
extern unsigned int pfm_intel_x86_get_event_nattrs(void *this, int pidx);
extern int intel_x86_attr2mod(void *this, int pidx, int attr_idx);

extern int pfm_intel_x86_get_perf_encoding(void *this, pfmlib_event_desc_t *e);
extern int pfm_intel_nhm_unc_get_perf_encoding(void *this, pfmlib_event_desc_t *e);
extern void pfm_intel_x86_perf_validate_pattrs(void *this, pfmlib_event_desc_t *e);
#endif /* __PFMLIB_INTEL_X86_PRIV_H__ */

