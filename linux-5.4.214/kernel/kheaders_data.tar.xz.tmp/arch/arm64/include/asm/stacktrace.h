/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __ASM_STACKTRACE_H
#define __ASM_STACKTRACE_H

#include <linux/percpu.h>
#include <linux/sched.h>
#include <linux/sched/task_stack.h>
#include <linux/types.h>

#include <asm/memory.h>
#include <asm/ptrace.h>
#include <asm/sdei.h>

enum stack_type {
	STACK_TYPE_UNKNOWN,
	STACK_TYPE_TASK,
	STACK_TYPE_IRQ,
	STACK_TYPE_OVERFLOW,
	STACK_TYPE_SDEI_NORMAL,
	STACK_TYPE_SDEI_CRITICAL,
	__NR_STACK_TYPES
};

struct stack_info {
	unsigned long low;
	unsigned long high;
	enum stack_type type;
};


struct stackframe {
	unsigned long fp;
	unsigned long pc;
	DECLARE_BITMAP(stacks_done, __NR_STACK_TYPES);
	unsigned long prev_fp;
	enum stack_type prev_type;
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
	int graph;
#endif
};

extern int unwind_frame(struct task_struct *tsk, struct stackframe *frame);
extern void walk_stackframe(struct task_struct *tsk, struct stackframe *frame,
			    int (*fn)(struct stackframe *, void *), void *data);
extern void dump_backtrace(struct pt_regs *regs, struct task_struct *tsk);

DECLARE_PER_CPU(unsigned long *, irq_stack_ptr);

static inline bool on_irq_stack(unsigned long sp,
				struct stack_info *info)
{
	unsigned long low = (unsigned long)raw_cpu_read(irq_stack_ptr);
	unsigned long high = low + IRQ_STACK_SIZE;

	if (!low)
		return false;

	if (sp < low || sp >= high)
		return false;

	if (info) {
		info->low = low;
		info->high = high;
		info->type = STACK_TYPE_IRQ;
	}

	return true;
}

static inline bool on_task_stack(const struct task_struct *tsk,
				 unsigned long sp,
				 struct stack_info *info)
{
	unsigned long low = (unsigned long)task_stack_page(tsk);
	unsigned long high = low + THREAD_SIZE;

	if (sp < low || sp >= high)
		return false;

	if (info) {
		info->low = low;
		info->high = high;
		info->type = STACK_TYPE_TASK;
	}

	return true;
}

#ifdef CONFIG_VMAP_STACK
DECLARE_PER_CPU(unsigned long [OVERFLOW_STACK_SIZE/sizeof(long)], overflow_stack);

static inline bool on_overflow_stack(unsigned long sp,
				struct stack_info *info)
{
	unsigned long low = (unsigned long)raw_cpu_ptr(overflow_stack);
	unsigned long high = low + OVERFLOW_STACK_SIZE;

	if (sp < low || sp >= high)
		return false;

	if (info) {
		info->low = low;
		info->high = high;
		info->type = STACK_TYPE_OVERFLOW;
	}

	return true;
}
#else
static inline bool on_overflow_stack(unsigned long sp,
			struct stack_info *info) { return false; }
#endif



static inline bool on_accessible_stack(const struct task_struct *tsk,
				       unsigned long sp,
				       struct stack_info *info)
{
	if (info)
		info->type = STACK_TYPE_UNKNOWN;

	if (on_task_stack(tsk, sp, info))
		return true;
	if (tsk != current || preemptible())
		return false;
	if (on_irq_stack(sp, info))
		return true;
	if (on_overflow_stack(sp, info))
		return true;
	if (on_sdei_stack(sp, info))
		return true;

	return false;
}

static inline void start_backtrace(struct stackframe *frame,
				   unsigned long fp, unsigned long pc)
{
	frame->fp = fp;
	frame->pc = pc;
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
	frame->graph = 0;
#endif

	
	bitmap_zero(frame->stacks_done, __NR_STACK_TYPES);
	frame->prev_fp = 0;
	frame->prev_type = STACK_TYPE_UNKNOWN;
}

#endif	
