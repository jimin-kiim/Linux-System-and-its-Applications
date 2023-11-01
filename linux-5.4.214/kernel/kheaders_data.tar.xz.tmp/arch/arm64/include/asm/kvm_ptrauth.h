/* SPDX-License-Identifier: GPL-2.0 */


#ifndef __ASM_KVM_PTRAUTH_H
#define __ASM_KVM_PTRAUTH_H

#ifdef __ASSEMBLY__

#include <asm/sysreg.h>

#ifdef	CONFIG_ARM64_PTR_AUTH

#define PTRAUTH_REG_OFFSET(x)	(x - CPU_APIAKEYLO_EL1)


.macro	ptrauth_save_state base, reg1, reg2
	mrs_s	\reg1, SYS_APIAKEYLO_EL1
	mrs_s	\reg2, SYS_APIAKEYHI_EL1
	stp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APIAKEYLO_EL1)]
	mrs_s	\reg1, SYS_APIBKEYLO_EL1
	mrs_s	\reg2, SYS_APIBKEYHI_EL1
	stp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APIBKEYLO_EL1)]
	mrs_s	\reg1, SYS_APDAKEYLO_EL1
	mrs_s	\reg2, SYS_APDAKEYHI_EL1
	stp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APDAKEYLO_EL1)]
	mrs_s	\reg1, SYS_APDBKEYLO_EL1
	mrs_s	\reg2, SYS_APDBKEYHI_EL1
	stp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APDBKEYLO_EL1)]
	mrs_s	\reg1, SYS_APGAKEYLO_EL1
	mrs_s	\reg2, SYS_APGAKEYHI_EL1
	stp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APGAKEYLO_EL1)]
.endm

.macro	ptrauth_restore_state base, reg1, reg2
	ldp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APIAKEYLO_EL1)]
	msr_s	SYS_APIAKEYLO_EL1, \reg1
	msr_s	SYS_APIAKEYHI_EL1, \reg2
	ldp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APIBKEYLO_EL1)]
	msr_s	SYS_APIBKEYLO_EL1, \reg1
	msr_s	SYS_APIBKEYHI_EL1, \reg2
	ldp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APDAKEYLO_EL1)]
	msr_s	SYS_APDAKEYLO_EL1, \reg1
	msr_s	SYS_APDAKEYHI_EL1, \reg2
	ldp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APDBKEYLO_EL1)]
	msr_s	SYS_APDBKEYLO_EL1, \reg1
	msr_s	SYS_APDBKEYHI_EL1, \reg2
	ldp	\reg1, \reg2, [\base, #PTRAUTH_REG_OFFSET(CPU_APGAKEYLO_EL1)]
	msr_s	SYS_APGAKEYLO_EL1, \reg1
	msr_s	SYS_APGAKEYHI_EL1, \reg2
.endm


.macro ptrauth_switch_to_guest g_ctxt, reg1, reg2, reg3
alternative_if ARM64_HAS_ADDRESS_AUTH_ARCH
	b	1000f
alternative_else_nop_endif
alternative_if_not ARM64_HAS_ADDRESS_AUTH_IMP_DEF
	b	1001f
alternative_else_nop_endif
1000:
	ldr	\reg1, [\g_ctxt, #(VCPU_HCR_EL2 - VCPU_CONTEXT)]
	and	\reg1, \reg1, #(HCR_API | HCR_APK)
	cbz	\reg1, 1001f
	add	\reg1, \g_ctxt, #CPU_APIAKEYLO_EL1
	ptrauth_restore_state	\reg1, \reg2, \reg3
1001:
.endm

.macro ptrauth_switch_to_host g_ctxt, h_ctxt, reg1, reg2, reg3
alternative_if ARM64_HAS_ADDRESS_AUTH_ARCH
	b	2000f
alternative_else_nop_endif
alternative_if_not ARM64_HAS_ADDRESS_AUTH_IMP_DEF
	b	2001f
alternative_else_nop_endif
2000:
	ldr	\reg1, [\g_ctxt, #(VCPU_HCR_EL2 - VCPU_CONTEXT)]
	and	\reg1, \reg1, #(HCR_API | HCR_APK)
	cbz	\reg1, 2001f
	add	\reg1, \g_ctxt, #CPU_APIAKEYLO_EL1
	ptrauth_save_state	\reg1, \reg2, \reg3
	add	\reg1, \h_ctxt, #CPU_APIAKEYLO_EL1
	ptrauth_restore_state	\reg1, \reg2, \reg3
	isb
2001:
.endm

#else 
.macro ptrauth_switch_to_guest g_ctxt, reg1, reg2, reg3
.endm
.macro ptrauth_switch_to_host g_ctxt, h_ctxt, reg1, reg2, reg3
.endm
#endif 
#endif 
#endif 
