/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_PROTOTYPES_H
#define __ASM_PROTOTYPES_H

#include <linux/arm-smccc.h>

#include <asm/ftrace.h>
#include <asm/page.h>
#include <asm/string.h>
#include <asm/uaccess.h>

#include <asm-generic/asm-prototypes.h>

long long __ashlti3(long long a, int b);
long long __ashrti3(long long a, int b);
long long __lshrti3(long long a, int b);

#endif 
