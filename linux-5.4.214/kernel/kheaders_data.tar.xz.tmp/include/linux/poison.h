/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_POISON_H
#define _LINUX_POISON_H




#ifdef CONFIG_ILLEGAL_POINTER_VALUE
# define POISON_POINTER_DELTA _AC(CONFIG_ILLEGAL_POINTER_VALUE, UL)
#else
# define POISON_POINTER_DELTA 0
#endif


#define LIST_POISON1  ((void *) 0x100 + POISON_POINTER_DELTA)
#define LIST_POISON2  ((void *) 0x122 + POISON_POINTER_DELTA)



#define TIMER_ENTRY_STATIC	((void *) 0x300 + POISON_POINTER_DELTA)


#ifdef CONFIG_PAGE_POISONING_ZERO
#define PAGE_POISON 0x00
#else
#define PAGE_POISON 0xaa
#endif



#define TAIL_MAPPING	((void *) 0x400 + POISON_POINTER_DELTA)



#define	RED_INACTIVE	0x09F911029D74E35BULL	
#define	RED_ACTIVE	0xD84156C5635688C0ULL	

#define SLUB_RED_INACTIVE	0xbb
#define SLUB_RED_ACTIVE		0xcc


#define	POISON_INUSE	0x5a	
#define POISON_FREE	0x6b	
#define	POISON_END	0xa5	


#define POISON_FREE_INITMEM	0xcc





#define JBD_POISON_FREE		0x5b
#define JBD2_POISON_FREE	0x5c


#define	POOL_POISON_FREED	0xa7	
#define	POOL_POISON_ALLOCATED	0xa9	


#define ATM_POISON_FREE		0x12
#define ATM_POISON		0xdeadbeef


#define MUTEX_DEBUG_INIT	0x11
#define MUTEX_DEBUG_FREE	0x22
#define MUTEX_POISON_WW_CTX	((void *) 0x500 + POISON_POINTER_DELTA)


#define KEY_DESTROY		0xbd

#endif
