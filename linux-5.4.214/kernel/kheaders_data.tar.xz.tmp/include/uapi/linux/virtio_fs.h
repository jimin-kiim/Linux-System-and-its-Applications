/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-3-Clause) */

#ifndef _UAPI_LINUX_VIRTIO_FS_H
#define _UAPI_LINUX_VIRTIO_FS_H

#include <linux/types.h>
#include <linux/virtio_ids.h>
#include <linux/virtio_config.h>
#include <linux/virtio_types.h>

struct virtio_fs_config {
	
	__u8 tag[36];

	
	__u32 num_request_queues;
} __attribute__((packed));

#endif 
