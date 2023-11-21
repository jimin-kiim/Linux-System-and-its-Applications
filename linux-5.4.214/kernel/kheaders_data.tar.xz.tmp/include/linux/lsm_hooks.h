

#ifndef __LINUX_LSM_HOOKS_H
#define __LINUX_LSM_HOOKS_H

#include <linux/security.h>
#include <linux/init.h>
#include <linux/rculist.h>


union security_list_options {
	int (*binder_set_context_mgr)(const struct cred *mgr);
	int (*binder_transaction)(const struct cred *from,
					const struct cred *to);
	int (*binder_transfer_binder)(const struct cred *from,
					const struct cred *to);
	int (*binder_transfer_file)(const struct cred *from,
					const struct cred *to,
					struct file *file);

	int (*ptrace_access_check)(struct task_struct *child,
					unsigned int mode);
	int (*ptrace_traceme)(struct task_struct *parent);
	int (*capget)(struct task_struct *target, kernel_cap_t *effective,
			kernel_cap_t *inheritable, kernel_cap_t *permitted);
	int (*capset)(struct cred *new, const struct cred *old,
			const kernel_cap_t *effective,
			const kernel_cap_t *inheritable,
			const kernel_cap_t *permitted);
	int (*capable)(const struct cred *cred,
			struct user_namespace *ns,
			int cap,
			unsigned int opts);
	int (*quotactl)(int cmds, int type, int id, struct super_block *sb);
	int (*quota_on)(struct dentry *dentry);
	int (*syslog)(int type);
	int (*settime)(const struct timespec64 *ts, const struct timezone *tz);
	int (*vm_enough_memory)(struct mm_struct *mm, long pages);

	int (*bprm_set_creds)(struct linux_binprm *bprm);
	int (*bprm_check_security)(struct linux_binprm *bprm);
	void (*bprm_committing_creds)(struct linux_binprm *bprm);
	void (*bprm_committed_creds)(struct linux_binprm *bprm);

	int (*fs_context_dup)(struct fs_context *fc, struct fs_context *src_sc);
	int (*fs_context_parse_param)(struct fs_context *fc, struct fs_parameter *param);

	int (*sb_alloc_security)(struct super_block *sb);
	void (*sb_free_security)(struct super_block *sb);
	void (*sb_free_mnt_opts)(void *mnt_opts);
	int (*sb_eat_lsm_opts)(char *orig, void **mnt_opts);
	int (*sb_remount)(struct super_block *sb, void *mnt_opts);
	int (*sb_kern_mount)(struct super_block *sb);
	int (*sb_show_options)(struct seq_file *m, struct super_block *sb);
	int (*sb_statfs)(struct dentry *dentry);
	int (*sb_mount)(const char *dev_name, const struct path *path,
			const char *type, unsigned long flags, void *data);
	int (*sb_umount)(struct vfsmount *mnt, int flags);
	int (*sb_pivotroot)(const struct path *old_path, const struct path *new_path);
	int (*sb_set_mnt_opts)(struct super_block *sb,
				void *mnt_opts,
				unsigned long kern_flags,
				unsigned long *set_kern_flags);
	int (*sb_clone_mnt_opts)(const struct super_block *oldsb,
					struct super_block *newsb,
					unsigned long kern_flags,
					unsigned long *set_kern_flags);
	int (*sb_add_mnt_opt)(const char *option, const char *val, int len,
			      void **mnt_opts);
	int (*move_mount)(const struct path *from_path, const struct path *to_path);
	int (*dentry_init_security)(struct dentry *dentry, int mode,
					const struct qstr *name, void **ctx,
					u32 *ctxlen);
	int (*dentry_create_files_as)(struct dentry *dentry, int mode,
					struct qstr *name,
					const struct cred *old,
					struct cred *new);


#ifdef CONFIG_SECURITY_PATH
	int (*path_unlink)(const struct path *dir, struct dentry *dentry);
	int (*path_mkdir)(const struct path *dir, struct dentry *dentry,
				umode_t mode);
	int (*path_rmdir)(const struct path *dir, struct dentry *dentry);
	int (*path_mknod)(const struct path *dir, struct dentry *dentry,
				umode_t mode, unsigned int dev);
	int (*path_truncate)(const struct path *path);
	int (*path_symlink)(const struct path *dir, struct dentry *dentry,
				const char *old_name);
	int (*path_link)(struct dentry *old_dentry, const struct path *new_dir,
				struct dentry *new_dentry);
	int (*path_rename)(const struct path *old_dir, struct dentry *old_dentry,
				const struct path *new_dir,
				struct dentry *new_dentry);
	int (*path_chmod)(const struct path *path, umode_t mode);
	int (*path_chown)(const struct path *path, kuid_t uid, kgid_t gid);
	int (*path_chroot)(const struct path *path);
#endif
	
	int (*path_notify)(const struct path *path, u64 mask,
				unsigned int obj_type);
	int (*inode_alloc_security)(struct inode *inode);
	void (*inode_free_security)(struct inode *inode);
	int (*inode_init_security)(struct inode *inode, struct inode *dir,
					const struct qstr *qstr,
					const char **name, void **value,
					size_t *len);
	int (*inode_create)(struct inode *dir, struct dentry *dentry,
				umode_t mode);
	int (*inode_link)(struct dentry *old_dentry, struct inode *dir,
				struct dentry *new_dentry);
	int (*inode_unlink)(struct inode *dir, struct dentry *dentry);
	int (*inode_symlink)(struct inode *dir, struct dentry *dentry,
				const char *old_name);
	int (*inode_mkdir)(struct inode *dir, struct dentry *dentry,
				umode_t mode);
	int (*inode_rmdir)(struct inode *dir, struct dentry *dentry);
	int (*inode_mknod)(struct inode *dir, struct dentry *dentry,
				umode_t mode, dev_t dev);
	int (*inode_rename)(struct inode *old_dir, struct dentry *old_dentry,
				struct inode *new_dir,
				struct dentry *new_dentry);
	int (*inode_readlink)(struct dentry *dentry);
	int (*inode_follow_link)(struct dentry *dentry, struct inode *inode,
				 bool rcu);
	int (*inode_permission)(struct inode *inode, int mask);
	int (*inode_setattr)(struct dentry *dentry, struct iattr *attr);
	int (*inode_getattr)(const struct path *path);
	int (*inode_setxattr)(struct dentry *dentry, const char *name,
				const void *value, size_t size, int flags);
	void (*inode_post_setxattr)(struct dentry *dentry, const char *name,
					const void *value, size_t size,
					int flags);
	int (*inode_getxattr)(struct dentry *dentry, const char *name);
	int (*inode_listxattr)(struct dentry *dentry);
	int (*inode_removexattr)(struct dentry *dentry, const char *name);
	int (*inode_need_killpriv)(struct dentry *dentry);
	int (*inode_killpriv)(struct dentry *dentry);
	int (*inode_getsecurity)(struct inode *inode, const char *name,
					void **buffer, bool alloc);
	int (*inode_setsecurity)(struct inode *inode, const char *name,
					const void *value, size_t size,
					int flags);
	int (*inode_listsecurity)(struct inode *inode, char *buffer,
					size_t buffer_size);
	void (*inode_getsecid)(struct inode *inode, u32 *secid);
	int (*inode_copy_up)(struct dentry *src, struct cred **new);
	int (*inode_copy_up_xattr)(const char *name);

	int (*kernfs_init_security)(struct kernfs_node *kn_dir,
				    struct kernfs_node *kn);

	int (*file_permission)(struct file *file, int mask);
	int (*file_alloc_security)(struct file *file);
	void (*file_free_security)(struct file *file);
	int (*file_ioctl)(struct file *file, unsigned int cmd,
				unsigned long arg);
	int (*mmap_addr)(unsigned long addr);
	int (*mmap_file)(struct file *file, unsigned long reqprot,
				unsigned long prot, unsigned long flags);
	int (*file_mprotect)(struct vm_area_struct *vma, unsigned long reqprot,
				unsigned long prot);
	int (*file_lock)(struct file *file, unsigned int cmd);
	int (*file_fcntl)(struct file *file, unsigned int cmd,
				unsigned long arg);
	void (*file_set_fowner)(struct file *file);
	int (*file_send_sigiotask)(struct task_struct *tsk,
					struct fown_struct *fown, int sig);
	int (*file_receive)(struct file *file);
	int (*file_open)(struct file *file);

	int (*task_alloc)(struct task_struct *task, unsigned long clone_flags);
	void (*task_free)(struct task_struct *task);
	int (*cred_alloc_blank)(struct cred *cred, gfp_t gfp);
	void (*cred_free)(struct cred *cred);
	int (*cred_prepare)(struct cred *new, const struct cred *old,
				gfp_t gfp);
	void (*cred_transfer)(struct cred *new, const struct cred *old);
	void (*cred_getsecid)(const struct cred *c, u32 *secid);
	int (*kernel_act_as)(struct cred *new, u32 secid);
	int (*kernel_create_files_as)(struct cred *new, struct inode *inode);
	int (*kernel_module_request)(char *kmod_name);
	int (*kernel_load_data)(enum kernel_load_data_id id);
	int (*kernel_read_file)(struct file *file, enum kernel_read_file_id id);
	int (*kernel_post_read_file)(struct file *file, char *buf, loff_t size,
				     enum kernel_read_file_id id);
	int (*task_fix_setuid)(struct cred *new, const struct cred *old,
				int flags);
	int (*task_setpgid)(struct task_struct *p, pid_t pgid);
	int (*task_getpgid)(struct task_struct *p);
	int (*task_getsid)(struct task_struct *p);
	void (*task_getsecid)(struct task_struct *p, u32 *secid);
	int (*task_setnice)(struct task_struct *p, int nice);
	int (*task_setioprio)(struct task_struct *p, int ioprio);
	int (*task_getioprio)(struct task_struct *p);
	int (*task_prlimit)(const struct cred *cred, const struct cred *tcred,
			    unsigned int flags);
	int (*task_setrlimit)(struct task_struct *p, unsigned int resource,
				struct rlimit *new_rlim);
	int (*task_setscheduler)(struct task_struct *p);
	int (*task_getscheduler)(struct task_struct *p);
	int (*task_movememory)(struct task_struct *p);
	int (*task_kill)(struct task_struct *p, struct kernel_siginfo *info,
				int sig, const struct cred *cred);
	int (*task_prctl)(int option, unsigned long arg2, unsigned long arg3,
				unsigned long arg4, unsigned long arg5);
	void (*task_to_inode)(struct task_struct *p, struct inode *inode);

	int (*ipc_permission)(struct kern_ipc_perm *ipcp, short flag);
	void (*ipc_getsecid)(struct kern_ipc_perm *ipcp, u32 *secid);

	int (*msg_msg_alloc_security)(struct msg_msg *msg);
	void (*msg_msg_free_security)(struct msg_msg *msg);

	int (*msg_queue_alloc_security)(struct kern_ipc_perm *perm);
	void (*msg_queue_free_security)(struct kern_ipc_perm *perm);
	int (*msg_queue_associate)(struct kern_ipc_perm *perm, int msqflg);
	int (*msg_queue_msgctl)(struct kern_ipc_perm *perm, int cmd);
	int (*msg_queue_msgsnd)(struct kern_ipc_perm *perm, struct msg_msg *msg,
				int msqflg);
	int (*msg_queue_msgrcv)(struct kern_ipc_perm *perm, struct msg_msg *msg,
				struct task_struct *target, long type,
				int mode);

	int (*shm_alloc_security)(struct kern_ipc_perm *perm);
	void (*shm_free_security)(struct kern_ipc_perm *perm);
	int (*shm_associate)(struct kern_ipc_perm *perm, int shmflg);
	int (*shm_shmctl)(struct kern_ipc_perm *perm, int cmd);
	int (*shm_shmat)(struct kern_ipc_perm *perm, char __user *shmaddr,
				int shmflg);

	int (*sem_alloc_security)(struct kern_ipc_perm *perm);
	void (*sem_free_security)(struct kern_ipc_perm *perm);
	int (*sem_associate)(struct kern_ipc_perm *perm, int semflg);
	int (*sem_semctl)(struct kern_ipc_perm *perm, int cmd);
	int (*sem_semop)(struct kern_ipc_perm *perm, struct sembuf *sops,
				unsigned nsops, int alter);

	int (*netlink_send)(struct sock *sk, struct sk_buff *skb);

	void (*d_instantiate)(struct dentry *dentry, struct inode *inode);

	int (*getprocattr)(struct task_struct *p, char *name, char **value);
	int (*setprocattr)(const char *name, void *value, size_t size);
	int (*ismaclabel)(const char *name);
	int (*secid_to_secctx)(u32 secid, char **secdata, u32 *seclen);
	int (*secctx_to_secid)(const char *secdata, u32 seclen, u32 *secid);
	void (*release_secctx)(char *secdata, u32 seclen);

	void (*inode_invalidate_secctx)(struct inode *inode);
	int (*inode_notifysecctx)(struct inode *inode, void *ctx, u32 ctxlen);
	int (*inode_setsecctx)(struct dentry *dentry, void *ctx, u32 ctxlen);
	int (*inode_getsecctx)(struct inode *inode, void **ctx, u32 *ctxlen);

#ifdef CONFIG_SECURITY_NETWORK
	int (*unix_stream_connect)(struct sock *sock, struct sock *other,
					struct sock *newsk);
	int (*unix_may_send)(struct socket *sock, struct socket *other);

	int (*socket_create)(int family, int type, int protocol, int kern);
	int (*socket_post_create)(struct socket *sock, int family, int type,
					int protocol, int kern);
	int (*socket_socketpair)(struct socket *socka, struct socket *sockb);
	int (*socket_bind)(struct socket *sock, struct sockaddr *address,
				int addrlen);
	int (*socket_connect)(struct socket *sock, struct sockaddr *address,
				int addrlen);
	int (*socket_listen)(struct socket *sock, int backlog);
	int (*socket_accept)(struct socket *sock, struct socket *newsock);
	int (*socket_sendmsg)(struct socket *sock, struct msghdr *msg,
				int size);
	int (*socket_recvmsg)(struct socket *sock, struct msghdr *msg,
				int size, int flags);
	int (*socket_getsockname)(struct socket *sock);
	int (*socket_getpeername)(struct socket *sock);
	int (*socket_getsockopt)(struct socket *sock, int level, int optname);
	int (*socket_setsockopt)(struct socket *sock, int level, int optname);
	int (*socket_shutdown)(struct socket *sock, int how);
	int (*socket_sock_rcv_skb)(struct sock *sk, struct sk_buff *skb);
	int (*socket_getpeersec_stream)(struct socket *sock,
					char __user *optval,
					int __user *optlen, unsigned len);
	int (*socket_getpeersec_dgram)(struct socket *sock,
					struct sk_buff *skb, u32 *secid);
	int (*sk_alloc_security)(struct sock *sk, int family, gfp_t priority);
	void (*sk_free_security)(struct sock *sk);
	void (*sk_clone_security)(const struct sock *sk, struct sock *newsk);
	void (*sk_getsecid)(struct sock *sk, u32 *secid);
	void (*sock_graft)(struct sock *sk, struct socket *parent);
	int (*inet_conn_request)(struct sock *sk, struct sk_buff *skb,
					struct request_sock *req);
	void (*inet_csk_clone)(struct sock *newsk,
				const struct request_sock *req);
	void (*inet_conn_established)(struct sock *sk, struct sk_buff *skb);
	int (*secmark_relabel_packet)(u32 secid);
	void (*secmark_refcount_inc)(void);
	void (*secmark_refcount_dec)(void);
	void (*req_classify_flow)(const struct request_sock *req,
					struct flowi *fl);
	int (*tun_dev_alloc_security)(void **security);
	void (*tun_dev_free_security)(void *security);
	int (*tun_dev_create)(void);
	int (*tun_dev_attach_queue)(void *security);
	int (*tun_dev_attach)(struct sock *sk, void *security);
	int (*tun_dev_open)(void *security);
	int (*sctp_assoc_request)(struct sctp_endpoint *ep,
				  struct sk_buff *skb);
	int (*sctp_bind_connect)(struct sock *sk, int optname,
				 struct sockaddr *address, int addrlen);
	void (*sctp_sk_clone)(struct sctp_endpoint *ep, struct sock *sk,
			      struct sock *newsk);
#endif	

#ifdef CONFIG_SECURITY_INFINIBAND
	int (*ib_pkey_access)(void *sec, u64 subnet_prefix, u16 pkey);
	int (*ib_endport_manage_subnet)(void *sec, const char *dev_name,
					u8 port_num);
	int (*ib_alloc_security)(void **sec);
	void (*ib_free_security)(void *sec);
#endif	

#ifdef CONFIG_SECURITY_NETWORK_XFRM
	int (*xfrm_policy_alloc_security)(struct xfrm_sec_ctx **ctxp,
					  struct xfrm_user_sec_ctx *sec_ctx,
						gfp_t gfp);
	int (*xfrm_policy_clone_security)(struct xfrm_sec_ctx *old_ctx,
						struct xfrm_sec_ctx **new_ctx);
	void (*xfrm_policy_free_security)(struct xfrm_sec_ctx *ctx);
	int (*xfrm_policy_delete_security)(struct xfrm_sec_ctx *ctx);
	int (*xfrm_state_alloc)(struct xfrm_state *x,
				struct xfrm_user_sec_ctx *sec_ctx);
	int (*xfrm_state_alloc_acquire)(struct xfrm_state *x,
					struct xfrm_sec_ctx *polsec,
					u32 secid);
	void (*xfrm_state_free_security)(struct xfrm_state *x);
	int (*xfrm_state_delete_security)(struct xfrm_state *x);
	int (*xfrm_policy_lookup)(struct xfrm_sec_ctx *ctx, u32 fl_secid,
					u8 dir);
	int (*xfrm_state_pol_flow_match)(struct xfrm_state *x,
						struct xfrm_policy *xp,
						const struct flowi *fl);
	int (*xfrm_decode_session)(struct sk_buff *skb, u32 *secid, int ckall);
#endif	

	
#ifdef CONFIG_KEYS
	int (*key_alloc)(struct key *key, const struct cred *cred,
				unsigned long flags);
	void (*key_free)(struct key *key);
	int (*key_permission)(key_ref_t key_ref, const struct cred *cred,
				unsigned perm);
	int (*key_getsecurity)(struct key *key, char **_buffer);
#endif	

#ifdef CONFIG_AUDIT
	int (*audit_rule_init)(u32 field, u32 op, char *rulestr,
				void **lsmrule);
	int (*audit_rule_known)(struct audit_krule *krule);
	int (*audit_rule_match)(u32 secid, u32 field, u32 op, void *lsmrule);
	void (*audit_rule_free)(void *lsmrule);
#endif 

#ifdef CONFIG_BPF_SYSCALL
	int (*bpf)(int cmd, union bpf_attr *attr,
				 unsigned int size);
	int (*bpf_map)(struct bpf_map *map, fmode_t fmode);
	int (*bpf_prog)(struct bpf_prog *prog);
	int (*bpf_map_alloc_security)(struct bpf_map *map);
	void (*bpf_map_free_security)(struct bpf_map *map);
	int (*bpf_prog_alloc_security)(struct bpf_prog_aux *aux);
	void (*bpf_prog_free_security)(struct bpf_prog_aux *aux);
#endif 
	int (*locked_down)(enum lockdown_reason what);
};

struct security_hook_heads {
	struct hlist_head binder_set_context_mgr;
	struct hlist_head binder_transaction;
	struct hlist_head binder_transfer_binder;
	struct hlist_head binder_transfer_file;
	struct hlist_head ptrace_access_check;
	struct hlist_head ptrace_traceme;
	struct hlist_head capget;
	struct hlist_head capset;
	struct hlist_head capable;
	struct hlist_head quotactl;
	struct hlist_head quota_on;
	struct hlist_head syslog;
	struct hlist_head settime;
	struct hlist_head vm_enough_memory;
	struct hlist_head bprm_set_creds;
	struct hlist_head bprm_check_security;
	struct hlist_head bprm_committing_creds;
	struct hlist_head bprm_committed_creds;
	struct hlist_head fs_context_dup;
	struct hlist_head fs_context_parse_param;
	struct hlist_head sb_alloc_security;
	struct hlist_head sb_free_security;
	struct hlist_head sb_free_mnt_opts;
	struct hlist_head sb_eat_lsm_opts;
	struct hlist_head sb_remount;
	struct hlist_head sb_kern_mount;
	struct hlist_head sb_show_options;
	struct hlist_head sb_statfs;
	struct hlist_head sb_mount;
	struct hlist_head sb_umount;
	struct hlist_head sb_pivotroot;
	struct hlist_head sb_set_mnt_opts;
	struct hlist_head sb_clone_mnt_opts;
	struct hlist_head sb_add_mnt_opt;
	struct hlist_head move_mount;
	struct hlist_head dentry_init_security;
	struct hlist_head dentry_create_files_as;
#ifdef CONFIG_SECURITY_PATH
	struct hlist_head path_unlink;
	struct hlist_head path_mkdir;
	struct hlist_head path_rmdir;
	struct hlist_head path_mknod;
	struct hlist_head path_truncate;
	struct hlist_head path_symlink;
	struct hlist_head path_link;
	struct hlist_head path_rename;
	struct hlist_head path_chmod;
	struct hlist_head path_chown;
	struct hlist_head path_chroot;
#endif
	
	struct hlist_head path_notify;
	struct hlist_head inode_alloc_security;
	struct hlist_head inode_free_security;
	struct hlist_head inode_init_security;
	struct hlist_head inode_create;
	struct hlist_head inode_link;
	struct hlist_head inode_unlink;
	struct hlist_head inode_symlink;
	struct hlist_head inode_mkdir;
	struct hlist_head inode_rmdir;
	struct hlist_head inode_mknod;
	struct hlist_head inode_rename;
	struct hlist_head inode_readlink;
	struct hlist_head inode_follow_link;
	struct hlist_head inode_permission;
	struct hlist_head inode_setattr;
	struct hlist_head inode_getattr;
	struct hlist_head inode_setxattr;
	struct hlist_head inode_post_setxattr;
	struct hlist_head inode_getxattr;
	struct hlist_head inode_listxattr;
	struct hlist_head inode_removexattr;
	struct hlist_head inode_need_killpriv;
	struct hlist_head inode_killpriv;
	struct hlist_head inode_getsecurity;
	struct hlist_head inode_setsecurity;
	struct hlist_head inode_listsecurity;
	struct hlist_head inode_getsecid;
	struct hlist_head inode_copy_up;
	struct hlist_head inode_copy_up_xattr;
	struct hlist_head kernfs_init_security;
	struct hlist_head file_permission;
	struct hlist_head file_alloc_security;
	struct hlist_head file_free_security;
	struct hlist_head file_ioctl;
	struct hlist_head mmap_addr;
	struct hlist_head mmap_file;
	struct hlist_head file_mprotect;
	struct hlist_head file_lock;
	struct hlist_head file_fcntl;
	struct hlist_head file_set_fowner;
	struct hlist_head file_send_sigiotask;
	struct hlist_head file_receive;
	struct hlist_head file_open;
	struct hlist_head task_alloc;
	struct hlist_head task_free;
	struct hlist_head cred_alloc_blank;
	struct hlist_head cred_free;
	struct hlist_head cred_prepare;
	struct hlist_head cred_transfer;
	struct hlist_head cred_getsecid;
	struct hlist_head kernel_act_as;
	struct hlist_head kernel_create_files_as;
	struct hlist_head kernel_load_data;
	struct hlist_head kernel_read_file;
	struct hlist_head kernel_post_read_file;
	struct hlist_head kernel_module_request;
	struct hlist_head task_fix_setuid;
	struct hlist_head task_setpgid;
	struct hlist_head task_getpgid;
	struct hlist_head task_getsid;
	struct hlist_head task_getsecid;
	struct hlist_head task_setnice;
	struct hlist_head task_setioprio;
	struct hlist_head task_getioprio;
	struct hlist_head task_prlimit;
	struct hlist_head task_setrlimit;
	struct hlist_head task_setscheduler;
	struct hlist_head task_getscheduler;
	struct hlist_head task_movememory;
	struct hlist_head task_kill;
	struct hlist_head task_prctl;
	struct hlist_head task_to_inode;
	struct hlist_head ipc_permission;
	struct hlist_head ipc_getsecid;
	struct hlist_head msg_msg_alloc_security;
	struct hlist_head msg_msg_free_security;
	struct hlist_head msg_queue_alloc_security;
	struct hlist_head msg_queue_free_security;
	struct hlist_head msg_queue_associate;
	struct hlist_head msg_queue_msgctl;
	struct hlist_head msg_queue_msgsnd;
	struct hlist_head msg_queue_msgrcv;
	struct hlist_head shm_alloc_security;
	struct hlist_head shm_free_security;
	struct hlist_head shm_associate;
	struct hlist_head shm_shmctl;
	struct hlist_head shm_shmat;
	struct hlist_head sem_alloc_security;
	struct hlist_head sem_free_security;
	struct hlist_head sem_associate;
	struct hlist_head sem_semctl;
	struct hlist_head sem_semop;
	struct hlist_head netlink_send;
	struct hlist_head d_instantiate;
	struct hlist_head getprocattr;
	struct hlist_head setprocattr;
	struct hlist_head ismaclabel;
	struct hlist_head secid_to_secctx;
	struct hlist_head secctx_to_secid;
	struct hlist_head release_secctx;
	struct hlist_head inode_invalidate_secctx;
	struct hlist_head inode_notifysecctx;
	struct hlist_head inode_setsecctx;
	struct hlist_head inode_getsecctx;
#ifdef CONFIG_SECURITY_NETWORK
	struct hlist_head unix_stream_connect;
	struct hlist_head unix_may_send;
	struct hlist_head socket_create;
	struct hlist_head socket_post_create;
	struct hlist_head socket_socketpair;
	struct hlist_head socket_bind;
	struct hlist_head socket_connect;
	struct hlist_head socket_listen;
	struct hlist_head socket_accept;
	struct hlist_head socket_sendmsg;
	struct hlist_head socket_recvmsg;
	struct hlist_head socket_getsockname;
	struct hlist_head socket_getpeername;
	struct hlist_head socket_getsockopt;
	struct hlist_head socket_setsockopt;
	struct hlist_head socket_shutdown;
	struct hlist_head socket_sock_rcv_skb;
	struct hlist_head socket_getpeersec_stream;
	struct hlist_head socket_getpeersec_dgram;
	struct hlist_head sk_alloc_security;
	struct hlist_head sk_free_security;
	struct hlist_head sk_clone_security;
	struct hlist_head sk_getsecid;
	struct hlist_head sock_graft;
	struct hlist_head inet_conn_request;
	struct hlist_head inet_csk_clone;
	struct hlist_head inet_conn_established;
	struct hlist_head secmark_relabel_packet;
	struct hlist_head secmark_refcount_inc;
	struct hlist_head secmark_refcount_dec;
	struct hlist_head req_classify_flow;
	struct hlist_head tun_dev_alloc_security;
	struct hlist_head tun_dev_free_security;
	struct hlist_head tun_dev_create;
	struct hlist_head tun_dev_attach_queue;
	struct hlist_head tun_dev_attach;
	struct hlist_head tun_dev_open;
	struct hlist_head sctp_assoc_request;
	struct hlist_head sctp_bind_connect;
	struct hlist_head sctp_sk_clone;
#endif	
#ifdef CONFIG_SECURITY_INFINIBAND
	struct hlist_head ib_pkey_access;
	struct hlist_head ib_endport_manage_subnet;
	struct hlist_head ib_alloc_security;
	struct hlist_head ib_free_security;
#endif	
#ifdef CONFIG_SECURITY_NETWORK_XFRM
	struct hlist_head xfrm_policy_alloc_security;
	struct hlist_head xfrm_policy_clone_security;
	struct hlist_head xfrm_policy_free_security;
	struct hlist_head xfrm_policy_delete_security;
	struct hlist_head xfrm_state_alloc;
	struct hlist_head xfrm_state_alloc_acquire;
	struct hlist_head xfrm_state_free_security;
	struct hlist_head xfrm_state_delete_security;
	struct hlist_head xfrm_policy_lookup;
	struct hlist_head xfrm_state_pol_flow_match;
	struct hlist_head xfrm_decode_session;
#endif	
#ifdef CONFIG_KEYS
	struct hlist_head key_alloc;
	struct hlist_head key_free;
	struct hlist_head key_permission;
	struct hlist_head key_getsecurity;
#endif	
#ifdef CONFIG_AUDIT
	struct hlist_head audit_rule_init;
	struct hlist_head audit_rule_known;
	struct hlist_head audit_rule_match;
	struct hlist_head audit_rule_free;
#endif 
#ifdef CONFIG_BPF_SYSCALL
	struct hlist_head bpf;
	struct hlist_head bpf_map;
	struct hlist_head bpf_prog;
	struct hlist_head bpf_map_alloc_security;
	struct hlist_head bpf_map_free_security;
	struct hlist_head bpf_prog_alloc_security;
	struct hlist_head bpf_prog_free_security;
#endif 
	struct hlist_head locked_down;
} __randomize_layout;


struct security_hook_list {
	struct hlist_node		list;
	struct hlist_head		*head;
	union security_list_options	hook;
	char				*lsm;
} __randomize_layout;


struct lsm_blob_sizes {
	int	lbs_cred;
	int	lbs_file;
	int	lbs_inode;
	int	lbs_ipc;
	int	lbs_msg_msg;
	int	lbs_task;
};


#define LSM_HOOK_INIT(HEAD, HOOK) \
	{ .head = &security_hook_heads.HEAD, .hook = { .HEAD = HOOK } }

extern struct security_hook_heads security_hook_heads;
extern char *lsm_names;

extern void security_add_hooks(struct security_hook_list *hooks, int count,
				char *lsm);

#define LSM_FLAG_LEGACY_MAJOR	BIT(0)
#define LSM_FLAG_EXCLUSIVE	BIT(1)

enum lsm_order {
	LSM_ORDER_FIRST = -1,	
	LSM_ORDER_MUTABLE = 0,
};

struct lsm_info {
	const char *name;	
	enum lsm_order order;	
	unsigned long flags;	
	int *enabled;		
	int (*init)(void);	
	struct lsm_blob_sizes *blobs; 
};

extern struct lsm_info __start_lsm_info[], __end_lsm_info[];
extern struct lsm_info __start_early_lsm_info[], __end_early_lsm_info[];

#define DEFINE_LSM(lsm)							\
	static struct lsm_info __lsm_##lsm				\
		__used __section(.lsm_info.init)			\
		__aligned(sizeof(unsigned long))

#define DEFINE_EARLY_LSM(lsm)						\
	static struct lsm_info __early_lsm_##lsm			\
		__used __section(.early_lsm_info.init)			\
		__aligned(sizeof(unsigned long))

#ifdef CONFIG_SECURITY_SELINUX_DISABLE

static inline void security_delete_hooks(struct security_hook_list *hooks,
						int count)
{
	int i;

	for (i = 0; i < count; i++)
		hlist_del_rcu(&hooks[i].list);
}
#endif 


#ifdef CONFIG_SECURITY_WRITABLE_HOOKS
#define __lsm_ro_after_init
#else
#define __lsm_ro_after_init	__ro_after_init
#endif 

extern int lsm_inode_alloc(struct inode *inode);

#endif 