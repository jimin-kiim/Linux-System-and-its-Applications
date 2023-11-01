/* SPDX-License-Identifier: GPL-2.0 */


#ifndef __ASM_STACKPROTECTOR_H
#define __ASM_STACKPROTECTOR_H

#include <linux/random.h>
#include <linux/version.h>

extern unsigned long __stack_chk_guard;


static __always_inline void boot_init_stack_canary(void)
{
	unsigned long canary;

	
	get_random_bytes(&canary, sizeof(canary));
	canary ^= LINUX_VERSION_CODE;
	canary &= CANARY_MASK;

	current->stack_canary = canary;
	if (!IS_ENABLED(CONFIG_STACKPROTECTOR_PER_TASK))
		__stack_chk_guard = current->stack_canary;
}

#endif	
