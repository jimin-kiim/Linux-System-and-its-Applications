/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _IP6T_MH_H
#define _IP6T_MH_H

#include <linux/types.h>


struct ip6t_mh {
	__u8 types[2];	
	__u8 invflags;	
};


#define IP6T_MH_INV_TYPE	0x01	
#define IP6T_MH_INV_MASK	0x01	

#endif 
