/**
 * PWM7 Generated Driver API Header File.
 * 
 * @file ccp7.h
 * 
 * @defgroup pwm7 PWM7
 * 
 * @brief This file contains the API prototypes for the PWM7 module.
 *
 * @version PWM7 Driver Version 2.0.3
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

#ifndef PWM7_H
#define PWM7_H

 /**
   Section: Included Files
 */

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>


 /**
 * @ingroup pwm7
 * @brief Initializes the CCP7 module. This is called only once before calling other CCP7 APIs.
 * @param None.
 * @return None.
 */
void CCP7_Initialize(void);
/**
 * @ingroup pwm7
 * @brief Loads the 16-bit duty cycle value.
 * @pre CCP7_Initialize() is already called.
 * @param dutyValue - 16-bit duty cycle value.
 * @return None.
 */
void CCP7_LoadDutyValue(uint16_t dutyValue);
/**
 * @ingroup pwm7
 * @brief Returns the PWM output status.
 * @pre CCP7_Initialize() is already called.
 * @param None.
 * @retval True - CCP7 PWM output is high
 * @retval False - CCP7 PWM output is low
 */
bool CCP7_OutputStatusGet(void);
#endif //PWM7_H
/**
 End of File
*/
