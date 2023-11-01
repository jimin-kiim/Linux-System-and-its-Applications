/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __ARM64_S2_PGTABLE_H_
#define __ARM64_S2_PGTABLE_H_

#include <linux/hugetlb.h>
#include <asm/pgtable.h>


#define pt_levels_pgdir_shift(lvls)	ARM64_HW_PGTABLE_LEVEL_SHIFT(4 - (lvls))


#define stage2_pgtable_levels(ipa)	ARM64_HW_PGTABLE_LEVELS((ipa) - 4)
#define kvm_stage2_levels(kvm)		VTCR_EL2_LVLS(kvm->arch.vtcr)


#define stage2_pgdir_shift(kvm)		pt_levels_pgdir_shift(kvm_stage2_levels(kvm))
#define stage2_pgdir_size(kvm)		(1ULL << stage2_pgdir_shift(kvm))
#define stage2_pgdir_mask(kvm)		~(stage2_pgdir_size(kvm) - 1)


#define pgd_ptrs_shift(ipa, pgdir_shift)	\
	((ipa) > (pgdir_shift) ? ((ipa) - (pgdir_shift)) : 0)
#define __s2_pgd_ptrs(ipa, lvls)		\
	(1 << (pgd_ptrs_shift((ipa), pt_levels_pgdir_shift(lvls))))
#define __s2_pgd_size(ipa, lvls)	(__s2_pgd_ptrs((ipa), (lvls)) * sizeof(pgd_t))

#define stage2_pgd_ptrs(kvm)		__s2_pgd_ptrs(kvm_phys_shift(kvm), kvm_stage2_levels(kvm))
#define stage2_pgd_size(kvm)		__s2_pgd_size(kvm_phys_shift(kvm), kvm_stage2_levels(kvm))


#define kvm_mmu_cache_min_pages(kvm)	(kvm_stage2_levels(kvm) - 1)


static inline bool kvm_stage2_has_pud(struct kvm *kvm)
{
	return (CONFIG_PGTABLE_LEVELS > 3) && (kvm_stage2_levels(kvm) > 3);
}

#define S2_PUD_SHIFT			ARM64_HW_PGTABLE_LEVEL_SHIFT(1)
#define S2_PUD_SIZE			(1UL << S2_PUD_SHIFT)
#define S2_PUD_MASK			(~(S2_PUD_SIZE - 1))

static inline bool stage2_pgd_none(struct kvm *kvm, pgd_t pgd)
{
	if (kvm_stage2_has_pud(kvm))
		return pgd_none(pgd);
	else
		return 0;
}

static inline void stage2_pgd_clear(struct kvm *kvm, pgd_t *pgdp)
{
	if (kvm_stage2_has_pud(kvm))
		pgd_clear(pgdp);
}

static inline bool stage2_pgd_present(struct kvm *kvm, pgd_t pgd)
{
	if (kvm_stage2_has_pud(kvm))
		return pgd_present(pgd);
	else
		return 1;
}

static inline void stage2_pgd_populate(struct kvm *kvm, pgd_t *pgd, pud_t *pud)
{
	if (kvm_stage2_has_pud(kvm))
		pgd_populate(NULL, pgd, pud);
}

static inline pud_t *stage2_pud_offset(struct kvm *kvm,
				       pgd_t *pgd, unsigned long address)
{
	if (kvm_stage2_has_pud(kvm))
		return pud_offset(pgd, address);
	else
		return (pud_t *)pgd;
}

static inline void stage2_pud_free(struct kvm *kvm, pud_t *pud)
{
	if (kvm_stage2_has_pud(kvm))
		free_page((unsigned long)pud);
}

static inline bool stage2_pud_table_empty(struct kvm *kvm, pud_t *pudp)
{
	if (kvm_stage2_has_pud(kvm))
		return kvm_page_empty(pudp);
	else
		return false;
}

static inline phys_addr_t
stage2_pud_addr_end(struct kvm *kvm, phys_addr_t addr, phys_addr_t end)
{
	if (kvm_stage2_has_pud(kvm)) {
		phys_addr_t boundary = (addr + S2_PUD_SIZE) & S2_PUD_MASK;

		return (boundary - 1 < end - 1) ? boundary : end;
	} else {
		return end;
	}
}


static inline bool kvm_stage2_has_pmd(struct kvm *kvm)
{
	return (CONFIG_PGTABLE_LEVELS > 2) && (kvm_stage2_levels(kvm) > 2);
}

#define S2_PMD_SHIFT			ARM64_HW_PGTABLE_LEVEL_SHIFT(2)
#define S2_PMD_SIZE			(1UL << S2_PMD_SHIFT)
#define S2_PMD_MASK			(~(S2_PMD_SIZE - 1))

static inline bool stage2_pud_none(struct kvm *kvm, pud_t pud)
{
	if (kvm_stage2_has_pmd(kvm))
		return pud_none(pud);
	else
		return 0;
}

static inline void stage2_pud_clear(struct kvm *kvm, pud_t *pud)
{
	if (kvm_stage2_has_pmd(kvm))
		pud_clear(pud);
}

static inline bool stage2_pud_present(struct kvm *kvm, pud_t pud)
{
	if (kvm_stage2_has_pmd(kvm))
		return pud_present(pud);
	else
		return 1;
}

static inline void stage2_pud_populate(struct kvm *kvm, pud_t *pud, pmd_t *pmd)
{
	if (kvm_stage2_has_pmd(kvm))
		pud_populate(NULL, pud, pmd);
}

static inline pmd_t *stage2_pmd_offset(struct kvm *kvm,
				       pud_t *pud, unsigned long address)
{
	if (kvm_stage2_has_pmd(kvm))
		return pmd_offset(pud, address);
	else
		return (pmd_t *)pud;
}

static inline void stage2_pmd_free(struct kvm *kvm, pmd_t *pmd)
{
	if (kvm_stage2_has_pmd(kvm))
		free_page((unsigned long)pmd);
}

static inline bool stage2_pud_huge(struct kvm *kvm, pud_t pud)
{
	if (kvm_stage2_has_pmd(kvm))
		return pud_huge(pud);
	else
		return 0;
}

static inline bool stage2_pmd_table_empty(struct kvm *kvm, pmd_t *pmdp)
{
	if (kvm_stage2_has_pmd(kvm))
		return kvm_page_empty(pmdp);
	else
		return 0;
}

static inline phys_addr_t
stage2_pmd_addr_end(struct kvm *kvm, phys_addr_t addr, phys_addr_t end)
{
	if (kvm_stage2_has_pmd(kvm)) {
		phys_addr_t boundary = (addr + S2_PMD_SIZE) & S2_PMD_MASK;

		return (boundary - 1 < end - 1) ? boundary : end;
	} else {
		return end;
	}
}

static inline bool stage2_pte_table_empty(struct kvm *kvm, pte_t *ptep)
{
	return kvm_page_empty(ptep);
}

static inline unsigned long stage2_pgd_index(struct kvm *kvm, phys_addr_t addr)
{
	return (((addr) >> stage2_pgdir_shift(kvm)) & (stage2_pgd_ptrs(kvm) - 1));
}

static inline phys_addr_t
stage2_pgd_addr_end(struct kvm *kvm, phys_addr_t addr, phys_addr_t end)
{
	phys_addr_t boundary = (addr + stage2_pgdir_size(kvm)) & stage2_pgdir_mask(kvm);

	return (boundary - 1 < end - 1) ? boundary : end;
}

#endif	
