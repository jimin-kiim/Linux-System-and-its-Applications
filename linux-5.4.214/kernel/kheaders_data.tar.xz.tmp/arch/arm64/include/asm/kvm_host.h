/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __ARM64_KVM_HOST_H__
#define __ARM64_KVM_HOST_H__

#include <linux/bitmap.h>
#include <linux/types.h>
#include <linux/jump_label.h>
#include <linux/kvm_types.h>
#include <linux/percpu.h>
#include <asm/arch_gicv3.h>
#include <asm/barrier.h>
#include <asm/cpufeature.h>
#include <asm/cputype.h>
#include <asm/daifflags.h>
#include <asm/fpsimd.h>
#include <asm/kvm.h>
#include <asm/kvm_asm.h>
#include <asm/kvm_mmio.h>
#include <asm/thread_info.h>

#define __KVM_HAVE_ARCH_INTC_INITIALIZED

#define KVM_USER_MEM_SLOTS 512
#define KVM_HALT_POLL_NS_DEFAULT 500000

#include <kvm/arm_vgic.h>
#include <kvm/arm_arch_timer.h>
#include <kvm/arm_pmu.h>

#define KVM_MAX_VCPUS VGIC_V3_MAX_CPUS

#define KVM_VCPU_MAX_FEATURES 7

#define KVM_REQ_SLEEP \
	KVM_ARCH_REQ_FLAGS(0, KVM_REQUEST_WAIT | KVM_REQUEST_NO_WAKEUP)
#define KVM_REQ_IRQ_PENDING	KVM_ARCH_REQ(1)
#define KVM_REQ_VCPU_RESET	KVM_ARCH_REQ(2)

DECLARE_STATIC_KEY_FALSE(userspace_irqchip_in_use);

extern unsigned int kvm_sve_max_vl;
int kvm_arm_init_sve(void);

int __attribute_const__ kvm_target_cpu(void);
int kvm_reset_vcpu(struct kvm_vcpu *vcpu);
void kvm_arch_vcpu_uninit(struct kvm_vcpu *vcpu);
int kvm_arch_vm_ioctl_check_extension(struct kvm *kvm, long ext);
void __extended_idmap_trampoline(phys_addr_t boot_pgd, phys_addr_t idmap_start);

struct kvm_vmid {
	
	u64    vmid_gen;
	u32    vmid;
};

struct kvm_arch {
	struct kvm_vmid vmid;

	
	pgd_t *pgd;
	phys_addr_t pgd_phys;

	
	u64    vtcr;

	
	int __percpu *last_vcpu_ran;

	
	int max_vcpus;

	
	struct vgic_dist	vgic;

	
	u32 psci_version;
};

#define KVM_NR_MEM_OBJS     40


struct kvm_mmu_memory_cache {
	int nobjs;
	void *objects[KVM_NR_MEM_OBJS];
};

struct kvm_vcpu_fault_info {
	u32 esr_el2;		
	u64 far_el2;		
	u64 hpfar_el2;		
	u64 disr_el1;		
};


enum vcpu_sysreg {
	__INVALID_SYSREG__,
	MPIDR_EL1,	
	CSSELR_EL1,	
	SCTLR_EL1,	
	ACTLR_EL1,	
	CPACR_EL1,	
	ZCR_EL1,	
	TTBR0_EL1,	
	TTBR1_EL1,	
	TCR_EL1,	
	ESR_EL1,	
	AFSR0_EL1,	
	AFSR1_EL1,	
	FAR_EL1,	
	MAIR_EL1,	
	VBAR_EL1,	
	CONTEXTIDR_EL1,	
	TPIDR_EL0,	
	TPIDRRO_EL0,	
	TPIDR_EL1,	
	AMAIR_EL1,	
	CNTKCTL_EL1,	
	PAR_EL1,	
	MDSCR_EL1,	
	MDCCINT_EL1,	
	DISR_EL1,	

	
	PMCR_EL0,	
	PMSELR_EL0,	
	PMEVCNTR0_EL0,	
	PMEVCNTR30_EL0 = PMEVCNTR0_EL0 + 30,
	PMCCNTR_EL0,	
	PMEVTYPER0_EL0,	
	PMEVTYPER30_EL0 = PMEVTYPER0_EL0 + 30,
	PMCCFILTR_EL0,	
	PMCNTENSET_EL0,	
	PMINTENSET_EL1,	
	PMOVSSET_EL0,	
	PMSWINC_EL0,	
	PMUSERENR_EL0,	

	
	APIAKEYLO_EL1,
	APIAKEYHI_EL1,
	APIBKEYLO_EL1,
	APIBKEYHI_EL1,
	APDAKEYLO_EL1,
	APDAKEYHI_EL1,
	APDBKEYLO_EL1,
	APDBKEYHI_EL1,
	APGAKEYLO_EL1,
	APGAKEYHI_EL1,

	
	DACR32_EL2,	
	IFSR32_EL2,	
	FPEXC32_EL2,	
	DBGVCR32_EL2,	

	NR_SYS_REGS	
};


#define c0_MPIDR	(MPIDR_EL1 * 2)	
#define c0_CSSELR	(CSSELR_EL1 * 2)
#define c1_SCTLR	(SCTLR_EL1 * 2)	
#define c1_ACTLR	(ACTLR_EL1 * 2)	
#define c1_CPACR	(CPACR_EL1 * 2)	
#define c2_TTBR0	(TTBR0_EL1 * 2)	
#define c2_TTBR0_high	(c2_TTBR0 + 1)	
#define c2_TTBR1	(TTBR1_EL1 * 2)	
#define c2_TTBR1_high	(c2_TTBR1 + 1)	
#define c2_TTBCR	(TCR_EL1 * 2)	
#define c2_TTBCR2	(c2_TTBCR + 1)	
#define c3_DACR		(DACR32_EL2 * 2)
#define c5_DFSR		(ESR_EL1 * 2)	
#define c5_IFSR		(IFSR32_EL2 * 2)
#define c5_ADFSR	(AFSR0_EL1 * 2)	
#define c5_AIFSR	(AFSR1_EL1 * 2)	
#define c6_DFAR		(FAR_EL1 * 2)	
#define c6_IFAR		(c6_DFAR + 1)	
#define c7_PAR		(PAR_EL1 * 2)	
#define c7_PAR_high	(c7_PAR + 1)	
#define c10_PRRR	(MAIR_EL1 * 2)	
#define c10_NMRR	(c10_PRRR + 1)	
#define c12_VBAR	(VBAR_EL1 * 2)	
#define c13_CID		(CONTEXTIDR_EL1 * 2)	
#define c13_TID_URW	(TPIDR_EL0 * 2)	
#define c13_TID_URO	(TPIDRRO_EL0 * 2)
#define c13_TID_PRIV	(TPIDR_EL1 * 2)	
#define c10_AMAIR0	(AMAIR_EL1 * 2)	
#define c10_AMAIR1	(c10_AMAIR0 + 1)
#define c14_CNTKCTL	(CNTKCTL_EL1 * 2) 

#define cp14_DBGDSCRext	(MDSCR_EL1 * 2)
#define cp14_DBGBCR0	(DBGBCR0_EL1 * 2)
#define cp14_DBGBVR0	(DBGBVR0_EL1 * 2)
#define cp14_DBGBXVR0	(cp14_DBGBVR0 + 1)
#define cp14_DBGWCR0	(DBGWCR0_EL1 * 2)
#define cp14_DBGWVR0	(DBGWVR0_EL1 * 2)
#define cp14_DBGDCCINT	(MDCCINT_EL1 * 2)
#define cp14_DBGVCR	(DBGVCR32_EL2 * 2)

#define NR_COPRO_REGS	(NR_SYS_REGS * 2)

struct kvm_cpu_context {
	struct kvm_regs	gp_regs;
	union {
		u64 sys_regs[NR_SYS_REGS];
		u32 copro[NR_COPRO_REGS];
	};

	struct kvm_vcpu *__hyp_running_vcpu;
};

struct kvm_pmu_events {
	u32 events_host;
	u32 events_guest;
};

struct kvm_host_data {
	struct kvm_cpu_context host_ctxt;
	struct kvm_pmu_events pmu_events;
};

typedef struct kvm_host_data kvm_host_data_t;

struct vcpu_reset_state {
	unsigned long	pc;
	unsigned long	r0;
	bool		be;
	bool		reset;
};

struct kvm_vcpu_arch {
	struct kvm_cpu_context ctxt;
	void *sve_state;
	unsigned int sve_max_vl;

	
	u64 hcr_el2;
	u32 mdcr_el2;

	
	struct kvm_vcpu_fault_info fault;

	
	u64 workaround_flags;

	
	u64 flags;

	
	struct kvm_guest_debug_arch *debug_ptr;
	struct kvm_guest_debug_arch vcpu_debug_state;
	struct kvm_guest_debug_arch external_debug_state;

	
	struct kvm_cpu_context *host_cpu_context;

	struct thread_info *host_thread_info;	
	struct user_fpsimd_state *host_fpsimd_state;	

	struct {
		
		struct kvm_guest_debug_arch regs;
		
		u64 pmscr_el1;
	} host_debug_state;

	
	struct vgic_cpu vgic_cpu;
	struct arch_timer_cpu timer_cpu;
	struct kvm_pmu pmu;

	

	
	struct {
		u32	mdscr_el1;
	} guest_debug_preserved;

	
	bool power_off;

	
	bool pause;

	
	struct kvm_decode mmio_decode;

	
	struct kvm_mmu_memory_cache mmu_page_cache;

	
	int target;
	DECLARE_BITMAP(features, KVM_VCPU_MAX_FEATURES);

	
	bool has_run_once;

	
	u64 vsesr_el2;

	
	struct vcpu_reset_state	reset_state;

	
	bool sysregs_loaded_on_cpu;
};


#define vcpu_sve_pffr(vcpu) ((void *)((char *)((vcpu)->arch.sve_state) + \
				      sve_ffr_offset((vcpu)->arch.sve_max_vl)))

#define vcpu_sve_state_size(vcpu) ({					\
	size_t __size_ret;						\
	unsigned int __vcpu_vq;						\
									\
	if (WARN_ON(!sve_vl_valid((vcpu)->arch.sve_max_vl))) {		\
		__size_ret = 0;						\
	} else {							\
		__vcpu_vq = sve_vq_from_vl((vcpu)->arch.sve_max_vl);	\
		__size_ret = SVE_SIG_REGS_SIZE(__vcpu_vq);		\
	}								\
									\
	__size_ret;							\
})


#define KVM_ARM64_DEBUG_DIRTY		(1 << 0)
#define KVM_ARM64_FP_ENABLED		(1 << 1) 
#define KVM_ARM64_FP_HOST		(1 << 2) 
#define KVM_ARM64_HOST_SVE_IN_USE	(1 << 3) 
#define KVM_ARM64_HOST_SVE_ENABLED	(1 << 4) 
#define KVM_ARM64_GUEST_HAS_SVE		(1 << 5) 
#define KVM_ARM64_VCPU_SVE_FINALIZED	(1 << 6) 
#define KVM_ARM64_GUEST_HAS_PTRAUTH	(1 << 7) 

#define vcpu_has_sve(vcpu) (system_supports_sve() && \
			    ((vcpu)->arch.flags & KVM_ARM64_GUEST_HAS_SVE))

#define vcpu_has_ptrauth(vcpu)	((system_supports_address_auth() || \
				  system_supports_generic_auth()) && \
				 ((vcpu)->arch.flags & KVM_ARM64_GUEST_HAS_PTRAUTH))

#define vcpu_gp_regs(v)		(&(v)->arch.ctxt.gp_regs)


#define __vcpu_sys_reg(v,r)	((v)->arch.ctxt.sys_regs[(r)])

u64 vcpu_read_sys_reg(const struct kvm_vcpu *vcpu, int reg);
void vcpu_write_sys_reg(struct kvm_vcpu *vcpu, u64 val, int reg);


#define CPx_BIAS		IS_ENABLED(CONFIG_CPU_BIG_ENDIAN)

#define vcpu_cp14(v,r)		((v)->arch.ctxt.copro[(r) ^ CPx_BIAS])
#define vcpu_cp15(v,r)		((v)->arch.ctxt.copro[(r) ^ CPx_BIAS])

struct kvm_vm_stat {
	ulong remote_tlb_flush;
};

struct kvm_vcpu_stat {
	u64 halt_successful_poll;
	u64 halt_attempted_poll;
	u64 halt_poll_invalid;
	u64 halt_wakeup;
	u64 hvc_exit_stat;
	u64 wfe_exit_stat;
	u64 wfi_exit_stat;
	u64 mmio_exit_user;
	u64 mmio_exit_kernel;
	u64 exits;
};

int kvm_vcpu_preferred_target(struct kvm_vcpu_init *init);
unsigned long kvm_arm_num_regs(struct kvm_vcpu *vcpu);
int kvm_arm_copy_reg_indices(struct kvm_vcpu *vcpu, u64 __user *indices);
int kvm_arm_get_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg);
int kvm_arm_set_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg);
int __kvm_arm_vcpu_get_events(struct kvm_vcpu *vcpu,
			      struct kvm_vcpu_events *events);

int __kvm_arm_vcpu_set_events(struct kvm_vcpu *vcpu,
			      struct kvm_vcpu_events *events);

#define KVM_ARCH_WANT_MMU_NOTIFIER
int kvm_unmap_hva_range(struct kvm *kvm,
			unsigned long start, unsigned long end, unsigned flags);
int kvm_set_spte_hva(struct kvm *kvm, unsigned long hva, pte_t pte);
int kvm_age_hva(struct kvm *kvm, unsigned long start, unsigned long end);
int kvm_test_age_hva(struct kvm *kvm, unsigned long hva);

struct kvm_vcpu *kvm_arm_get_running_vcpu(void);
struct kvm_vcpu * __percpu *kvm_get_running_vcpus(void);
void kvm_arm_halt_guest(struct kvm *kvm);
void kvm_arm_resume_guest(struct kvm *kvm);

u64 __kvm_call_hyp(void *hypfn, ...);


#define kvm_call_hyp(f, ...)						\
	do {								\
		if (has_vhe()) {					\
			f(__VA_ARGS__);					\
			isb();						\
		} else {						\
			__kvm_call_hyp(kvm_ksym_ref(f), ##__VA_ARGS__); \
		}							\
	} while(0)

#define kvm_call_hyp_ret(f, ...)					\
	({								\
		typeof(f(__VA_ARGS__)) ret;				\
									\
		if (has_vhe()) {					\
			ret = f(__VA_ARGS__);				\
			isb();						\
		} else {						\
			ret = __kvm_call_hyp(kvm_ksym_ref(f),		\
					     ##__VA_ARGS__);		\
		}							\
									\
		ret;							\
	})

void force_vm_exit(const cpumask_t *mask);
void kvm_mmu_wp_memory_region(struct kvm *kvm, int slot);

int handle_exit(struct kvm_vcpu *vcpu, struct kvm_run *run,
		int exception_index);
void handle_exit_early(struct kvm_vcpu *vcpu, struct kvm_run *run,
		       int exception_index);

int kvm_perf_init(void);
int kvm_perf_teardown(void);

void kvm_set_sei_esr(struct kvm_vcpu *vcpu, u64 syndrome);

struct kvm_vcpu *kvm_mpidr_to_vcpu(struct kvm *kvm, unsigned long mpidr);

DECLARE_PER_CPU(kvm_host_data_t, kvm_host_data);

static inline void kvm_init_host_cpu_context(struct kvm_cpu_context *cpu_ctxt)
{
	
	cpu_ctxt->sys_regs[MPIDR_EL1] = read_cpuid_mpidr();
}

void __kvm_enable_ssbs(void);

static inline void __cpu_init_hyp_mode(phys_addr_t pgd_ptr,
				       unsigned long hyp_stack_ptr,
				       unsigned long vector_ptr)
{
	
	u64 tpidr_el2 = ((u64)this_cpu_ptr(&kvm_host_data) -
			 (u64)kvm_ksym_ref(kvm_host_data));

	
	BUG_ON(!static_branch_likely(&arm64_const_caps_ready));
	__kvm_call_hyp((void *)pgd_ptr, hyp_stack_ptr, vector_ptr, tpidr_el2);

	
	if (!has_vhe() && this_cpu_has_cap(ARM64_SSBS) &&
	    arm64_get_ssbd_state() == ARM64_SSBD_FORCE_DISABLE) {
		kvm_call_hyp(__kvm_enable_ssbs);
	}
}

static inline bool kvm_arch_requires_vhe(void)
{
	
	if (system_supports_sve())
		return true;

	
	if (cpus_have_cap(ARM64_WORKAROUND_1165522))
		return true;

	return false;
}

void kvm_arm_vcpu_ptrauth_trap(struct kvm_vcpu *vcpu);

static inline void kvm_arch_hardware_unsetup(void) {}
static inline void kvm_arch_sync_events(struct kvm *kvm) {}
static inline void kvm_arch_sched_in(struct kvm_vcpu *vcpu, int cpu) {}
static inline void kvm_arch_vcpu_block_finish(struct kvm_vcpu *vcpu) {}

void kvm_arm_init_debug(void);
void kvm_arm_vcpu_init_debug(struct kvm_vcpu *vcpu);
void kvm_arm_setup_debug(struct kvm_vcpu *vcpu);
void kvm_arm_clear_debug(struct kvm_vcpu *vcpu);
void kvm_arm_reset_debug_ptr(struct kvm_vcpu *vcpu);
int kvm_arm_vcpu_arch_set_attr(struct kvm_vcpu *vcpu,
			       struct kvm_device_attr *attr);
int kvm_arm_vcpu_arch_get_attr(struct kvm_vcpu *vcpu,
			       struct kvm_device_attr *attr);
int kvm_arm_vcpu_arch_has_attr(struct kvm_vcpu *vcpu,
			       struct kvm_device_attr *attr);

static inline void __cpu_init_stage2(void) {}


int kvm_arch_vcpu_run_map_fp(struct kvm_vcpu *vcpu);
void kvm_arch_vcpu_load_fp(struct kvm_vcpu *vcpu);
void kvm_arch_vcpu_ctxsync_fp(struct kvm_vcpu *vcpu);
void kvm_arch_vcpu_put_fp(struct kvm_vcpu *vcpu);

static inline bool kvm_pmu_counter_deferred(struct perf_event_attr *attr)
{
	return (!has_vhe() && attr->exclude_host);
}

#ifdef CONFIG_KVM 
static inline int kvm_arch_vcpu_run_pid_change(struct kvm_vcpu *vcpu)
{
	return kvm_arch_vcpu_run_map_fp(vcpu);
}

void kvm_set_pmu_events(u32 set, struct perf_event_attr *attr);
void kvm_clr_pmu_events(u32 clr);

void kvm_vcpu_pmu_restore_guest(struct kvm_vcpu *vcpu);
void kvm_vcpu_pmu_restore_host(struct kvm_vcpu *vcpu);
#else
static inline void kvm_set_pmu_events(u32 set, struct perf_event_attr *attr) {}
static inline void kvm_clr_pmu_events(u32 clr) {}
#endif

static inline void kvm_arm_vhe_guest_enter(void)
{
	local_daif_mask();

	
	if (system_uses_irq_prio_masking())
		dsb(sy);
}

static inline void kvm_arm_vhe_guest_exit(void)
{
	
	local_daif_restore(DAIF_PROCCTX_NOIRQ);

	
	isb();
}

#define KVM_BP_HARDEN_UNKNOWN		-1
#define KVM_BP_HARDEN_WA_NEEDED		0
#define KVM_BP_HARDEN_NOT_REQUIRED	1

static inline int kvm_arm_harden_branch_predictor(void)
{
	switch (get_spectre_v2_workaround_state()) {
	case ARM64_BP_HARDEN_WA_NEEDED:
		return KVM_BP_HARDEN_WA_NEEDED;
	case ARM64_BP_HARDEN_NOT_REQUIRED:
		return KVM_BP_HARDEN_NOT_REQUIRED;
	case ARM64_BP_HARDEN_UNKNOWN:
	default:
		return KVM_BP_HARDEN_UNKNOWN;
	}
}

#define KVM_SSBD_UNKNOWN		-1
#define KVM_SSBD_FORCE_DISABLE		0
#define KVM_SSBD_KERNEL		1
#define KVM_SSBD_FORCE_ENABLE		2
#define KVM_SSBD_MITIGATED		3

static inline int kvm_arm_have_ssbd(void)
{
	switch (arm64_get_ssbd_state()) {
	case ARM64_SSBD_FORCE_DISABLE:
		return KVM_SSBD_FORCE_DISABLE;
	case ARM64_SSBD_KERNEL:
		return KVM_SSBD_KERNEL;
	case ARM64_SSBD_FORCE_ENABLE:
		return KVM_SSBD_FORCE_ENABLE;
	case ARM64_SSBD_MITIGATED:
		return KVM_SSBD_MITIGATED;
	case ARM64_SSBD_UNKNOWN:
	default:
		return KVM_SSBD_UNKNOWN;
	}
}

void kvm_vcpu_load_sysregs(struct kvm_vcpu *vcpu);
void kvm_vcpu_put_sysregs(struct kvm_vcpu *vcpu);

void kvm_set_ipa_limit(void);

#define __KVM_HAVE_ARCH_VM_ALLOC
struct kvm *kvm_arch_alloc_vm(void);
void kvm_arch_free_vm(struct kvm *kvm);

int kvm_arm_setup_stage2(struct kvm *kvm, unsigned long type);

int kvm_arm_vcpu_finalize(struct kvm_vcpu *vcpu, int feature);
bool kvm_arm_vcpu_is_finalized(struct kvm_vcpu *vcpu);

#define kvm_arm_vcpu_sve_finalized(vcpu) \
	((vcpu)->arch.flags & KVM_ARM64_VCPU_SVE_FINALIZED)

#define kvm_arm_vcpu_loaded(vcpu)	((vcpu)->arch.sysregs_loaded_on_cpu)

static inline enum mitigation_state kvm_arm_get_spectre_bhb_state(void)
{
	return arm64_get_spectre_bhb_state();
}

#endif 
