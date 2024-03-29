/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef _XT_DSCP_H
#define _XT_DSCP_H

#include <linux/types.h>

#define XT_DSCP_MASK	0xfc	
#define XT_DSCP_SHIFT	2
#define XT_DSCP_MAX	0x3f	


struct xt_dscp_info {
	__u8 dscp;
	__u8 invert;
};

struct xt_tos_match_info {
	__u8 tos_mask;
	__u8 tos_value;
	__u8 invert;
};

#endif 
