/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_SYNC_BITOPS_H__
#define __ASM_SYNC_BITOPS_H__

#include <asm/bitops.h>
#include <asm/cmpxchg.h>



#define sync_set_bit(nr, p)			set_bit(nr, p)
#define sync_clear_bit(nr, p)			clear_bit(nr, p)
#define sync_change_bit(nr, p)			change_bit(nr, p)
#define sync_test_and_set_bit(nr, p)		test_and_set_bit(nr, p)
#define sync_test_and_clear_bit(nr, p)		test_and_clear_bit(nr, p)
#define sync_test_and_change_bit(nr, p)		test_and_change_bit(nr, p)
#define sync_test_bit(nr, addr)			test_bit(nr, addr)
#define arch_sync_cmpxchg			arch_cmpxchg

#endif
