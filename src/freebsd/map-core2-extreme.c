/****************************/
/* THIS IS OPEN SOURCE CODE */
/****************************/

/* 
* File:    map-core2-extreme.c
* CVS:     $Id$
* Author:  George Neville-Neil
*          gnn@freebsd.org
*          Harald Servat
*          redcrash@gmail.com
*/

#include SUBSTRATE
#include "papiStdEventDefs.h"
#include "map.h"


/****************************************************************************
 CORE2_EXTREME SUBSTRATE 
 CORE2_EXTREME SUBSTRATE 
 CORE2_EXTREME SUBSTRATE
 CORE2_EXTREME SUBSTRATE
 CORE2_EXTREME SUBSTRATE
****************************************************************************/

/*
	NativeEvent_Value_Core2ExtremeProcessor must match Core2ExtremeProcessor_info 
*/

Native_Event_LabelDescription_t Core2ExtremeProcessor_info[] =
{
	{"BACLEARS", "The number of times the front end is resteered."},
	{"BOGUS_BR", "The number of byte sequences mistakenly detected as taken branch instructions."},
	{"BR_BAC_MISSP_EXEC", "The number of branch instructions that were mispredicted when decoded."},
	{"BR_CALL_MISSP_EXEC", "The number of mispredicted CALL instructions that were executed."},
	{"BR_CALL_EXEC", "The number of CALL instructions executed."},
	{"BR_CND_EXEC", "The number of conditional branches executed, but not necessarily retired."},
	{"BR_CND_MISSP_EXEC", "The number of mispredicted conditional branches executed."},
	{"BR_IND_CALL_EXEC", "The number of indirect CALL instructions executed."},
	{"BR_IND_EXEC", "The number of indirect branch instructions executed."},
	{"BR_IND_MISSP_EXEC", "The number of mispredicted indirect branch instructions executed."},
	{"BR_INST_DECODED", "The number of branch instructions decoded."},
	{"BR_INST_EXEC", "The number of branches executed, but not necessarily retired."},
	{"BR_INST_RETIRED.ANY", "The number of branch instructions retired.  This is an architectural performance event."},
	{"BR_INST_RETIRED.MISPRED", "The number of mispredicted branch instructions retired.  This is an architectural performance event."},
	{"BR_INST_RETIRED.MISPRED_NOT_TAKEN", "The number of not taken branch instructions retired that were mispredicted."},
	{"BR_INST_RETIRED.MISPRED_TAKEN", "The number taken branch instructions retired that were mispredicted."},
	{"BR_INST_RETIRED.PRED_NOT_TAKEN", "The number of not taken branch instructions retired that were correctly predicted."},
	{"BR_INST_RETIRED.PRED_TAKEN", "The number of taken branch instructions retired that were correctly predicted."},
	{"BR_INST_RETIRED.TAKEN", "The number of taken branch instructions retired."},
	{"BR_MISSP_EXEC", "The number of mispredicted branch instructions that were executed."},
	{"BR_RET_MISSP_EXEC", "The number of mispredicted RET instructions executed."},
	{"BR_RET_BAC_MISSP_EXEC", "The number of RET instructions executed that were mispredicted at decode time."},
	{"BR_RET_EXEC", "The number of RET instructions executed."},
	{"BR_TKN_BUBBLE_1", "The number of branch predicted taken with bubble 1."},
	{"BR_TKN_BUBBLE_2", "The number of branch predicted taken with bubble 2."},
	{"BUSQ_EMPTY", "The number of cycles during which the core did not have any pending transactions in the bus queue."},
	{"BUS_BNR_DRV", "Number of Bus Not Ready signals asserted on the bus."},
	{"BUS_DATA_RCV", "Number of bus cycles during which the processor is receiving data."},
	{"BUS_DRDY_CLOCKS", "The number of bus cycles during which the Data Ready signal is asserted on the bus."},
	{"BUS_HIT_DRV", "The number of bus cycles during which the processor drives the HIT# pin."},
	{"BUS_HITM_DRV", "The number of bus cycles during which the processor drives the HITM# pin."},
	{"BUS_IO_WAIT", "The number of core cycles during which I/O requests wait in the bus queue."},
	{"BUS_LOCK_CLOCKS", "The number of bus cycles during which the LOCK signal was asserted on the bus."},
	{"BUS_REQUEST_OUTSTANDING", "The number of pending full cache line read transactions on the bus occuring in each cycle."},
	{"BUS_TRANS_ANY", "The number of bus transactions of any kind."},
	{"BUS_TRANS_BRD", "The number of burst read transactions."},
	{"BUS_TRANS_BURST", "The number of burst transactions."},
	{"BUS_TRANS_DEF", "The number of deferred bus transactions."},
	{"BUS_TRANS_IFETCH", "The number of instruction fetch full cache line bus transactions."},
	{"BUS_TRANS_INVAL", "The number of invalidate bus transactions."},
	{"BUS_TRANS_IO", "The number of completed I/O bus transaactions due to IN and OUT instructions."},
	{"BUS_TRANS_MEM", "The number of memory bus transactions."},
	{"BUS_TRANS_P", "The number of partial bus transactions."},
	{"BUS_TRANS_PWR", "The number of partial write bus transactions."},
	{"BUS_TRANS_RFO", "The number of Read For Ownership bus transactions."},
	{"BUS_TRANS_WB", "The number of explicit writeback bus transactions due to dirty line evictions."},
	{"CMP_SNOOP", "The number of times the L1 data cache is snooped by the other core in the same processor."},
	{"CPU_CLK_UNHALTED.BUS", "The number of bus cycles when the core is not in the halt state. This is an architectural performance event."},
	{"CPU_CLK_UNHALTED.CORE_P", "The number of core cycles while the core is not in a halt state.  This is an architectural performance event."},
	{"CPU_CLK_UNHALTED.NO_OTHER", "The number of bus cycles during which the core remains unhalted and the other core is halted."},
	{"CYCLES_DIV_BUSY", "The number of cycles the divider is busy.  This event is only available on PMC0."},
	{"CYCLES_INT_MASKED", "The number of cycles during which interrupts are disabled."},
	{"CYCLES_INT_PENDING_AND_MASKED", "The number of cycles during which there were pending interrupts while interrupts were disabled."},
	{"CYCLES_L1I_MEM_STALLED", "The number of cycles for which an instruction fetch stalls."},
	{"DELAYED_BYPASS.FP", "The number of floating point operations that used data immediately after the data was generated by a non floating point execution unit."},
	{"DELAYED_BYPASS.LOAD", "The number of delayed bypass penalty cycles that a load operation incurred."},
	{"DELAYED_BYPASS.SIMD", "The number of times SIMD operations use data immediately after data, was generated by a non-SIMD execution unit."},
	{"DIV", "The number of divide operations executed."},
	{"DTLB_MISSES.ANY", "The number of Data TLB misses, including misses that result from speculative accesses."},
	{"DTLB_MISSES.L0_MISS_LD", "The number of level 0 DTLB misses due to load operations."},
	{"DTLB_MISSES.MISS_LD", "The number of Data TLB misses due to load operations."},
	{"DTLB_MISSES.MISS_ST", "The number of Data TLB misses due to store operations."},
	{"EIST_TRANS", "The number of Enhanced Intel SpeedStep Technology transitions."},
	{"ESP.ADDITIONS", "The number of automatic additions to the esp register."},
	{"ESP.SYNCH", "The number of times the esp register was explicitly used in an address expression after it is implicitly used by a PUSH or POP instruction."},
	{"EXT_SNOOP", "The number of snoop responses to bus transactions."},
	{"FP_ASSIST", "The number of floating point operations executed that needed a microcode assist."},
	{"FP_COMP_OPS_EXE", "The number of floating point computational micro-ops executed.  The event is available only on PMC0."},
	{"FP_MMX_TRANS_TO_FP", "The number of transitions from MMX instructions to floating point instructions."},
	{"FP_MMX_TRANS_TO_MMX", "The number of transitions from floating point instructions to MMX instructions."},
	{"HW_INT_RCV", "The number of hardware interrupts recieved."},
	{"IDLE_DURING_DIV", "The number of cycles the divider is busy and no other execution unit or load operation was in progress.  This event is available only on PMC0."},
	{"ILD_STALL", "The number of cycles the instruction length decoder stalled due to a length changing prefix."},
	{"INST_QUEUE.FULL", "The number of cycles during which the instruction queue is full."},
	{"INST_RETIRED.ANY_P", "The number of instructions retired.  This is an architectural performance event."},
	{"INST_RETIRED.LOADS", "The number of instructions retired that contained a load operation."},
	{"INST_RETIRED.OTHER", "The number of instructions retired that did not contain a load or a store operation."},
	{"INST_RETIRED.STORES", "The number of instructions retired that contained a store operation."},
	{"INST_RETIRED.VM_H", "The number of instructions retired while in VMX root operation."},
	{"ITLB.FLUSH", "The number of ITLB flushes."},
	{"ITLB.LARGE_MISS", "The number of instruction fetches from large pages that miss the ITLB."},
	{"ITLB.MISSES", "The number of instruction fetches from both large and small pages that miss the ITLB."},
	{"ITLB.SMALL_MISS", "The number of instruction fetches from small pages that miss the ITLB."},
	{"ITLB_MISS_RETIRED", "The number of retired instructions that missed the ITLB when they were fetched."},
	{"L1D_ALL_CACHE_REF", "The number of data reads and writes to cacheable memory."},
	{"L1D_ALL_REF", "The number of references to L1 data cache counting loads and stores of to all memory types."},
	{"L1D_CACHE_LD", "Number of data reads from cacheable memory excluding locked reads."},
	{"L1D_CACHE_LOCK", "Number of locked reads from cacheable memory."},
	{"L1D_CACHE_LOCK_DURATION", "The number of cycles during which any cache line is locked by any locking instruction."},
	{"L1D_CACHE_ST", "The number of data writes to cacheable memory excluding locked writes."},
	{"L1D_M_EVICT", "The number of modified cache lines evicted from L1 data cache."},
	{"L1D_M_REPL", "The number of modified lines allocated in L1 data cache."},
	{"L1D_PEND_MISS", "The total number of outstanding L1 data cache misses at any clock."},
	{"L1D_PREFETCH.REQUESTS", "The number of times L1 data cache requested to prefetch a data cache line."},
	{"L1D_REPL", "The number of lines brought into L1 data cache."},
	{"L1D_SPLIT.LOADS", "The number of load operations that span two cache lines."},
	{"L1D_SPLIT.STORES", "The number of store operations that span two cache lines."},
	{"L1I_MISSES", "The number of instruction fetch unit misses."},
	{"L1I_READS", "The number of instruction fetches."},
	{"L2_ADS", "The number of cycles that the L2 address bus is in use."},
	{"L2_DBUS_BUSY_RD", "The number of cycles during which the L2 data bus is busy transferring data to the core."},
	{"L2_IFETCH", "The number of instruction cache line requests from the instruction fetch unit."},
	{"L2_LD", "The number of L2 cache read requests from L1 cache and L2 prefetchers."},
	{"L2_LINES_IN", "The number of cache lines allocated in L2 cache."},
	{"L2_LINES_OUT", "The number of L2 cache lines evicted."},
	{"L2_LOCK", "The number of locked accesses to cache lines that miss L1 data cache."},
	{"L2_M_LINES_IN", "The number of L2 cache line modifications."},
	{"L2_M_LINES_OUT", "The number of modified lines evicted from L2 cache."},
	{"L2_NO_REQ", "Number of cycles during which no L2 cache requests were pending from a core."},
	{"L2_REJECT_BUSQ", "Number of L2 cache requests that were rejected."},
	{"L2_RQSTS", "The number of completed L2 cache requests."},
	{"L2_RQSTS.SELF.DEMAND.I_STATE", "The number of completed L2 cache demand requests from this core that missed the L2 cache.  This is an architectural performance event."},
	{"L2_RQSTS.SELF.DEMAND.MESI", "The number of completed L2 cache demand requests from this core.  This is an architectural performance event."},
	{"L2_ST", "The number of store operations that miss the L1 cache and request data from the L2 cache."},
	{"LOAD_BLOCK.L1D", "The number of loads blocked by the L1 data cache."},
	{"LOAD_BLOCK.OVERLAP_STORE", "The number of loads that partially overlap an earlier store or are aliased with a previous store."},
	{"LOAD_BLOCK.STA", "The number of loads blocked by preceding stores whose address is yet to be calculated."},
	{"LOAD_BLOCK.STD", "The number of loads blocked by preceding stores to the same address whose data value is not known."},
	{"LOAD_BLOCK.UNTIL_RETIRE", "The numer of load operations that were blocked until retirement."},
	{"LOAD_HIT_PRE", "The number of load operations that conflicted with an prefetch to the same cache line."},
	{"MACHINE_NUKES.MEM_ORDER", "The number of times the execution pipeline was restarted due to a memory ordering conflict or memory disambiguation misprediction."},
	{"MACHINE_NUKES.SMC", "The number of times a program writes to a code section."},
	{"MACRO_INSTS.CISC_DECODED", "The number of complex instructions decoded."},
	{"MACRO_INSTS.DECODED", "The number of instructions decoded."},
	{"MEMORY_DISAMBIGUATION.RESET", "The number of cycles during which memory disambiguation misprediction occurs."},
	{"MEMORY_DISAMBIGUATION.SUCCESS", "The number of load operations that were successfully disambiguated."},
	{"MEM_LOAD_RETIRED.DTLB_MISS", "The number of retired loads that missed the DTLB."},
	{"MEM_LOAD_RETIRED.L1D_LINE_MISS", "The number of retired load operations that missed L1 data cache and that sent a request to L2 cache. This event is only available on PMC0."},
	{"MEM_LOAD_RETIRED.L1D_MISS", "The number of retired load operations that missed L1 data cache.  This event is only available on PMC0."},
	{"MEM_LOAD_RETIRED.L2_LINE_MISS", "The number of load operations that missed L2 cache and that caused a bus request."},
	{"MEM_LOAD_RETIRED.L2_MISS", "The number of load operations that missed L2 cache."},
	{"MUL","The number of multiply operations executed (only available on PMC1.)"},
	{"PAGE_WALKS.COUNT", "The number of page walks executed due to an ITLB or DTLB miss."},
	{"PAGE_WALKS.CYCLES", "The number of cycles spent in a page walk caused by an ITLB or DTLB miss."},
	{"PREF_RQSTS_DN", "The number of downward prefetches issued from the Data Prefetch Logic unit to L2 cache."},
	{"PREF_RQSTS_UP", "The number of upward prefetches issued from the Data Prefetch Logic unit to L2 cache."},
	{"RAT_STALLS.ANY", "The number of stall cycles due to any of RAT_STALLS.FLAGS RAT_STALLS.FPSW, RAT_STALLS.PARTIAL and RAT_STALLS.ROB_READ_PORT."},
	{"RAT_STALLS.FLAGS", "The number of cycles execution stalled due to a flag register induced stall."},
	{"RAT_STALLS.FPSW", "The number of times the floating point status word was written."},
	{"RAT_STALLS.OTHER_SERIALIZATION_STALLS", "The number of stalls due to other RAT resource serialization not counted by umask 0FH."},
	{"RAT_STALLS.PARTIAL_CYCLES", "The number of cycles of added instruction execution latency due to the use of a register that was partially written by previous instructions."},
	{"RAT_STALLS.ROB_READ_PORT", "The number of cycles when ROB read port stalls occurred."},
	{"RESOURCE_STALLS.ANY", "The number of cycles during which any resource related stall occurred."},
	{"RESOURCE_STALLS.BR_MISS_CLEAR", "The number of cycles stalled due to branch misprediction."},
	{"RESOURCE_STALLS.FPCW", "The number of cycles stalled due to writing the floating point control word."},
	{"RESOURCE_STALLS.LD_ST", "The number of cycles during which the number of loads and stores in the pipeline exceeded their limits."},
	{"RESOURCE_STALLS.ROB_FULL", "The number of cycles when the reorder buffer was full."},
	{"RESOURCE_STALLS.RS_FULL", "The number of cycles during which the RS was full."},
	{"RS_UOPS_DISPATCHED", "The number of micro-ops dispatched for execution."},
	{"RS_UOPS_DISPATCHED.PORT0", "The number of cycles micro-ops were dispatched for execution on port 0."},
	{"RS_UOPS_DISPATCHED.PORT1", "The number of cycles micro-ops were dispatched for execution on port 1."},
	{"RS_UOPS_DISPATCHED.PORT2", "The number of cycles micro-ops were dispatched for execution on port 2."},
	{"RS_UOPS_DISPATCHED.PORT3", "The number of cycles micro-ops were dispatched for execution on port 3."},
	{"RS_UOPS_DISPATCHED.PORT4", "The number of cycles micro-ops were dispatched for execution on port 4."},
	{"RS_UOPS_DISPATCHED.PORT5", "The number of cycles micro-ops were dispatched for execution on port 5."},
	{"SB_DRAIN_CYCLES", "The number of cycles while the store buffer is draining."},
	{"SEGMENT_REG_LOADS", "The number of segment register loads."},
	{"SEG_REG_RENAMES.ANY", "The number of times the any segment register was renamed."},
	{"SEG_REG_RENAMES.DS", "The number of times the ds register is renamed."},
	{"SEG_REG_RENAMES.ES", "The number of times the es register is renamed."},
	{"SEG_REG_RENAMES.FS", "The number of times the fs register is renamed."},
	{"SEG_REG_RENAMES.GS", "The number of times the gs register is renamed."},
	{"SEG_RENAME_STALLS.ANY", "The number of stalls due to lack of resource to rename any segment register."},
	{"SEG_RENAME_STALLS.DS", "The number of stalls due to lack of renaming resources for the ds register."},
	{"SEG_RENAME_STALLS.ES", "The number of stalls due to lack of renaming resources for the es register."},
	{"SEG_RENAME_STALLS.FS", "The number of stalls due to lack of renaming resources for the fs register."},
	{"SEG_RENAME_STALLS.GS", "The number of stalls due to lack of renaming resources for the gs register."},
	{"SIMD_ASSIST", "The number SIMD assists invoked."},
	{"SIMD_COMP_INST_RETIRED.PACKED_DOUBLE", "Then number of computational SSE2 packed double precision instructions retired."},
	{"SIMD_COMP_INST_RETIRED.PACKED_SINGLE", "Then number of computational SSE2 packed single precision instructions retired."},
	{"SIMD_COMP_INST_RETIRED.SCALAR_DOUBLE", "Then number of computational SSE2 scalar double precision instructions retired."},
	{"SIMD_COMP_INST_RETIRED.SCALAR_SINGLE", "Then number of computational SSE2 scalar single precision instructions retired."},
	{"SIMD_INSTR_RETIRED", "The number of retired SIMD instructions that use MMX registers."},
	{"SIMD_INST_RETIRED.ANY", "The number of streaming SIMD instructions retired."},
	{"SIMD_INST_RETIRED.PACKED_DOUBLE", "The number of SSE2 packed double precision instructions retired."},
	{"SIMD_INST_RETIRED.PACKED_SINGLE", "The number of SSE packed single precision instructions retired."},
	{"SIMD_INST_RETIRED.SCALAR_DOUBLE", "The number of SSE2 scalar double precision instructions retired."},
	{"SIMD_INST_RETIRED.SCALAR_SINGLE", "The number of SSE scalar single precision instructions retired."},
	{"SIMD_INST_RETIRED.VECTOR", "The number of SSE2 vector instructions retired."},
	{"SIMD_SAT_INSTR_RETIRED", "The number of saturated arithmetic SIMD instructions retired."},
	{"SIMD_SAT_UOP_EXEC", "The number of SIMD saturated arithmetic micro-ops executed."},
	{"SIMD_UOPS_EXEC", "The number of SIMD micro-ops executed."},
	{"SIMD_UOP_TYPE_EXEC.ARITHMETIC", "The number of SIMD packed arithmetic micro-ops executed."},
	{"SIMD_UOP_TYPE_EXEC.LOGICAL", "The number of SIMD packed logical micro-ops executed."},
	{"SIMD_UOP_TYPE_EXEC.MUL", "The number of SIMD packed multiply micro-ops executed."},
	{"SIMD_UOP_TYPE_EXEC.PACK", "The number of SIMD pack micro-ops executed."},
	{"SIMD_UOP_TYPE_EXEC.SHIFT", "The number of SIMD packed shift micro-ops executed."},
	{"SIMD_UOP_TYPE_EXEC.UNPACK", "The number of SIMD unpack micro-ops executed."},
	{"SNOOP_STALL_DRV", "The number of times the bus stalled for snoops."},
	{"SSE_PRE_EXEC.L1", "The number of PREFETCHT0 instructions executed."},
	{"SSE_PRE_EXEC.L2", "The number of PREFETCHT1 instructions executed."},
	{"SSE_PRE_EXEC.NTA", "The number of PREFETCHNTA instructions executed."},
	{"SSE_PRE_EXEC.STORES", "The number of times SSE non-temporal store instructions were executed."},
	{"SSE_PRE_MISS.L1", "The number of times the PREFETCHT0 instruction executed and missed all cache levels."},
	{"SSE_PRE_MISS.L2", "The number of times the PREFETCHT1 instruction executed and missed all cache levels."},
	{"SSE_PRE_MISS.NTA", "The number of times the PREFETCHNTA instruction executed and missed all cache levels."},
	{"STORE_BLOCK.ORDER", "The number of cycles while a store was waiting for another store to be globally observed."},
	{"STORE_BLOCK.SNOOP", "The number of cycles while a store was blocked due to a conflict with an internal or external snoop."},
	{"THERMAL_TRIP", "The number of thermal trips."},
	{"UOPS_RETIRED.ANY", "The number of micro-ops retired."},
	{"UOPS_RETIRED.FUSED", "The number of fused micro-ops retired."},
	{"UOPS_RETIRED.LD_IND_BR", "The number of micro-ops retired that fused a load with another operation."},
	{"UOPS_RETIRED.MACRO_FUSION", "The number of times retired instruction pairs were fused into one micro-op."},
	{"UOPS_RETIRED.NON_FUSED", "he number of non-fused micro-ops retired."},
	{"UOPS_RETIRED.STD_STA", "The number of store address calculations that fused into one micro-op."},
	{"X87_OPS_RETIRED.ANY", "The number of floating point computational instructions retired."},
	{"X87_OPS_RETIRED.FXCH", "The number of FXCH instructions retired."},
	{ NULL, NULL } 
};

/* PAPI PRESETS */
hwi_search_t Core2ExtremeProcessor_map[] = {
	{PAPI_BR_INS, {0, {PNE_CORE2EXTREME_BR_INST_RETIRED_ANY, PAPI_NULL}, {0,}}},
	{PAPI_RES_STL, {0, {PNE_CORE2EXTREME_RESOURCE_STALLS_ANY, PAPI_NULL}, {0,}}},
	{PAPI_TOT_CYC, {0, {PNE_CORE2EXTREME_CPU_CLK_UNHALTED_BUS, PAPI_NULL}, {0,}}},
	{PAPI_TOT_INS, {0, {PNE_CORE2EXTREME_INST_RETIRED_ANY_P, PAPI_NULL}, {0,}}},
	{PAPI_HW_INT, {0, {PNE_CORE2EXTREME_HW_INT_RCV, PAPI_NULL}, {0,}}},
	{PAPI_BR_TKN, {0, {PNE_CORE2EXTREME_BR_INST_RETIRED_TAKEN, PAPI_NULL}, {0,}}},
	{PAPI_BR_MSP, {0, {PNE_CORE2EXTREME_BR_MISSP_EXEC, PAPI_NULL}, {0,}}},
	{PAPI_TLB_DM, {0, {PNE_CORE2EXTREME_DTLB_MISSES_ANY, PAPI_NULL}, {0,}}},
	{PAPI_TLB_IM, {0, {PNE_CORE2EXTREME_ITLB_MISSES, PAPI_NULL}, {0,}}},
#if HWPMC_NUM_COUNTERS >= 2
	{PAPI_TLB_TL, {DERIVED_ADD, {PNE_CORE2EXTREME_DTLB_MISSES_ANY, PNE_CORE2EXTREME_ITLB_MISSES, PAPI_NULL},{0,}}},
#endif
	{PAPI_L1_DCA, {0, {PNE_CORE2EXTREME_L1D_ALL_REF, PAPI_NULL}, {0,}}},
	{PAPI_L1_ICA, {0, {PNE_CORE2EXTREME_L1I_READS, PAPI_NULL}, {0,}}},
#if HWPMC_NUM_COUNTERS >= 2
	{PAPI_L1_TCA, {DERIVED_ADD, {PNE_CORE2EXTREME_L1D_ALL_REF, PNE_CORE2EXTREME_L1I_READS, PAPI_NULL}, {0,}}},
#endif
	/* PAPI_L2_ICH seems not to work
	{PAPI_L2_ICH, {0, {PNE_CORE2EXTREME_L2_IFETCH, PAPI_NULL}, {0,}}},
	*/
	{PAPI_L2_DCH, {0, {PNE_CORE2EXTREME_L2_LD, PAPI_NULL}, {0,}}},
	{PAPI_FP_INS, {0, {PNE_CORE2EXTREME_X87_OPS_RETIRED_ANY, PAPI_NULL}, {0,}}},
	{PAPI_L1_DCM, {0, {PNE_CORE2EXTREME_MEM_LOAD_RETIRED_L1D_MISS, PAPI_NULL}, {0,}}},
	{PAPI_L1_ICM, {0, {PNE_CORE2EXTREME_L1I_MISSES, PAPI_NULL}, {0,}}},
#if HWPMC_NUM_COUNTERS >= 2
	{PAPI_L1_TCM, {DERIVED_ADD, {PNE_CORE2EXTREME_MEM_LOAD_RETIRED_L1D_MISS, PNE_CORE2EXTREME_L1I_MISSES, PAPI_NULL}, {0,}}},
#endif
	{PAPI_L2_DCM, {0, {PNE_CORE2EXTREME_MEM_LOAD_RETIRED_L2_MISS, PAPI_NULL}, {0,}}},
	{0, {0, {PAPI_NULL}, {0,}}}
};

