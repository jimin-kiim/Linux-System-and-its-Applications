/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_START_KERNEL_H
#define _LINUX_START_KERNEL_H

#include <linux/linkage.h>
#include <linux/init.h>



extern asmlinkage void __init start_kernel(void);
extern void __init arch_call_rest_init(void);
extern void __ref rest_init(void);

#endif 