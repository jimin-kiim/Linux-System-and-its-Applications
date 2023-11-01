/* SPDX-License-Identifier: GPL-2.0-or-later */


#ifndef LINUX_HMM_H
#define LINUX_HMM_H

#include <linux/kconfig.h>
#include <asm/pgtable.h>

#ifdef CONFIG_HMM_MIRROR

#include <linux/device.h>
#include <linux/migrate.h>
#include <linux/memremap.h>
#include <linux/completion.h>
#include <linux/mmu_notifier.h>



struct hmm {
	struct mmu_notifier	mmu_notifier;
	spinlock_t		ranges_lock;
	struct list_head	ranges;
	struct list_head	mirrors;
	struct rw_semaphore	mirrors_sem;
	wait_queue_head_t	wq;
	long			notifiers;
};


enum hmm_pfn_flag_e {
	HMM_PFN_VALID = 0,
	HMM_PFN_WRITE,
	HMM_PFN_DEVICE_PRIVATE,
	HMM_PFN_FLAG_MAX
};


enum hmm_pfn_value_e {
	HMM_PFN_ERROR,
	HMM_PFN_NONE,
	HMM_PFN_SPECIAL,
	HMM_PFN_VALUE_MAX
};


struct hmm_range {
	struct hmm		*hmm;
	struct list_head	list;
	unsigned long		start;
	unsigned long		end;
	uint64_t		*pfns;
	const uint64_t		*flags;
	const uint64_t		*values;
	uint64_t		default_flags;
	uint64_t		pfn_flags_mask;
	uint8_t			pfn_shift;
	bool			valid;
};


static inline bool hmm_range_wait_until_valid(struct hmm_range *range,
					      unsigned long timeout)
{
	return wait_event_timeout(range->hmm->wq, range->valid,
				  msecs_to_jiffies(timeout)) != 0;
}


static inline bool hmm_range_valid(struct hmm_range *range)
{
	return range->valid;
}


static inline struct page *hmm_device_entry_to_page(const struct hmm_range *range,
						    uint64_t entry)
{
	if (entry == range->values[HMM_PFN_NONE])
		return NULL;
	if (entry == range->values[HMM_PFN_ERROR])
		return NULL;
	if (entry == range->values[HMM_PFN_SPECIAL])
		return NULL;
	if (!(entry & range->flags[HMM_PFN_VALID]))
		return NULL;
	return pfn_to_page(entry >> range->pfn_shift);
}


static inline unsigned long
hmm_device_entry_to_pfn(const struct hmm_range *range, uint64_t pfn)
{
	if (pfn == range->values[HMM_PFN_NONE])
		return -1UL;
	if (pfn == range->values[HMM_PFN_ERROR])
		return -1UL;
	if (pfn == range->values[HMM_PFN_SPECIAL])
		return -1UL;
	if (!(pfn & range->flags[HMM_PFN_VALID]))
		return -1UL;
	return (pfn >> range->pfn_shift);
}


static inline uint64_t hmm_device_entry_from_page(const struct hmm_range *range,
						  struct page *page)
{
	return (page_to_pfn(page) << range->pfn_shift) |
		range->flags[HMM_PFN_VALID];
}


static inline uint64_t hmm_device_entry_from_pfn(const struct hmm_range *range,
						 unsigned long pfn)
{
	return (pfn << range->pfn_shift) |
		range->flags[HMM_PFN_VALID];
}



struct hmm_mirror;


struct hmm_mirror_ops {
	
	void (*release)(struct hmm_mirror *mirror);

	
	int (*sync_cpu_device_pagetables)(
		struct hmm_mirror *mirror,
		const struct mmu_notifier_range *update);
};


struct hmm_mirror {
	struct hmm			*hmm;
	const struct hmm_mirror_ops	*ops;
	struct list_head		list;
};

int hmm_mirror_register(struct hmm_mirror *mirror, struct mm_struct *mm);
void hmm_mirror_unregister(struct hmm_mirror *mirror);


int hmm_range_register(struct hmm_range *range, struct hmm_mirror *mirror);
void hmm_range_unregister(struct hmm_range *range);


#define HMM_FAULT_ALLOW_RETRY		(1 << 0)


#define HMM_FAULT_SNAPSHOT		(1 << 1)

long hmm_range_fault(struct hmm_range *range, unsigned int flags);

long hmm_range_dma_map(struct hmm_range *range,
		       struct device *device,
		       dma_addr_t *daddrs,
		       unsigned int flags);
long hmm_range_dma_unmap(struct hmm_range *range,
			 struct device *device,
			 dma_addr_t *daddrs,
			 bool dirty);


#define HMM_RANGE_DEFAULT_TIMEOUT 1000

#endif 

#endif 
