/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _LINUX_REFCOUNT_H
#define _LINUX_REFCOUNT_H

#include <linux/atomic.h>
#include <linux/bug.h>
#include <linux/compiler.h>
#include <linux/limits.h>
#include <linux/spinlock_types.h>

struct mutex;


typedef struct refcount_struct {
	atomic_t refs;
} refcount_t;

#define REFCOUNT_INIT(n)	{ .refs = ATOMIC_INIT(n), }
#define REFCOUNT_MAX		INT_MAX
#define REFCOUNT_SATURATED	(INT_MIN / 2)

enum refcount_saturation_type {
	REFCOUNT_ADD_NOT_ZERO_OVF,
	REFCOUNT_ADD_OVF,
	REFCOUNT_ADD_UAF,
	REFCOUNT_SUB_UAF,
	REFCOUNT_DEC_LEAK,
};

void refcount_warn_saturate(refcount_t *r, enum refcount_saturation_type t);


static inline void refcount_set(refcount_t *r, int n)
{
	atomic_set(&r->refs, n);
}


static inline unsigned int refcount_read(const refcount_t *r)
{
	return atomic_read(&r->refs);
}


static inline __must_check bool refcount_add_not_zero(int i, refcount_t *r)
{
	int old = refcount_read(r);

	do {
		if (!old)
			break;
	} while (!atomic_try_cmpxchg_relaxed(&r->refs, &old, old + i));

	if (unlikely(old < 0 || old + i < 0))
		refcount_warn_saturate(r, REFCOUNT_ADD_NOT_ZERO_OVF);

	return old;
}


static inline void refcount_add(int i, refcount_t *r)
{
	int old = atomic_fetch_add_relaxed(i, &r->refs);

	if (unlikely(!old))
		refcount_warn_saturate(r, REFCOUNT_ADD_UAF);
	else if (unlikely(old < 0 || old + i < 0))
		refcount_warn_saturate(r, REFCOUNT_ADD_OVF);
}


static inline __must_check bool refcount_inc_not_zero(refcount_t *r)
{
	return refcount_add_not_zero(1, r);
}


static inline void refcount_inc(refcount_t *r)
{
	refcount_add(1, r);
}


static inline __must_check bool refcount_sub_and_test(int i, refcount_t *r)
{
	int old = atomic_fetch_sub_release(i, &r->refs);

	if (old == i) {
		smp_acquire__after_ctrl_dep();
		return true;
	}

	if (unlikely(old < 0 || old - i < 0))
		refcount_warn_saturate(r, REFCOUNT_SUB_UAF);

	return false;
}


static inline __must_check bool refcount_dec_and_test(refcount_t *r)
{
	return refcount_sub_and_test(1, r);
}


static inline void refcount_dec(refcount_t *r)
{
	if (unlikely(atomic_fetch_sub_release(1, &r->refs) <= 1))
		refcount_warn_saturate(r, REFCOUNT_DEC_LEAK);
}

extern __must_check bool refcount_dec_if_one(refcount_t *r);
extern __must_check bool refcount_dec_not_one(refcount_t *r);
extern __must_check bool refcount_dec_and_mutex_lock(refcount_t *r, struct mutex *lock);
extern __must_check bool refcount_dec_and_lock(refcount_t *r, spinlock_t *lock);
extern __must_check bool refcount_dec_and_lock_irqsave(refcount_t *r,
						       spinlock_t *lock,
						       unsigned long *flags);
#endif 
