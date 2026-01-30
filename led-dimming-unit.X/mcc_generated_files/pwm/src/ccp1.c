/**
 * PWM1 Generated Driver File.
 * 
 * @file ccp1.c
 * 
 * @ingroup pwm1
 * 
 * @brief This file contains the API implementations for the PWM1 driver.
 *
 * @version PWM1 Driver Version 2.0.3
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
#include "../ccp1.h"

/**
  Section: Macro Declarations
*/

/* cppcheck-suppress misra-c2012-2.5 */
#define PWM1_INITIALIZE_DUTY_VALUE    511

/**
  Section: PWM1 Module APIs
*/

void CCP1_Initialize(void)
{
    // Set the PWM1 to the options selected in the User Interface
    
    // CCPM PWM; EN enabled; FMT right_aligned; 
    CCP1CON = 0x8F;
    
    // CCPRH 1; 
    CCPR1H = 0x1;
    
    // CCPRL 255; 
    CCPR1L = 0xFF;
    
    // Selecting Timer 2
    CCPTMRS1bits.C1TSEL = 0x0;
}

void CCP1_LoadDutyValue(uint16_t dutycycleValue)
{
    uint16_t dutyValue = dutycycleValue;
	  dutyValue &= 0x03FF;
    
    // Load duty cycle value
    if(1U == CCP1CONbits.FMT)
    {
        dutyValue <<= 6U;
        CCPR1H = (uint8_t)(dutyValue >> 8);
        CCPR1L = (uint8_t)dutyValue;
    }
    else
    {
        CCPR1H = (uint8_t)(dutyValue >> 8);
        CCPR1L = (uint8_t)dutyValue;
    }
}
bool CCP1_OutputStatusGet(void)
{
    // Returns the output status
    return(CCP1CONbits.OUT);
}
/**
 End of File
*/
