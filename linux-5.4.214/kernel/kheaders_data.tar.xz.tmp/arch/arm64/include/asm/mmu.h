/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __ASM_MMU_H
#define __ASM_MMU_H

#include <asm/cputype.h>

#define MMCF_AARCH32	0x1	
#define USER_ASID_BIT	48
#define USER_ASID_FLAG	(UL(1) << USER_ASID_BIT)
#define TTBR_ASID_MASK	(UL(0xffff) << 48)

#define BP_HARDEN_EL2_SLOTS 4

#ifndef __ASSEMBLY__

typedef struct {
	atomic64_t	id;
	void		*vdso;
	unsigned long	flags;
} mm_context_t;


#define ASID(mm)	((mm)->context.id.counter & 0xffff)

static __always_inline bool arm64_kernel_unmapped_at_el0(void)
{
	return IS_ENABLED(CONFIG_UNMAP_KERNEL_AT_EL0) &&
	       cpus_have_const_cap(ARM64_UNMAP_KERNEL_AT_EL0);
}

static inline bool arm64_kernel_use_ng_mappings(void)
{
	bool tx1_bug;

	
	if (!IS_ENABLED(CONFIG_UNMAP_KERNEL_AT_EL0))
		return false;

	
	if (arm64_kernel_unmapped_at_el0())
		return true;

	if (!IS_ENABLED(CONFIG_RANDOMIZE_BASE))
		return false;

	
	if (!IS_ENABLED(CONFIG_CAVIUM_ERRATUM_27456)) {
		tx1_bug = false;
#ifndef MODULE
	} else if (!static_branch_likely(&arm64_const_caps_ready)) {
		extern const struct midr_range cavium_erratum_27456_cpus[];

		tx1_bug = is_midr_in_range_list(read_cpuid_id(),
						cavium_erratum_27456_cpus);
#endif
	} else {
		tx1_bug = __cpus_have_const_cap(ARM64_WORKAROUND_CAVIUM_27456);
	}

	return !tx1_bug && kaslr_offset() > 0;
}

typedef void (*bp_hardening_cb_t)(void);

struct bp_hardening_data {
	int			hyp_vectors_slot;
	bp_hardening_cb_t	fn;

	
	const char *template_start;
};

#if (defined(CONFIG_HARDEN_BRANCH_PREDICTOR) ||	\
     defined(CONFIG_HARDEN_EL2_VECTORS))
extern char __bp_harden_hyp_vecs_start[], __bp_harden_hyp_vecs_end[];
extern atomic_t arm64_el2_vector_last_slot;
#endif  

#ifdef CONFIG_HARDEN_BRANCH_PREDICTOR
DECLARE_PER_CPU_READ_MOSTLY(struct bp_hardening_data, bp_hardening_data);

static inline struct bp_hardening_data *arm64_get_bp_hardening_data(void)
{
	return this_cpu_ptr(&bp_hardening_data);
}

static inline void arm64_apply_bp_hardening(void)
{
	struct bp_hardening_data *d;

	if (!cpus_have_const_cap(ARM64_HARDEN_BRANCH_PREDICTOR))
		return;

	d = arm64_get_bp_hardening_data();
	if (d->fn)
		d->fn();
}
#else
static inline struct bp_hardening_data *arm64_get_bp_hardening_data(void)
{
	return NULL;
}

static inline void arm64_apply_bp_hardening(void)	{ }
#endif	

extern void arm64_memblock_init(void);
extern void paging_init(void);
extern void bootmem_init(void);
extern void __iomem *early_io_map(phys_addr_t phys, unsigned long virt);
extern void init_mem_pgprot(void);
extern void create_pgd_mapping(struct mm_struct *mm, phys_addr_t phys,
			       unsigned long virt, phys_addr_t size,
			       pgprot_t prot, bool page_mappings_only);
extern void *fixmap_remap_fdt(phys_addr_t dt_phys, int *size, pgprot_t prot);
extern void mark_linear_text_alias_ro(void);

#define INIT_MM_CONTEXT(name)	\
	.pgd = init_pg_dir,

#endif	
#endif
