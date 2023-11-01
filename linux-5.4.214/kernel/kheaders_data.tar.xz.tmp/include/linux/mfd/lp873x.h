

#ifndef __LINUX_MFD_LP873X_H
#define __LINUX_MFD_LP873X_H

#include <linux/i2c.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>


#define LP873X			0x00


#define LP873X_REG_DEV_REV		0X00
#define LP873X_REG_OTP_REV		0X01
#define LP873X_REG_BUCK0_CTRL_1		0X02
#define LP873X_REG_BUCK0_CTRL_2		0X03
#define LP873X_REG_BUCK1_CTRL_1		0X04
#define LP873X_REG_BUCK1_CTRL_2		0X05
#define LP873X_REG_BUCK0_VOUT		0X06
#define LP873X_REG_BUCK1_VOUT		0X07
#define LP873X_REG_LDO0_CTRL		0X08
#define LP873X_REG_LDO1_CTRL            0X09
#define LP873X_REG_LDO0_VOUT		0X0A
#define LP873X_REG_LDO1_VOUT		0X0B
#define LP873X_REG_BUCK0_DELAY		0X0C
#define LP873X_REG_BUCK1_DELAY		0X0D
#define LP873X_REG_LDO0_DELAY		0X0E
#define LP873X_REG_LDO1_DELAY		0X0F
#define LP873X_REG_GPO_DELAY		0X10
#define LP873X_REG_GPO2_DELAY		0X11
#define LP873X_REG_GPO_CTRL		0X12
#define LP873X_REG_CONFIG		0X13
#define LP873X_REG_PLL_CTRL		0X14
#define LP873X_REG_PGOOD_CTRL1		0X15
#define LP873X_REG_PGOOD_CTRL2		0X16
#define LP873X_REG_PG_FAULT		0X17
#define LP873X_REG_RESET		0X18
#define LP873X_REG_INT_TOP_1		0X19
#define LP873X_REG_INT_TOP_2		0X1A
#define LP873X_REG_INT_BUCK		0X1B
#define LP873X_REG_INT_LDO		0X1C
#define LP873X_REG_TOP_STAT		0X1D
#define LP873X_REG_BUCK_STAT		0X1E
#define LP873X_REG_LDO_STAT		0x1F
#define LP873X_REG_TOP_MASK_1		0x20
#define LP873X_REG_TOP_MASK_2		0x21
#define LP873X_REG_BUCK_MASK		0x22
#define LP873X_REG_LDO_MASK		0x23
#define LP873X_REG_SEL_I_LOAD		0x24
#define LP873X_REG_I_LOAD_2		0x25
#define LP873X_REG_I_LOAD_1		0x26

#define LP873X_REG_MAX			LP873X_REG_I_LOAD_1


#define LP873X_DEV_REV_DEV_ID			0xC0
#define LP873X_DEV_REV_ALL_LAYER		0x30
#define LP873X_DEV_REV_METAL_LAYER		0x0F

#define LP873X_OTP_REV_OTP_ID			0xFF

#define LP873X_BUCK0_CTRL_1_BUCK0_FPWM		BIT(3)
#define LP873X_BUCK0_CTRL_1_BUCK0_RDIS_EN	BIT(2)
#define LP873X_BUCK0_CTRL_1_BUCK0_EN_PIN_CTRL	BIT(1)
#define LP873X_BUCK0_CTRL_1_BUCK0_EN		BIT(0)

#define LP873X_BUCK0_CTRL_2_BUCK0_ILIM		0x38
#define LP873X_BUCK0_CTRL_2_BUCK0_SLEW_RATE	0x07

#define LP873X_BUCK1_CTRL_1_BUCK1_FPWM		BIT(3)
#define LP873X_BUCK1_CTRL_1_BUCK1_RDIS_EN	BIT(2)
#define LP873X_BUCK1_CTRL_1_BUCK1_EN_PIN_CTRL	BIT(1)
#define LP873X_BUCK1_CTRL_1_BUCK1_EN		BIT(0)

#define LP873X_BUCK1_CTRL_2_BUCK1_ILIM		0x38
#define LP873X_BUCK1_CTRL_2_BUCK1_SLEW_RATE	0x07

#define LP873X_BUCK0_VOUT_BUCK0_VSET		0xFF

#define LP873X_BUCK1_VOUT_BUCK1_VSET		0xFF

#define LP873X_LDO0_CTRL_LDO0_RDIS_EN		BIT(2)
#define LP873X_LDO0_CTRL_LDO0_EN_PIN_CTRL	BIT(1)
#define LP873X_LDO0_CTRL_LDO0_EN		BIT(0)

#define LP873X_LDO1_CTRL_LDO1_RDIS_EN		BIT(2)
#define LP873X_LDO1_CTRL_LDO1_EN_PIN_CTRL	BIT(1)
#define LP873X_LDO1_CTRL_LDO1_EN		BIT(0)

#define LP873X_LDO0_VOUT_LDO0_VSET		0x1F

#define LP873X_LDO1_VOUT_LDO1_VSET		0x1F

#define LP873X_BUCK0_DELAY_BUCK0_SD_DELAY	0xF0
#define LP873X_BUCK0_DELAY_BUCK0_SU_DELAY	0x0F

#define LP873X_BUCK1_DELAY_BUCK1_SD_DELAY	0xF0
#define LP873X_BUCK1_DELAY_BUCK1_SU_DELAY	0x0F

#define LP873X_LDO0_DELAY_LDO0_SD_DELAY	0xF0
#define LP873X_LDO0_DELAY_LDO0_SU_DELAY	0x0F

#define LP873X_LDO1_DELAY_LDO1_SD_DELAY	0xF0
#define LP873X_LDO1_DELAY_LDO1_SU_DELAY	0x0F

#define LP873X_GPO_DELAY_GPO_SD_DELAY		0xF0
#define LP873X_GPO_DELAY_GPO_SU_DELAY		0x0F

#define LP873X_GPO2_DELAY_GPO2_SD_DELAY	0xF0
#define LP873X_GPO2_DELAY_GPO2_SU_DELAY	0x0F

#define LP873X_GPO_CTRL_GPO2_OD		BIT(6)
#define LP873X_GPO_CTRL_GPO2_EN_PIN_CTRL	BIT(5)
#define LP873X_GPO_CTRL_GPO2_EN		BIT(4)
#define LP873X_GPO_CTRL_GPO_OD			BIT(2)
#define LP873X_GPO_CTRL_GPO_EN_PIN_CTRL	BIT(1)
#define LP873X_GPO_CTRL_GPO_EN			BIT(0)

#define LP873X_CONFIG_SU_DELAY_SEL		BIT(6)
#define LP873X_CONFIG_SD_DELAY_SEL		BIT(5)
#define LP873X_CONFIG_CLKIN_PIN_SEL		BIT(4)
#define LP873X_CONFIG_CLKIN_PD			BIT(3)
#define LP873X_CONFIG_EN_PD			BIT(2)
#define LP873X_CONFIG_TDIE_WARN_LEVEL		BIT(1)
#define LP873X_EN_SPREAD_SPEC			BIT(0)

#define LP873X_PLL_CTRL_EN_PLL			BIT(6)
#define LP873X_EXT_CLK_FREQ			0x1F

#define LP873X_PGOOD_CTRL1_PGOOD_POL		BIT(7)
#define LP873X_PGOOD_CTRL1_PGOOD_OD		BIT(6)
#define LP873X_PGOOD_CTRL1_PGOOD_WINDOW_LDO	BIT(5)
#define LP873X_PGOOD_CTRL1_PGOOD_WINDOWN_BUCK	BIT(4)
#define LP873X_PGOOD_CTRL1_PGOOD_EN_PGOOD_LDO1	BIT(3)
#define LP873X_PGOOD_CTRL1_PGOOD_EN_PGOOD_LDO0	BIT(2)
#define LP873X_PGOOD_CTRL1_PGOOD_EN_PGOOD_BUCK1	BIT(1)
#define LP873X_PGOOD_CTRL1_PGOOD_EN_PGOOD_BUCK0	BIT(0)

#define LP873X_PGOOD_CTRL2_EN_PGOOD_TWARN	BIT(2)
#define LP873X_PGOOD_CTRL2_EN_PG_FAULT_GATE	BIT(1)
#define LP873X_PGOOD_CTRL2_PGOOD_MODE		BIT(0)

#define LP873X_PG_FAULT_PG_FAULT_LDO1		BIT(3)
#define LP873X_PG_FAULT_PG_FAULT_LDO0		BIT(2)
#define LP873X_PG_FAULT_PG_FAULT_BUCK1		BIT(1)
#define LP873X_PG_FAULT_PG_FAULT_BUCK0		BIT(0)

#define LP873X_RESET_SW_RESET			BIT(0)

#define LP873X_INT_TOP_1_PGOOD_INT		BIT(7)
#define LP873X_INT_TOP_1_LDO_INT		BIT(6)
#define LP873X_INT_TOP_1_BUCK_INT		BIT(5)
#define LP873X_INT_TOP_1_SYNC_CLK_INT		BIT(4)
#define LP873X_INT_TOP_1_TDIE_SD_INT		BIT(3)
#define LP873X_INT_TOP_1_TDIE_WARN_INT		BIT(2)
#define LP873X_INT_TOP_1_OVP_INT		BIT(1)
#define LP873X_INT_TOP_1_I_MEAS_INT		BIT(0)

#define LP873X_INT_TOP_2_RESET_REG_INT		BIT(0)

#define LP873X_INT_BUCK_BUCK1_PG_INT		BIT(6)
#define LP873X_INT_BUCK_BUCK1_SC_INT		BIT(5)
#define LP873X_INT_BUCK_BUCK1_ILIM_INT		BIT(4)
#define LP873X_INT_BUCK_BUCK0_PG_INT		BIT(2)
#define LP873X_INT_BUCK_BUCK0_SC_INT		BIT(1)
#define LP873X_INT_BUCK_BUCK0_ILIM_INT		BIT(0)

#define LP873X_INT_LDO_LDO1_PG_INT		BIT(6)
#define LP873X_INT_LDO_LDO1_SC_INT		BIT(5)
#define LP873X_INT_LDO_LDO1_ILIM_INT		BIT(4)
#define LP873X_INT_LDO_LDO0_PG_INT		BIT(2)
#define LP873X_INT_LDO_LDO0_SC_INT		BIT(1)
#define LP873X_INT_LDO_LDO0_ILIM_INT		BIT(0)

#define LP873X_TOP_STAT_PGOOD_STAT		BIT(7)
#define LP873X_TOP_STAT_SYNC_CLK_STAT		BIT(4)
#define LP873X_TOP_STAT_TDIE_SD_STAT		BIT(3)
#define LP873X_TOP_STAT_TDIE_WARN_STAT		BIT(2)
#define LP873X_TOP_STAT_OVP_STAT		BIT(1)

#define LP873X_BUCK_STAT_BUCK1_STAT		BIT(7)
#define LP873X_BUCK_STAT_BUCK1_PG_STAT		BIT(6)
#define LP873X_BUCK_STAT_BUCK1_ILIM_STAT	BIT(4)
#define LP873X_BUCK_STAT_BUCK0_STAT		BIT(3)
#define LP873X_BUCK_STAT_BUCK0_PG_STAT		BIT(2)
#define LP873X_BUCK_STAT_BUCK0_ILIM_STAT	BIT(0)

#define LP873X_LDO_STAT_LDO1_STAT		BIT(7)
#define LP873X_LDO_STAT_LDO1_PG_STAT		BIT(6)
#define LP873X_LDO_STAT_LDO1_ILIM_STAT		BIT(4)
#define LP873X_LDO_STAT_LDO0_STAT		BIT(3)
#define LP873X_LDO_STAT_LDO0_PG_STAT		BIT(2)
#define LP873X_LDO_STAT_LDO0_ILIM_STAT		BIT(0)

#define LP873X_TOP_MASK_1_PGOOD_INT_MASK	BIT(7)
#define LP873X_TOP_MASK_1_SYNC_CLK_MASK	BIT(4)
#define LP873X_TOP_MASK_1_TDIE_WARN_MASK	BIT(2)
#define LP873X_TOP_MASK_1_I_MEAS_MASK		BIT(0)

#define LP873X_TOP_MASK_2_RESET_REG_MASK	BIT(0)

#define LP873X_BUCK_MASK_BUCK1_PGF_MASK	BIT(7)
#define LP873X_BUCK_MASK_BUCK1_PGR_MASK	BIT(6)
#define LP873X_BUCK_MASK_BUCK1_ILIM_MASK	BIT(4)
#define LP873X_BUCK_MASK_BUCK0_PGF_MASK	BIT(3)
#define LP873X_BUCK_MASK_BUCK0_PGR_MASK	BIT(2)
#define LP873X_BUCK_MASK_BUCK0_ILIM_MASK	BIT(0)

#define LP873X_LDO_MASK_LDO1_PGF_MASK		BIT(7)
#define LP873X_LDO_MASK_LDO1_PGR_MASK		BIT(6)
#define LP873X_LDO_MASK_LDO1_ILIM_MASK		BIT(4)
#define LP873X_LDO_MASK_LDO0_PGF_MASK		BIT(3)
#define LP873X_LDO_MASK_LDO0_PGR_MASK		BIT(2)
#define LP873X_LDO_MASK_LDO0_ILIM_MASK		BIT(0)

#define LP873X_SEL_I_LOAD_CURRENT_BUCK_SELECT	BIT(0)

#define LP873X_I_LOAD_2_BUCK_LOAD_CURRENT	BIT(0)

#define LP873X_I_LOAD_1_BUCK_LOAD_CURRENT	0xFF

#define LP873X_MAX_REG_ID		LP873X_LDO_1


#define LP873X_NUM_BUCK		2

#define LP873X_NUM_LDO		2

#define LP873X_NUM_REGULATOR		(LP873X_NUM_BUCK + LP873X_NUM_LDO)

enum lp873x_regulator_id {
	
	LP873X_BUCK_0,
	LP873X_BUCK_1,
	
	LP873X_LDO_0,
	LP873X_LDO_1,
};


struct lp873x {
	struct device *dev;
	u8 rev;
	struct regmap *regmap;
};
#endif 
