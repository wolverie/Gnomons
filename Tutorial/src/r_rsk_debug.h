/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*******************************************************************************/
/* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.   */
/*******************************************************************************
* File Name     : r_rsk_debug.h
* Version       : Applilet4 for RL78/L1C V1.00.00.03 [24 Sep 2013]
* Device(s)     : R5F110PJ
* Tool-Chain    : CA78K0R
* H/W Platform  : RSKRL78L1C
* Description   : Provides declarations of functions defined in debug.c
*******************************************************************************/
/*******************************************************************************
* History       : 28/10/2013  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
* Project Includes
*******************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_sci.h"
/*******************************************************************************
* Macro Definitions
*******************************************************************************/

/* Multiple inclusion prevention macro */
#ifndef R_RSK_DEBUG_H
#define R_RSK_DEBUG_H

/* Macro for definition of serial debug transmit function - user edits this */
#define SERIAL_DEBUG_WRITE (R_SCI7_AsyncTransmit)


/*******************************************************************************
* Global Variables
*******************************************************************************/


/*******************************************************************************
* Global Function Prototypes
*******************************************************************************/
/* DebugPrint() function prototype */
uint16_t R_DEBUG_Print(const char * const dbg_str);

/* End of multiple inclusion prevention macro */
#endif

