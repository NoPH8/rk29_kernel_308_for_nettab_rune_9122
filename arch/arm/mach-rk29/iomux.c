/*
 * arch/arm/mach-rk29/iomux.c
 *
 *Copyright (C) 2010 ROCKCHIP, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <asm/system.h>
#include <asm/io.h>
#include <linux/spinlock.h>

#include <mach/rk29_iomap.h>  
#include <mach/iomux.h>


static struct mux_config rk29_muxs[] = {
/*
 *	 description				mux  mode   mux	  mux  
 *						reg  offset inter mode
 */    
///GPIO0L                                                                             
MUX_CFG(GPIO0B7_EBCGDOE_SMCOEN_NAME,				GPIO0L,   30,    2,	  0,	DEFAULT)    
MUX_CFG(GPIO0B6_EBCSDSHR_SMCBLSN1_HOSTINT_NAME,		GPIO0L,   28,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0B5_EBCVCOM_SMCBLSN0_NAME,		 		GPIO0L,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0B4_EBCBORDER1_SMCWEN_NAME,		 		GPIO0L,   24,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0B3_EBCBORDER0_SMCADDR3_HOSTDATA3_NAME,	GPIO0L,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0B2_EBCSDCE2_SMCADDR2_HOSTDATA2_NAME,	GPIO0L,   20,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0B1_EBCSDCE1_SMCADDR1_HOSTDATA1_NAME,	GPIO0L,   18,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0B0_EBCSDCE0_SMCADDR0_HOSTDATA0_NAME,	GPIO0L,   16,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0A7_MIIMDCLK_NAME,		 				GPIO0L,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0A6_MIIMD_NAME,		 					GPIO0L,   12,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0A5_FLASHDQS_NAME,		 				GPIO0L,   10,    2,	  0,	DEFAULT)
///GPIO0H
MUX_CFG(GPIO0D7_FLASHCSN6_NAME,		 				GPIO0H,   30,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0D6_FLASHCSN5_NAME,		 				GPIO0H,   28,    2,	  0,	DEFAULT)
MUX_CFG(GPIO0D5_FLASHCSN4_NAME,		 				GPIO0H,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0D4_FLASHCSN3_NAME,		 				GPIO0H,   24,    2,	  0,	DEFAULT)  
MUX_CFG(GPIO0D3_FLASHCSN2_NAME,		 				GPIO0H,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0D2_FLASHCSN1_NAME,		 				GPIO0H,   20,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0D1_EBCGDCLK_SMCADDR4_HOSTDATA4_NAME,	GPIO0H,   18,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0D0_EBCSDOE_SMCADVN_NAME,		 		GPIO0H,   16,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0C7_EBCSDCE5_SMCDATA15_NAME,		 	GPIO0H,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0C6_EBCSDCE4_SMCDATA14_NAME,		 	GPIO0H,   12,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0C5_EBCSDCE3_SMCDATA13_NAME,		 	GPIO0H,   10,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO0C4_EBCSDCE2_SMCDATA12_NAME,		 	GPIO0H,   8,	 2,	  0,	DEFAULT)    
MUX_CFG(GPIO0C3_EBCSDCE1_SMCDATA11_NAME,		 	GPIO0H,   6,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO0C2_EBCSDCE0_SMCDATA10_NAME,		 	GPIO0H,   4,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO0C1_EBCGDR1_SMCDATA9_NAME,		 		GPIO0H,   2,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO0C0_EBCGDSP_SMCDATA8_NAME,		 		GPIO0H,   0,     2,	  0,	DEFAULT) 
///GPIO1L
MUX_CFG(GPIO1B7_UART0SOUT_NAME,		 				GPIO1L,   30,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1B6_UART0SIN_NAME,		 				GPIO1L,   28,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1B5_PWM0_NAME,		 					GPIO1L,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1B4_VIPCLKOUT_NAME,		 				GPIO1L,   24,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1B3_VIPDATA3_NAME,		 				GPIO1L,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1B2_VIPDATA2_NAME,		 				GPIO1L,   20,    2,	  0,	DEFAULT)
MUX_CFG(GPIO1B1_VIPDATA1_NAME,		 				GPIO1L,   18,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1B0_VIPDATA0_NAME,		 				GPIO1L,   16,    2,	  0,	DEFAULT)
MUX_CFG(GPIO1A7_I2C1SCL_NAME,		 				GPIO1L,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1A6_I2C1SDA_NAME,		 				GPIO1L,   12,    2,	  0,	DEFAULT)  
MUX_CFG(GPIO1A5_EMMCPWREN_PWM3_NAME,		 		GPIO1L,   10,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1A4_EMMCWRITEPRT_SPI0CS1_NAME,		 	GPIO1L,   8,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO1A3_EMMCDETECTN_SPI1CS1_NAME,		 	GPIO1L,   6,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO1A2_SMCCSN1_NAME,		 				GPIO1L,   4,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO1A1_SMCCSN0_NAME,		 				GPIO1L,   2,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO1A0_FLASHCS7_MDDRTQ_NAME,		 		GPIO1L,   0,     2,	  0,	DEFAULT) 
///GPIO1H
MUX_CFG(GPIO1D7_SDMMC0DATA5_NAME,		 			GPIO1H,   30,    2,	  0,	DEFAULT)
MUX_CFG(GPIO1D6_SDMMC0DATA4_NAME,		 			GPIO1H,   28,    2,	  0,	DEFAULT)    
MUX_CFG(GPIO1D5_SDMMC0DATA3_NAME,		 			GPIO1H,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1D4_SDMMC0DATA2_NAME,		 			GPIO1H,   24,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1D3_SDMMC0DATA1_NAME,		 			GPIO1H,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1D2_SDMMC0DATA0_NAME,		 			GPIO1H,   20,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1D1_SDMMC0CMD_NAME,		 				GPIO1H,   18,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1D0_SDMMC0CLKOUT_NAME,		 			GPIO1H,   16,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1C7_SDMMC1CLKOUT_NAME,		 			GPIO1H,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1C6_SDMMC1DATA3_NAME,		 			GPIO1H,   12,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1C5_SDMMC1DATA2_NAME,		 			GPIO1H,   10,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO1C4_SDMMC1DATA1_NAME,		 			GPIO1H,   8,     2,	  0,	DEFAULT)
MUX_CFG(GPIO1C3_SDMMC1DATA0_NAME,		 			GPIO1H,   6,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO1C2_SDMMC1CMD_NAME,		 				GPIO1H,   4,     2,	  0,	DEFAULT)
MUX_CFG(GPIO1C1_UART0RTSN_SDMMC1WRITEPRT_NAME,		GPIO1H,   2,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO1C0_UART0CTSN_SDMMC1DETECTN_NAME,		GPIO1H,   0,     2,	  0,	DEFAULT)  
///GPIO2L
MUX_CFG(GPIO2B7_I2C0SCL_NAME,		 				GPIO2L,   30,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2B6_I2C0SDA_NAME,		 				GPIO2L,   28,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2B5_UART3RTSN_I2C3SCL_NAME,		 		GPIO2L,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2B4_UART3CTSN_I2C3SDA_NAME,		 		GPIO2L,   24,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2B3_UART3SOUT_NAME,		 				GPIO2L,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2B2_UART3SIN_NAME,		 				GPIO2L,   20,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2B1_UART2SOUT_NAME,		 				GPIO2L,   18,    2,	  0,	DEFAULT)
MUX_CFG(GPIO2B0_UART2SIN_NAME,		 				GPIO2L,   16,    2,	  0,	DEFAULT)    
MUX_CFG(GPIO2A7_UART2RTSN_NAME,		 				GPIO2L,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2A6_UART2CTSN_NAME,		 				GPIO2L,   12,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2A5_UART1SOUT_NAME,		 				GPIO2L,   10,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2A4_UART1SIN_NAME,		 				GPIO2L,   8,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO2A3_SDMMC0WRITEPRT_PWM2_NAME,		 	GPIO2L,   6,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO2A2_SDMMC0DETECTN_NAME,		 			GPIO2L,   4,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO2A1_SDMMC0DATA7_NAME,		 			GPIO2L,   2,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO2A0_SDMMC0DATA6_NAME,		 			GPIO2L,   0,     2,	  0,	DEFAULT) 
///GPIO2H
MUX_CFG(GPIO2D7_I2S0SDO3_MIITXD3_NAME,		 		GPIO2H,   30,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2D6_I2S0SDO2_MIITXD2_NAME,		 		GPIO2H,   28,    2,	  0,	DEFAULT)
MUX_CFG(GPIO2D5_I2S0SDO1_MIIRXD3_NAME,		 		GPIO2H,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2D4_I2S0SDO0_MIIRXD2_NAME,		 		GPIO2H,   24,    2,	  0,	DEFAULT)
MUX_CFG(GPIO2D3_I2S0SDI_MIICOL_NAME,		 		GPIO2H,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2D2_I2S0LRCKRX_MIITXERR_NAME,		 	GPIO2H,   20,    2,	  0,	DEFAULT)  
MUX_CFG(GPIO2D1_I2S0SCLK_MIICRS_NAME,		 		GPIO2H,   18,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2D0_I2S0CLK_MIIRXCLKIN_NAME,		 	GPIO2H,   16,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2C7_SPI1RXD_NAME,		 				GPIO2H,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2C6_SPI1TXD_NAME,		 				GPIO2H,   12,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2C5_SPI1CSN0_NAME,		 				GPIO2H,   10,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO2C4_SPI1CLK_NAME,		 				GPIO2H,   8,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO2C3_SPI0RXD_NAME,		 				GPIO2H,   6,     2,	  0,	DEFAULT)
MUX_CFG(GPIO2C2_SPI0TXD_NAME,		 				GPIO2H,   4,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO2C1_SPI0CSN0_NAME,		 				GPIO2H,   2,     2,	  0,	DEFAULT)
MUX_CFG(GPIO2C0_SPI0CLK_NAME,		 				GPIO2H,   0,     2,	  0,	DEFAULT) 
///GPIO3L
MUX_CFG(GPIO3B7_EMMCDATA5_NAME,		 				GPIO3L,   30,    2,	  0,	DEFAULT)
MUX_CFG(GPIO3B6_EMMCDATA4_NAME,		 				GPIO3L,   28,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3B5_EMMCDATA3_NAME,		 				GPIO3L,   26,    2,	  0,	DEFAULT)  
MUX_CFG(GPIO3B4_EMMCDATA2_NAME,		 				GPIO3L,   24,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3B3_EMMCDATA1_NAME,		 				GPIO3L,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3B2_EMMCDATA0_NAME,		 				GPIO3L,   20,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3B1_EMMCMD_NAME,		 				GPIO3L,   18,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3B0_EMMCLKOUT_NAME,		 				GPIO3L,   16,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3A7_SMCADDR15_HOSTDATA15_NAME,		 	GPIO3L,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3A6_SMCADDR14_HOSTDATA14_NAME,		 	GPIO3L,   12,    2,	  0,	DEFAULT)
MUX_CFG(GPIO3A5_I2S1LRCKTX_NAME,		 			GPIO3L,   10,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3A4_I2S1SDO_NAME,		 				GPIO3L,   8,    2,	  0,	DEFAULT)
MUX_CFG(GPIO3A3_I2S1SDI_NAME,		 				GPIO3L,   6,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3A2_I2S1LRCKRX_NAME,		 			GPIO3L,   4,    2,	  0,	DEFAULT)
MUX_CFG(GPIO3A1_I2S1SCLK_NAME,		 				GPIO3L,   2,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3A0_I2S1CLK_NAME,		 				GPIO3L,   0,    2,	  0,	DEFAULT)  
///GPIO3H
MUX_CFG(GPIO3D7_SMCADDR9_HOSTDATA9_NAME,		 	GPIO3H,   30,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3D6_SMCADDR8_HOSTDATA8_NAME,		 	GPIO3H,   28,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3D5_SMCADDR7_HOSTDATA7_NAME,		 	GPIO3H,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3D4_HOSTWRN_NAME,		 				GPIO3H,   24,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3D3_HOSTRDN_NAME,		 				GPIO3H,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3D2_HOSTCSN_NAME,		 				GPIO3H,   20,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3D1_SMCADDR19_HOSTADDR1_NAME,		 	GPIO3H,   18,    2,	  0,	DEFAULT)
MUX_CFG(GPIO3D0_SMCADDR18_HOSTADDR0_NAME,		 	GPIO3H,   16,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3C7_SMCADDR17_HOSTDATA17_NAME,		 	GPIO3H,   14,    2,	  0,	DEFAULT)
MUX_CFG(GPIO3C6_SMCADDR16_HOSTDATA16_NAME,		 	GPIO3H,   12,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO3C5_SMCADDR12_HOSTDATA12_NAME,		 	GPIO3H,   10,    2,	  0,	DEFAULT)
MUX_CFG(GPIO3C4_SMCADDR11_HOSTDATA11_NAME,		 	GPIO3H,   8,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO3C3_SMCADDR10_HOSTDATA10_NAME,		 	GPIO3H,   6,     2,	  0,	DEFAULT)  
MUX_CFG(GPIO3C2_SMCADDR13_HOSTDATA13_NAME,		 	GPIO3H,   4,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO3C1_EMMCDATA7_NAME,		 				GPIO3H,   2,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO3C0_EMMCDATA6_NAME,		 				GPIO3H,   0,     2,	  0,	DEFAULT) 
///GPIO4L
MUX_CFG(GPIO4B7_FLASHDATA15_NAME,		 			GPIO4L,   30,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4B6_FLASHDATA14_NAME,		 			GPIO4L,   28,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4B5_FLASHDATA13_NAME,		 			GPIO4L,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4B4_FLASHDATA12_NAME,		 			GPIO4L,   24,    2,	  0,	DEFAULT)
MUX_CFG(GPIO4B3_FLASHDATA11_NAME,		 			GPIO4L,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4B2_FLASHDATA10_NAME,		 			GPIO4L,   20,    2,	  0,	DEFAULT)
MUX_CFG(GPIO4B1_FLASHDATA9_NAME,		 			GPIO4L,   18,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4B0_FLASHDATA8_NAME,		 			GPIO4L,   16,    2,	  0,	DEFAULT)
MUX_CFG(GPIO4A7_SPDIFTX_NAME,		 				GPIO4L,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4A6_OTG1DRVVBUS_NAME,		 			GPIO4L,   12,    2,	  0,	DEFAULT)  
MUX_CFG(GPIO4A5_OTG0DRVVBUS_NAME,		 			GPIO4L,   10,    2,	  0,	DEFAULT) 
///GPIO4H                                            		  
MUX_CFG(GPIO4D7_I2S0LRCKTX1_NAME,		 			GPIO4H,   30,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4D6_I2S0LRCKTX0_NAME,		 			GPIO4H,   28,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4D5_CPUTRACECTL_NAME,		 			GPIO4H,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4D4_CPUTRACECLK_NAME,		 			GPIO4H,   24,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO6C76_CPUTRACEDATA76_NAME,		 		GPIO4H,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO6C54_CPUTRACEDATA54_NAME,		 		GPIO4H,   20,    2,	  0,	DEFAULT)
MUX_CFG(GPIO4D32_CPUTRACEDATA32_NAME,		 		GPIO4H,   18,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4D10_CPUTRACEDATA10_NAME,		 		GPIO4H,   16,    2,	  0,	DEFAULT)
MUX_CFG(GPIO4C7_RMIIRXD0_MIIRXD0_NAME,		 		GPIO4H,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4C6_RMIIRXD1_MIIRXD1_NAME,		 		GPIO4H,   12,    2,	  0,	DEFAULT)
MUX_CFG(GPIO4C5_RMIICSRDVALID_MIIRXDVALID_NAME,		GPIO4H,   10,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO4C4_RMIIRXERR_MIIRXERR_NAME,		 	GPIO4H,   8,     2,	  0,	DEFAULT)  
MUX_CFG(GPIO4C3_RMIITXD0_MIITXD0_NAME,		 		GPIO4H,   6,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO4C2_RMIITXD1_MIITXD1_NAME,		 		GPIO4H,   4,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO4C1_RMIITXEN_MIITXEN_NAME,		 		GPIO4H,   2,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO4C0_RMIICLKOUT_RMIICLKIN_NAME,		 	GPIO4H,   0,     2,	  0,	DEFAULT) 
///GPIO5L
MUX_CFG(GPIO5B7_HSADCCLKOUTGPSCLK_NAME,		 		GPIO5L,   30,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5B6_HSADCDATA9_NAME,		 			GPIO5L,   28,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5B5_HSADCDATA8_NAME,		 			GPIO5L,   26,    2,	  0,	DEFAULT)
MUX_CFG(GPIO5B4_HSADCDATA7_NAME,		 			GPIO5L,   24,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5B3_HSADCDATA6_NAME,		 			GPIO5L,   22,    2,	  0,	DEFAULT)
MUX_CFG(GPIO5B2_HSADCDATA5_NAME,		 			GPIO5L,   20,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5B1_HSADCDATA4_NAME,		 			GPIO5L,   18,    2,	  0,	DEFAULT)
MUX_CFG(GPIO5B0_HSADCDATA3_NAME,		 			GPIO5L,   16,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5A7_HSADCDATA2_NAME,		 			GPIO5L,   14,    2,	  0,	DEFAULT)  
MUX_CFG(GPIO5A6_HSADCDATA1_NAME,		 			GPIO5L,   12,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5A5_HSADCDATA0_NAME,		 			GPIO5L,   10,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5A4_TSSYNC_NAME,		 				GPIO5L,   8,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5A3_MIITXCLKIN_NAME,		 			GPIO5L,   6,    2,	  0,	DEFAULT) 
///GPIO5H                                                     
MUX_CFG(GPIO5D6_SDMMC1PWREN_NAME,		 			GPIO5H,   28,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5D5_SDMMC0PWREN_NAME,		 			GPIO5H,   26,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5D4_I2C2SCL_NAME,		 				GPIO5H,   24,    2,	  0,	DEFAULT)
MUX_CFG(GPIO5D3_I2C2SDA_NAME,		 				GPIO5H,   22,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5D2_PWM1_UART1SIRIN_NAME,		 		GPIO5H,   20,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5D1_EBCSDCLK_SMCADDR6_HOSTDATA6_NAME,	GPIO5H,   18,    2,	  0,	DEFAULT)
MUX_CFG(GPIO5D0_EBCSDLE_SMCADDR5_HOSTDATA5_NAME,	GPIO5H,   16,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5C7_EBCSDDO7_SMCDATA7_NAME,		 		GPIO5H,   14,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5C6_EBCSDDO6_SMCDATA6_NAME,		 		GPIO5H,   12,    2,	  0,	DEFAULT)
MUX_CFG(GPIO5C5_EBCSDDO5_SMCDATA5_NAME,		 		GPIO5H,   10,    2,	  0,	DEFAULT) 
MUX_CFG(GPIO5C4_EBCSDDO4_SMCDATA4_NAME,		 		GPIO5H,   8,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO5C3_EBCSDDO3_SMCDATA3_NAME,		 		GPIO5H,   6,     2,	  0,	DEFAULT)
MUX_CFG(GPIO5C2_EBCSDDO2_SMCDATA2_NAME,		 		GPIO5H,   4,     2,	  0,	DEFAULT) 
MUX_CFG(GPIO5C1_EBCSDDO1_SMCDATA1_NAME,		 		GPIO5H,   2,     2,	  0,	DEFAULT)
MUX_CFG(GPIO5C0_EBCSDDO0_SMCDATA0_NAME,		 		GPIO5H,   0,     2,	  0,	DEFAULT) 
};     


void rk29_mux_set(struct mux_config *cfg)
{
	int regValue;
	int mask;
	
	mask = ((1<<(cfg->interleave))-1)<<cfg->offset;
	regValue = readl(cfg->mux_reg);
	regValue &= ~mask;
	regValue |= (cfg->mode<<cfg->offset);
	#ifdef DEBUG_LHH
	printk("%s::regValue is %x,mask is %x\n",__FUNCTION__,regValue,mask);
	#endif
	writel(regValue,cfg->mux_reg);
	
	return;
}

int rk29_iomux_init(void)
{
	int i;
	for(i=0;i<ARRAY_SIZE(rk29_muxs);i++)
	{
		if(rk29_muxs[i].flags != DEFAULT)
			rk29_mux_set(&rk29_muxs[i]);	
	}

#ifdef CONFIG_UART0_RK29
	rk29_mux_api_set(GPIO1B7_UART0SOUT_NAME, GPIO1L_UART0_SOUT);
	rk29_mux_api_set(GPIO1B6_UART0SIN_NAME, GPIO1L_UART0_SIN);
#ifdef CONFIG_UART0_CTS_RTS_RK29
	rk29_mux_api_set(GPIO1C1_UART0RTSN_SDMMC1WRITEPRT_NAME, GPIO1H_UART0_RTS_N);
	rk29_mux_api_set(GPIO1C0_UART0CTSN_SDMMC1DETECTN_NAME, GPIO1H_UART0_CTS_N);
#endif
#endif
#ifdef CONFIG_UART1_RK29
	rk29_mux_api_set(GPIO2A5_UART1SOUT_NAME, GPIO2L_UART1_SOUT);
	rk29_mux_api_set(GPIO2A4_UART1SIN_NAME, GPIO2L_UART1_SIN);
#endif
#ifdef CONFIG_UART2_RK29
	rk29_mux_api_set(GPIO2B1_UART2SOUT_NAME, GPIO2L_UART2_SOUT);
	rk29_mux_api_set(GPIO2B0_UART2SIN_NAME, GPIO2L_UART2_SIN);
#ifdef CONFIG_UART2_CTS_RTS_RK29
	rk29_mux_api_set(GPIO2A7_UART2RTSN_NAME, GPIO2L_UART2_RTS_N);
	rk29_mux_api_set(GPIO2A6_UART2CTSN_NAME, GPIO2L_UART2_CTS_N);
#endif
#endif
#ifdef CONFIG_UART3_RK29
	rk29_mux_api_set(GPIO2B3_UART3SOUT_NAME, GPIO2L_UART3_SOUT);
	rk29_mux_api_set(GPIO2B2_UART3SIN_NAME, GPIO2L_UART3_SIN);
#ifdef CONFIG_UART3_CTS_RTS_RK29
	rk29_mux_api_set(GPIO2B5_UART3RTSN_I2C3SCL_NAME, GPIO2L_UART3_RTS_N);
	rk29_mux_api_set(GPIO2B4_UART3CTSN_I2C3SDA_NAME, GPIO2L_UART3_CTS_N);
#endif
#endif
#ifdef CONFIG_SPIM0_RK29
	rk29_mux_api_set(GPIO2C0_SPI0CLK_NAME, GPIO2H_SPI0_CLK);
	rk29_mux_api_set(GPIO2C1_SPI0CSN0_NAME, GPIO2H_SPI0_CSN0);
	rk29_mux_api_set(GPIO2C2_SPI0TXD_NAME, GPIO2H_SPI0_TXD);
	rk29_mux_api_set(GPIO2C3_SPI0RXD_NAME, GPIO2H_SPI0_RXD);
#endif
#ifdef CONFIG_SPIM1_RK29
	rk29_mux_api_set(GPIO2C4_SPI1CLK_NAME, GPIO2H_SPI1_CLK);
	rk29_mux_api_set(GPIO2C5_SPI1CSN0_NAME, GPIO2H_SPI1_CSN0);
	rk29_mux_api_set(GPIO2C6_SPI1TXD_NAME, GPIO2H_SPI1_TXD);
	rk29_mux_api_set(GPIO2C7_SPI1RXD_NAME, GPIO2H_SPI1_RXD);
#endif
#ifdef CONFIG_RK29_VMAC
	rk29_mux_api_set(GPIO4C0_RMIICLKOUT_RMIICLKIN_NAME, GPIO4H_RMII_CLKOUT);
	rk29_mux_api_set(GPIO4C1_RMIITXEN_MIITXEN_NAME, GPIO4H_RMII_TX_EN);
	rk29_mux_api_set(GPIO4C2_RMIITXD1_MIITXD1_NAME, GPIO4H_RMII_TXD1);
	rk29_mux_api_set(GPIO4C3_RMIITXD0_MIITXD0_NAME, GPIO4H_RMII_TXD0);
	rk29_mux_api_set(GPIO4C4_RMIIRXERR_MIIRXERR_NAME, GPIO4H_RMII_RX_ERR);
	rk29_mux_api_set(GPIO4C5_RMIICSRDVALID_MIIRXDVALID_NAME, GPIO4H_RMII_CSR_DVALID);
	rk29_mux_api_set(GPIO4C6_RMIIRXD1_MIIRXD1_NAME, GPIO4H_RMII_RXD1);
	rk29_mux_api_set(GPIO4C7_RMIIRXD0_MIIRXD0_NAME, GPIO4H_RMII_RXD0);

	rk29_mux_api_set(GPIO0A7_MIIMDCLK_NAME, GPIO0L_MII_MDCLK);
	rk29_mux_api_set(GPIO0A6_MIIMD_NAME, GPIO0L_MII_MD);
#endif

	return 0;
}
EXPORT_SYMBOL(rk29_iomux_init);
/*
 *config iomux : input iomux name and iomux flags
 */ 
void rk29_mux_api_set(char *name, unsigned int mode)
{
	int i;

	if (!name) {
			return;
	}

	for(i=0;i<ARRAY_SIZE(rk29_muxs);i++)
	{
		if (!strcmp(rk29_muxs[i].name, name))
		{
		    rk29_muxs[i].premode = rk29_muxs[i].mode;
			rk29_muxs[i].mode = mode;
			rk29_mux_set(&rk29_muxs[i]);	
			break;			
		}
	}
}
EXPORT_SYMBOL(rk29_mux_api_set);

                                                       
