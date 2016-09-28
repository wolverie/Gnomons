/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2013, 2014 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_cmt_user.c
* Version      : Code Generator for RX64M V1.00.01.01 [09 May 2014]
* Device(s)    : R5F564MLCxFC
* Tool-Chain   : CCRX
* Description  : This file implements device driver for CMT module.
* Creation Date: 19/06/2014
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cmt.h"
/* Start user code for include. Do not edit comment generated here */
/* Defines switch callback functions required by interrupt handlers */
#include "r_rsk_switch.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
static volatile uint8_t one_ms_delay_complete = FALSE;

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_cmt_cmi0_interrupt
* Description  : This function is CMI0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_CMT0_CMI0
#pragma interrupt r_cmt_cmi0_interrupt(vect=VECT(CMT0,CMI0),fint)
#else
#pragma interrupt r_cmt_cmi0_interrupt(vect=VECT(CMT0,CMI0))
#endif
static void r_cmt_cmi0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    one_ms_delay_complete = TRUE;

    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_cmt_cmi1_interrupt
* Description  : This function is CMI1 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_CMT1_CMI1
#pragma interrupt r_cmt_cmi1_interrupt(vect=VECT(CMT1,CMI1),fint)
#else
#pragma interrupt r_cmt_cmi1_interrupt(vect=VECT(CMT1,CMI1))
#endif
static void r_cmt_cmi1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */

    /* Stop this timer - we start it again in the de-bounce routines */
    R_CMT1_Stop();

    /* Call the de-bounce call back routine */
    R_SWITCH_DebounceIsrCallback();

    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_cmt_cmi2_interrupt
* Description  : This function is CMI2 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_PERIB_INTB128
#pragma interrupt r_cmt_cmi2_interrupt(vect=VECT(PERIB,INTB128),fint)
#else
#pragma interrupt r_cmt_cmi2_interrupt(vect=VECT(PERIB,INTB128))
#endif
static void r_cmt_cmi2_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */

    /* Stop this timer - we start it again in the de-bounce routines */
    R_CMT2_Stop();

    /* Call the de-bounce call back routine */
    R_SWITCH_DebounceIsrCallback();

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/*******************************************************************************
* Function Name: R_CMT_MsDelay
* Description  : Uses CMT0 to wait for a specified number of milliseconds
* Arguments    : uint16_t millisecs, number of milliseconds to wait
* Return Value : None
*******************************************************************************/
void R_CMT_MsDelay (const uint16_t millisec)
{
    uint16_t ms_count = 0;

    do
    {
        R_CMT0_Start();
        while (FALSE == one_ms_delay_complete)
        {
            /* Wait */
        }
        R_CMT0_Stop();
        one_ms_delay_complete = FALSE;
        ms_count++;
    } while (ms_count < millisec);


}
/*******************************************************************************
End of function R_CMT_MsDelay
*******************************************************************************/
/* End user code. Do not edit comment generated here */
