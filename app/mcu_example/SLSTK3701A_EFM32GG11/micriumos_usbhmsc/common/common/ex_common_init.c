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
*                                          COMMON INIT EXAMPLE
*
* File : ex_common_init.c
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*********************************************************************************************************
*/

#include  <rtos_description.h>

#ifdef  RTOS_MODULE_COMMON_AVAIL

#include  <cpu/include/cpu.h>
#include  <common/include/common.h>
#include  <common/include/auth.h>
#include  <common/include/rtos_err.h>
#include  <common/include/rtos_utils.h>

#include  <rtos_cfg.h>

#ifdef  RTOS_MODULE_COMMON_CLK_AVAIL
#include  <common/include/clk.h>
#endif

#ifdef  RTOS_MODULE_COMMON_SHELL_AVAIL
#include  <common/include/shell.h>
#endif


/*
*********************************************************************************************************
*********************************************************************************************************
*                                          GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           Ex_CommonInit()
*
* Description : Provides example on how to initialize the Common module and how to recover the default
*               configuration structure, if needed.
*
* Argument(s) : None.
*
* Return(s)   : None.
*
* Note(s)     : None.
*********************************************************************************************************
*/

void  Ex_CommonInit (void)
{
    RTOS_ERR  err;


    Common_Init(&err);
    APP_RTOS_ASSERT_CRITICAL(err.Code == RTOS_ERR_NONE, ;);

#ifdef  RTOS_MODULE_COMMON_SHELL_AVAIL
    Shell_Init(&err);
    APP_RTOS_ASSERT_CRITICAL(err.Code == RTOS_ERR_NONE, ;);
#endif

#ifdef  RTOS_MODULE_COMMON_CLK_AVAIL
    Clk_Init(&err);
    APP_RTOS_ASSERT_CRITICAL(err.Code == RTOS_ERR_NONE, ;);
#endif

    Auth_Init(&err);
    APP_RTOS_ASSERT_CRITICAL(err.Code == RTOS_ERR_NONE, ;);
}


#endif  /* RTOS_MODULE_COMMON_AVAIL */
