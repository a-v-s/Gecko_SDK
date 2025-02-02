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
*                                       USB DEVICE CONFIGURATION
*
*                                      CONFIGURATION TEMPLATE FILE
*
* File : usbd_cfg.h
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*********************************************************************************************************
*/

#ifndef  _USBD_CFG_H_
#define  _USBD_CFG_H_


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*********************************************************************************************************
*/

#include  <common/include/lib_def.h>


/*
*********************************************************************************************************
*********************************************************************************************************
*                                      OPTIMIZATION CONFIGURATION
*
* Note(s) : (1) USB Device product can be configured to be optimized for speed and determinism or for
*               reduced RAM usage.
*********************************************************************************************************
*********************************************************************************************************
*/

#define  USBD_CFG_OPTIMIZE_SPD                              DEF_DISABLED


/*
*********************************************************************************************************
*********************************************************************************************************
*                                      GENERAL USB CONFIGURATION
*
* Note(s) : (1) If none of the USB device controller is used at High-Speed, USBD_CFG_HS_EN can be set to
*               DEF_DISABLED.
*
*           (2) Microsoft OS descriptors are useful for vendor class as it automates the process of
*               loading the WinUSB driver without having to provide a .inf file.
*
*           (3) Isochronous endpoints must be enabled when using the audio class. Make sure your driver
*               supports isochronous endpoints.
*
*           (4) USB device supports submission of multiple URB when USBD_CFG_URB_EXTRA_EN is set to
*               DEF_ENABLED. Make sure your driver supports URB queuing before setting this to
*               DEF_ENABLED.
*********************************************************************************************************
*********************************************************************************************************
*/

#define  USBD_CFG_HS_EN                                     DEF_DISABLED

#define  USBD_CFG_MS_OS_DESC_EN                             DEF_ENABLED

#define  USBD_CFG_STR_EN                                    DEF_ENABLED

#define  USBD_CFG_EP_ISOC_EN                                DEF_DISABLED

#define  USBD_CFG_URB_EXTRA_EN                              DEF_ENABLED


/*
*********************************************************************************************************
*********************************************************************************************************
*                                      AUDIO CLASS CONFIGURATION
*
* Note(s) : (1) When USBD_AUDIO_CFG_FU_MAX_CTRL_EN is set to DEF_DISABLED, only 'mute' and 'volume'
*               units are kept.
*
*           (2) Audio class must compensate for jitter and clock differences between host and device.
*               This can be done by either enabling the feedback endpoint for playback interfaces
*               (USBD_AUDIO_CFG_PLAYBACK_FEEDBACK_EN) or by enabling software correction
*               (USBD_AUDIO_CFG_PLAYBACK_CORR_EN / USBD_AUDIO_CFG_RECORD_CORR_EN).
*********************************************************************************************************
*********************************************************************************************************
*/

#define  USBD_AUDIO_CFG_PLAYBACK_EN                         DEF_ENABLED

#define  USBD_AUDIO_CFG_RECORD_EN                           DEF_ENABLED

#define  USBD_AUDIO_CFG_FU_MAX_CTRL_EN                      DEF_DISABLED

#define  USBD_AUDIO_CFG_MU_EN                               DEF_DISABLED

#define  USBD_AUDIO_CFG_SU_EN                               DEF_DISABLED

#define  USBD_AUDIO_CFG_PLAYBACK_FEEDBACK_EN                DEF_DISABLED

#define  USBD_AUDIO_CFG_PLAYBACK_CORR_EN                    DEF_ENABLED

#define  USBD_AUDIO_CFG_RECORD_CORR_EN                      DEF_ENABLED

#define  USBD_AUDIO_CFG_STAT_EN                             DEF_DISABLED


/*
*********************************************************************************************************
*********************************************************************************************************
*                                        MSC SCSI CONFIGURATION
*
* Note(s) : (1) Host queries the device periodically to ensure media is still present. Since for some
*               media type the 'StatusGet' operation can take some time (for example, SD cards), it is
*               recommended to use the refresh task.
*********************************************************************************************************
*********************************************************************************************************
*/

#define  USBD_SCSI_CFG_REFRESH_TASK_EN                      DEF_ENABLED

#define  USBD_SCSI_CFG_64_BIT_LBA_EN                        DEF_DISABLED


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*********************************************************************************************************
*/

#endif                                                          /* End of usbd_cfg.h module include.                    */
