/***************************************************************************//**
 * @file
 * @brief TFT Display refresh handling
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

#ifndef __TFTDRAW_H
#define __TFTDRAW_H

#include "em_device.h"
#include "glib/glib.h"

#ifdef __cplusplus
extern "C" {
#endif

void TFT_displayUpdate(GLIB_Context_t *gcPtr);

#ifdef __cplusplus
}
#endif

#endif
