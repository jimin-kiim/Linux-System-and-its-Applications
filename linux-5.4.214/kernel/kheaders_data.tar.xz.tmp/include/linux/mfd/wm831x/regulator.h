/* SPDX-License-Identifier: GPL-2.0-or-later */


#ifndef __MFD_WM831X_REGULATOR_H__
#define __MFD_WM831X_REGULATOR_H__


#define WM831X_CS1_ENA                          0x8000  
#define WM831X_CS1_ENA_MASK                     0x8000  
#define WM831X_CS1_ENA_SHIFT                        15  
#define WM831X_CS1_ENA_WIDTH                         1  
#define WM831X_CS1_DRIVE                        0x4000  
#define WM831X_CS1_DRIVE_MASK                   0x4000  
#define WM831X_CS1_DRIVE_SHIFT                      14  
#define WM831X_CS1_DRIVE_WIDTH                       1  
#define WM831X_CS1_SLPENA                       0x1000  
#define WM831X_CS1_SLPENA_MASK                  0x1000  
#define WM831X_CS1_SLPENA_SHIFT                     12  
#define WM831X_CS1_SLPENA_WIDTH                      1  
#define WM831X_CS1_OFF_RAMP_MASK                0x0C00  
#define WM831X_CS1_OFF_RAMP_SHIFT                   10  
#define WM831X_CS1_OFF_RAMP_WIDTH                    2  
#define WM831X_CS1_ON_RAMP_MASK                 0x0300  
#define WM831X_CS1_ON_RAMP_SHIFT                     8  
#define WM831X_CS1_ON_RAMP_WIDTH                     2  
#define WM831X_CS1_ISEL_MASK                    0x003F  
#define WM831X_CS1_ISEL_SHIFT                        0  
#define WM831X_CS1_ISEL_WIDTH                        6  


#define WM831X_CS2_ENA                          0x8000  
#define WM831X_CS2_ENA_MASK                     0x8000  
#define WM831X_CS2_ENA_SHIFT                        15  
#define WM831X_CS2_ENA_WIDTH                         1  
#define WM831X_CS2_DRIVE                        0x4000  
#define WM831X_CS2_DRIVE_MASK                   0x4000  
#define WM831X_CS2_DRIVE_SHIFT                      14  
#define WM831X_CS2_DRIVE_WIDTH                       1  
#define WM831X_CS2_SLPENA                       0x1000  
#define WM831X_CS2_SLPENA_MASK                  0x1000  
#define WM831X_CS2_SLPENA_SHIFT                     12  
#define WM831X_CS2_SLPENA_WIDTH                      1  
#define WM831X_CS2_OFF_RAMP_MASK                0x0C00  
#define WM831X_CS2_OFF_RAMP_SHIFT                   10  
#define WM831X_CS2_OFF_RAMP_WIDTH                    2  
#define WM831X_CS2_ON_RAMP_MASK                 0x0300  
#define WM831X_CS2_ON_RAMP_SHIFT                     8  
#define WM831X_CS2_ON_RAMP_WIDTH                     2  
#define WM831X_CS2_ISEL_MASK                    0x003F  
#define WM831X_CS2_ISEL_SHIFT                        0  
#define WM831X_CS2_ISEL_WIDTH                        6  


#define WM831X_EPE2_ENA                         0x0080  
#define WM831X_EPE2_ENA_MASK                    0x0080  
#define WM831X_EPE2_ENA_SHIFT                        7  
#define WM831X_EPE2_ENA_WIDTH                        1  
#define WM831X_EPE1_ENA                         0x0040  
#define WM831X_EPE1_ENA_MASK                    0x0040  
#define WM831X_EPE1_ENA_SHIFT                        6  
#define WM831X_EPE1_ENA_WIDTH                        1  
#define WM831X_DC4_ENA                          0x0008  
#define WM831X_DC4_ENA_MASK                     0x0008  
#define WM831X_DC4_ENA_SHIFT                         3  
#define WM831X_DC4_ENA_WIDTH                         1  
#define WM831X_DC3_ENA                          0x0004  
#define WM831X_DC3_ENA_MASK                     0x0004  
#define WM831X_DC3_ENA_SHIFT                         2  
#define WM831X_DC3_ENA_WIDTH                         1  
#define WM831X_DC2_ENA                          0x0002  
#define WM831X_DC2_ENA_MASK                     0x0002  
#define WM831X_DC2_ENA_SHIFT                         1  
#define WM831X_DC2_ENA_WIDTH                         1  
#define WM831X_DC1_ENA                          0x0001  
#define WM831X_DC1_ENA_MASK                     0x0001  
#define WM831X_DC1_ENA_SHIFT                         0  
#define WM831X_DC1_ENA_WIDTH                         1  


#define WM831X_LDO11_ENA                        0x0400  
#define WM831X_LDO11_ENA_MASK                   0x0400  
#define WM831X_LDO11_ENA_SHIFT                      10  
#define WM831X_LDO11_ENA_WIDTH                       1  
#define WM831X_LDO10_ENA                        0x0200  
#define WM831X_LDO10_ENA_MASK                   0x0200  
#define WM831X_LDO10_ENA_SHIFT                       9  
#define WM831X_LDO10_ENA_WIDTH                       1  
#define WM831X_LDO9_ENA                         0x0100  
#define WM831X_LDO9_ENA_MASK                    0x0100  
#define WM831X_LDO9_ENA_SHIFT                        8  
#define WM831X_LDO9_ENA_WIDTH                        1  
#define WM831X_LDO8_ENA                         0x0080  
#define WM831X_LDO8_ENA_MASK                    0x0080  
#define WM831X_LDO8_ENA_SHIFT                        7  
#define WM831X_LDO8_ENA_WIDTH                        1  
#define WM831X_LDO7_ENA                         0x0040  
#define WM831X_LDO7_ENA_MASK                    0x0040  
#define WM831X_LDO7_ENA_SHIFT                        6  
#define WM831X_LDO7_ENA_WIDTH                        1  
#define WM831X_LDO6_ENA                         0x0020  
#define WM831X_LDO6_ENA_MASK                    0x0020  
#define WM831X_LDO6_ENA_SHIFT                        5  
#define WM831X_LDO6_ENA_WIDTH                        1  
#define WM831X_LDO5_ENA                         0x0010  
#define WM831X_LDO5_ENA_MASK                    0x0010  
#define WM831X_LDO5_ENA_SHIFT                        4  
#define WM831X_LDO5_ENA_WIDTH                        1  
#define WM831X_LDO4_ENA                         0x0008  
#define WM831X_LDO4_ENA_MASK                    0x0008  
#define WM831X_LDO4_ENA_SHIFT                        3  
#define WM831X_LDO4_ENA_WIDTH                        1  
#define WM831X_LDO3_ENA                         0x0004  
#define WM831X_LDO3_ENA_MASK                    0x0004  
#define WM831X_LDO3_ENA_SHIFT                        2  
#define WM831X_LDO3_ENA_WIDTH                        1  
#define WM831X_LDO2_ENA                         0x0002  
#define WM831X_LDO2_ENA_MASK                    0x0002  
#define WM831X_LDO2_ENA_SHIFT                        1  
#define WM831X_LDO2_ENA_WIDTH                        1  
#define WM831X_LDO1_ENA                         0x0001  
#define WM831X_LDO1_ENA_MASK                    0x0001  
#define WM831X_LDO1_ENA_SHIFT                        0  
#define WM831X_LDO1_ENA_WIDTH                        1  


#define WM831X_EPE2_STS                         0x0080  
#define WM831X_EPE2_STS_MASK                    0x0080  
#define WM831X_EPE2_STS_SHIFT                        7  
#define WM831X_EPE2_STS_WIDTH                        1  
#define WM831X_EPE1_STS                         0x0040  
#define WM831X_EPE1_STS_MASK                    0x0040  
#define WM831X_EPE1_STS_SHIFT                        6  
#define WM831X_EPE1_STS_WIDTH                        1  
#define WM831X_DC4_STS                          0x0008  
#define WM831X_DC4_STS_MASK                     0x0008  
#define WM831X_DC4_STS_SHIFT                         3  
#define WM831X_DC4_STS_WIDTH                         1  
#define WM831X_DC3_STS                          0x0004  
#define WM831X_DC3_STS_MASK                     0x0004  
#define WM831X_DC3_STS_SHIFT                         2  
#define WM831X_DC3_STS_WIDTH                         1  
#define WM831X_DC2_STS                          0x0002  
#define WM831X_DC2_STS_MASK                     0x0002  
#define WM831X_DC2_STS_SHIFT                         1  
#define WM831X_DC2_STS_WIDTH                         1  
#define WM831X_DC1_STS                          0x0001  
#define WM831X_DC1_STS_MASK                     0x0001  
#define WM831X_DC1_STS_SHIFT                         0  
#define WM831X_DC1_STS_WIDTH                         1  


#define WM831X_LDO11_STS                        0x0400  
#define WM831X_LDO11_STS_MASK                   0x0400  
#define WM831X_LDO11_STS_SHIFT                      10  
#define WM831X_LDO11_STS_WIDTH                       1  
#define WM831X_LDO10_STS                        0x0200  
#define WM831X_LDO10_STS_MASK                   0x0200  
#define WM831X_LDO10_STS_SHIFT                       9  
#define WM831X_LDO10_STS_WIDTH                       1  
#define WM831X_LDO9_STS                         0x0100  
#define WM831X_LDO9_STS_MASK                    0x0100  
#define WM831X_LDO9_STS_SHIFT                        8  
#define WM831X_LDO9_STS_WIDTH                        1  
#define WM831X_LDO8_STS                         0x0080  
#define WM831X_LDO8_STS_MASK                    0x0080  
#define WM831X_LDO8_STS_SHIFT                        7  
#define WM831X_LDO8_STS_WIDTH                        1  
#define WM831X_LDO7_STS                         0x0040  
#define WM831X_LDO7_STS_MASK                    0x0040  
#define WM831X_LDO7_STS_SHIFT                        6  
#define WM831X_LDO7_STS_WIDTH                        1  
#define WM831X_LDO6_STS                         0x0020  
#define WM831X_LDO6_STS_MASK                    0x0020  
#define WM831X_LDO6_STS_SHIFT                        5  
#define WM831X_LDO6_STS_WIDTH                        1  
#define WM831X_LDO5_STS                         0x0010  
#define WM831X_LDO5_STS_MASK                    0x0010  
#define WM831X_LDO5_STS_SHIFT                        4  
#define WM831X_LDO5_STS_WIDTH                        1  
#define WM831X_LDO4_STS                         0x0008  
#define WM831X_LDO4_STS_MASK                    0x0008  
#define WM831X_LDO4_STS_SHIFT                        3  
#define WM831X_LDO4_STS_WIDTH                        1  
#define WM831X_LDO3_STS                         0x0004  
#define WM831X_LDO3_STS_MASK                    0x0004  
#define WM831X_LDO3_STS_SHIFT                        2  
#define WM831X_LDO3_STS_WIDTH                        1  
#define WM831X_LDO2_STS                         0x0002  
#define WM831X_LDO2_STS_MASK                    0x0002  
#define WM831X_LDO2_STS_SHIFT                        1  
#define WM831X_LDO2_STS_WIDTH                        1  
#define WM831X_LDO1_STS                         0x0001  
#define WM831X_LDO1_STS_MASK                    0x0001  
#define WM831X_LDO1_STS_SHIFT                        0  
#define WM831X_LDO1_STS_WIDTH                        1  


#define WM831X_DC2_OV_STS                       0x2000  
#define WM831X_DC2_OV_STS_MASK                  0x2000  
#define WM831X_DC2_OV_STS_SHIFT                     13  
#define WM831X_DC2_OV_STS_WIDTH                      1  
#define WM831X_DC1_OV_STS                       0x1000  
#define WM831X_DC1_OV_STS_MASK                  0x1000  
#define WM831X_DC1_OV_STS_SHIFT                     12  
#define WM831X_DC1_OV_STS_WIDTH                      1  
#define WM831X_DC2_HC_STS                       0x0200  
#define WM831X_DC2_HC_STS_MASK                  0x0200  
#define WM831X_DC2_HC_STS_SHIFT                      9  
#define WM831X_DC2_HC_STS_WIDTH                      1  
#define WM831X_DC1_HC_STS                       0x0100  
#define WM831X_DC1_HC_STS_MASK                  0x0100  
#define WM831X_DC1_HC_STS_SHIFT                      8  
#define WM831X_DC1_HC_STS_WIDTH                      1  
#define WM831X_DC4_UV_STS                       0x0008  
#define WM831X_DC4_UV_STS_MASK                  0x0008  
#define WM831X_DC4_UV_STS_SHIFT                      3  
#define WM831X_DC4_UV_STS_WIDTH                      1  
#define WM831X_DC3_UV_STS                       0x0004  
#define WM831X_DC3_UV_STS_MASK                  0x0004  
#define WM831X_DC3_UV_STS_SHIFT                      2  
#define WM831X_DC3_UV_STS_WIDTH                      1  
#define WM831X_DC2_UV_STS                       0x0002  
#define WM831X_DC2_UV_STS_MASK                  0x0002  
#define WM831X_DC2_UV_STS_SHIFT                      1  
#define WM831X_DC2_UV_STS_WIDTH                      1  
#define WM831X_DC1_UV_STS                       0x0001  
#define WM831X_DC1_UV_STS_MASK                  0x0001  
#define WM831X_DC1_UV_STS_SHIFT                      0  
#define WM831X_DC1_UV_STS_WIDTH                      1  


#define WM831X_INTLDO_UV_STS                    0x8000  
#define WM831X_INTLDO_UV_STS_MASK               0x8000  
#define WM831X_INTLDO_UV_STS_SHIFT                  15  
#define WM831X_INTLDO_UV_STS_WIDTH                   1  
#define WM831X_LDO10_UV_STS                     0x0200  
#define WM831X_LDO10_UV_STS_MASK                0x0200  
#define WM831X_LDO10_UV_STS_SHIFT                    9  
#define WM831X_LDO10_UV_STS_WIDTH                    1  
#define WM831X_LDO9_UV_STS                      0x0100  
#define WM831X_LDO9_UV_STS_MASK                 0x0100  
#define WM831X_LDO9_UV_STS_SHIFT                     8  
#define WM831X_LDO9_UV_STS_WIDTH                     1  
#define WM831X_LDO8_UV_STS                      0x0080  
#define WM831X_LDO8_UV_STS_MASK                 0x0080  
#define WM831X_LDO8_UV_STS_SHIFT                     7  
#define WM831X_LDO8_UV_STS_WIDTH                     1  
#define WM831X_LDO7_UV_STS                      0x0040  
#define WM831X_LDO7_UV_STS_MASK                 0x0040  
#define WM831X_LDO7_UV_STS_SHIFT                     6  
#define WM831X_LDO7_UV_STS_WIDTH                     1  
#define WM831X_LDO6_UV_STS                      0x0020  
#define WM831X_LDO6_UV_STS_MASK                 0x0020  
#define WM831X_LDO6_UV_STS_SHIFT                     5  
#define WM831X_LDO6_UV_STS_WIDTH                     1  
#define WM831X_LDO5_UV_STS                      0x0010  
#define WM831X_LDO5_UV_STS_MASK                 0x0010  
#define WM831X_LDO5_UV_STS_SHIFT                     4  
#define WM831X_LDO5_UV_STS_WIDTH                     1  
#define WM831X_LDO4_UV_STS                      0x0008  
#define WM831X_LDO4_UV_STS_MASK                 0x0008  
#define WM831X_LDO4_UV_STS_SHIFT                     3  
#define WM831X_LDO4_UV_STS_WIDTH                     1  
#define WM831X_LDO3_UV_STS                      0x0004  
#define WM831X_LDO3_UV_STS_MASK                 0x0004  
#define WM831X_LDO3_UV_STS_SHIFT                     2  
#define WM831X_LDO3_UV_STS_WIDTH                     1  
#define WM831X_LDO2_UV_STS                      0x0002  
#define WM831X_LDO2_UV_STS_MASK                 0x0002  
#define WM831X_LDO2_UV_STS_SHIFT                     1  
#define WM831X_LDO2_UV_STS_WIDTH                     1  
#define WM831X_LDO1_UV_STS                      0x0001  
#define WM831X_LDO1_UV_STS_MASK                 0x0001  
#define WM831X_LDO1_UV_STS_SHIFT                     0  
#define WM831X_LDO1_UV_STS_WIDTH                     1  


#define WM831X_DC1_RATE_MASK                    0xC000  
#define WM831X_DC1_RATE_SHIFT                       14  
#define WM831X_DC1_RATE_WIDTH                        2  
#define WM831X_DC1_PHASE                        0x1000  
#define WM831X_DC1_PHASE_MASK                   0x1000  
#define WM831X_DC1_PHASE_SHIFT                      12  
#define WM831X_DC1_PHASE_WIDTH                       1  
#define WM831X_DC1_FREQ_MASK                    0x0300  
#define WM831X_DC1_FREQ_SHIFT                        8  
#define WM831X_DC1_FREQ_WIDTH                        2  
#define WM831X_DC1_FLT                          0x0080  
#define WM831X_DC1_FLT_MASK                     0x0080  
#define WM831X_DC1_FLT_SHIFT                         7  
#define WM831X_DC1_FLT_WIDTH                         1  
#define WM831X_DC1_SOFT_START_MASK              0x0030  
#define WM831X_DC1_SOFT_START_SHIFT                  4  
#define WM831X_DC1_SOFT_START_WIDTH                  2  
#define WM831X_DC1_CAP_MASK                     0x0003  
#define WM831X_DC1_CAP_SHIFT                         0  
#define WM831X_DC1_CAP_WIDTH                         2  


#define WM831X_DC1_ERR_ACT_MASK                 0xC000  
#define WM831X_DC1_ERR_ACT_SHIFT                    14  
#define WM831X_DC1_ERR_ACT_WIDTH                     2  
#define WM831X_DC1_HWC_SRC_MASK                 0x1800  
#define WM831X_DC1_HWC_SRC_SHIFT                    11  
#define WM831X_DC1_HWC_SRC_WIDTH                     2  
#define WM831X_DC1_HWC_VSEL                     0x0400  
#define WM831X_DC1_HWC_VSEL_MASK                0x0400  
#define WM831X_DC1_HWC_VSEL_SHIFT                   10  
#define WM831X_DC1_HWC_VSEL_WIDTH                    1  
#define WM831X_DC1_HWC_MODE_MASK                0x0300  
#define WM831X_DC1_HWC_MODE_SHIFT                    8  
#define WM831X_DC1_HWC_MODE_WIDTH                    2  
#define WM831X_DC1_HC_THR_MASK                  0x0070  
#define WM831X_DC1_HC_THR_SHIFT                      4  
#define WM831X_DC1_HC_THR_WIDTH                      3  
#define WM831X_DC1_HC_IND_ENA                   0x0001  
#define WM831X_DC1_HC_IND_ENA_MASK              0x0001  
#define WM831X_DC1_HC_IND_ENA_SHIFT                  0  
#define WM831X_DC1_HC_IND_ENA_WIDTH                  1  


#define WM831X_DC1_ON_SLOT_MASK                 0xE000  
#define WM831X_DC1_ON_SLOT_SHIFT                    13  
#define WM831X_DC1_ON_SLOT_WIDTH                     3  
#define WM831X_DC1_ON_MODE_MASK                 0x0300  
#define WM831X_DC1_ON_MODE_SHIFT                     8  
#define WM831X_DC1_ON_MODE_WIDTH                     2  
#define WM831X_DC1_ON_VSEL_MASK                 0x007F  
#define WM831X_DC1_ON_VSEL_SHIFT                     0  
#define WM831X_DC1_ON_VSEL_WIDTH                     7  


#define WM831X_DC1_SLP_SLOT_MASK                0xE000  
#define WM831X_DC1_SLP_SLOT_SHIFT                   13  
#define WM831X_DC1_SLP_SLOT_WIDTH                    3  
#define WM831X_DC1_SLP_MODE_MASK                0x0300  
#define WM831X_DC1_SLP_MODE_SHIFT                    8  
#define WM831X_DC1_SLP_MODE_WIDTH                    2  
#define WM831X_DC1_SLP_VSEL_MASK                0x007F  
#define WM831X_DC1_SLP_VSEL_SHIFT                    0  
#define WM831X_DC1_SLP_VSEL_WIDTH                    7  


#define WM831X_DC1_DVS_SRC_MASK                 0x1800  
#define WM831X_DC1_DVS_SRC_SHIFT                    11  
#define WM831X_DC1_DVS_SRC_WIDTH                     2  
#define WM831X_DC1_DVS_VSEL_MASK                0x007F  
#define WM831X_DC1_DVS_VSEL_SHIFT                    0  
#define WM831X_DC1_DVS_VSEL_WIDTH                    7  


#define WM831X_DC2_RATE_MASK                    0xC000  
#define WM831X_DC2_RATE_SHIFT                       14  
#define WM831X_DC2_RATE_WIDTH                        2  
#define WM831X_DC2_PHASE                        0x1000  
#define WM831X_DC2_PHASE_MASK                   0x1000  
#define WM831X_DC2_PHASE_SHIFT                      12  
#define WM831X_DC2_PHASE_WIDTH                       1  
#define WM831X_DC2_FREQ_MASK                    0x0300  
#define WM831X_DC2_FREQ_SHIFT                        8  
#define WM831X_DC2_FREQ_WIDTH                        2  
#define WM831X_DC2_FLT                          0x0080  
#define WM831X_DC2_FLT_MASK                     0x0080  
#define WM831X_DC2_FLT_SHIFT                         7  
#define WM831X_DC2_FLT_WIDTH                         1  
#define WM831X_DC2_SOFT_START_MASK              0x0030  
#define WM831X_DC2_SOFT_START_SHIFT                  4  
#define WM831X_DC2_SOFT_START_WIDTH                  2  
#define WM831X_DC2_CAP_MASK                     0x0003  
#define WM831X_DC2_CAP_SHIFT                         0  
#define WM831X_DC2_CAP_WIDTH                         2  


#define WM831X_DC2_ERR_ACT_MASK                 0xC000  
#define WM831X_DC2_ERR_ACT_SHIFT                    14  
#define WM831X_DC2_ERR_ACT_WIDTH                     2  
#define WM831X_DC2_HWC_SRC_MASK                 0x1800  
#define WM831X_DC2_HWC_SRC_SHIFT                    11  
#define WM831X_DC2_HWC_SRC_WIDTH                     2  
#define WM831X_DC2_HWC_VSEL                     0x0400  
#define WM831X_DC2_HWC_VSEL_MASK                0x0400  
#define WM831X_DC2_HWC_VSEL_SHIFT                   10  
#define WM831X_DC2_HWC_VSEL_WIDTH                    1  
#define WM831X_DC2_HWC_MODE_MASK                0x0300  
#define WM831X_DC2_HWC_MODE_SHIFT                    8  
#define WM831X_DC2_HWC_MODE_WIDTH                    2  
#define WM831X_DC2_HC_THR_MASK                  0x0070  
#define WM831X_DC2_HC_THR_SHIFT                      4  
#define WM831X_DC2_HC_THR_WIDTH                      3  
#define WM831X_DC2_HC_IND_ENA                   0x0001  
#define WM831X_DC2_HC_IND_ENA_MASK              0x0001  
#define WM831X_DC2_HC_IND_ENA_SHIFT                  0  
#define WM831X_DC2_HC_IND_ENA_WIDTH                  1  


#define WM831X_DC2_ON_SLOT_MASK                 0xE000  
#define WM831X_DC2_ON_SLOT_SHIFT                    13  
#define WM831X_DC2_ON_SLOT_WIDTH                     3  
#define WM831X_DC2_ON_MODE_MASK                 0x0300  
#define WM831X_DC2_ON_MODE_SHIFT                     8  
#define WM831X_DC2_ON_MODE_WIDTH                     2  
#define WM831X_DC2_ON_VSEL_MASK                 0x007F  
#define WM831X_DC2_ON_VSEL_SHIFT                     0  
#define WM831X_DC2_ON_VSEL_WIDTH                     7  


#define WM831X_DC2_SLP_SLOT_MASK                0xE000  
#define WM831X_DC2_SLP_SLOT_SHIFT                   13  
#define WM831X_DC2_SLP_SLOT_WIDTH                    3  
#define WM831X_DC2_SLP_MODE_MASK                0x0300  
#define WM831X_DC2_SLP_MODE_SHIFT                    8  
#define WM831X_DC2_SLP_MODE_WIDTH                    2  
#define WM831X_DC2_SLP_VSEL_MASK                0x007F  
#define WM831X_DC2_SLP_VSEL_SHIFT                    0  
#define WM831X_DC2_SLP_VSEL_WIDTH                    7  


#define WM831X_DC2_DVS_SRC_MASK                 0x1800  
#define WM831X_DC2_DVS_SRC_SHIFT                    11  
#define WM831X_DC2_DVS_SRC_WIDTH                     2  
#define WM831X_DC2_DVS_VSEL_MASK                0x007F  
#define WM831X_DC2_DVS_VSEL_SHIFT                    0  
#define WM831X_DC2_DVS_VSEL_WIDTH                    7  


#define WM831X_DC3_PHASE                        0x1000  
#define WM831X_DC3_PHASE_MASK                   0x1000  
#define WM831X_DC3_PHASE_SHIFT                      12  
#define WM831X_DC3_PHASE_WIDTH                       1  
#define WM831X_DC3_FLT                          0x0080  
#define WM831X_DC3_FLT_MASK                     0x0080  
#define WM831X_DC3_FLT_SHIFT                         7  
#define WM831X_DC3_FLT_WIDTH                         1  
#define WM831X_DC3_SOFT_START_MASK              0x0030  
#define WM831X_DC3_SOFT_START_SHIFT                  4  
#define WM831X_DC3_SOFT_START_WIDTH                  2  
#define WM831X_DC3_STNBY_LIM_MASK               0x000C  
#define WM831X_DC3_STNBY_LIM_SHIFT                   2  
#define WM831X_DC3_STNBY_LIM_WIDTH                   2  
#define WM831X_DC3_CAP_MASK                     0x0003  
#define WM831X_DC3_CAP_SHIFT                         0  
#define WM831X_DC3_CAP_WIDTH                         2  


#define WM831X_DC3_ERR_ACT_MASK                 0xC000  
#define WM831X_DC3_ERR_ACT_SHIFT                    14  
#define WM831X_DC3_ERR_ACT_WIDTH                     2  
#define WM831X_DC3_HWC_SRC_MASK                 0x1800  
#define WM831X_DC3_HWC_SRC_SHIFT                    11  
#define WM831X_DC3_HWC_SRC_WIDTH                     2  
#define WM831X_DC3_HWC_VSEL                     0x0400  
#define WM831X_DC3_HWC_VSEL_MASK                0x0400  
#define WM831X_DC3_HWC_VSEL_SHIFT                   10  
#define WM831X_DC3_HWC_VSEL_WIDTH                    1  
#define WM831X_DC3_HWC_MODE_MASK                0x0300  
#define WM831X_DC3_HWC_MODE_SHIFT                    8  
#define WM831X_DC3_HWC_MODE_WIDTH                    2  
#define WM831X_DC3_OVP                          0x0080  
#define WM831X_DC3_OVP_MASK                     0x0080  
#define WM831X_DC3_OVP_SHIFT                         7  
#define WM831X_DC3_OVP_WIDTH                         1  


#define WM831X_DC3_ON_SLOT_MASK                 0xE000  
#define WM831X_DC3_ON_SLOT_SHIFT                    13  
#define WM831X_DC3_ON_SLOT_WIDTH                     3  
#define WM831X_DC3_ON_MODE_MASK                 0x0300  
#define WM831X_DC3_ON_MODE_SHIFT                     8  
#define WM831X_DC3_ON_MODE_WIDTH                     2  
#define WM831X_DC3_ON_VSEL_MASK                 0x007F  
#define WM831X_DC3_ON_VSEL_SHIFT                     0  
#define WM831X_DC3_ON_VSEL_WIDTH                     7  


#define WM831X_DC3_SLP_SLOT_MASK                0xE000  
#define WM831X_DC3_SLP_SLOT_SHIFT                   13  
#define WM831X_DC3_SLP_SLOT_WIDTH                    3  
#define WM831X_DC3_SLP_MODE_MASK                0x0300  
#define WM831X_DC3_SLP_MODE_SHIFT                    8  
#define WM831X_DC3_SLP_MODE_WIDTH                    2  
#define WM831X_DC3_SLP_VSEL_MASK                0x007F  
#define WM831X_DC3_SLP_VSEL_SHIFT                    0  
#define WM831X_DC3_SLP_VSEL_WIDTH                    7  


#define WM831X_DC4_ERR_ACT_MASK                 0xC000  
#define WM831X_DC4_ERR_ACT_SHIFT                    14  
#define WM831X_DC4_ERR_ACT_WIDTH                     2  
#define WM831X_DC4_HWC_SRC_MASK                 0x1800  
#define WM831X_DC4_HWC_SRC_SHIFT                    11  
#define WM831X_DC4_HWC_SRC_WIDTH                     2  
#define WM831X_DC4_HWC_MODE                     0x0100  
#define WM831X_DC4_HWC_MODE_MASK                0x0100  
#define WM831X_DC4_HWC_MODE_SHIFT                    8  
#define WM831X_DC4_HWC_MODE_WIDTH                    1  
#define WM831X_DC4_RANGE_MASK                   0x000C  
#define WM831X_DC4_RANGE_SHIFT                       2  
#define WM831X_DC4_RANGE_WIDTH                       2  
#define WM831X_DC4_FBSRC                        0x0001  
#define WM831X_DC4_FBSRC_MASK                   0x0001  
#define WM831X_DC4_FBSRC_SHIFT                       0  
#define WM831X_DC4_FBSRC_WIDTH                       1  


#define WM831X_DC4_SLPENA                       0x0100  
#define WM831X_DC4_SLPENA_MASK                  0x0100  
#define WM831X_DC4_SLPENA_SHIFT                      8  
#define WM831X_DC4_SLPENA_WIDTH                      1  


#define WM831X_LDO1_ERR_ACT_MASK                0xC000  
#define WM831X_LDO1_ERR_ACT_SHIFT                   14  
#define WM831X_LDO1_ERR_ACT_WIDTH                    2  
#define WM831X_LDO1_HWC_SRC_MASK                0x1800  
#define WM831X_LDO1_HWC_SRC_SHIFT                   11  
#define WM831X_LDO1_HWC_SRC_WIDTH                    2  
#define WM831X_LDO1_HWC_VSEL                    0x0400  
#define WM831X_LDO1_HWC_VSEL_MASK               0x0400  
#define WM831X_LDO1_HWC_VSEL_SHIFT                  10  
#define WM831X_LDO1_HWC_VSEL_WIDTH                   1  
#define WM831X_LDO1_HWC_MODE_MASK               0x0300  
#define WM831X_LDO1_HWC_MODE_SHIFT                   8  
#define WM831X_LDO1_HWC_MODE_WIDTH                   2  
#define WM831X_LDO1_FLT                         0x0080  
#define WM831X_LDO1_FLT_MASK                    0x0080  
#define WM831X_LDO1_FLT_SHIFT                        7  
#define WM831X_LDO1_FLT_WIDTH                        1  
#define WM831X_LDO1_SWI                         0x0040  
#define WM831X_LDO1_SWI_MASK                    0x0040  
#define WM831X_LDO1_SWI_SHIFT                        6  
#define WM831X_LDO1_SWI_WIDTH                        1  
#define WM831X_LDO1_LP_MODE                     0x0001  
#define WM831X_LDO1_LP_MODE_MASK                0x0001  
#define WM831X_LDO1_LP_MODE_SHIFT                    0  
#define WM831X_LDO1_LP_MODE_WIDTH                    1  


#define WM831X_LDO1_ON_SLOT_MASK                0xE000  
#define WM831X_LDO1_ON_SLOT_SHIFT                   13  
#define WM831X_LDO1_ON_SLOT_WIDTH                    3  
#define WM831X_LDO1_ON_MODE                     0x0100  
#define WM831X_LDO1_ON_MODE_MASK                0x0100  
#define WM831X_LDO1_ON_MODE_SHIFT                    8  
#define WM831X_LDO1_ON_MODE_WIDTH                    1  
#define WM831X_LDO1_ON_VSEL_MASK                0x001F  
#define WM831X_LDO1_ON_VSEL_SHIFT                    0  
#define WM831X_LDO1_ON_VSEL_WIDTH                    5  


#define WM831X_LDO1_SLP_SLOT_MASK               0xE000  
#define WM831X_LDO1_SLP_SLOT_SHIFT                  13  
#define WM831X_LDO1_SLP_SLOT_WIDTH                   3  
#define WM831X_LDO1_SLP_MODE                    0x0100  
#define WM831X_LDO1_SLP_MODE_MASK               0x0100  
#define WM831X_LDO1_SLP_MODE_SHIFT                   8  
#define WM831X_LDO1_SLP_MODE_WIDTH                   1  
#define WM831X_LDO1_SLP_VSEL_MASK               0x001F  
#define WM831X_LDO1_SLP_VSEL_SHIFT                   0  
#define WM831X_LDO1_SLP_VSEL_WIDTH                   5  


#define WM831X_LDO2_ERR_ACT_MASK                0xC000  
#define WM831X_LDO2_ERR_ACT_SHIFT                   14  
#define WM831X_LDO2_ERR_ACT_WIDTH                    2  
#define WM831X_LDO2_HWC_SRC_MASK                0x1800  
#define WM831X_LDO2_HWC_SRC_SHIFT                   11  
#define WM831X_LDO2_HWC_SRC_WIDTH                    2  
#define WM831X_LDO2_HWC_VSEL                    0x0400  
#define WM831X_LDO2_HWC_VSEL_MASK               0x0400  
#define WM831X_LDO2_HWC_VSEL_SHIFT                  10  
#define WM831X_LDO2_HWC_VSEL_WIDTH                   1  
#define WM831X_LDO2_HWC_MODE_MASK               0x0300  
#define WM831X_LDO2_HWC_MODE_SHIFT                   8  
#define WM831X_LDO2_HWC_MODE_WIDTH                   2  
#define WM831X_LDO2_FLT                         0x0080  
#define WM831X_LDO2_FLT_MASK                    0x0080  
#define WM831X_LDO2_FLT_SHIFT                        7  
#define WM831X_LDO2_FLT_WIDTH                        1  
#define WM831X_LDO2_SWI                         0x0040  
#define WM831X_LDO2_SWI_MASK                    0x0040  
#define WM831X_LDO2_SWI_SHIFT                        6  
#define WM831X_LDO2_SWI_WIDTH                        1  
#define WM831X_LDO2_LP_MODE                     0x0001  
#define WM831X_LDO2_LP_MODE_MASK                0x0001  
#define WM831X_LDO2_LP_MODE_SHIFT                    0  
#define WM831X_LDO2_LP_MODE_WIDTH                    1  


#define WM831X_LDO2_ON_SLOT_MASK                0xE000  
#define WM831X_LDO2_ON_SLOT_SHIFT                   13  
#define WM831X_LDO2_ON_SLOT_WIDTH                    3  
#define WM831X_LDO2_ON_MODE                     0x0100  
#define WM831X_LDO2_ON_MODE_MASK                0x0100  
#define WM831X_LDO2_ON_MODE_SHIFT                    8  
#define WM831X_LDO2_ON_MODE_WIDTH                    1  
#define WM831X_LDO2_ON_VSEL_MASK                0x001F  
#define WM831X_LDO2_ON_VSEL_SHIFT                    0  
#define WM831X_LDO2_ON_VSEL_WIDTH                    5  


#define WM831X_LDO2_SLP_SLOT_MASK               0xE000  
#define WM831X_LDO2_SLP_SLOT_SHIFT                  13  
#define WM831X_LDO2_SLP_SLOT_WIDTH                   3  
#define WM831X_LDO2_SLP_MODE                    0x0100  
#define WM831X_LDO2_SLP_MODE_MASK               0x0100  
#define WM831X_LDO2_SLP_MODE_SHIFT                   8  
#define WM831X_LDO2_SLP_MODE_WIDTH                   1  
#define WM831X_LDO2_SLP_VSEL_MASK               0x001F  
#define WM831X_LDO2_SLP_VSEL_SHIFT                   0  
#define WM831X_LDO2_SLP_VSEL_WIDTH                   5  


#define WM831X_LDO3_ERR_ACT_MASK                0xC000  
#define WM831X_LDO3_ERR_ACT_SHIFT                   14  
#define WM831X_LDO3_ERR_ACT_WIDTH                    2  
#define WM831X_LDO3_HWC_SRC_MASK                0x1800  
#define WM831X_LDO3_HWC_SRC_SHIFT                   11  
#define WM831X_LDO3_HWC_SRC_WIDTH                    2  
#define WM831X_LDO3_HWC_VSEL                    0x0400  
#define WM831X_LDO3_HWC_VSEL_MASK               0x0400  
#define WM831X_LDO3_HWC_VSEL_SHIFT                  10  
#define WM831X_LDO3_HWC_VSEL_WIDTH                   1  
#define WM831X_LDO3_HWC_MODE_MASK               0x0300  
#define WM831X_LDO3_HWC_MODE_SHIFT                   8  
#define WM831X_LDO3_HWC_MODE_WIDTH                   2  
#define WM831X_LDO3_FLT                         0x0080  
#define WM831X_LDO3_FLT_MASK                    0x0080  
#define WM831X_LDO3_FLT_SHIFT                        7  
#define WM831X_LDO3_FLT_WIDTH                        1  
#define WM831X_LDO3_SWI                         0x0040  
#define WM831X_LDO3_SWI_MASK                    0x0040  
#define WM831X_LDO3_SWI_SHIFT                        6  
#define WM831X_LDO3_SWI_WIDTH                        1  
#define WM831X_LDO3_LP_MODE                     0x0001  
#define WM831X_LDO3_LP_MODE_MASK                0x0001  
#define WM831X_LDO3_LP_MODE_SHIFT                    0  
#define WM831X_LDO3_LP_MODE_WIDTH                    1  


#define WM831X_LDO3_ON_SLOT_MASK                0xE000  
#define WM831X_LDO3_ON_SLOT_SHIFT                   13  
#define WM831X_LDO3_ON_SLOT_WIDTH                    3  
#define WM831X_LDO3_ON_MODE                     0x0100  
#define WM831X_LDO3_ON_MODE_MASK                0x0100  
#define WM831X_LDO3_ON_MODE_SHIFT                    8  
#define WM831X_LDO3_ON_MODE_WIDTH                    1  
#define WM831X_LDO3_ON_VSEL_MASK                0x001F  
#define WM831X_LDO3_ON_VSEL_SHIFT                    0  
#define WM831X_LDO3_ON_VSEL_WIDTH                    5  


#define WM831X_LDO3_SLP_SLOT_MASK               0xE000  
#define WM831X_LDO3_SLP_SLOT_SHIFT                  13  
#define WM831X_LDO3_SLP_SLOT_WIDTH                   3  
#define WM831X_LDO3_SLP_MODE                    0x0100  
#define WM831X_LDO3_SLP_MODE_MASK               0x0100  
#define WM831X_LDO3_SLP_MODE_SHIFT                   8  
#define WM831X_LDO3_SLP_MODE_WIDTH                   1  
#define WM831X_LDO3_SLP_VSEL_MASK               0x001F  
#define WM831X_LDO3_SLP_VSEL_SHIFT                   0  
#define WM831X_LDO3_SLP_VSEL_WIDTH                   5  


#define WM831X_LDO4_ERR_ACT_MASK                0xC000  
#define WM831X_LDO4_ERR_ACT_SHIFT                   14  
#define WM831X_LDO4_ERR_ACT_WIDTH                    2  
#define WM831X_LDO4_HWC_SRC_MASK                0x1800  
#define WM831X_LDO4_HWC_SRC_SHIFT                   11  
#define WM831X_LDO4_HWC_SRC_WIDTH                    2  
#define WM831X_LDO4_HWC_VSEL                    0x0400  
#define WM831X_LDO4_HWC_VSEL_MASK               0x0400  
#define WM831X_LDO4_HWC_VSEL_SHIFT                  10  
#define WM831X_LDO4_HWC_VSEL_WIDTH                   1  
#define WM831X_LDO4_HWC_MODE_MASK               0x0300  
#define WM831X_LDO4_HWC_MODE_SHIFT                   8  
#define WM831X_LDO4_HWC_MODE_WIDTH                   2  
#define WM831X_LDO4_FLT                         0x0080  
#define WM831X_LDO4_FLT_MASK                    0x0080  
#define WM831X_LDO4_FLT_SHIFT                        7  
#define WM831X_LDO4_FLT_WIDTH                        1  
#define WM831X_LDO4_SWI                         0x0040  
#define WM831X_LDO4_SWI_MASK                    0x0040  
#define WM831X_LDO4_SWI_SHIFT                        6  
#define WM831X_LDO4_SWI_WIDTH                        1  
#define WM831X_LDO4_LP_MODE                     0x0001  
#define WM831X_LDO4_LP_MODE_MASK                0x0001  
#define WM831X_LDO4_LP_MODE_SHIFT                    0  
#define WM831X_LDO4_LP_MODE_WIDTH                    1  


#define WM831X_LDO4_ON_SLOT_MASK                0xE000  
#define WM831X_LDO4_ON_SLOT_SHIFT                   13  
#define WM831X_LDO4_ON_SLOT_WIDTH                    3  
#define WM831X_LDO4_ON_MODE                     0x0100  
#define WM831X_LDO4_ON_MODE_MASK                0x0100  
#define WM831X_LDO4_ON_MODE_SHIFT                    8  
#define WM831X_LDO4_ON_MODE_WIDTH                    1  
#define WM831X_LDO4_ON_VSEL_MASK                0x001F  
#define WM831X_LDO4_ON_VSEL_SHIFT                    0  
#define WM831X_LDO4_ON_VSEL_WIDTH                    5  


#define WM831X_LDO4_SLP_SLOT_MASK               0xE000  
#define WM831X_LDO4_SLP_SLOT_SHIFT                  13  
#define WM831X_LDO4_SLP_SLOT_WIDTH                   3  
#define WM831X_LDO4_SLP_MODE                    0x0100  
#define WM831X_LDO4_SLP_MODE_MASK               0x0100  
#define WM831X_LDO4_SLP_MODE_SHIFT                   8  
#define WM831X_LDO4_SLP_MODE_WIDTH                   1  
#define WM831X_LDO4_SLP_VSEL_MASK               0x001F  
#define WM831X_LDO4_SLP_VSEL_SHIFT                   0  
#define WM831X_LDO4_SLP_VSEL_WIDTH                   5  


#define WM831X_LDO5_ERR_ACT_MASK                0xC000  
#define WM831X_LDO5_ERR_ACT_SHIFT                   14  
#define WM831X_LDO5_ERR_ACT_WIDTH                    2  
#define WM831X_LDO5_HWC_SRC_MASK                0x1800  
#define WM831X_LDO5_HWC_SRC_SHIFT                   11  
#define WM831X_LDO5_HWC_SRC_WIDTH                    2  
#define WM831X_LDO5_HWC_VSEL                    0x0400  
#define WM831X_LDO5_HWC_VSEL_MASK               0x0400  
#define WM831X_LDO5_HWC_VSEL_SHIFT                  10  
#define WM831X_LDO5_HWC_VSEL_WIDTH                   1  
#define WM831X_LDO5_HWC_MODE_MASK               0x0300  
#define WM831X_LDO5_HWC_MODE_SHIFT                   8  
#define WM831X_LDO5_HWC_MODE_WIDTH                   2  
#define WM831X_LDO5_FLT                         0x0080  
#define WM831X_LDO5_FLT_MASK                    0x0080  
#define WM831X_LDO5_FLT_SHIFT                        7  
#define WM831X_LDO5_FLT_WIDTH                        1  
#define WM831X_LDO5_SWI                         0x0040  
#define WM831X_LDO5_SWI_MASK                    0x0040  
#define WM831X_LDO5_SWI_SHIFT                        6  
#define WM831X_LDO5_SWI_WIDTH                        1  
#define WM831X_LDO5_LP_MODE                     0x0001  
#define WM831X_LDO5_LP_MODE_MASK                0x0001  
#define WM831X_LDO5_LP_MODE_SHIFT                    0  
#define WM831X_LDO5_LP_MODE_WIDTH                    1  


#define WM831X_LDO5_ON_SLOT_MASK                0xE000  
#define WM831X_LDO5_ON_SLOT_SHIFT                   13  
#define WM831X_LDO5_ON_SLOT_WIDTH                    3  
#define WM831X_LDO5_ON_MODE                     0x0100  
#define WM831X_LDO5_ON_MODE_MASK                0x0100  
#define WM831X_LDO5_ON_MODE_SHIFT                    8  
#define WM831X_LDO5_ON_MODE_WIDTH                    1  
#define WM831X_LDO5_ON_VSEL_MASK                0x001F  
#define WM831X_LDO5_ON_VSEL_SHIFT                    0  
#define WM831X_LDO5_ON_VSEL_WIDTH                    5  


#define WM831X_LDO5_SLP_SLOT_MASK               0xE000  
#define WM831X_LDO5_SLP_SLOT_SHIFT                  13  
#define WM831X_LDO5_SLP_SLOT_WIDTH                   3  
#define WM831X_LDO5_SLP_MODE                    0x0100  
#define WM831X_LDO5_SLP_MODE_MASK               0x0100  
#define WM831X_LDO5_SLP_MODE_SHIFT                   8  
#define WM831X_LDO5_SLP_MODE_WIDTH                   1  
#define WM831X_LDO5_SLP_VSEL_MASK               0x001F  
#define WM831X_LDO5_SLP_VSEL_SHIFT                   0  
#define WM831X_LDO5_SLP_VSEL_WIDTH                   5  


#define WM831X_LDO6_ERR_ACT_MASK                0xC000  
#define WM831X_LDO6_ERR_ACT_SHIFT                   14  
#define WM831X_LDO6_ERR_ACT_WIDTH                    2  
#define WM831X_LDO6_HWC_SRC_MASK                0x1800  
#define WM831X_LDO6_HWC_SRC_SHIFT                   11  
#define WM831X_LDO6_HWC_SRC_WIDTH                    2  
#define WM831X_LDO6_HWC_VSEL                    0x0400  
#define WM831X_LDO6_HWC_VSEL_MASK               0x0400  
#define WM831X_LDO6_HWC_VSEL_SHIFT                  10  
#define WM831X_LDO6_HWC_VSEL_WIDTH                   1  
#define WM831X_LDO6_HWC_MODE_MASK               0x0300  
#define WM831X_LDO6_HWC_MODE_SHIFT                   8  
#define WM831X_LDO6_HWC_MODE_WIDTH                   2  
#define WM831X_LDO6_FLT                         0x0080  
#define WM831X_LDO6_FLT_MASK                    0x0080  
#define WM831X_LDO6_FLT_SHIFT                        7  
#define WM831X_LDO6_FLT_WIDTH                        1  
#define WM831X_LDO6_SWI                         0x0040  
#define WM831X_LDO6_SWI_MASK                    0x0040  
#define WM831X_LDO6_SWI_SHIFT                        6  
#define WM831X_LDO6_SWI_WIDTH                        1  
#define WM831X_LDO6_LP_MODE                     0x0001  
#define WM831X_LDO6_LP_MODE_MASK                0x0001  
#define WM831X_LDO6_LP_MODE_SHIFT                    0  
#define WM831X_LDO6_LP_MODE_WIDTH                    1  


#define WM831X_LDO6_ON_SLOT_MASK                0xE000  
#define WM831X_LDO6_ON_SLOT_SHIFT                   13  
#define WM831X_LDO6_ON_SLOT_WIDTH                    3  
#define WM831X_LDO6_ON_MODE                     0x0100  
#define WM831X_LDO6_ON_MODE_MASK                0x0100  
#define WM831X_LDO6_ON_MODE_SHIFT                    8  
#define WM831X_LDO6_ON_MODE_WIDTH                    1  
#define WM831X_LDO6_ON_VSEL_MASK                0x001F  
#define WM831X_LDO6_ON_VSEL_SHIFT                    0  
#define WM831X_LDO6_ON_VSEL_WIDTH                    5  


#define WM831X_LDO6_SLP_SLOT_MASK               0xE000  
#define WM831X_LDO6_SLP_SLOT_SHIFT                  13  
#define WM831X_LDO6_SLP_SLOT_WIDTH                   3  
#define WM831X_LDO6_SLP_MODE                    0x0100  
#define WM831X_LDO6_SLP_MODE_MASK               0x0100  
#define WM831X_LDO6_SLP_MODE_SHIFT                   8  
#define WM831X_LDO6_SLP_MODE_WIDTH                   1  
#define WM831X_LDO6_SLP_VSEL_MASK               0x001F  
#define WM831X_LDO6_SLP_VSEL_SHIFT                   0  
#define WM831X_LDO6_SLP_VSEL_WIDTH                   5  


#define WM831X_LDO7_ERR_ACT_MASK                0xC000  
#define WM831X_LDO7_ERR_ACT_SHIFT                   14  
#define WM831X_LDO7_ERR_ACT_WIDTH                    2  
#define WM831X_LDO7_HWC_SRC_MASK                0x1800  
#define WM831X_LDO7_HWC_SRC_SHIFT                   11  
#define WM831X_LDO7_HWC_SRC_WIDTH                    2  
#define WM831X_LDO7_HWC_VSEL                    0x0400  
#define WM831X_LDO7_HWC_VSEL_MASK               0x0400  
#define WM831X_LDO7_HWC_VSEL_SHIFT                  10  
#define WM831X_LDO7_HWC_VSEL_WIDTH                   1  
#define WM831X_LDO7_HWC_MODE_MASK               0x0300  
#define WM831X_LDO7_HWC_MODE_SHIFT                   8  
#define WM831X_LDO7_HWC_MODE_WIDTH                   2  
#define WM831X_LDO7_FLT                         0x0080  
#define WM831X_LDO7_FLT_MASK                    0x0080  
#define WM831X_LDO7_FLT_SHIFT                        7  
#define WM831X_LDO7_FLT_WIDTH                        1  
#define WM831X_LDO7_SWI                         0x0040  
#define WM831X_LDO7_SWI_MASK                    0x0040  
#define WM831X_LDO7_SWI_SHIFT                        6  
#define WM831X_LDO7_SWI_WIDTH                        1  


#define WM831X_LDO7_ON_SLOT_MASK                0xE000  
#define WM831X_LDO7_ON_SLOT_SHIFT                   13  
#define WM831X_LDO7_ON_SLOT_WIDTH                    3  
#define WM831X_LDO7_ON_MODE                     0x0100  
#define WM831X_LDO7_ON_MODE_MASK                0x0100  
#define WM831X_LDO7_ON_MODE_SHIFT                    8  
#define WM831X_LDO7_ON_MODE_WIDTH                    1  
#define WM831X_LDO7_ON_VSEL_MASK                0x001F  
#define WM831X_LDO7_ON_VSEL_SHIFT                    0  
#define WM831X_LDO7_ON_VSEL_WIDTH                    5  


#define WM831X_LDO7_SLP_SLOT_MASK               0xE000  
#define WM831X_LDO7_SLP_SLOT_SHIFT                  13  
#define WM831X_LDO7_SLP_SLOT_WIDTH                   3  
#define WM831X_LDO7_SLP_MODE                    0x0100  
#define WM831X_LDO7_SLP_MODE_MASK               0x0100  
#define WM831X_LDO7_SLP_MODE_SHIFT                   8  
#define WM831X_LDO7_SLP_MODE_WIDTH                   1  
#define WM831X_LDO7_SLP_VSEL_MASK               0x001F  
#define WM831X_LDO7_SLP_VSEL_SHIFT                   0  
#define WM831X_LDO7_SLP_VSEL_WIDTH                   5  


#define WM831X_LDO8_ERR_ACT_MASK                0xC000  
#define WM831X_LDO8_ERR_ACT_SHIFT                   14  
#define WM831X_LDO8_ERR_ACT_WIDTH                    2  
#define WM831X_LDO8_HWC_SRC_MASK                0x1800  
#define WM831X_LDO8_HWC_SRC_SHIFT                   11  
#define WM831X_LDO8_HWC_SRC_WIDTH                    2  
#define WM831X_LDO8_HWC_VSEL                    0x0400  
#define WM831X_LDO8_HWC_VSEL_MASK               0x0400  
#define WM831X_LDO8_HWC_VSEL_SHIFT                  10  
#define WM831X_LDO8_HWC_VSEL_WIDTH                   1  
#define WM831X_LDO8_HWC_MODE_MASK               0x0300  
#define WM831X_LDO8_HWC_MODE_SHIFT                   8  
#define WM831X_LDO8_HWC_MODE_WIDTH                   2  
#define WM831X_LDO8_FLT                         0x0080  
#define WM831X_LDO8_FLT_MASK                    0x0080  
#define WM831X_LDO8_FLT_SHIFT                        7  
#define WM831X_LDO8_FLT_WIDTH                        1  
#define WM831X_LDO8_SWI                         0x0040  
#define WM831X_LDO8_SWI_MASK                    0x0040  
#define WM831X_LDO8_SWI_SHIFT                        6  
#define WM831X_LDO8_SWI_WIDTH                        1  


#define WM831X_LDO8_ON_SLOT_MASK                0xE000  
#define WM831X_LDO8_ON_SLOT_SHIFT                   13  
#define WM831X_LDO8_ON_SLOT_WIDTH                    3  
#define WM831X_LDO8_ON_MODE                     0x0100  
#define WM831X_LDO8_ON_MODE_MASK                0x0100  
#define WM831X_LDO8_ON_MODE_SHIFT                    8  
#define WM831X_LDO8_ON_MODE_WIDTH                    1  
#define WM831X_LDO8_ON_VSEL_MASK                0x001F  
#define WM831X_LDO8_ON_VSEL_SHIFT                    0  
#define WM831X_LDO8_ON_VSEL_WIDTH                    5  


#define WM831X_LDO8_SLP_SLOT_MASK               0xE000  
#define WM831X_LDO8_SLP_SLOT_SHIFT                  13  
#define WM831X_LDO8_SLP_SLOT_WIDTH                   3  
#define WM831X_LDO8_SLP_MODE                    0x0100  
#define WM831X_LDO8_SLP_MODE_MASK               0x0100  
#define WM831X_LDO8_SLP_MODE_SHIFT                   8  
#define WM831X_LDO8_SLP_MODE_WIDTH                   1  
#define WM831X_LDO8_SLP_VSEL_MASK               0x001F  
#define WM831X_LDO8_SLP_VSEL_SHIFT                   0  
#define WM831X_LDO8_SLP_VSEL_WIDTH                   5  


#define WM831X_LDO9_ERR_ACT_MASK                0xC000  
#define WM831X_LDO9_ERR_ACT_SHIFT                   14  
#define WM831X_LDO9_ERR_ACT_WIDTH                    2  
#define WM831X_LDO9_HWC_SRC_MASK                0x1800  
#define WM831X_LDO9_HWC_SRC_SHIFT                   11  
#define WM831X_LDO9_HWC_SRC_WIDTH                    2  
#define WM831X_LDO9_HWC_VSEL                    0x0400  
#define WM831X_LDO9_HWC_VSEL_MASK               0x0400  
#define WM831X_LDO9_HWC_VSEL_SHIFT                  10  
#define WM831X_LDO9_HWC_VSEL_WIDTH                   1  
#define WM831X_LDO9_HWC_MODE_MASK               0x0300  
#define WM831X_LDO9_HWC_MODE_SHIFT                   8  
#define WM831X_LDO9_HWC_MODE_WIDTH                   2  
#define WM831X_LDO9_FLT                         0x0080  
#define WM831X_LDO9_FLT_MASK                    0x0080  
#define WM831X_LDO9_FLT_SHIFT                        7  
#define WM831X_LDO9_FLT_WIDTH                        1  
#define WM831X_LDO9_SWI                         0x0040  
#define WM831X_LDO9_SWI_MASK                    0x0040  
#define WM831X_LDO9_SWI_SHIFT                        6  
#define WM831X_LDO9_SWI_WIDTH                        1  


#define WM831X_LDO9_ON_SLOT_MASK                0xE000  
#define WM831X_LDO9_ON_SLOT_SHIFT                   13  
#define WM831X_LDO9_ON_SLOT_WIDTH                    3  
#define WM831X_LDO9_ON_MODE                     0x0100  
#define WM831X_LDO9_ON_MODE_MASK                0x0100  
#define WM831X_LDO9_ON_MODE_SHIFT                    8  
#define WM831X_LDO9_ON_MODE_WIDTH                    1  
#define WM831X_LDO9_ON_VSEL_MASK                0x001F  
#define WM831X_LDO9_ON_VSEL_SHIFT                    0  
#define WM831X_LDO9_ON_VSEL_WIDTH                    5  


#define WM831X_LDO9_SLP_SLOT_MASK               0xE000  
#define WM831X_LDO9_SLP_SLOT_SHIFT                  13  
#define WM831X_LDO9_SLP_SLOT_WIDTH                   3  
#define WM831X_LDO9_SLP_MODE                    0x0100  
#define WM831X_LDO9_SLP_MODE_MASK               0x0100  
#define WM831X_LDO9_SLP_MODE_SHIFT                   8  
#define WM831X_LDO9_SLP_MODE_WIDTH                   1  
#define WM831X_LDO9_SLP_VSEL_MASK               0x001F  
#define WM831X_LDO9_SLP_VSEL_SHIFT                   0  
#define WM831X_LDO9_SLP_VSEL_WIDTH                   5  


#define WM831X_LDO10_ERR_ACT_MASK               0xC000  
#define WM831X_LDO10_ERR_ACT_SHIFT                  14  
#define WM831X_LDO10_ERR_ACT_WIDTH                   2  
#define WM831X_LDO10_HWC_SRC_MASK               0x1800  
#define WM831X_LDO10_HWC_SRC_SHIFT                  11  
#define WM831X_LDO10_HWC_SRC_WIDTH                   2  
#define WM831X_LDO10_HWC_VSEL                   0x0400  
#define WM831X_LDO10_HWC_VSEL_MASK              0x0400  
#define WM831X_LDO10_HWC_VSEL_SHIFT                 10  
#define WM831X_LDO10_HWC_VSEL_WIDTH                  1  
#define WM831X_LDO10_HWC_MODE_MASK              0x0300  
#define WM831X_LDO10_HWC_MODE_SHIFT                  8  
#define WM831X_LDO10_HWC_MODE_WIDTH                  2  
#define WM831X_LDO10_FLT                        0x0080  
#define WM831X_LDO10_FLT_MASK                   0x0080  
#define WM831X_LDO10_FLT_SHIFT                       7  
#define WM831X_LDO10_FLT_WIDTH                       1  
#define WM831X_LDO10_SWI                        0x0040  
#define WM831X_LDO10_SWI_MASK                   0x0040  
#define WM831X_LDO10_SWI_SHIFT                       6  
#define WM831X_LDO10_SWI_WIDTH                       1  


#define WM831X_LDO10_ON_SLOT_MASK               0xE000  
#define WM831X_LDO10_ON_SLOT_SHIFT                  13  
#define WM831X_LDO10_ON_SLOT_WIDTH                   3  
#define WM831X_LDO10_ON_MODE                    0x0100  
#define WM831X_LDO10_ON_MODE_MASK               0x0100  
#define WM831X_LDO10_ON_MODE_SHIFT                   8  
#define WM831X_LDO10_ON_MODE_WIDTH                   1  
#define WM831X_LDO10_ON_VSEL_MASK               0x001F  
#define WM831X_LDO10_ON_VSEL_SHIFT                   0  
#define WM831X_LDO10_ON_VSEL_WIDTH                   5  


#define WM831X_LDO10_SLP_SLOT_MASK              0xE000  
#define WM831X_LDO10_SLP_SLOT_SHIFT                 13  
#define WM831X_LDO10_SLP_SLOT_WIDTH                  3  
#define WM831X_LDO10_SLP_MODE                   0x0100  
#define WM831X_LDO10_SLP_MODE_MASK              0x0100  
#define WM831X_LDO10_SLP_MODE_SHIFT                  8  
#define WM831X_LDO10_SLP_MODE_WIDTH                  1  
#define WM831X_LDO10_SLP_VSEL_MASK              0x001F  
#define WM831X_LDO10_SLP_VSEL_SHIFT                  0  
#define WM831X_LDO10_SLP_VSEL_WIDTH                  5  


#define WM831X_LDO11_ON_SLOT_MASK               0xE000  
#define WM831X_LDO11_ON_SLOT_SHIFT                  13  
#define WM831X_LDO11_ON_SLOT_WIDTH                   3  
#define WM831X_LDO11_OFFENA                     0x1000  
#define WM831X_LDO11_OFFENA_MASK                0x1000  
#define WM831X_LDO11_OFFENA_SHIFT                   12  
#define WM831X_LDO11_OFFENA_WIDTH                    1  
#define WM831X_LDO11_VSEL_SRC                   0x0080  
#define WM831X_LDO11_VSEL_SRC_MASK              0x0080  
#define WM831X_LDO11_VSEL_SRC_SHIFT                  7  
#define WM831X_LDO11_VSEL_SRC_WIDTH                  1  
#define WM831X_LDO11_ON_VSEL_MASK               0x000F  
#define WM831X_LDO11_ON_VSEL_SHIFT                   0  
#define WM831X_LDO11_ON_VSEL_WIDTH                   4  


#define WM831X_LDO11_SLP_SLOT_MASK              0xE000  
#define WM831X_LDO11_SLP_SLOT_SHIFT                 13  
#define WM831X_LDO11_SLP_SLOT_WIDTH                  3  
#define WM831X_LDO11_SLP_VSEL_MASK              0x000F  
#define WM831X_LDO11_SLP_VSEL_SHIFT                  0  
#define WM831X_LDO11_SLP_VSEL_WIDTH                  4  


#define WM831X_DC4_OK                           0x0008  
#define WM831X_DC4_OK_MASK                      0x0008  
#define WM831X_DC4_OK_SHIFT                          3  
#define WM831X_DC4_OK_WIDTH                          1  
#define WM831X_DC3_OK                           0x0004  
#define WM831X_DC3_OK_MASK                      0x0004  
#define WM831X_DC3_OK_SHIFT                          2  
#define WM831X_DC3_OK_WIDTH                          1  
#define WM831X_DC2_OK                           0x0002  
#define WM831X_DC2_OK_MASK                      0x0002  
#define WM831X_DC2_OK_SHIFT                          1  
#define WM831X_DC2_OK_WIDTH                          1  
#define WM831X_DC1_OK                           0x0001  
#define WM831X_DC1_OK_MASK                      0x0001  
#define WM831X_DC1_OK_SHIFT                          0  
#define WM831X_DC1_OK_WIDTH                          1  


#define WM831X_LDO10_OK                         0x0200  
#define WM831X_LDO10_OK_MASK                    0x0200  
#define WM831X_LDO10_OK_SHIFT                        9  
#define WM831X_LDO10_OK_WIDTH                        1  
#define WM831X_LDO9_OK                          0x0100  
#define WM831X_LDO9_OK_MASK                     0x0100  
#define WM831X_LDO9_OK_SHIFT                         8  
#define WM831X_LDO9_OK_WIDTH                         1  
#define WM831X_LDO8_OK                          0x0080  
#define WM831X_LDO8_OK_MASK                     0x0080  
#define WM831X_LDO8_OK_SHIFT                         7  
#define WM831X_LDO8_OK_WIDTH                         1  
#define WM831X_LDO7_OK                          0x0040  
#define WM831X_LDO7_OK_MASK                     0x0040  
#define WM831X_LDO7_OK_SHIFT                         6  
#define WM831X_LDO7_OK_WIDTH                         1  
#define WM831X_LDO6_OK                          0x0020  
#define WM831X_LDO6_OK_MASK                     0x0020  
#define WM831X_LDO6_OK_SHIFT                         5  
#define WM831X_LDO6_OK_WIDTH                         1  
#define WM831X_LDO5_OK                          0x0010  
#define WM831X_LDO5_OK_MASK                     0x0010  
#define WM831X_LDO5_OK_SHIFT                         4  
#define WM831X_LDO5_OK_WIDTH                         1  
#define WM831X_LDO4_OK                          0x0008  
#define WM831X_LDO4_OK_MASK                     0x0008  
#define WM831X_LDO4_OK_SHIFT                         3  
#define WM831X_LDO4_OK_WIDTH                         1  
#define WM831X_LDO3_OK                          0x0004  
#define WM831X_LDO3_OK_MASK                     0x0004  
#define WM831X_LDO3_OK_SHIFT                         2  
#define WM831X_LDO3_OK_WIDTH                         1  
#define WM831X_LDO2_OK                          0x0002  
#define WM831X_LDO2_OK_MASK                     0x0002  
#define WM831X_LDO2_OK_SHIFT                         1  
#define WM831X_LDO2_OK_WIDTH                         1  
#define WM831X_LDO1_OK                          0x0001  
#define WM831X_LDO1_OK_MASK                     0x0001  
#define WM831X_LDO1_OK_SHIFT                         0  
#define WM831X_LDO1_OK_WIDTH                         1  

#define WM831X_ISINK_MAX_ISEL 55
extern const unsigned int wm831x_isinkv_values[WM831X_ISINK_MAX_ISEL + 1];

#endif
