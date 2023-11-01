/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __LINUX_MFD_CROS_EC_H
#define __LINUX_MFD_CROS_EC_H

#include <linux/device.h>


struct cros_ec_dev {
	struct device class_dev;
	struct cros_ec_device *ec_dev;
	struct device *dev;
	struct cros_ec_debugfs *debug_info;
	bool has_kb_wake_angle;
	u16 cmd_offset;
	u32 features[2];
};

#define to_cros_ec_dev(dev)  container_of(dev, struct cros_ec_dev, class_dev)

#endif 
