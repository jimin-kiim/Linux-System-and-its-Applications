/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_POINTER_AUTH_H
#define __ASM_POINTER_AUTH_H

#include <linux/bitops.h>

#include <asm/cpufeature.h>
#include <asm/memory.h>
#include <asm/sysreg.h>

#ifdef CONFIG_ARM64_PTR_AUTH

struct ptrauth_key {
	unsigned long lo, hi;
};


struct ptrauth_keys {
	struct ptrauth_key apia;
	struct ptrauth_key apib;
	struct ptrauth_key apda;
	struct ptrauth_key apdb;
	struct ptrauth_key apga;
};


#include <linux/random.h>

static inline void ptrauth_keys_init(struct ptrauth_keys *keys)
{
	if (system_supports_address_auth()) {
		get_random_bytes(&keys->apia, sizeof(keys->apia));
		get_random_bytes(&keys->apib, sizeof(keys->apib));
		get_random_bytes(&keys->apda, sizeof(keys->apda));
		get_random_bytes(&keys->apdb, sizeof(keys->apdb));
	}

	if (system_supports_generic_auth())
		get_random_bytes(&keys->apga, sizeof(keys->apga));
}

#define __ptrauth_key_install(k, v)				\
do {								\
	struct ptrauth_key __pki_v = (v);			\
	write_sysreg_s(__pki_v.lo, SYS_ ## k ## KEYLO_EL1);	\
	write_sysreg_s(__pki_v.hi, SYS_ ## k ## KEYHI_EL1);	\
} while (0)

static inline void ptrauth_keys_switch(struct ptrauth_keys *keys)
{
	if (system_supports_address_auth()) {
		__ptrauth_key_install(APIA, keys->apia);
		__ptrauth_key_install(APIB, keys->apib);
		__ptrauth_key_install(APDA, keys->apda);
		__ptrauth_key_install(APDB, keys->apdb);
	}

	if (system_supports_generic_auth())
		__ptrauth_key_install(APGA, keys->apga);
}

extern int ptrauth_prctl_reset_keys(struct task_struct *tsk, unsigned long arg);


#define ptrauth_user_pac_mask()	GENMASK(54, vabits_actual)


static inline unsigned long ptrauth_strip_insn_pac(unsigned long ptr)
{
	return ptr & ~ptrauth_user_pac_mask();
}

#define ptrauth_thread_init_user(tsk)					\
do {									\
	struct task_struct *__ptiu_tsk = (tsk);				\
	ptrauth_keys_init(&__ptiu_tsk->thread.keys_user);		\
	ptrauth_keys_switch(&__ptiu_tsk->thread.keys_user);		\
} while (0)

#define ptrauth_thread_switch(tsk)	\
	ptrauth_keys_switch(&(tsk)->thread.keys_user)

#else 
#define ptrauth_prctl_reset_keys(tsk, arg)	(-EINVAL)
#define ptrauth_strip_insn_pac(lr)	(lr)
#define ptrauth_thread_init_user(tsk)
#define ptrauth_thread_switch(tsk)
#endif 

#endif 
