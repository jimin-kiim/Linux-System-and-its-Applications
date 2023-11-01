/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __ASM_PROCESSOR_H
#define __ASM_PROCESSOR_H

#define KERNEL_DS		UL(-1)
#define USER_DS			((UL(1) << MAX_USER_VA_BITS) - 1)


#define NET_IP_ALIGN	0

#ifndef __ASSEMBLY__

#include <linux/build_bug.h>
#include <linux/cache.h>
#include <linux/init.h>
#include <linux/stddef.h>
#include <linux/string.h>

#include <asm/alternative.h>
#include <asm/cpufeature.h>
#include <asm/hw_breakpoint.h>
#include <asm/lse.h>
#include <asm/pgtable-hwdef.h>
#include <asm/pointer_auth.h>
#include <asm/ptrace.h>
#include <asm/types.h>



#define DEFAULT_MAP_WINDOW_64	(UL(1) << VA_BITS_MIN)
#define TASK_SIZE_64		(UL(1) << vabits_actual)

#ifdef CONFIG_COMPAT
#if defined(CONFIG_ARM64_64K_PAGES) && defined(CONFIG_KUSER_HELPERS)

#define TASK_SIZE_32		UL(0x100000000)
#else
#define TASK_SIZE_32		(UL(0x100000000) - PAGE_SIZE)
#endif 
#define TASK_SIZE		(test_thread_flag(TIF_32BIT) ? \
				TASK_SIZE_32 : TASK_SIZE_64)
#define TASK_SIZE_OF(tsk)	(test_tsk_thread_flag(tsk, TIF_32BIT) ? \
				TASK_SIZE_32 : TASK_SIZE_64)
#define DEFAULT_MAP_WINDOW	(test_thread_flag(TIF_32BIT) ? \
				TASK_SIZE_32 : DEFAULT_MAP_WINDOW_64)
#else
#define TASK_SIZE		TASK_SIZE_64
#define DEFAULT_MAP_WINDOW	DEFAULT_MAP_WINDOW_64
#endif 

#ifdef CONFIG_ARM64_FORCE_52BIT
#define STACK_TOP_MAX		TASK_SIZE_64
#define TASK_UNMAPPED_BASE	(PAGE_ALIGN(TASK_SIZE / 4))
#else
#define STACK_TOP_MAX		DEFAULT_MAP_WINDOW_64
#define TASK_UNMAPPED_BASE	(PAGE_ALIGN(DEFAULT_MAP_WINDOW / 4))
#endif 

#ifdef CONFIG_COMPAT
#define AARCH32_VECTORS_BASE	0xffff0000
#define STACK_TOP		(test_thread_flag(TIF_32BIT) ? \
				AARCH32_VECTORS_BASE : STACK_TOP_MAX)
#else
#define STACK_TOP		STACK_TOP_MAX
#endif 

#ifndef CONFIG_ARM64_FORCE_52BIT
#define arch_get_mmap_end(addr) ((addr > DEFAULT_MAP_WINDOW) ? TASK_SIZE :\
				DEFAULT_MAP_WINDOW)

#define arch_get_mmap_base(addr, base) ((addr > DEFAULT_MAP_WINDOW) ? \
					base + TASK_SIZE - DEFAULT_MAP_WINDOW :\
					base)
#endif 

extern phys_addr_t arm64_dma_phys_limit;
#define ARCH_LOW_ADDRESS_LIMIT	(arm64_dma_phys_limit - 1)

struct debug_info {
#ifdef CONFIG_HAVE_HW_BREAKPOINT
	
	int			suspended_step;
	
	int			bps_disabled;
	int			wps_disabled;
	
	struct perf_event	*hbp_break[ARM_MAX_BRP];
	struct perf_event	*hbp_watch[ARM_MAX_WRP];
#endif
};

struct cpu_context {
	unsigned long x19;
	unsigned long x20;
	unsigned long x21;
	unsigned long x22;
	unsigned long x23;
	unsigned long x24;
	unsigned long x25;
	unsigned long x26;
	unsigned long x27;
	unsigned long x28;
	unsigned long fp;
	unsigned long sp;
	unsigned long pc;
};

struct thread_struct {
	struct cpu_context	cpu_context;	

	
	struct {
		unsigned long	tp_value;	
		unsigned long	tp2_value;
		struct user_fpsimd_state fpsimd_state;
	} uw;

	unsigned int		fpsimd_cpu;
	void			*sve_state;	
	unsigned int		sve_vl;		
	unsigned int		sve_vl_onexec;	
	unsigned long		fault_address;	
	unsigned long		fault_code;	
	struct debug_info	debug;		
#ifdef CONFIG_ARM64_PTR_AUTH
	struct ptrauth_keys	keys_user;
#endif
};

static inline void arch_thread_struct_whitelist(unsigned long *offset,
						unsigned long *size)
{
	
	BUILD_BUG_ON(sizeof_field(struct thread_struct, uw) !=
		     sizeof_field(struct thread_struct, uw.tp_value) +
		     sizeof_field(struct thread_struct, uw.tp2_value) +
		     sizeof_field(struct thread_struct, uw.fpsimd_state));

	*offset = offsetof(struct thread_struct, uw);
	*size = sizeof_field(struct thread_struct, uw);
}

#ifdef CONFIG_COMPAT
#define task_user_tls(t)						\
({									\
	unsigned long *__tls;						\
	if (is_compat_thread(task_thread_info(t)))			\
		__tls = &(t)->thread.uw.tp2_value;			\
	else								\
		__tls = &(t)->thread.uw.tp_value;			\
	__tls;								\
 })
#else
#define task_user_tls(t)	(&(t)->thread.uw.tp_value)
#endif


void tls_preserve_current_state(void);

#define INIT_THREAD {				\
	.fpsimd_cpu = NR_CPUS,			\
}

static inline void start_thread_common(struct pt_regs *regs, unsigned long pc)
{
	s32 previous_syscall = regs->syscallno;
	memset(regs, 0, sizeof(*regs));
	regs->syscallno = previous_syscall;
	regs->pc = pc;

	if (system_uses_irq_prio_masking())
		regs->pmr_save = GIC_PRIO_IRQON;
}

static inline void set_ssbs_bit(struct pt_regs *regs)
{
	regs->pstate |= PSR_SSBS_BIT;
}

static inline void set_compat_ssbs_bit(struct pt_regs *regs)
{
	regs->pstate |= PSR_AA32_SSBS_BIT;
}

static inline void start_thread(struct pt_regs *regs, unsigned long pc,
				unsigned long sp)
{
	start_thread_common(regs, pc);
	regs->pstate = PSR_MODE_EL0t;

	if (arm64_get_ssbd_state() != ARM64_SSBD_FORCE_ENABLE)
		set_ssbs_bit(regs);

	regs->sp = sp;
}

#ifdef CONFIG_COMPAT
static inline void compat_start_thread(struct pt_regs *regs, unsigned long pc,
				       unsigned long sp)
{
	start_thread_common(regs, pc);
	regs->pstate = PSR_AA32_MODE_USR;
	if (pc & 1)
		regs->pstate |= PSR_AA32_T_BIT;

#ifdef __AARCH64EB__
	regs->pstate |= PSR_AA32_E_BIT;
#endif

	if (arm64_get_ssbd_state() != ARM64_SSBD_FORCE_ENABLE)
		set_compat_ssbs_bit(regs);

	regs->compat_sp = sp;
}
#endif


struct task_struct;


extern void release_thread(struct task_struct *);

unsigned long get_wchan(struct task_struct *p);

static inline void cpu_relax(void)
{
	asm volatile("yield" ::: "memory");
}


extern struct task_struct *cpu_switch_to(struct task_struct *prev,
					 struct task_struct *next);

#define task_pt_regs(p) \
	((struct pt_regs *)(THREAD_SIZE + task_stack_page(p)) - 1)

#define KSTK_EIP(tsk)	((unsigned long)task_pt_regs(tsk)->pc)
#define KSTK_ESP(tsk)	user_stack_pointer(task_pt_regs(tsk))


#define ARCH_HAS_PREFETCH
static inline void prefetch(const void *ptr)
{
	asm volatile("prfm pldl1keep, %a0\n" : : "p" (ptr));
}

#define ARCH_HAS_PREFETCHW
static inline void prefetchw(const void *ptr)
{
	asm volatile("prfm pstl1keep, %a0\n" : : "p" (ptr));
}

#define ARCH_HAS_SPINLOCK_PREFETCH
static inline void spin_lock_prefetch(const void *ptr)
{
	asm volatile(ARM64_LSE_ATOMIC_INSN(
		     "prfm pstl1strm, %a0",
		     "nop") : : "p" (ptr));
}

extern unsigned long __ro_after_init signal_minsigstksz; 
extern void __init minsigstksz_setup(void);


#include <asm/fpsimd.h>


#define SVE_SET_VL(arg)	sve_set_current_vl(arg)
#define SVE_GET_VL()	sve_get_current_vl()


#define PAC_RESET_KEYS(tsk, arg)	ptrauth_prctl_reset_keys(tsk, arg)

#ifdef CONFIG_ARM64_TAGGED_ADDR_ABI

long set_tagged_addr_ctrl(unsigned long arg);
long get_tagged_addr_ctrl(void);
#define SET_TAGGED_ADDR_CTRL(arg)	set_tagged_addr_ctrl(arg)
#define GET_TAGGED_ADDR_CTRL()		get_tagged_addr_ctrl()
#endif



#define current_top_of_stack()							\
({										\
	struct stack_info _info;						\
	BUG_ON(!on_accessible_stack(current, current_stack_pointer, &_info));	\
	_info.high;								\
})
#define on_thread_stack()	(on_task_stack(current, current_stack_pointer, NULL))

#endif 
#endif 
