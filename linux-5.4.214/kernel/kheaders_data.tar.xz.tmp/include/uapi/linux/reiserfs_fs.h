/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef _LINUX_REISER_FS_H
#define _LINUX_REISER_FS_H

#include <linux/types.h>
#include <linux/magic.h>




#define REISERFS_IOC_UNPACK		_IOW(0xCD,1,long)

#define REISERFS_IOC_GETFLAGS		FS_IOC_GETFLAGS
#define REISERFS_IOC_SETFLAGS		FS_IOC_SETFLAGS
#define REISERFS_IOC_GETVERSION		FS_IOC_GETVERSION
#define REISERFS_IOC_SETVERSION		FS_IOC_SETVERSION

#endif				
