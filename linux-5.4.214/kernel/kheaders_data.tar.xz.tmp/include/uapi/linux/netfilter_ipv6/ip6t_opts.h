/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _IP6T_OPTS_H
#define _IP6T_OPTS_H

#include <linux/types.h>

#define IP6T_OPTS_OPTSNR 16

struct ip6t_opts {
	__u32 hdrlen;			
	__u8 flags;				
	__u8 invflags;			
	__u16 opts[IP6T_OPTS_OPTSNR];	
	__u8 optsnr;			
};

#define IP6T_OPTS_LEN 		0x01
#define IP6T_OPTS_OPTS 		0x02
#define IP6T_OPTS_NSTRICT	0x04


#define IP6T_OPTS_INV_LEN	0x01	
#define IP6T_OPTS_INV_MASK	0x01	

#endif 
