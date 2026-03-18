/**
 * TMR2 Generated Driver File
 *
 * @file tmr2.c
 * 
 * @ingroup  tmr2
 * 
 * @brief This file contains the API implementation for the TMR2 module.
 *
 * @version Driver Version 2.0.0
 *
 * @version Package Version 2.0.0
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

#include <xc.h>
#include "../tmr2.h"

static void (*TMR2_PeriodMatchCallback)(void);
static void TMR2_DefaultPeriodMatchCallback(void);

/**
  Section: TMR2 APIs
*/

void TMR2_Initialize(void)
{
    // Set TMR2 to the options selected in the User Interface
    PR2 = 0x27;            // Period 0; Frequency 4000000Hz; Count 39
    TMR2 = 0x0;
    TMR2_PeriodMatchCallback = TMR2_DefaultPeriodMatchCallback;
    
    PIR1bits.TMR2IF = 0;   
    PIE1bits.TMR2IE = 1;
    T2CON = (0 << _T2CON_T2CKPS_POSN)   // T2CKPS 1:1
        | (0 << _T2CON_TMR2ON_POSN)   // TMR2ON off
        | (0 << _T2CON_T2OUTPS_POSN);  // T2OUTPS 1:1
}

void TMR2_Deinitialize(void)
{
    T2CONbits.TMR2ON = 0;
    PIR1bits.TMR2IF = 0;	   
    PIE1bits.TMR2IE = 0;
    T2CON = 0x0;
    PR2 = 0xFF;
    TMR2 =0x0;
}

void TMR2_Start(void)
{   
    T2CONbits.TMR2ON = 1;
}

void TMR2_Stop(void)
{   
    T2CONbits.TMR2ON = 0;
}

uint8_t TMR2_CounterGet(void)
{
    return TMR2;
}

void TMR2_CounterSet(uint8_t counterValue)
{  
    TMR2 = counterValue;
}

void TMR2_PeriodSet(uint8_t periodCount)
{
    PR2 = periodCount;
}

uint8_t TMR2_PeriodGet(void)
{
    return PR2;
}

uint8_t TMR2_MaxCountGet(void)
{
    return TMR2_MAX_COUNT;
}

void TMR2_TMRInterruptEnable(void)
{
    PIE1bits.TMR2IE = true;
}

void TMR2_TMRInterruptDisable(void)
{
    PIE1bits.TMR2IE = false;
}

void TMR2_ISR(void)
{
    // The ticker is set to 1 -> The callback function gets called every time this ISR executes.
    if(NULL != TMR2_PeriodMatchCallback)
    {
        TMR2_PeriodMatchCallback();
    }
    PIR1bits.TMR2IF = 0;
}

void TMR2_PeriodMatchCallbackRegister(void (* CallbackHandler)(void))
{
   TMR2_PeriodMatchCallback = CallbackHandler;
}

static void TMR2_DefaultPeriodMatchCallback(void)
{
    // Default callback function
}

