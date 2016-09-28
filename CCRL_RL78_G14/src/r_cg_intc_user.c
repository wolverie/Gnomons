/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2015 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_intc_user.c
* Version      : CodeGenerator for RL78/G14 V2.04.02.01 [15 May 2015]
* Device(s)    : R5F104PJ
* Tool-Chain   : CCRL
* Description  : This file implements device driver for INTC module.
* Creation Date: 2/4/2016
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_intc.h"
/* Start user code for include. Do not edit comment generated here */
#include "rskrl78g14def.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_intc0_interrupt(vect=INTP0)
#pragma interrupt r_intc1_interrupt(vect=INTP1)
#pragma interrupt r_intc2_interrupt(vect=INTP2)
#pragma interrupt r_intc3_interrupt(vect=INTP3)
#pragma interrupt r_intc4_interrupt(vect=INTP4)
#pragma interrupt r_intc5_interrupt(vect=INTP5)
#pragma interrupt r_intc6_interrupt(vect=INTP6)
#pragma interrupt r_intc7_interrupt(vect=INTP7)
#pragma interrupt r_intc8_interrupt(vect=INTP8)
#pragma interrupt r_intc9_interrupt(vect=INTP9)
#pragma interrupt r_intc10_interrupt(vect=INTP10)
#pragma interrupt r_intc11_interrupt(vect=INTP11)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
void Toggle_LEDs(void);

/* Switch flag which indicates which switches have been pressed */
volatile uint8_t gSwitch_Flag = 0x00;
volatile uint8_t gTest_Count = 0;

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_intc0_interrupt
* Description  : This function is INTP0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc1_interrupt
* Description  : This function is INTP1 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc2_interrupt
* Description  : This function is INTP2 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc2_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc3_interrupt
* Description  : This function is INTP3 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc3_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc4_interrupt
* Description  : This function is INTP4 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc4_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc5_interrupt
* Description  : This function is INTP5 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc5_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc6_interrupt
* Description  : This function is INTP6 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc6_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc7_interrupt
* Description  : This function is INTP7 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc7_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc8_interrupt
* Description  : This function is INTP8 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc8_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    gSwitch_Flag = SWITCHPRESS_1;

    /* Clear interrupt flag */
    PIF8 = 0;
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc9_interrupt
* Description  : This function is INTP9 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc9_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    gSwitch_Flag = SWITCHPRESS_2;

    /* Clear interrupt flag */
    PIF9 = 0;
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc10_interrupt
* Description  : This function is INTP10 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc10_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    gSwitch_Flag = SWITCHPRESS_3;

    /* Clear interrupt flag */
    PIF10 = 0;
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_intc11_interrupt
* Description  : This function is INTP11 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_intc11_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name	: FlashLEDs
* Description 	: Flashes the user LEDs on the RSK
* Argument  	: none
* Return value  : none
***********************************************************************************************************************/
void Flash_LEDs(void)
{
	/* Declare loop iteration count variable.
	   Declared as volatile to prevent optimisation when compiled
	   and executed using the Release build configuration  */
	volatile uint32_t led_delay=0;
	volatile uint8_t flash_count=0;
	volatile uint8_t test_variable = 1;

	/* Enable SW1 interrupts */
	R_INTC8_Start();

	/* Enable SW2 interrupts */
	R_INTC9_Start();

	/* Enable SW3 interrupts */
	R_INTC10_Start();

	/* Flash the LEDs for 200 times or until a user switch is pressed. */
	while((0 == gSwitch_Flag) && (flash_count++ < 200))
	{
		/* LED flashing Delay */
		for(led_delay=0; led_delay<400000; led_delay++)
		{
			/* Delay */
		}

		gTest_Count++;
		/* Toggles the LEDs after a specific delay. */
		Toggle_LEDs();
	}

	/* Reset the flag variable */
	gSwitch_Flag = 0;

	/* Disable SW1 interrupts */
	R_INTC8_Stop();

	/* Disable SW2 interrupts */
	R_INTC9_Stop();

	/* Disable SW3 interrupts */
	R_INTC10_Stop();
}
/***********************************************************************************************************************
End of function FlashLEDs
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name	: Toggle_LEDs
* Description 	: Toggles the LEDs on the RSK
* Argument  	: none
* Return value  : none
***********************************************************************************************************************/
void Toggle_LEDs(void)
{
    /*	Toggle the state of the user LEDs  */
    LED0 = ~LED0;
    LED1 = ~LED1;
    LED2 = ~LED2;
    LED3 = ~LED3;
}
/* End user code. Do not edit comment generated here */
