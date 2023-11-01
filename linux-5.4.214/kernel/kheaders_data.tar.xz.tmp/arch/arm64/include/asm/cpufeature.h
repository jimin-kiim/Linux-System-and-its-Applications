/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __ASM_CPUFEATURE_H
#define __ASM_CPUFEATURE_H

#include <asm/cpucaps.h>
#include <asm/cputype.h>
#include <asm/hwcap.h>
#include <asm/sysreg.h>

#define MAX_CPU_FEATURES	64
#define cpu_feature(x)		KERNEL_HWCAP_ ## x

#ifndef __ASSEMBLY__

#include <linux/bug.h>
#include <linux/jump_label.h>
#include <linux/kernel.h>



enum ftr_type {
	FTR_EXACT,			
	FTR_LOWER_SAFE,			
	FTR_HIGHER_SAFE,		
	FTR_HIGHER_OR_ZERO_SAFE,	
};

#define FTR_STRICT	true	
#define FTR_NONSTRICT	false	

#define FTR_SIGNED	true	
#define FTR_UNSIGNED	false	

#define FTR_VISIBLE	true	
#define FTR_HIDDEN	false	

#define FTR_VISIBLE_IF_IS_ENABLED(config)		\
	(IS_ENABLED(config) ? FTR_VISIBLE : FTR_HIDDEN)

struct arm64_ftr_bits {
	bool		sign;	
	bool		visible;
	bool		strict;	
	enum ftr_type	type;
	u8		shift;
	u8		width;
	s64		safe_val; 
};


struct arm64_ftr_reg {
	const char			*name;
	u64				strict_mask;
	u64				user_mask;
	u64				sys_val;
	u64				user_val;
	const struct arm64_ftr_bits	*ftr_bits;
};

extern struct arm64_ftr_reg arm64_ftr_reg_ctrel0;





#define ARM64_CPUCAP_SCOPE_LOCAL_CPU		((u16)BIT(0))
#define ARM64_CPUCAP_SCOPE_SYSTEM		((u16)BIT(1))

#define ARM64_CPUCAP_SCOPE_BOOT_CPU		((u16)BIT(2))
#define ARM64_CPUCAP_SCOPE_MASK			\
	(ARM64_CPUCAP_SCOPE_SYSTEM	|	\
	 ARM64_CPUCAP_SCOPE_LOCAL_CPU	|	\
	 ARM64_CPUCAP_SCOPE_BOOT_CPU)

#define SCOPE_SYSTEM				ARM64_CPUCAP_SCOPE_SYSTEM
#define SCOPE_LOCAL_CPU				ARM64_CPUCAP_SCOPE_LOCAL_CPU
#define SCOPE_BOOT_CPU				ARM64_CPUCAP_SCOPE_BOOT_CPU
#define SCOPE_ALL				ARM64_CPUCAP_SCOPE_MASK


#define ARM64_CPUCAP_PERMITTED_FOR_LATE_CPU	((u16)BIT(4))

#define ARM64_CPUCAP_OPTIONAL_FOR_LATE_CPU	((u16)BIT(5))


#define ARM64_CPUCAP_LOCAL_CPU_ERRATUM		\
	(ARM64_CPUCAP_SCOPE_LOCAL_CPU | ARM64_CPUCAP_OPTIONAL_FOR_LATE_CPU)

#define ARM64_CPUCAP_SYSTEM_FEATURE	\
	(ARM64_CPUCAP_SCOPE_SYSTEM | ARM64_CPUCAP_PERMITTED_FOR_LATE_CPU)

#define ARM64_CPUCAP_WEAK_LOCAL_CPU_FEATURE		\
	(ARM64_CPUCAP_SCOPE_LOCAL_CPU		|	\
	 ARM64_CPUCAP_OPTIONAL_FOR_LATE_CPU	|	\
	 ARM64_CPUCAP_PERMITTED_FOR_LATE_CPU)


#define ARM64_CPUCAP_BOOT_RESTRICTED_CPU_LOCAL_FEATURE	\
	(ARM64_CPUCAP_SCOPE_LOCAL_CPU		|	\
	 ARM64_CPUCAP_OPTIONAL_FOR_LATE_CPU)


#define ARM64_CPUCAP_STRICT_BOOT_CPU_FEATURE ARM64_CPUCAP_SCOPE_BOOT_CPU

struct arm64_cpu_capabilities {
	const char *desc;
	u16 capability;
	u16 type;
	bool (*matches)(const struct arm64_cpu_capabilities *caps, int scope);
	
	void (*cpu_enable)(const struct arm64_cpu_capabilities *cap);
	union {
		struct {	
			struct midr_range midr_range;
			const struct arm64_midr_revidr {
				u32 midr_rv;		
				u32 revidr_mask;
			} * const fixed_revs;
		};

		const struct midr_range *midr_range_list;
		struct {	
			u32 sys_reg;
			u8 field_pos;
			u8 min_field_value;
			u8 hwcap_type;
			bool sign;
			unsigned long hwcap;
		};
	};

	
	const struct arm64_cpu_capabilities *match_list;
};

static inline int cpucap_default_scope(const struct arm64_cpu_capabilities *cap)
{
	return cap->type & ARM64_CPUCAP_SCOPE_MASK;
}

static inline bool
cpucap_late_cpu_optional(const struct arm64_cpu_capabilities *cap)
{
	return !!(cap->type & ARM64_CPUCAP_OPTIONAL_FOR_LATE_CPU);
}

static inline bool
cpucap_late_cpu_permitted(const struct arm64_cpu_capabilities *cap)
{
	return !!(cap->type & ARM64_CPUCAP_PERMITTED_FOR_LATE_CPU);
}


static inline bool
cpucap_multi_entry_cap_matches(const struct arm64_cpu_capabilities *entry,
			       int scope)
{
	const struct arm64_cpu_capabilities *caps;

	for (caps = entry->match_list; caps->matches; caps++)
		if (caps->matches(caps, scope))
			return true;

	return false;
}

extern DECLARE_BITMAP(cpu_hwcaps, ARM64_NCAPS);
extern struct static_key_false cpu_hwcap_keys[ARM64_NCAPS];
extern struct static_key_false arm64_const_caps_ready;


#define ARM64_NPATCHABLE (ARM64_NCAPS + 1)
extern DECLARE_BITMAP(boot_capabilities, ARM64_NPATCHABLE);

#define for_each_available_cap(cap)		\
	for_each_set_bit(cap, cpu_hwcaps, ARM64_NCAPS)

bool this_cpu_has_cap(unsigned int cap);
void cpu_set_feature(unsigned int num);
bool cpu_have_feature(unsigned int num);
unsigned long cpu_get_elf_hwcap(void);
unsigned long cpu_get_elf_hwcap2(void);

#define cpu_set_named_feature(name) cpu_set_feature(cpu_feature(name))
#define cpu_have_named_feature(name) cpu_have_feature(cpu_feature(name))


static __always_inline bool __cpus_have_const_cap(int num)
{
	if (num >= ARM64_NCAPS)
		return false;
	return static_branch_unlikely(&cpu_hwcap_keys[num]);
}

static inline bool cpus_have_cap(unsigned int num)
{
	if (num >= ARM64_NCAPS)
		return false;
	return test_bit(num, cpu_hwcaps);
}

static __always_inline bool cpus_have_const_cap(int num)
{
	if (static_branch_likely(&arm64_const_caps_ready))
		return __cpus_have_const_cap(num);
	else
		return cpus_have_cap(num);
}

static inline void cpus_set_cap(unsigned int num)
{
	if (num >= ARM64_NCAPS) {
		pr_warn("Attempt to set an illegal CPU capability (%d >= %d)\n",
			num, ARM64_NCAPS);
	} else {
		__set_bit(num, cpu_hwcaps);
	}
}

static inline int __attribute_const__
cpuid_feature_extract_signed_field_width(u64 features, int field, int width)
{
	return (s64)(features << (64 - width - field)) >> (64 - width);
}

static inline int __attribute_const__
cpuid_feature_extract_signed_field(u64 features, int field)
{
	return cpuid_feature_extract_signed_field_width(features, field, 4);
}

static inline unsigned int __attribute_const__
cpuid_feature_extract_unsigned_field_width(u64 features, int field, int width)
{
	return (u64)(features << (64 - width - field)) >> (64 - width);
}

static inline unsigned int __attribute_const__
cpuid_feature_extract_unsigned_field(u64 features, int field)
{
	return cpuid_feature_extract_unsigned_field_width(features, field, 4);
}

static inline u64 arm64_ftr_mask(const struct arm64_ftr_bits *ftrp)
{
	return (u64)GENMASK(ftrp->shift + ftrp->width - 1, ftrp->shift);
}

static inline u64 arm64_ftr_reg_user_value(const struct arm64_ftr_reg *reg)
{
	return (reg->user_val | (reg->sys_val & reg->user_mask));
}

static inline int __attribute_const__
cpuid_feature_extract_field_width(u64 features, int field, int width, bool sign)
{
	return (sign) ?
		cpuid_feature_extract_signed_field_width(features, field, width) :
		cpuid_feature_extract_unsigned_field_width(features, field, width);
}

static inline int __attribute_const__
cpuid_feature_extract_field(u64 features, int field, bool sign)
{
	return cpuid_feature_extract_field_width(features, field, 4, sign);
}

static inline s64 arm64_ftr_value(const struct arm64_ftr_bits *ftrp, u64 val)
{
	return (s64)cpuid_feature_extract_field_width(val, ftrp->shift, ftrp->width, ftrp->sign);
}

static inline bool id_aa64mmfr0_mixed_endian_el0(u64 mmfr0)
{
	return cpuid_feature_extract_unsigned_field(mmfr0, ID_AA64MMFR0_BIGENDEL_SHIFT) == 0x1 ||
		cpuid_feature_extract_unsigned_field(mmfr0, ID_AA64MMFR0_BIGENDEL0_SHIFT) == 0x1;
}

static inline bool id_aa64pfr0_32bit_el0(u64 pfr0)
{
	u32 val = cpuid_feature_extract_unsigned_field(pfr0, ID_AA64PFR0_EL0_SHIFT);

	return val == ID_AA64PFR0_EL0_32BIT_64BIT;
}

static inline bool id_aa64pfr0_sve(u64 pfr0)
{
	u32 val = cpuid_feature_extract_unsigned_field(pfr0, ID_AA64PFR0_SVE_SHIFT);

	return val > 0;
}

void __init setup_cpu_features(void);
void check_local_cpu_capabilities(void);

u64 read_sanitised_ftr_reg(u32 id);

static inline bool cpu_supports_mixed_endian_el0(void)
{
	return id_aa64mmfr0_mixed_endian_el0(read_cpuid(ID_AA64MMFR0_EL1));
}

static inline bool supports_csv2p3(int scope)
{
	u64 pfr0;
	u8 csv2_val;

	if (scope == SCOPE_LOCAL_CPU)
		pfr0 = read_sysreg_s(SYS_ID_AA64PFR0_EL1);
	else
		pfr0 = read_sanitised_ftr_reg(SYS_ID_AA64PFR0_EL1);

	csv2_val = cpuid_feature_extract_unsigned_field(pfr0,
							ID_AA64PFR0_CSV2_SHIFT);
	return csv2_val == 3;
}

static inline bool supports_clearbhb(int scope)
{
	u64 isar2;

	if (scope == SCOPE_LOCAL_CPU)
		isar2 = read_sysreg_s(SYS_ID_AA64ISAR2_EL1);
	else
		isar2 = read_sanitised_ftr_reg(SYS_ID_AA64ISAR2_EL1);

	return cpuid_feature_extract_unsigned_field(isar2,
						    ID_AA64ISAR2_CLEARBHB_SHIFT);
}

static inline bool system_supports_32bit_el0(void)
{
	return cpus_have_const_cap(ARM64_HAS_32BIT_EL0);
}

static inline bool system_supports_4kb_granule(void)
{
	u64 mmfr0;
	u32 val;

	mmfr0 =	read_sanitised_ftr_reg(SYS_ID_AA64MMFR0_EL1);
	val = cpuid_feature_extract_unsigned_field(mmfr0,
						ID_AA64MMFR0_TGRAN4_SHIFT);

	return val == ID_AA64MMFR0_TGRAN4_SUPPORTED;
}

static inline bool system_supports_64kb_granule(void)
{
	u64 mmfr0;
	u32 val;

	mmfr0 =	read_sanitised_ftr_reg(SYS_ID_AA64MMFR0_EL1);
	val = cpuid_feature_extract_unsigned_field(mmfr0,
						ID_AA64MMFR0_TGRAN64_SHIFT);

	return val == ID_AA64MMFR0_TGRAN64_SUPPORTED;
}

static inline bool system_supports_16kb_granule(void)
{
	u64 mmfr0;
	u32 val;

	mmfr0 =	read_sanitised_ftr_reg(SYS_ID_AA64MMFR0_EL1);
	val = cpuid_feature_extract_unsigned_field(mmfr0,
						ID_AA64MMFR0_TGRAN16_SHIFT);

	return val == ID_AA64MMFR0_TGRAN16_SUPPORTED;
}

static inline bool system_supports_mixed_endian_el0(void)
{
	return id_aa64mmfr0_mixed_endian_el0(read_sanitised_ftr_reg(SYS_ID_AA64MMFR0_EL1));
}

static inline bool system_supports_mixed_endian(void)
{
	u64 mmfr0;
	u32 val;

	mmfr0 =	read_sanitised_ftr_reg(SYS_ID_AA64MMFR0_EL1);
	val = cpuid_feature_extract_unsigned_field(mmfr0,
						ID_AA64MMFR0_BIGENDEL_SHIFT);

	return val == 0x1;
}

static inline bool system_supports_fpsimd(void)
{
	return !cpus_have_const_cap(ARM64_HAS_NO_FPSIMD);
}

static inline bool system_uses_ttbr0_pan(void)
{
	return IS_ENABLED(CONFIG_ARM64_SW_TTBR0_PAN) &&
		!cpus_have_const_cap(ARM64_HAS_PAN);
}

static inline bool system_supports_sve(void)
{
	return IS_ENABLED(CONFIG_ARM64_SVE) &&
		cpus_have_const_cap(ARM64_SVE);
}

static inline bool system_supports_cnp(void)
{
	return IS_ENABLED(CONFIG_ARM64_CNP) &&
		cpus_have_const_cap(ARM64_HAS_CNP);
}

static inline bool system_supports_address_auth(void)
{
	return IS_ENABLED(CONFIG_ARM64_PTR_AUTH) &&
		(cpus_have_const_cap(ARM64_HAS_ADDRESS_AUTH_ARCH) ||
		 cpus_have_const_cap(ARM64_HAS_ADDRESS_AUTH_IMP_DEF));
}

static inline bool system_supports_generic_auth(void)
{
	return IS_ENABLED(CONFIG_ARM64_PTR_AUTH) &&
		(cpus_have_const_cap(ARM64_HAS_GENERIC_AUTH_ARCH) ||
		 cpus_have_const_cap(ARM64_HAS_GENERIC_AUTH_IMP_DEF));
}

static __always_inline bool system_uses_irq_prio_masking(void)
{
	return IS_ENABLED(CONFIG_ARM64_PSEUDO_NMI) &&
	       cpus_have_const_cap(ARM64_HAS_IRQ_PRIO_MASKING);
}

static inline bool system_has_prio_mask_debugging(void)
{
	return IS_ENABLED(CONFIG_ARM64_DEBUG_PRIORITY_MASKING) &&
	       system_uses_irq_prio_masking();
}

#define ARM64_BP_HARDEN_UNKNOWN		-1
#define ARM64_BP_HARDEN_WA_NEEDED	0
#define ARM64_BP_HARDEN_NOT_REQUIRED	1

int get_spectre_v2_workaround_state(void);

#define ARM64_SSBD_UNKNOWN		-1
#define ARM64_SSBD_FORCE_DISABLE	0
#define ARM64_SSBD_KERNEL		1
#define ARM64_SSBD_FORCE_ENABLE		2
#define ARM64_SSBD_MITIGATED		3

static inline int arm64_get_ssbd_state(void)
{
#ifdef CONFIG_ARM64_SSBD
	extern int ssbd_state;
	return ssbd_state;
#else
	return ARM64_SSBD_UNKNOWN;
#endif
}

void arm64_set_ssbd_mitigation(bool state);


enum mitigation_state {
	SPECTRE_UNAFFECTED,
	SPECTRE_MITIGATED,
	SPECTRE_VULNERABLE,
};

enum mitigation_state arm64_get_spectre_bhb_state(void);
bool is_spectre_bhb_affected(const struct arm64_cpu_capabilities *entry, int scope);
u8 spectre_bhb_loop_affected(int scope);
void spectre_bhb_enable_mitigation(const struct arm64_cpu_capabilities *__unused);

extern int do_emulate_mrs(struct pt_regs *regs, u32 sys_reg, u32 rt);

static inline u32 id_aa64mmfr0_parange_to_phys_shift(int parange)
{
	switch (parange) {
	case 0: return 32;
	case 1: return 36;
	case 2: return 40;
	case 3: return 42;
	case 4: return 44;
	case 5: return 48;
	case 6: return 52;
	
	default: return CONFIG_ARM64_PA_BITS;
	}
}
#endif 

#endif
