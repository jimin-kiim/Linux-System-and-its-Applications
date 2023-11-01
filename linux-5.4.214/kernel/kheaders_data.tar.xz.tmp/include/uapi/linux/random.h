/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */


#ifndef _UAPI_LINUX_RANDOM_H
#define _UAPI_LINUX_RANDOM_H

#include <linux/types.h>
#include <linux/ioctl.h>
#include <linux/irqnr.h>




#define RNDGETENTCNT	_IOR( 'R', 0x00, int )


#define RNDADDTOENTCNT	_IOW( 'R', 0x01, int )


#define RNDGETPOOL	_IOR( 'R', 0x02, int [2] )


#define RNDADDENTROPY	_IOW( 'R', 0x03, int [2] )


#define RNDZAPENTCNT	_IO( 'R', 0x04 )


#define RNDCLEARPOOL	_IO( 'R', 0x06 )


#define RNDRESEEDCRNG	_IO( 'R', 0x07 )

struct rand_pool_info {
	int	entropy_count;
	int	buf_size;
	__u32	buf[0];
};


#define GRND_NONBLOCK	0x0001
#define GRND_RANDOM	0x0002
#define GRND_INSECURE	0x0004

#endif 
