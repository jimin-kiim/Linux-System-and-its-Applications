/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __ASM_VDSO_H
#define __ASM_VDSO_H


#define VDSO_LBASE	0x0

#ifndef __ASSEMBLY__

#include <generated/vdso-offsets.h>
#ifdef CONFIG_COMPAT_VDSO
#include <generated/vdso32-offsets.h>
#endif

#define VDSO_SYMBOL(base, name)						   \
({									   \
	(void *)(vdso_offset_##name - VDSO_LBASE + (unsigned long)(base)); \
})

#endif 

#endif 
