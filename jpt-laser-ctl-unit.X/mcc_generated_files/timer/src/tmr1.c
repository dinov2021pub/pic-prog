/**
  * TMR1 Generated Driver File
  *
  * @file tmr1.c
  *
  * @ingroup tmr1
  *
  * @brief This file contains the API implementation for the TMR1 driver.
  *
  * @version TMR1 Driver Version 2.1.0
  *
  * @version Package Version 2.1.0
*/
/*
? [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

/**
   Section: Included Files
*/

#include <xc.h>
#include "../tmr1.h"

/**
 * @misradeviation{@advisory,8.7}
 * The TMRx_CounterSet function is declared in a header file that can be included in any translation unit that must use it. 
 */

static volatile uint16_t timer1ReloadVal;
static void (*TMR1_OverflowCallback)(void);
static void TMR1_DefaultOverflowCallback(void);
static void (*TMR1_GateCallback)(void);
static void TMR1_DefaultGateCallback(void);

void TMR1_Initialize(void)
{
    T1CONbits.TMR1ON = 0U;
	
    TMR1H = 0xFF;                       // Period 40 us; Count 65,376
    TMR1L = 0x60;

    timer1ReloadVal=((uint16_t)TMR1H << 8U) | TMR1L;
	
    T1GCON = (0 << _T1GCON_T1GSS_POSN)   // T1GSS T1G_pin
        | (0 << _T1GCON_T1GGO_POSN)   // T1GGO done
        | (0 << _T1GCON_T1GSPM_POSN)   // T1GSPM disabled
        | (0 << _T1GCON_T1GTM_POSN)   // T1GTM disabled
        | (0 << _T1GCON_T1GPOL_POSN)   // T1GPOL low
        | (0 << _T1GCON_TMR1GE_POSN);  // TMR1GE disabled
    TMR1_OverflowCallback =TMR1_DefaultOverflowCallback;
    TMR1_GateCallback = TMR1_DefaultGateCallback;

    // Clear interrupt flags
	PIR1bits.TMR1IF = 0U;
	PIR1bits.TMR1GIF = 0U;
    
    T1CON = (1 << _T1CON_TMR1ON_POSN)   // TMR1ON enabled
        | (1 << _T1CON_nT1SYNC_POSN)   // nT1SYNC do_not_synchronize
        | (0 << _T1CON_T1CKPS_POSN)   // T1CKPS 1:1
        | (0 << _T1CON_TMR1CS_POSN)   // TMR1CS FOSC/4
        | (0 << _T1CON_T1OSCEN_POSN);  // T1OSCEN disabled
}

void TMR1_Deinitialize(void)
{
    T1CONbits.TMR1ON = 0U;
    	   
    PIE1bits.TMR1IE = 0U;
    PIR1bits.TMR1IF = 0U;
    PIE1bits.TMR1GIE = 0U;
    PIR1bits.TMR1GIF = 0U;	
    
    T1CON = 0x0U;
    T1GCON = 0x0U;
    TMR1H = 0x0U;
    TMR1L = 0x0U;
}

void TMR1_Start(void)
{
    T1CONbits.TMR1ON = 1U;
}

void TMR1_Stop(void)
{
    T1CONbits.TMR1ON = 0U;
}

uint16_t TMR1_CounterGet(void)
{
    uint16_t counterValue;
    uint8_t counterHighByte;
    uint8_t counterLowByte;
    
    counterLowByte = TMR1L;
    counterHighByte = TMR1H;    
    counterValue = ((uint16_t)counterHighByte << 8U) | counterLowByte;

    return counterValue;
}

/* cppcheck-suppress misra-c2012-8.7 */
void TMR1_CounterSet(uint16_t timerVal)
{
    if (1U == T1CONbits.nT1SYNC)
    {
	    bool onState = T1CONbits.TMR1ON;	
		
        T1CONbits.TMR1ON = 0U;
        
        TMR1H = (uint8_t)(timerVal >> 8U);
        TMR1L = (uint8_t)timerVal;

        T1CONbits.TMR1ON = onState;
    }
    else
    {
        TMR1H = (uint8_t)(timerVal >> 8U);
        TMR1L = (uint8_t)timerVal;
    }
}

void TMR1_Reload(void)
{
    /* cppcheck-suppress misra-c2012-8.7 */
    TMR1_CounterSet(timer1ReloadVal);
}

uint16_t TMR1_MaxCountGet(void)
{
    return TMR1_MAX_COUNT;
}

void TMR1_PeriodSet(uint16_t periodVal)
{
    timer1ReloadVal = periodVal;
}

uint16_t TMR1_PeriodGet(void)
{
    return timer1ReloadVal;
}

void TMR1_SinglePulseAcquisitionStart(void)
{
    T1GCONbits.T1GGO = 1U;
}

uint8_t TMR1_GateStateGet(void)
{
    return (T1GCONbits.T1GVAL);
}

bool TMR1_OverflowStatusGet(void)
{
    return(PIR1bits.TMR1IF);
}

void TMR1_OverflowStatusClear(void)
{
    PIR1bits.TMR1IF = 0U;
}

bool TMR1_GateEventStatusGet(void)
{
    return(PIR1bits.TMR1GIF);
}

void TMR1_GateEventStatusClear(void)
{
    PIR1bits.TMR1GIF = 0U;
}

void TMR1_Tasks(void)
{
    if(1U == PIR1bits.TMR1IF)
    {
        /* cppcheck-suppress misra-c2012-8.7 */
        TMR1_CounterSet(timer1ReloadVal);
        if(NULL != TMR1_OverflowCallback)
        { 
            TMR1_OverflowCallback();
        }
        PIR1bits.TMR1IF = 0;
    }
    if(1U == PIR1bits.TMR1GIF)
    {
         if(NULL != TMR1_GateCallback)
        {
            TMR1_GateCallback();
        }
        PIR1bits.TMR1GIF = 0;
    }
}


void TMR1_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    TMR1_OverflowCallback = CallbackHandler;
}

static void TMR1_DefaultOverflowCallback(void)
{
    // Use TMR1_OverflowCallbackRegister function to register custom callback
}

void TMR1_GateCallbackRegister(void (* CallbackHandler)(void))
{
    TMR1_GateCallback = CallbackHandler;
}

static void TMR1_DefaultGateCallback(void)
{
    // Use TMR1_GateCallbackRegister function to register custom callback
}

/**
  End of File
*/
