/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __MTD_NAND_BCH_H__
#define __MTD_NAND_BCH_H__

struct mtd_info;
struct nand_chip;
struct nand_bch_control;

#if IS_ENABLED(CONFIG_MTD_NAND_ECC_SW_BCH)

static inline int mtd_nand_has_bch(void) { return 1; }


int nand_bch_calculate_ecc(struct nand_chip *chip, const u_char *dat,
			   u_char *ecc_code);


int nand_bch_correct_data(struct nand_chip *chip, u_char *dat,
			  u_char *read_ecc, u_char *calc_ecc);

struct nand_bch_control *nand_bch_init(struct mtd_info *mtd);

void nand_bch_free(struct nand_bch_control *nbc);

#else 

static inline int mtd_nand_has_bch(void) { return 0; }

static inline int
nand_bch_calculate_ecc(struct nand_chip *chip, const u_char *dat,
		       u_char *ecc_code)
{
	return -1;
}

static inline int
nand_bch_correct_data(struct nand_chip *chip, unsigned char *buf,
		      unsigned char *read_ecc, unsigned char *calc_ecc)
{
	return -ENOTSUPP;
}

static inline struct nand_bch_control *nand_bch_init(struct mtd_info *mtd)
{
	return NULL;
}

static inline void nand_bch_free(struct nand_bch_control *nbc) {}

#endif 

#endif 