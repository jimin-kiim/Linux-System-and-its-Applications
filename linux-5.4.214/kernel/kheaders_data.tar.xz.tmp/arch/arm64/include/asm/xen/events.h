/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_ARM64_XEN_EVENTS_H
#define _ASM_ARM64_XEN_EVENTS_H

#include <asm/ptrace.h>
#include <asm/atomic.h>

enum ipi_vector {
	XEN_PLACEHOLDER_VECTOR,

	
	XEN_NR_IPIS,
};

static inline int xen_irqs_disabled(struct pt_regs *regs)
{
	return !interrupts_enabled(regs);
}

#define xchg_xen_ulong(ptr, val) xchg((ptr), (val))


static inline bool xen_support_evtchn_rebind(void)
{
	return true;
}

#endif 
