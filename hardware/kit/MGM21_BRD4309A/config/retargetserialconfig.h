/***************************************************************************//**
 * @file
 * @brief Provide stdio retargeting configuration parameters.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef RETARGETSERIALCONFIG_H
#define RETARGETSERIALCONFIG_H

#include "bsp.h"

/***************************************************************************//**
 *
 * When retargeting serial output the user can choose which peripheral
 * to use as the serial output device. This choice is made by configuring
 * one or more of the following defines: RETARGET_USART0, RETARGET_LEUART0,
 * RETARGET_VCOM.
 *
 * This table shows the supported configurations and the resulting serial
 * output device.
 *
 * +----------------------------------------------------------------------+
 * | Defines                            | Serial Output (Locations)       |
 * |----------------------------------------------------------------------+
 * | None                               | USART0 (Rx PA6, Tx PA5)         |
 * | RETARGET_USART0                    | USART0 (Rx PA6, Tx PA5)         |
 * | RETARGET_VCOM                      | VCOM using USART0               |
 * +----------------------------------------------------------------------+
 *
 * Note that the default configuration is the same as RETARGET_USART0.
 *
 ******************************************************************************/

#if !defined(RETARGET_USART0)
#define RETARGET_USART0    /* Use USART0 by default. */
#endif

#if defined(RETARGET_USART0)
  #define RETARGET_IRQ_NAME    USART0_RX_IRQHandler         /* UART IRQ Handler */
  #define RETARGET_CLK         cmuClock_USART0              /* HFPER Clock */
  #define RETARGET_IRQn        USART0_RX_IRQn               /* IRQ number */
  #define RETARGET_UART        USART0                       /* UART instance */
  #define RETARGET_UART_INDEX  0                            /* UART instance number */
  #define RETARGET_TX          USART_Tx                     /* Set TX to USART_Tx */
  #define RETARGET_RX          USART_Rx                     /* Set RX to USART_Rx */
  #define RETARGET_TXPORT      gpioPortC                    /* UART transmission port */
  #define RETARGET_TXPIN       0                            /* UART transmission pin */
  #define RETARGET_RXPORT      gpioPortC                    /* UART reception port */
  #define RETARGET_RXPIN       1                            /* UART reception pin */
  #define RETARGET_USART       1                            /* Includes em_usart.h */
#else
#error "Illegal USART selection."
#endif

#if defined(RETARGET_VCOM)
  #define RETARGET_PERIPHERAL_ENABLE() \
  GPIO_PinModeSet(BSP_BCC_ENABLE_PORT, BSP_BCC_ENABLE_PIN, gpioModePushPull, 1);
#else
  #define RETARGET_PERIPHERAL_ENABLE()
#endif

#endif
