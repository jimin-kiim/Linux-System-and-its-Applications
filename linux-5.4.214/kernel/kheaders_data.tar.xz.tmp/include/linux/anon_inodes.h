/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _LINUX_ANON_INODES_H
#define _LINUX_ANON_INODES_H

struct file_operations;

struct file *anon_inode_getfile(const char *name,
				const struct file_operations *fops,
				void *priv, int flags);
int anon_inode_getfd(const char *name, const struct file_operations *fops,
		     void *priv, int flags);

#endif 

