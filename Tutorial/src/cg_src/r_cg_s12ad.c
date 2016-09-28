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
* File Name    : r_cg_s12ad.c
* Version      : Code Generator for RX64M V1.00.01.01 [09 May 2014]
* Device(s)    : R5F564MLCxFC
* Tool-Chain   : CCRX
* Description  : This file implements device driver for S12AD module.
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
#include "r_cg_s12ad.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


/***********************************************************************************************************************
* Function Name: R_S12AD0_Create
* Description  : This function initializes the AD0 converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_S12AD0_Create(void)
{
    /* Cancel S12AD0 module stop state */
    MSTP(S12AD) = 0U;  

    /* Disable and clear S12ADI0, S12GBADI0, S12CMPI0 interrupt flags */
    S12AD.ADCSR.BIT.ADIE = 0U;
    S12AD.ADCSR.BIT.GBADIE = 0U;
    S12AD.ADCMPCR.BIT.CMPIE = 0U;
    IEN(PERIB, INTB129) = 0U;

    /* Set S12AD0 control registers */
    S12AD.ADDISCR.BYTE = _00_AD0_DISCONECT_SETTING;
    S12AD.ADCSR.WORD = _0000_AD_DBLTRIGGER_DISABLE | _0100_AD_ASYNC_TRIGGER | _0200_AD_SYNCASYNCTRG_ENABLE | 
                       _1000_AD_SCAN_END_INTERRUPT_ENABLE | _0000_AD_SINGLE_SCAN_MODE;
    S12AD.ADCER.WORD = _0000_AD_AUTO_CLEARING_DISABLE | _0000_AD_RIGHT_ALIGNMENT | _0000_AD_RESOLUTION_12BIT;
    S12AD.ADADC.BYTE = _00_AD_1_TIME_CONVERSION | _00_AD_ADDITION_MODE;

    /* Set channels and sampling time */
    S12AD.ADANSA0.WORD = _0001_AD0_CHANNEL_SELECT_A0;
    S12AD.ADADS0.WORD = _0000_AD0_ADDAVG_CHANNEL_SELECT0;
    S12AD.ADSSTR0 = _DC_AD0_SAMPLING_STATE_0;

    /* Set compare control register */
    S12AD.ADCMPCR.BYTE = _80_AD_COMPARISON_INTERRUPT_ENABLE | _00_AD_WINDOWFUNCTION_DISABLE;
    S12AD.ADCMPANSR0.WORD = _0000_AD0_COMPARECHANNEL_SELECT0;
    S12AD.ADCMPLR0.WORD = _0000_AD0_COMPARELEVEL_SELECT0;
    S12AD.ADCMPDR0 = 0x0000U;

    /* Set AD conversion start trigger sources */
    S12AD.ADSTRGR.WORD = _0000_AD_TRSA_ADTRG;

    /* Set interrupt and priority level */
    ICU.SLIBXR129.BYTE = 0x40U;
    IPR(PERIB, INTB129) = _0F_AD_PRIORITY_LEVEL15;

    /* Set AN000 pin */
    MPC.P40PFS.BIT.ASEL = 1U;
    PORT4.PMR.BYTE &= 0xFEU;
    PORT4.PDR.BYTE &= 0xFEU;

    /* Set ADTRG0# pin */
    MPC.P07PFS.BYTE = 0x09U;
    PORT0.PMR.BYTE |= 0x80U;
    PORT0.PDR.BYTE &= 0x7FU;

}

/***********************************************************************************************************************
* Function Name: R_S12AD0_Start
* Description  : This function starts the AD0 converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_S12AD0_Start(void)
{
    IR(PERIB, INTB129) = 0U;
    IEN(PERIB, INTB129) = 1U;
    ICU.GENBL1.BIT.EN20 = 1U;
    S12AD.ADCSR.BIT.TRGE = 1U;
}

/***********************************************************************************************************************
* Function Name: R_S12AD0_Stop
* Description  : This function stops the AD0 converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_S12AD0_Stop(void)
{
    S12AD.ADCSR.BIT.TRGE = 0U;
    IEN(PERIB, INTB129) = 0U;
    IR(PERIB, INTB129) = 0U;
    ICU.GENBL1.BIT.EN20 = 0U;
}

/***********************************************************************************************************************
* Function Name: R_S12AD0_Get_ValueResult
* Description  : This function gets result from the AD0 converter.
* Arguments    : channel -
*                    channel of data register to be read
*                buffer -
*                    buffer pointer
* Return Value : None
***********************************************************************************************************************/
void R_S12AD0_Get_ValueResult(ad_channel_t channel, uint16_t * const buffer)
{
   if (channel == ADSELFDIAGNOSIS)
    {
        *buffer = (uint16_t)(S12AD.ADRD.WORD);
    }
    else if (channel == ADCHANNEL0)
    {
        *buffer = (uint16_t)(S12AD.ADDR0);
    }
    else if (channel == ADCHANNEL1)
    {
        *buffer = (uint16_t)(S12AD.ADDR1);
    }
    else if (channel == ADCHANNEL2)
    {
        *buffer = (uint16_t)(S12AD.ADDR2);
    }
    else if (channel == ADCHANNEL3)
    {
        *buffer = (uint16_t)(S12AD.ADDR3);
    }
    else if (channel == ADCHANNEL4)
    {
        *buffer = (uint16_t)(S12AD.ADDR4);
    }
    else if (channel == ADCHANNEL5)
    {
        *buffer = (uint16_t)(S12AD.ADDR5);
    }
    else if (channel == ADCHANNEL6)
    {
        *buffer = (uint16_t)(S12AD.ADDR6);
    }
    else if (channel == ADCHANNEL7)
    {
        *buffer = (uint16_t)(S12AD.ADDR7);
    }
    else if (channel == ADDATADUPLICATION)
    {
        *buffer = (uint16_t)(S12AD.ADDBLDR.WORD);
    }
    else if (channel == ADDATADUPLICATIONA)
    {
        *buffer = (uint16_t)(S12AD.ADDBLDRA);
    }
    else if (channel == ADDATADUPLICATIONB)
    {
        *buffer = (uint16_t)(S12AD.ADDBLDRB);
    }
}
/***********************************************************************************************************************
* Function Name: R_S12AD0_Set_CompareValue
* Description  : This function sets reference data for AD0 comparison.
* Arguments    : reg_value0 -
*                    reference data 0 for comparison
*                reg_value1 -
*                    reference data 1 for comparison
* Return Value : None
***********************************************************************************************************************/
void R_S12AD0_Set_CompareValue(uint16_t reg_value0, uint16_t reg_value1 )
{
     S12AD.ADCMPDR0 = reg_value0;
     S12AD.ADCMPDR1 = reg_value1;
}





/* Start user code for adding. Do not edit comment generated here */
/*******************************************************************************
* Function Name: R_S12AD0_SWTriggerStart
* Description  : This function starts the AD0 converter.
* Arguments    : None
* Return Value : None
*******************************************************************************/
void R_S12AD0_SWTriggerStart (void)
{
    IR(PERIB, INTB129) = 0U;
    IEN(PERIB, INTB129) = 1U;
    ICU.GENBL1.BIT.EN19 = 1U;
    S12AD.ADCSR.BIT.ADST = 1U;
}

/*******************************************************************************
End of function R_S12AD0_SWTriggerStart
*******************************************************************************/

/*******************************************************************************
* Function Name: R_S12AD0_SWTriggerStop
* Description  : This function stops the AD0 converter.
* Arguments    : None
* Return Value : None
*******************************************************************************/
void R_S12AD0_SWTriggerStop (void)
{
    S12AD.ADCSR.BIT.ADST = 0U;
    IEN(PERIB, INTB129) = 0U;
    IR(PERIB, INTB129) = 0U;
    ICU.GENBL1.BIT.EN19 = 0U;
}

/*******************************************************************************
End of function R_S12AD0_SWTriggerStop
*******************************************************************************/
/* End user code. Do not edit comment generated here */
