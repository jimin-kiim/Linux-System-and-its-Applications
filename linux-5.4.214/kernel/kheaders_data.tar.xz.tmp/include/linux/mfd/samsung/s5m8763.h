/* SPDX-License-Identifier: GPL-2.0+ */


#ifndef __LINUX_MFD_S5M8763_H
#define __LINUX_MFD_S5M8763_H


enum s5m8763_reg {
	S5M8763_REG_IRQ1,
	S5M8763_REG_IRQ2,
	S5M8763_REG_IRQ3,
	S5M8763_REG_IRQ4,
	S5M8763_REG_IRQM1,
	S5M8763_REG_IRQM2,
	S5M8763_REG_IRQM3,
	S5M8763_REG_IRQM4,
	S5M8763_REG_STATUS1,
	S5M8763_REG_STATUS2,
	S5M8763_REG_STATUSM1,
	S5M8763_REG_STATUSM2,
	S5M8763_REG_CHGR1,
	S5M8763_REG_CHGR2,
	S5M8763_REG_LDO_ACTIVE_DISCHARGE1,
	S5M8763_REG_LDO_ACTIVE_DISCHARGE2,
	S5M8763_REG_BUCK_ACTIVE_DISCHARGE3,
	S5M8763_REG_ONOFF1,
	S5M8763_REG_ONOFF2,
	S5M8763_REG_ONOFF3,
	S5M8763_REG_ONOFF4,
	S5M8763_REG_BUCK1_VOLTAGE1,
	S5M8763_REG_BUCK1_VOLTAGE2,
	S5M8763_REG_BUCK1_VOLTAGE3,
	S5M8763_REG_BUCK1_VOLTAGE4,
	S5M8763_REG_BUCK2_VOLTAGE1,
	S5M8763_REG_BUCK2_VOLTAGE2,
	S5M8763_REG_BUCK3,
	S5M8763_REG_BUCK4,
	S5M8763_REG_LDO1_LDO2,
	S5M8763_REG_LDO3,
	S5M8763_REG_LDO4,
	S5M8763_REG_LDO5,
	S5M8763_REG_LDO6,
	S5M8763_REG_LDO7,
	S5M8763_REG_LDO7_LDO8,
	S5M8763_REG_LDO9_LDO10,
	S5M8763_REG_LDO11,
	S5M8763_REG_LDO12,
	S5M8763_REG_LDO13,
	S5M8763_REG_LDO14,
	S5M8763_REG_LDO15,
	S5M8763_REG_LDO16,
	S5M8763_REG_BKCHR,
	S5M8763_REG_LBCNFG1,
	S5M8763_REG_LBCNFG2,
};


enum s5m8763_regulators {
	S5M8763_LDO1,
	S5M8763_LDO2,
	S5M8763_LDO3,
	S5M8763_LDO4,
	S5M8763_LDO5,
	S5M8763_LDO6,
	S5M8763_LDO7,
	S5M8763_LDO8,
	S5M8763_LDO9,
	S5M8763_LDO10,
	S5M8763_LDO11,
	S5M8763_LDO12,
	S5M8763_LDO13,
	S5M8763_LDO14,
	S5M8763_LDO15,
	S5M8763_LDO16,
	S5M8763_BUCK1,
	S5M8763_BUCK2,
	S5M8763_BUCK3,
	S5M8763_BUCK4,
	S5M8763_AP_EN32KHZ,
	S5M8763_CP_EN32KHZ,
	S5M8763_ENCHGVI,
	S5M8763_ESAFEUSB1,
	S5M8763_ESAFEUSB2,
};

#define S5M8763_ENRAMP                  (1 << 4)
#endif 
