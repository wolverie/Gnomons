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
* File Name     : debug.c
* Version       : 1.00
* Version       : Applilet4 for RL78/L1C V1.00.00.03 [24 Sep 2013]
* Device(s)     : R5F110PJ
* Tool-Chain    : CA78K0R
* H/W Platform  : RSKRL78L1C
* Description   : Defines  routines and variables for serial port debug.
*******************************************************************************/
/*******************************************************************************
* History       : 08/10/2013  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
* User Includes (Project Level Includes)
*******************************************************************************/
#include <string.h>
#include "r_cg_macrodriver.h"
#include "r_rsk_debug.h"


/*******************************************************************************
* Global Variables
*******************************************************************************/

/******************************************************************************
* Function Name : R_DEBUG_Print
* Description   : Takes a string and sends it to the debug terminal
* Parameters    : dbg_str:  debug string
* Return value  : number of characters sent to terminal
******************************************************************************/
uint16_t R_DEBUG_Print (const char * const dbg_str)
{
    static char  debug_buf[128];

    const size_t n_chs = strlen(dbg_str);

    /* Copy to the global buffer as this will be used in the interrupt */
    strcpy(debug_buf, dbg_str);

    /* Send to the terminal */
    SERIAL_DEBUG_WRITE((uint8_t *)debug_buf, (uint16_t)n_chs);

    return (uint16_t)n_chs;
}

/******************************************************************************
* End of function R_DEBUG_Print
******************************************************************************/

