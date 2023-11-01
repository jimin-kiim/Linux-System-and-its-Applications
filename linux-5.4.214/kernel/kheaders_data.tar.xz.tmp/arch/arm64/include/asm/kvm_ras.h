/* SPDX-License-Identifier: GPL-2.0 */


#ifndef __ARM64_KVM_RAS_H__
#define __ARM64_KVM_RAS_H__

#include <linux/acpi.h>
#include <linux/errno.h>
#include <linux/types.h>

#include <asm/acpi.h>


static inline int kvm_handle_guest_sea(phys_addr_t addr, unsigned int esr)
{
	
	lockdep_assert_irqs_enabled();

	return apei_claim_sea(NULL);
}

#endif 
