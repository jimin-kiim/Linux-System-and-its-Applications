/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __ASM_NEON_H
#define __ASM_NEON_H

#include <linux/types.h>
#include <asm/fpsimd.h>

#define cpu_has_neon()		system_supports_fpsimd()

void kernel_neon_begin(void);
void kernel_neon_end(void);

#endif 
