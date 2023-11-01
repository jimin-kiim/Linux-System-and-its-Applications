

#ifndef IB_UMEM_ODP_H
#define IB_UMEM_ODP_H

#include <rdma/ib_umem.h>
#include <rdma/ib_verbs.h>
#include <linux/interval_tree.h>

struct ib_umem_odp {
	struct ib_umem umem;
	struct ib_ucontext_per_mm *per_mm;

	
	struct page		**page_list;
	
	dma_addr_t		*dma_list;
	
	struct mutex		umem_mutex;
	void			*private; 

	int notifiers_seq;
	int notifiers_count;
	int npages;

	
	struct interval_tree_node interval_tree;

	
	bool is_implicit_odp;

	struct completion	notifier_completion;
	int			dying;
	unsigned int		page_shift;
	struct work_struct	work;
};

static inline struct ib_umem_odp *to_ib_umem_odp(struct ib_umem *umem)
{
	return container_of(umem, struct ib_umem_odp, umem);
}


static inline unsigned long ib_umem_start(struct ib_umem_odp *umem_odp)
{
	return umem_odp->interval_tree.start;
}


static inline unsigned long ib_umem_end(struct ib_umem_odp *umem_odp)
{
	return umem_odp->interval_tree.last + 1;
}

static inline size_t ib_umem_odp_num_pages(struct ib_umem_odp *umem_odp)
{
	return (ib_umem_end(umem_odp) - ib_umem_start(umem_odp)) >>
	       umem_odp->page_shift;
}


#define ODP_READ_ALLOWED_BIT  (1<<0ULL)
#define ODP_WRITE_ALLOWED_BIT (1<<1ULL)

#define ODP_DMA_ADDR_MASK (~(ODP_READ_ALLOWED_BIT | ODP_WRITE_ALLOWED_BIT))

#ifdef CONFIG_INFINIBAND_ON_DEMAND_PAGING

struct ib_ucontext_per_mm {
	struct mmu_notifier mn;
	struct pid *tgid;

	struct rb_root_cached umem_tree;
	
	struct rw_semaphore umem_rwsem;
};

struct ib_umem_odp *ib_umem_odp_get(struct ib_udata *udata, unsigned long addr,
				    size_t size, int access);
struct ib_umem_odp *ib_umem_odp_alloc_implicit(struct ib_udata *udata,
					       int access);
struct ib_umem_odp *ib_umem_odp_alloc_child(struct ib_umem_odp *root_umem,
					    unsigned long addr, size_t size);
void ib_umem_odp_release(struct ib_umem_odp *umem_odp);

int ib_umem_odp_map_dma_pages(struct ib_umem_odp *umem_odp, u64 start_offset,
			      u64 bcnt, u64 access_mask,
			      unsigned long current_seq);

void ib_umem_odp_unmap_dma_pages(struct ib_umem_odp *umem_odp, u64 start_offset,
				 u64 bound);

typedef int (*umem_call_back)(struct ib_umem_odp *item, u64 start, u64 end,
			      void *cookie);

int rbt_ib_umem_for_each_in_range(struct rb_root_cached *root,
				  u64 start, u64 end,
				  umem_call_back cb,
				  bool blockable, void *cookie);


static inline struct ib_umem_odp *
rbt_ib_umem_lookup(struct rb_root_cached *root, u64 addr, u64 length)
{
	struct interval_tree_node *node;

	node = interval_tree_iter_first(root, addr, addr + length - 1);
	if (!node)
		return NULL;
	return container_of(node, struct ib_umem_odp, interval_tree);

}

static inline int ib_umem_mmu_notifier_retry(struct ib_umem_odp *umem_odp,
					     unsigned long mmu_seq)
{
	

	if (unlikely(umem_odp->notifiers_count))
		return 1;
	if (umem_odp->notifiers_seq != mmu_seq)
		return 1;
	return 0;
}

#else 

static inline struct ib_umem_odp *ib_umem_odp_get(struct ib_udata *udata,
						  unsigned long addr,
						  size_t size, int access)
{
	return ERR_PTR(-EINVAL);
}

static inline void ib_umem_odp_release(struct ib_umem_odp *umem_odp) {}

#endif 

#endif 
