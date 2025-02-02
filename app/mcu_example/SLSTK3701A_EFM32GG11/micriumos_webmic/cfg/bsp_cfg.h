/***************************************************************************//**
 * @file
 * @brief
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.
 * The software is governed by the sections of the MSLA applicable to Micrium
 * Software.
 *
 ******************************************************************************/

/*
 *********************************************************************************************************
 *
 *                                         BSP CONFIGURATION
 *
 *                                      CONFIGURATION TEMPLATE FILE
 *
 * Filename      : bsp_cfg.h
 * Programmer(s) : Micrium
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *********************************************************************************************************
 *                                               MODULE
 *********************************************************************************************************
 *********************************************************************************************************
 */

#ifndef  _BSP_CFG_H_
#define  _BSP_CFG_H_

/*
 *********************************************************************************************************
 *********************************************************************************************************
 *                                             INCLUDE FILES
 *********************************************************************************************************
 *********************************************************************************************************
 */

#include  <bsp_opt_def.h>

/*
 *********************************************************************************************************
 *********************************************************************************************************
 *                                     CLOCK CONFIGURATION
 *********************************************************************************************************
 *********************************************************************************************************
 */

#define  BSP_HF_CLK_SEL                                     BSP_HF_CLK_HFXO

#define  BSP_LF_CLK_SEL                                     BSP_LF_CLK_LFXO

/*
 *********************************************************************************************************
 *********************************************************************************************************
 *                                             MODULE END
 *********************************************************************************************************
 *********************************************************************************************************
 */

#endif /* End of bsp_cfg.h module include.                  */
