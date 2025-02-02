/***************************************************************************//**
 * @file
 * @brief Draws the graphics on the display
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

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DEMO_VERSION "Demo v1.0"

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/
void GRAPHICS_Init(void);
void GRAPHICS_ShowStatus(bool si114x_status, bool si7013_status, bool removeObject, bool lowBat);
void GRAPHICS_Draw(int xoffset, int32_t tempData, uint32_t rhData, uint32_t uvData, int yoffset, bool lowBat);

#ifdef __cplusplus
}
#endif

#endif /* __GRAPHICS_H__ */
