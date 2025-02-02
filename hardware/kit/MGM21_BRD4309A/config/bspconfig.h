/***************************************************************************//**
 * @file
 * @brief Provide BSP (board support package) configuration parameters.
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef BSPCONFIG_H
#define BSPCONFIG_H

#define BSP_STK
#define BSP_WSTK
#define BSP_WSTK_BRD4309A

#define BSP_BCC_USART         USART0
#define BSP_BCC_USART_INDEX   0
#define BSP_BCC_CLK           cmuClock_USART0
#define BSP_BCC_TXPORT        gpioPortC
#define BSP_BCC_TXPIN         0
#define BSP_BCC_RXPORT        gpioPortC
#define BSP_BCC_RXPIN         1

#define BSP_BCC_ENABLE_PORT   gpioPortD
#define BSP_BCC_ENABLE_PIN    0                 /* VCOM_ENABLE */

#define BSP_EXTFLASH_PRESENT  0

#define BSP_GPIO_LEDS
#define BSP_NO_OF_LEDS          2
#define BSP_GPIO_LED0_PORT      gpioPortA
#define BSP_GPIO_LED0_PIN       4
#define BSP_GPIO_LED1_PORT      gpioPortD
#define BSP_GPIO_LED1_PIN       1
#define BSP_GPIO_LEDARRAY_INIT  { { BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN }, { BSP_GPIO_LED1_PORT, BSP_GPIO_LED1_PIN } }

#define BSP_GPIO_BUTTONS
#define BSP_NO_OF_BUTTONS       2
#define BSP_GPIO_PB0_PORT       gpioPortA
#define BSP_GPIO_PB0_PIN        4
#define BSP_GPIO_PB1_PORT       gpioPortD
#define BSP_GPIO_PB1_PIN        1

#define BSP_GPIO_BUTTONARRAY_INIT { { BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN }, { BSP_GPIO_PB1_PORT, BSP_GPIO_PB1_PIN } }

#define BSP_INIT_DEFAULT        0

#define BSP_LFXO_CTUNE          79U
#define BSP_HFXO_CTUNE          133U

#if !defined(CMU_HFXOINIT_WSTK_DEFAULT)
#define CMU_HFXOINIT_WSTK_DEFAULT                  \
  {                                                \
    false,      /* Low-noise mode for EFR32 */     \
    false,      /* deprecated/unused */            \
    false,      /* deprecated/unused */            \
    false,      /* deprecated/unused */            \
    _CMU_HFXOSTARTUPCTRL_CTUNE_DEFAULT,            \
    BSP_HFXO_CTUNE, /* Steady-state CTUNE value */ \
    _CMU_HFXOSTEADYSTATECTRL_REGISH_DEFAULT,       \
    _CMU_HFXOSTARTUPCTRL_IBTRIMXOCORE_DEFAULT,     \
    _CMU_HFXOSTEADYSTATECTRL_IBTRIMXOCORE_DEFAULT, \
    0x0,        /* unused */                       \
    _CMU_HFXOTIMEOUTCTRL_SHUNTOPTTIMEOUT_DEFAULT,  \
    _CMU_HFXOTIMEOUTCTRL_PEAKDETTIMEOUT_DEFAULT,   \
    0x4,        /* Recommended steady timeout */   \
    _CMU_HFXOTIMEOUTCTRL_STARTUPTIMEOUT_DEFAULT,   \
    cmuOscMode_Crystal,                            \
  }
#endif

#if !defined(BSP_LFXOINIT_DEFAULT)
/* LFXO initialization values optimized for the board. */
#define BSP_LFXOINIT_DEFAULT                                                           \
  {                                                                                    \
    2,                            /* CL=12.5 pF which makes gain=2 a good value. */    \
    BSP_LFXO_CTUNE,               /* Optimal CTUNE value to get 32768 Hz. */           \
    cmuLfxoStartupDelay_2KCycles, /* Timeout before oscillation is stable. */          \
    cmuLfxoOscMode_Crystal,       /* Crystal mode */                                   \
    false,                        /* Disable high amplitude mode */                    \
    true,                         /* Enable AGC for automatic amplitude adjustment. */ \
    false,                        /* Disable failure detection in EM4. */              \
    false,                        /* Disable failure detection. */                     \
    false,                        /* LFXO starts on demand. */                         \
    false,                        /* LFXO starts on demand. */                         \
    false                         /* Don't lock registers.  */                         \
  }
#endif

#if !defined(RADIO_PTI_INIT)
#define RADIO_PTI_INIT                                                  \
  {                                                                     \
    RADIO_PTI_MODE_UART,    /* Simplest output mode is UART mode */     \
    1600000,                /* Choose 1.6 MHz for best compatibility */ \
    0,                      /* DOUT location = PC4 */                   \
    gpioPortC,                                                          \
    4,                                                                  \
    0,                      /* DCLK is not wired on this board */       \
    gpioPortA,                                                          \
    0,                                                                  \
    0,                      /* DFRAME location = PC5 */                 \
    gpioPortC,                                                          \
    5,                                                                  \
  }
#endif

#if !defined(RAIL_PTI_CONFIG)
#define RAIL_PTI_CONFIG                                                 \
  {                                                                     \
    RAIL_PTI_MODE_UART,     /* Simplest output mode is UART mode */     \
    1600000,                /* Choose 1.6 MHz for best compatibility */ \
    0,                      /* DOUT location = PC4 */                   \
    gpioPortC,                                                          \
    4,                                                                  \
    0,                      /* DCLK is not wired on this board */       \
    gpioPortA,                                                          \
    0,                                                                  \
    0,                      /* DFRAME location = PC5 */                 \
    gpioPortC,                                                          \
    5,                                                                  \
  }
#endif

#if !defined(RADIO_PA_2P4_INIT)
#define RADIO_PA_2P4_INIT                                    \
  {                                                          \
    PA_SEL_2P4_MP,    /* Power Amplifier mode */             \
    PA_VOLTMODE_VBAT, /* Power Amplifier vPA Voltage mode */ \
    100,              /* Desired output power in dBm * 10 */ \
    0,                /* Output power offset in dBm * 10 */  \
    2,                /* Desired ramp time in us */          \
  }
#endif

#if !defined(RAIL_PA_2P4_CONFIG)
#define RAIL_PA_2P4_CONFIG                                            \
  {                                                                   \
    RAIL_TX_POWER_MODE_2P4_MP, /* Power Amplifier mode */             \
    3300,                      /* Power Amplifier vPA Voltage mode */ \
    2,                         /* Desired ramp time in us */          \
  }
#endif

#if !defined(RAIL_PA_DEFAULT_POWER)
#define RAIL_PA_DEFAULT_POWER 100
#endif

#define BSP_BCP_VERSION 2
#include "bsp_bcp.h"

#endif /* BSPCONFIG_H */
