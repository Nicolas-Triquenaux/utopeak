/*
 * Copyright (c) 2011 Google, Inc
 * Contributed by Stephane Eranian <eranian@gmail.com>
 *
 * Regenerated from previous version by:
 *
 * Copyright (c) 2006, 2007 Advanced Micro Devices, Inc.
 * Contributed by Ray Bryant <raybry@mpdtxmail.amd.com> 
 * Contributed by Robert Richter <robert.richter@amd.com>
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
 *
 * This file has been automatically generated.
 *
 * PMU: amd64_k8 (AMD64 K8)
 */

/* History
 *
 * Feb 10 2006 -- Ray Bryant, raybry@mpdtxmail.amd.com
 *
 * Brought event table up-to-date with the 3.85 (October 2005) version of the
 * "BIOS and Kernel Developer's Guide for the AMD Athlon[tm] 64 and
 * AMD Opteron[tm] Processors," AMD Publication # 26094.
 * 
 * Dec 12 2007 -- Robert Richter, robert.richter@amd.com
 *
 * Updated to: BIOS and Kernel Developer's Guide for AMD NPT Family
 * 0Fh Processors, Publication # 32559, Revision: 3.08, Issue Date:
 * July 2007
 * 
 * Feb 26 2009 -- Robert Richter, robert.richter@amd.com
 *
 * Updates and fixes of some revision flags and descriptions according
 * to these documents:
 * BIOS and Kernel Developer's Guide, #26094, Revision: 3.30
 * BIOS and Kernel Developer's Guide, #32559, Revision: 3.12
 */

static const amd64_umask_t amd64_k8_dispatched_fpu[]={
   { .uname  = "OPS_ADD",
     .udesc  = "Add pipe ops",
     .ucode = 0x1,
   },
   { .uname  = "OPS_MULTIPLY",
     .udesc  = "Multiply pipe ops",
     .ucode = 0x2,
   },
   { .uname  = "OPS_STORE",
     .udesc  = "Store pipe ops",
     .ucode = 0x4,
   },
   { .uname  = "OPS_ADD_PIPE_LOAD_OPS",
     .udesc  = "Add pipe load ops",
     .ucode = 0x8,
   },
   { .uname  = "OPS_MULTIPLY_PIPE_LOAD_OPS",
     .udesc  = "Multiply pipe load ops",
     .ucode = 0x10,
   },
   { .uname  = "OPS_STORE_PIPE_LOAD_OPS",
     .udesc  = "Store pipe load ops",
     .ucode = 0x20,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x3f,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_segment_register_loads[]={
   { .uname  = "ES",
     .udesc  = "ES",
     .ucode = 0x1,
   },
   { .uname  = "CS",
     .udesc  = "CS",
     .ucode = 0x2,
   },
   { .uname  = "SS",
     .udesc  = "SS",
     .ucode = 0x4,
   },
   { .uname  = "DS",
     .udesc  = "DS",
     .ucode = 0x8,
   },
   { .uname  = "FS",
     .udesc  = "FS",
     .ucode = 0x10,
   },
   { .uname  = "GS",
     .udesc  = "GS",
     .ucode = 0x20,
   },
   { .uname  = "HS",
     .udesc  = "HS",
     .ucode = 0x40,
   },
   { .uname  = "ALL",
     .udesc  = "All segments",
     .ucode = 0x7f,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_locked_ops[]={
   { .uname  = "EXECUTED",
     .udesc  = "The number of locked instructions executed",
     .ucode = 0x1,
   },
   { .uname  = "CYCLES_SPECULATIVE_PHASE",
     .udesc  = "The number of cycles spent in speculative phase",
     .ucode = 0x2,
   },
   { .uname  = "CYCLES_NON_SPECULATIVE_PHASE",
     .udesc  = "The number of cycles spent in non-speculative phase (including cache miss penalty)",
     .ucode = 0x4,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x7,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_memory_requests[]={
   { .uname  = "NON_CACHEABLE",
     .udesc  = "Requests to non-cacheable (UC) memory",
     .ucode = 0x1,
   },
   { .uname  = "WRITE_COMBINING",
     .udesc  = "Requests to write-combining (WC) memory or WC buffer flushes to WB memory",
     .ucode = 0x2,
   },
   { .uname  = "STREAMING_STORE",
     .udesc  = "Streaming store (SS) requests",
     .ucode = 0x80,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x83,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_data_cache_refills[]={
   { .uname  = "SYSTEM",
     .udesc  = "Refill from System",
     .ucode = 0x1,
   },
   { .uname  = "L2_SHARED",
     .udesc  = "Shared-state line from L2",
     .ucode = 0x2,
   },
   { .uname  = "L2_EXCLUSIVE",
     .udesc  = "Exclusive-state line from L2",
     .ucode = 0x4,
   },
   { .uname  = "L2_OWNED",
     .udesc  = "Owned-state line from L2",
     .ucode = 0x8,
   },
   { .uname  = "L2_MODIFIED",
     .udesc  = "Modified-state line from L2",
     .ucode = 0x10,
   },
   { .uname  = "ALL",
     .udesc  = "Shared, Exclusive, Owned, Modified State Refills",
     .ucode = 0x1f,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_data_cache_refills_from_system[]={
   { .uname  = "INVALID",
     .udesc  = "Invalid",
     .ucode = 0x1,
   },
   { .uname  = "SHARED",
     .udesc  = "Shared",
     .ucode = 0x2,
   },
   { .uname  = "EXCLUSIVE",
     .udesc  = "Exclusive",
     .ucode = 0x4,
   },
   { .uname  = "OWNED",
     .udesc  = "Owned",
     .ucode = 0x8,
   },
   { .uname  = "MODIFIED",
     .udesc  = "Modified",
     .ucode = 0x10,
   },
   { .uname  = "ALL",
     .udesc  = "Invalid, Shared, Exclusive, Owned, Modified",
     .ucode = 0x1f,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_scrubber_single_bit_ecc_errors[]={
   { .uname  = "SCRUBBER_ERROR",
     .udesc  = "Scrubber error",
     .ucode = 0x1,
   },
   { .uname  = "PIGGYBACK_ERROR",
     .udesc  = "Piggyback scrubber errors",
     .ucode = 0x2,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x3,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_prefetch_instructions_dispatched[]={
   { .uname  = "LOAD",
     .udesc  = "Load (Prefetch, PrefetchT0/T1/T2)",
     .ucode = 0x1,
   },
   { .uname  = "STORE",
     .udesc  = "Store (PrefetchW)",
     .ucode = 0x2,
   },
   { .uname  = "NTA",
     .udesc  = "NTA (PrefetchNTA)",
     .ucode = 0x4,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x7,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_dcache_misses_by_locked_instructions[]={
   { .uname  = "DATA_CACHE_MISSES_BY_LOCKED_INSTRUCTIONS",
     .udesc  = "Data cache misses by locked instructions",
     .ucode = 0x2,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x2,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_data_prefetches[]={
   { .uname  = "CANCELLED",
     .udesc  = "Cancelled prefetches",
     .ucode = 0x1,
   },
   { .uname  = "ATTEMPTED",
     .udesc  = "Prefetch attempts",
     .ucode = 0x2,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x3,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_system_read_responses[]={
   { .uname  = "EXCLUSIVE",
     .udesc  = "Exclusive",
     .ucode = 0x1,
   },
   { .uname  = "MODIFIED",
     .udesc  = "Modified",
     .ucode = 0x2,
   },
   { .uname  = "SHARED",
     .udesc  = "Shared",
     .ucode = 0x4,
   },
   { .uname  = "ALL",
     .udesc  = "Exclusive, Modified, Shared",
     .ucode = 0x7,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_quadwords_written_to_system[]={
   { .uname  = "QUADWORD_WRITE_TRANSFER",
     .udesc  = "Quadword write transfer",
     .ucode = 0x1,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x1,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_requests_to_l2[]={
   { .uname  = "INSTRUCTIONS",
     .udesc  = "IC fill",
     .ucode = 0x1,
   },
   { .uname  = "DATA",
     .udesc  = "DC fill",
     .ucode = 0x2,
   },
   { .uname  = "TLB_WALK",
     .udesc  = "TLB fill (page table walks)",
     .ucode = 0x4,
   },
   { .uname  = "SNOOP",
     .udesc  = "Tag snoop request",
     .ucode = 0x8,
   },
   { .uname  = "CANCELLED",
     .udesc  = "Cancelled request",
     .ucode = 0x10,
   },
   { .uname  = "ALL",
     .udesc  = "All non-cancelled requests",
     .ucode = 0x1f,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_l2_cache_miss[]={
   { .uname  = "INSTRUCTIONS",
     .udesc  = "IC fill",
     .ucode = 0x1,
   },
   { .uname  = "DATA",
     .udesc  = "DC fill (includes possible replays, whereas event 41h does not)",
     .ucode = 0x2,
   },
   { .uname  = "TLB_WALK",
     .udesc  = "TLB page table walk",
     .ucode = 0x4,
   },
   { .uname  = "ALL",
     .udesc  = "Instructions, Data, TLB walk",
     .ucode = 0x7,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_l2_fill_writeback[]={
   { .uname  = "L2_FILLS",
     .udesc  = "L2 fills (victims from L1 caches, TLB page table walks and data prefetches)",
     .ucode = 0x1,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x1,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL | AMD64_FL_TILL_K8_REV_E,
   },
   { .uname  = "L2_WRITEBACKS",
     .udesc  = "L2 Writebacks to system.",
     .ucode = 0x2,
     .uflags= AMD64_FL_K8_REV_F,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x3,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL | AMD64_FL_K8_REV_F,
   },
};

static const amd64_umask_t amd64_k8_retired_mmx_and_fp_instructions[]={
   { .uname  = "X87",
     .udesc  = "X87 instructions",
     .ucode = 0x1,
   },
   { .uname  = "MMX_AND_3DNOW",
     .udesc  = "MMX and 3DNow! instructions",
     .ucode = 0x2,
   },
   { .uname  = "PACKED_SSE_AND_SSE2",
     .udesc  = "Packed SSE and SSE2 instructions",
     .ucode = 0x4,
   },
   { .uname  = "SCALAR_SSE_AND_SSE2",
     .udesc  = "Scalar SSE and SSE2 instructions",
     .ucode = 0x8,
   },
   { .uname  = "ALL",
     .udesc  = "X87, MMX(TM), 3DNow!(TM), Scalar and Packed SSE and SSE2 instructions",
     .ucode = 0xf,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_retired_fastpath_double_op_instructions[]={
   { .uname  = "POSITION_0",
     .udesc  = "With low op in position 0",
     .ucode = 0x1,
   },
   { .uname  = "POSITION_1",
     .udesc  = "With low op in position 1",
     .ucode = 0x2,
   },
   { .uname  = "POSITION_2",
     .udesc  = "With low op in position 2",
     .ucode = 0x4,
   },
   { .uname  = "ALL",
     .udesc  = "With low op in position 0, 1, or 2",
     .ucode = 0x7,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_fpu_exceptions[]={
   { .uname  = "X87_RECLASS_MICROFAULTS",
     .udesc  = "X87 reclass microfaults",
     .ucode = 0x1,
   },
   { .uname  = "SSE_RETYPE_MICROFAULTS",
     .udesc  = "SSE retype microfaults",
     .ucode = 0x2,
   },
   { .uname  = "SSE_RECLASS_MICROFAULTS",
     .udesc  = "SSE reclass microfaults",
     .ucode = 0x4,
   },
   { .uname  = "SSE_AND_X87_MICROTRAPS",
     .udesc  = "SSE and x87 microtraps",
     .ucode = 0x8,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0xf,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_dram_accesses_page[]={
   { .uname  = "HIT",
     .udesc  = "Page hit",
     .ucode = 0x1,
   },
   { .uname  = "MISS",
     .udesc  = "Page Miss",
     .ucode = 0x2,
   },
   { .uname  = "CONFLICT",
     .udesc  = "Page Conflict",
     .ucode = 0x4,
   },
   { .uname  = "ALL",
     .udesc  = "Page Hit, Miss, or Conflict",
     .ucode = 0x7,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_memory_controller_turnarounds[]={
   { .uname  = "CHIP_SELECT",
     .udesc  = "DIMM (chip select) turnaround",
     .ucode = 0x1,
   },
   { .uname  = "READ_TO_WRITE",
     .udesc  = "Read to write turnaround",
     .ucode = 0x2,
   },
   { .uname  = "WRITE_TO_READ",
     .udesc  = "Write to read turnaround",
     .ucode = 0x4,
   },
   { .uname  = "ALL",
     .udesc  = "All Memory Controller Turnarounds",
     .ucode = 0x7,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_memory_controller_bypass[]={
   { .uname  = "HIGH_PRIORITY",
     .udesc  = "Memory controller high priority bypass",
     .ucode = 0x1,
   },
   { .uname  = "LOW_PRIORITY",
     .udesc  = "Memory controller low priority bypass",
     .ucode = 0x2,
   },
   { .uname  = "DRAM_INTERFACE",
     .udesc  = "DRAM controller interface bypass",
     .ucode = 0x4,
   },
   { .uname  = "DRAM_QUEUE",
     .udesc  = "DRAM controller queue bypass",
     .ucode = 0x8,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0xf,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_sized_blocks[]={
   { .uname  = "32_BYTE_WRITES",
     .udesc  = "32-byte Sized Writes",
     .ucode = 0x4,
   },
   { .uname  = "64_BYTE_WRITES",
     .udesc  = "64-byte Sized Writes",
     .ucode = 0x8,
   },
   { .uname  = "32_BYTE_READS",
     .udesc  = "32-byte Sized Reads",
     .ucode = 0x10,
   },
   { .uname  = "64_BYTE_READS",
     .udesc  = "64-byte Sized Reads",
     .ucode = 0x20,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x3c,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_thermal_status_and_ecc_errors[]={
   { .uname  = "CLKS_CPU_ACTIVE",
     .udesc  = "Number of clocks CPU is active when HTC is active",
     .ucode = 0x1,
     .uflags= AMD64_FL_K8_REV_F,
   },
   { .uname  = "CLKS_CPU_INACTIVE",
     .udesc  = "Number of clocks CPU clock is inactive when HTC is active",
     .ucode = 0x2,
     .uflags= AMD64_FL_K8_REV_F,
   },
   { .uname  = "CLKS_DIE_TEMP_TOO_HIGH",
     .udesc  = "Number of clocks when die temperature is higher than the software high temperature threshold",
     .ucode = 0x4,
     .uflags= AMD64_FL_K8_REV_F,
   },
   { .uname  = "CLKS_TEMP_THRESHOLD_EXCEEDED",
     .udesc  = "Number of clocks when high temperature threshold was exceeded",
     .ucode = 0x8,
     .uflags= AMD64_FL_K8_REV_F,
   },
   { .uname  = "DRAM_ECC_ERRORS",
     .udesc  = "Number of correctable and Uncorrectable DRAM ECC errors",
     .ucode = 0x80,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x80,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL | AMD64_FL_TILL_K8_REV_E,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x8f,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL | AMD64_FL_K8_REV_F,
   },
};

static const amd64_umask_t amd64_k8_cpu_io_requests_to_memory_io[]={
   { .uname  = "I_O_TO_I_O",
     .udesc  = "I/O to I/O",
     .ucode = 0x1,
   },
   { .uname  = "I_O_TO_MEM",
     .udesc  = "I/O to Mem",
     .ucode = 0x2,
   },
   { .uname  = "CPU_TO_I_O",
     .udesc  = "CPU to I/O",
     .ucode = 0x4,
   },
   { .uname  = "CPU_TO_MEM",
     .udesc  = "CPU to Mem",
     .ucode = 0x8,
   },
   { .uname  = "TO_REMOTE_NODE",
     .udesc  = "To remote node",
     .ucode = 0x10,
   },
   { .uname  = "TO_LOCAL_NODE",
     .udesc  = "To local node",
     .ucode = 0x20,
   },
   { .uname  = "FROM_REMOTE_NODE",
     .udesc  = "From remote node",
     .ucode = 0x40,
   },
   { .uname  = "FROM_LOCAL_NODE",
     .udesc  = "From local node",
     .ucode = 0x80,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0xff,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_cache_block[]={
   { .uname  = "VICTIM_WRITEBACK",
     .udesc  = "Victim Block (Writeback)",
     .ucode = 0x1,
   },
   { .uname  = "DCACHE_LOAD_MISS",
     .udesc  = "Read Block (Dcache load miss refill)",
     .ucode = 0x4,
   },
   { .uname  = "SHARED_ICACHE_REFILL",
     .udesc  = "Read Block Shared (Icache refill)",
     .ucode = 0x8,
   },
   { .uname  = "READ_BLOCK_MODIFIED",
     .udesc  = "Read Block Modified (Dcache store miss refill)",
     .ucode = 0x10,
   },
   { .uname  = "READ_TO_DIRTY",
     .udesc  = "Change to Dirty (first store to clean block already in cache)",
     .ucode = 0x20,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x3d,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_sized_commands[]={
   { .uname  = "NON_POSTED_WRITE_BYTE",
     .udesc  = "NonPosted SzWr Byte (1-32 bytes) Legacy or mapped I/O, typically 1-4 bytes",
     .ucode = 0x1,
   },
   { .uname  = "NON_POSTED_WRITE_DWORD",
     .udesc  = "NonPosted SzWr Dword (1-16 dwords) Legacy or mapped I/O, typically 1 dword",
     .ucode = 0x2,
   },
   { .uname  = "POSTED_WRITE_BYTE",
     .udesc  = "Posted SzWr Byte (1-32 bytes) Sub-cache-line DMA writes, size varies; also flushes of partially-filled Write Combining buffer",
     .ucode = 0x4,
   },
   { .uname  = "POSTED_WRITE_DWORD",
     .udesc  = "Posted SzWr Dword (1-16 dwords) Block-oriented DMA writes, often cache-line sized; also processor Write Combining buffer flushes",
     .ucode = 0x8,
   },
   { .uname  = "READ_BYTE_4_BYTES",
     .udesc  = "SzRd Byte (4 bytes) Legacy or mapped I/O",
     .ucode = 0x10,
   },
   { .uname  = "READ_DWORD_1_16_DWORDS",
     .udesc  = "SzRd Dword (1-16 dwords) Block-oriented DMA reads, typically cache-line size",
     .ucode = 0x20,
   },
   { .uname  = "READ_MODIFY_WRITE",
     .udesc  = "RdModWr",
     .ucode = 0x40,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x7f,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_probe[]={
   { .uname  = "MISS",
     .udesc  = "Probe miss",
     .ucode = 0x1,
   },
   { .uname  = "HIT_CLEAN",
     .udesc  = "Probe hit clean",
     .ucode = 0x2,
   },
   { .uname  = "HIT_DIRTY_NO_MEMORY_CANCEL",
     .udesc  = "Probe hit dirty without memory cancel (probed by Sized Write or Change2Dirty)",
     .ucode = 0x4,
   },
   { .uname  = "HIT_DIRTY_WITH_MEMORY_CANCEL",
     .udesc  = "Probe hit dirty with memory cancel (probed by DMA read or cache refill request)",
     .ucode = 0x8,
   },
   { .uname  = "UPSTREAM_DISPLAY_REFRESH_READS",
     .udesc  = "Upstream display refresh reads",
     .ucode = 0x10,
   },
   { .uname  = "UPSTREAM_NON_DISPLAY_REFRESH_READS",
     .udesc  = "Upstream non-display refresh reads",
     .ucode = 0x20,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x3f,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL | AMD64_FL_TILL_K8_REV_C,
   },
   { .uname  = "UPSTREAM_WRITES",
     .udesc  = "Upstream writes",
     .ucode = 0x40,
     .uflags= AMD64_FL_K8_REV_D,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x7f,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL | AMD64_FL_K8_REV_D,
   },
};

static const amd64_umask_t amd64_k8_gart[]={
   { .uname  = "APERTURE_HIT_FROM_CPU",
     .udesc  = "GART aperture hit on access from CPU",
     .ucode = 0x1,
   },
   { .uname  = "APERTURE_HIT_FROM_IO",
     .udesc  = "GART aperture hit on access from I/O",
     .ucode = 0x2,
   },
   { .uname  = "MISS",
     .udesc  = "GART miss",
     .ucode = 0x4,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0x7,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_umask_t amd64_k8_hypertransport_link0[]={
   { .uname  = "COMMAND_DWORD_SENT",
     .udesc  = "Command dword sent",
     .ucode = 0x1,
   },
   { .uname  = "DATA_DWORD_SENT",
     .udesc  = "Data dword sent",
     .ucode = 0x2,
   },
   { .uname  = "BUFFER_RELEASE_DWORD_SENT",
     .udesc  = "Buffer release dword sent",
     .ucode = 0x4,
   },
   { .uname  = "NOP_DWORD_SENT",
     .udesc  = "Nop dword sent (idle)",
     .ucode = 0x8,
   },
   { .uname  = "ALL",
     .udesc  = "All sub-events selected",
     .ucode = 0xf,
     .uflags= AMD64_FL_NCOMBO | AMD64_FL_DFL,
   },
};

static const amd64_entry_t amd64_k8_pe[]={
{ .name    = "DISPATCHED_FPU",
  .desc    = "Dispatched FPU Operations",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x0,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_dispatched_fpu),
  .ngrp    = 1,
  .umasks  = amd64_k8_dispatched_fpu,
},
{ .name    = "CYCLES_NO_FPU_OPS_RETIRED",
  .desc    = "Cycles with no FPU Ops Retired",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x1,
},
{ .name    = "DISPATCHED_FPU_OPS_FAST_FLAG",
  .desc    = "Dispatched Fast Flag FPU Operations",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x2,
},
{ .name    = "SEGMENT_REGISTER_LOADS",
  .desc    = "Segment Register Loads",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x20,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_segment_register_loads),
  .ngrp    = 1,
  .umasks  = amd64_k8_segment_register_loads,
},
{ .name    = "PIPELINE_RESTART_DUE_TO_SELF_MODIFYING_CODE",
  .desc    = "Pipeline restart due to self-modifying code",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x21,
},
{ .name    = "PIPELINE_RESTART_DUE_TO_PROBE_HIT",
  .desc    = "Pipeline restart due to probe hit",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x22,
},
{ .name    = "LS_BUFFER_2_FULL_CYCLES",
  .desc    = "LS Buffer 2 Full",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x23,
},
{ .name    = "LOCKED_OPS",
  .desc    = "Locked Operations",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x24,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_locked_ops),
  .ngrp    = 1,
  .umasks  = amd64_k8_locked_ops,
},
{ .name    = "MEMORY_REQUESTS",
  .desc    = "Memory Requests by Type",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x65,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_memory_requests),
  .ngrp    = 1,
  .umasks  = amd64_k8_memory_requests,
},
{ .name    = "DATA_CACHE_ACCESSES",
  .desc    = "Data Cache Accesses",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x40,
},
{ .name    = "DATA_CACHE_MISSES",
  .desc    = "Data Cache Misses",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x41,
},
{ .name    = "DATA_CACHE_REFILLS",
  .desc    = "Data Cache Refills from L2 or System",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x42,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_data_cache_refills),
  .ngrp    = 1,
  .umasks  = amd64_k8_data_cache_refills,
},
{ .name    = "DATA_CACHE_REFILLS_FROM_SYSTEM",
  .desc    = "Data Cache Refills from System",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x43,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_data_cache_refills_from_system),
  .ngrp    = 1,
  .umasks  = amd64_k8_data_cache_refills_from_system,
},
{ .name    = "DATA_CACHE_LINES_EVICTED",
  .desc    = "Data Cache Lines Evicted",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x44,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_data_cache_refills_from_system),
  .ngrp    = 1,
  .umasks  = amd64_k8_data_cache_refills_from_system, /* identical to actual umasks list for this event */
},
{ .name    = "L1_DTLB_MISS_AND_L2_DTLB_HIT",
  .desc    = "L1 DTLB Miss and L2 DTLB Hit",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x45,
},
{ .name    = "L1_DTLB_AND_L2_DTLB_MISS",
  .desc    = "L1 DTLB and L2 DTLB Miss",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x46,
},
{ .name    = "MISALIGNED_ACCESSES",
  .desc    = "Misaligned Accesses",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x47,
},
{ .name    = "MICROARCHITECTURAL_LATE_CANCEL_OF_AN_ACCESS",
  .desc    = "Microarchitectural Late Cancel of an Access",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x48,
},
{ .name    = "MICROARCHITECTURAL_EARLY_CANCEL_OF_AN_ACCESS",
  .desc    = "Microarchitectural Early Cancel of an Access",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x49,
},
{ .name    = "SCRUBBER_SINGLE_BIT_ECC_ERRORS",
  .desc    = "Single-bit ECC Errors Recorded by Scrubber",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x4a,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_scrubber_single_bit_ecc_errors),
  .ngrp    = 1,
  .umasks  = amd64_k8_scrubber_single_bit_ecc_errors,
},
{ .name    = "PREFETCH_INSTRUCTIONS_DISPATCHED",
  .desc    = "Prefetch Instructions Dispatched",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x4b,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_prefetch_instructions_dispatched),
  .ngrp    = 1,
  .umasks  = amd64_k8_prefetch_instructions_dispatched,
},
{ .name    = "DCACHE_MISSES_BY_LOCKED_INSTRUCTIONS",
  .desc    = "DCACHE Misses by Locked Instructions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x4c,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_dcache_misses_by_locked_instructions),
  .ngrp    = 1,
  .umasks  = amd64_k8_dcache_misses_by_locked_instructions,
},
{ .name    = "DATA_PREFETCHES",
  .desc    = "Data Prefetcher",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x67,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_data_prefetches),
  .ngrp    = 1,
  .umasks  = amd64_k8_data_prefetches,
},
{ .name    = "SYSTEM_READ_RESPONSES",
  .desc    = "System Read Responses by Coherency State",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x6c,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_system_read_responses),
  .ngrp    = 1,
  .umasks  = amd64_k8_system_read_responses,
},
{ .name    = "QUADWORDS_WRITTEN_TO_SYSTEM",
  .desc    = "Quadwords Written to System",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x6d,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_quadwords_written_to_system),
  .ngrp    = 1,
  .umasks  = amd64_k8_quadwords_written_to_system,
},
{ .name    = "REQUESTS_TO_L2",
  .desc    = "Requests to L2 Cache",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x7d,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_requests_to_l2),
  .ngrp    = 1,
  .umasks  = amd64_k8_requests_to_l2,
},
{ .name    = "L2_CACHE_MISS",
  .desc    = "L2 Cache Misses",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x7e,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_l2_cache_miss),
  .ngrp    = 1,
  .umasks  = amd64_k8_l2_cache_miss,
},
{ .name    = "L2_FILL_WRITEBACK",
  .desc    = "L2 Fill/Writeback",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x7f,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_l2_fill_writeback),
  .ngrp    = 1,
  .umasks  = amd64_k8_l2_fill_writeback,
},
{ .name    = "INSTRUCTION_CACHE_FETCHES",
  .desc    = "Instruction Cache Fetches",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x80,
},
{ .name    = "INSTRUCTION_CACHE_MISSES",
  .desc    = "Instruction Cache Misses",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x81,
},
{ .name    = "INSTRUCTION_CACHE_REFILLS_FROM_L2",
  .desc    = "Instruction Cache Refills from L2",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x82,
},
{ .name    = "INSTRUCTION_CACHE_REFILLS_FROM_SYSTEM",
  .desc    = "Instruction Cache Refills from System",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x83,
},
{ .name    = "L1_ITLB_MISS_AND_L2_ITLB_HIT",
  .desc    = "L1 ITLB Miss and L2 ITLB Hit",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x84,
},
{ .name    = "L1_ITLB_MISS_AND_L2_ITLB_MISS",
  .desc    = "L1 ITLB Miss and L2 ITLB Miss",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x85,
},
{ .name    = "PIPELINE_RESTART_DUE_TO_INSTRUCTION_STREAM_PROBE",
  .desc    = "Pipeline Restart Due to Instruction Stream Probe",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x86,
},
{ .name    = "INSTRUCTION_FETCH_STALL",
  .desc    = "Instruction Fetch Stall",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x87,
},
{ .name    = "RETURN_STACK_HITS",
  .desc    = "Return Stack Hits",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x88,
},
{ .name    = "RETURN_STACK_OVERFLOWS",
  .desc    = "Return Stack Overflows",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x89,
},
{ .name    = "RETIRED_CLFLUSH_INSTRUCTIONS",
  .desc    = "Retired CLFLUSH Instructions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x26,
},
{ .name    = "RETIRED_CPUID_INSTRUCTIONS",
  .desc    = "Retired CPUID Instructions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x27,
},
{ .name    = "CPU_CLK_UNHALTED",
  .desc    = "CPU Clocks not Halted",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0x76,
},
{ .name    = "RETIRED_INSTRUCTIONS",
  .desc    = "Retired Instructions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc0,
},
{ .name    = "RETIRED_UOPS",
  .desc    = "Retired uops",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc1,
},
{ .name    = "RETIRED_BRANCH_INSTRUCTIONS",
  .desc    = "Retired Branch Instructions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc2,
},
{ .name    = "RETIRED_MISPREDICTED_BRANCH_INSTRUCTIONS",
  .desc    = "Retired Mispredicted Branch Instructions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc3,
},
{ .name    = "RETIRED_TAKEN_BRANCH_INSTRUCTIONS",
  .desc    = "Retired Taken Branch Instructions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc4,
},
{ .name    = "RETIRED_TAKEN_BRANCH_INSTRUCTIONS_MISPREDICTED",
  .desc    = "Retired Taken Branch Instructions Mispredicted",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc5,
},
{ .name    = "RETIRED_FAR_CONTROL_TRANSFERS",
  .desc    = "Retired Far Control Transfers",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc6,
},
{ .name    = "RETIRED_BRANCH_RESYNCS",
  .desc    = "Retired Branch Resyncs",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc7,
},
{ .name    = "RETIRED_NEAR_RETURNS",
  .desc    = "Retired Near Returns",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc8,
},
{ .name    = "RETIRED_NEAR_RETURNS_MISPREDICTED",
  .desc    = "Retired Near Returns Mispredicted",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xc9,
},
{ .name    = "RETIRED_INDIRECT_BRANCHES_MISPREDICTED",
  .desc    = "Retired Indirect Branches Mispredicted",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xca,
},
{ .name    = "RETIRED_MMX_AND_FP_INSTRUCTIONS",
  .desc    = "Retired MMX/FP Instructions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xcb,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_retired_mmx_and_fp_instructions),
  .ngrp    = 1,
  .umasks  = amd64_k8_retired_mmx_and_fp_instructions,
},
{ .name    = "RETIRED_FASTPATH_DOUBLE_OP_INSTRUCTIONS",
  .desc    = "Retired Fastpath Double Op Instructions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xcc,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_retired_fastpath_double_op_instructions),
  .ngrp    = 1,
  .umasks  = amd64_k8_retired_fastpath_double_op_instructions,
},
{ .name    = "INTERRUPTS_MASKED_CYCLES",
  .desc    = "Interrupts-Masked Cycles",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xcd,
},
{ .name    = "INTERRUPTS_MASKED_CYCLES_WITH_INTERRUPT_PENDING",
  .desc    = "Interrupts-Masked Cycles with Interrupt Pending",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xce,
},
{ .name    = "INTERRUPTS_TAKEN",
  .desc    = "Interrupts Taken",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xcf,
},
{ .name    = "DECODER_EMPTY",
  .desc    = "Decoder Empty",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd0,
},
{ .name    = "DISPATCH_STALLS",
  .desc    = "Dispatch Stalls",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd1,
},
{ .name    = "DISPATCH_STALL_FOR_BRANCH_ABORT",
  .desc    = "Dispatch Stall for Branch Abort to Retire",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd2,
},
{ .name    = "DISPATCH_STALL_FOR_SERIALIZATION",
  .desc    = "Dispatch Stall for Serialization",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd3,
},
{ .name    = "DISPATCH_STALL_FOR_SEGMENT_LOAD",
  .desc    = "Dispatch Stall for Segment Load",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd4,
},
{ .name    = "DISPATCH_STALL_FOR_REORDER_BUFFER_FULL",
  .desc    = "Dispatch Stall for Reorder Buffer Full",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd5,
},
{ .name    = "DISPATCH_STALL_FOR_RESERVATION_STATION_FULL",
  .desc    = "Dispatch Stall for Reservation Station Full",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd6,
},
{ .name    = "DISPATCH_STALL_FOR_FPU_FULL",
  .desc    = "Dispatch Stall for FPU Full",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd7,
},
{ .name    = "DISPATCH_STALL_FOR_LS_FULL",
  .desc    = "Dispatch Stall for LS Full",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd8,
},
{ .name    = "DISPATCH_STALL_WAITING_FOR_ALL_QUIET",
  .desc    = "Dispatch Stall Waiting for All Quiet",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xd9,
},
{ .name    = "DISPATCH_STALL_FOR_FAR_TRANSFER_OR_RSYNC",
  .desc    = "Dispatch Stall for Far Transfer or Resync to Retire",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xda,
},
{ .name    = "FPU_EXCEPTIONS",
  .desc    = "FPU Exceptions",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xdb,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_fpu_exceptions),
  .ngrp    = 1,
  .umasks  = amd64_k8_fpu_exceptions,
},
{ .name    = "DR0_BREAKPOINT_MATCHES",
  .desc    = "DR0 Breakpoint Matches",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xdc,
},
{ .name    = "DR1_BREAKPOINT_MATCHES",
  .desc    = "DR1 Breakpoint Matches",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xdd,
},
{ .name    = "DR2_BREAKPOINT_MATCHES",
  .desc    = "DR2 Breakpoint Matches",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xde,
},
{ .name    = "DR3_BREAKPOINT_MATCHES",
  .desc    = "DR3 Breakpoint Matches",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xdf,
},
{ .name    = "DRAM_ACCESSES_PAGE",
  .desc    = "DRAM Accesses",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xe0,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_dram_accesses_page),
  .ngrp    = 1,
  .umasks  = amd64_k8_dram_accesses_page,
},
{ .name    = "MEMORY_CONTROLLER_PAGE_TABLE_OVERFLOWS",
  .desc    = "Memory Controller Page Table Overflows",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xe1,
},
{ .name    = "MEMORY_CONTROLLER_TURNAROUNDS",
  .desc    = "Memory Controller Turnarounds",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xe3,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_memory_controller_turnarounds),
  .ngrp    = 1,
  .umasks  = amd64_k8_memory_controller_turnarounds,
},
{ .name    = "MEMORY_CONTROLLER_BYPASS",
  .desc    = "Memory Controller Bypass Counter Saturation",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xe4,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_memory_controller_bypass),
  .ngrp    = 1,
  .umasks  = amd64_k8_memory_controller_bypass,
},
{ .name    = "SIZED_BLOCKS",
  .desc    = "Sized Blocks",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xe5,
  .flags   = AMD64_FL_K8_REV_D,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_sized_blocks),
  .ngrp    = 1,
  .umasks  = amd64_k8_sized_blocks,
},
{ .name    = "THERMAL_STATUS_AND_ECC_ERRORS",
  .desc    = "Thermal Status and ECC Errors",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xe8,
  .flags   = AMD64_FL_K8_REV_E,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_thermal_status_and_ecc_errors),
  .ngrp    = 1,
  .umasks  = amd64_k8_thermal_status_and_ecc_errors,
},
{ .name    = "CPU_IO_REQUESTS_TO_MEMORY_IO",
  .desc    = "CPU/IO Requests to Memory/IO",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xe9,
  .flags   = AMD64_FL_K8_REV_E,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_cpu_io_requests_to_memory_io),
  .ngrp    = 1,
  .umasks  = amd64_k8_cpu_io_requests_to_memory_io,
},
{ .name    = "CACHE_BLOCK",
  .desc    = "Cache Block Commands",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xea,
  .flags   = AMD64_FL_K8_REV_E,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_cache_block),
  .ngrp    = 1,
  .umasks  = amd64_k8_cache_block,
},
{ .name    = "SIZED_COMMANDS",
  .desc    = "Sized Commands",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xeb,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_sized_commands),
  .ngrp    = 1,
  .umasks  = amd64_k8_sized_commands,
},
{ .name    = "PROBE",
  .desc    = "Probe Responses and Upstream Requests",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xec,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_probe),
  .ngrp    = 1,
  .umasks  = amd64_k8_probe,
},
{ .name    = "GART",
  .desc    = "GART Events",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xee,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_gart),
  .ngrp    = 1,
  .umasks  = amd64_k8_gart,
},
{ .name    = "HYPERTRANSPORT_LINK0",
  .desc    = "HyperTransport Link 0 Transmit Bandwidth",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xf6,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_hypertransport_link0),
  .ngrp    = 1,
  .umasks  = amd64_k8_hypertransport_link0,
},
{ .name    = "HYPERTRANSPORT_LINK1",
  .desc    = "HyperTransport Link 1 Transmit Bandwidth",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xf7,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_hypertransport_link0),
  .ngrp    = 1,
  .umasks  = amd64_k8_hypertransport_link0, /* identical to actual umasks list for this event */
},
{ .name    = "HYPERTRANSPORT_LINK2",
  .desc    = "HyperTransport Link 2 Transmit Bandwidth",
  .modmsk  = AMD64_BASIC_ATTRS,
  .code    = 0xf8,
  .numasks = LIBPFM_ARRAY_SIZE(amd64_k8_hypertransport_link0),
  .ngrp    = 1,
  .umasks  = amd64_k8_hypertransport_link0, /* identical to actual umasks list for this event */
},
};

