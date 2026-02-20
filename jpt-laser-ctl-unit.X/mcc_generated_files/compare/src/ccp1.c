/**
 * CCP1 Generated Driver File.
 * 
 * @file ccp1.c
 * 
 * @ingroup compare1
 * 
 * @brief This file contains the API implementation for the CCP1 driver.
 *
 * @version CCP1 Driver Version 1.1.0
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
  Section: Compare Module APIs
*/

void CCP1_Initialize(void)
{
    // Set the CCP1 to the options selected in the User Interface

    // CCPM Clearoutput; DCB 0; 
    CCP1CON = 0x9;
   
    // CCPRH 0; 
    CCPR1H = 0x0;
  
    // CCPRL 0; 
    CCPR1L = 0x0;
   

}

void CCP1_SetCompareCount(uint16_t compareCount)
{
  CCPR1_PERIOD_REG_T module;
    
    // Write the 16-bit compare value
    module.ccpr1_16Bit = compareCount;
    
    CCPR1L = module.ccpr1l;
    CCPR1H = module.ccpr1h;
}

bool CCP1_IsCompareComplete(void)
{
    // Check if compare is complete by reading "CCPIF" flag.
    bool status = PIR1bits.CCP1IF;
    if(status)
        PIR1bits.CCP1IF = 0;
    return (status);
}

/**
 End of File
*/
