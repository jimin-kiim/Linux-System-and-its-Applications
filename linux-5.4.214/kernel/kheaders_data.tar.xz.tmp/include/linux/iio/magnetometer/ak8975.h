/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __IIO_MAGNETOMETER_AK8975_H__
#define __IIO_MAGNETOMETER_AK8975_H__

#include <linux/iio/iio.h>


struct ak8975_platform_data {
	int                     eoc_gpio;
	struct iio_mount_matrix orientation;
};

#endif
