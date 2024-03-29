/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef MFD_T7L66XB_H
#define MFD_T7L66XB_H

#include <linux/mfd/core.h>
#include <linux/mfd/tmio.h>

struct t7l66xb_platform_data {
	int (*enable)(struct platform_device *dev);
	int (*suspend)(struct platform_device *dev);
	int (*resume)(struct platform_device *dev);

	int irq_base; 

	struct tmio_nand_data *nand_data;
};


#define IRQ_T7L66XB_MMC        (1)
#define IRQ_T7L66XB_NAND       (3)

#define T7L66XB_NR_IRQS	8

#endif
