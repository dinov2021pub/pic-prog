/**
 * ADC Type Definitions Header File
 *
 * @file adc_types.h
 *
 * @defgroup adc ADC
 *
 * @brief This file provides type definitions for the Analog-to-Digital Converter (ADC) module.
 *
 * @version ADC Driver Version 3.0.0
 * 
 * @version ADC Package Version 4.0.0
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

#ifndef ADC_TYPES_H
#define	ADC_TYPES_H

// Section: Macros

/**
 @ingroup adc
 @brief ADC resolution value.
*/
#define ADC_RESOLUTION 10U

/**
 @ingroup adc
 @brief ADC bit set value.
*/
#define ADC_BIT_SET 1U

/**
 @ingroup adc
 @brief ADC bit clear value.
*/
#define ADC_BIT_CLEAR 0U

// Section: Types

/**
 @ingroup adc
 @typedef adc_result_t
 @brief ADC conversion result type.
*/
typedef int16_t adc_result_t;

// Section: Enumerations

/**
 * @ingroup adc
 * @enum adc_channel_t
 * @brief Describes the available Analog-to-Digital Converter (ADC) channels.
*/
typedef enum
{
    ADC_CHANNEL_FVRBUFFER1 =  0x3f, /**< FVRBuffer1*/ 
    ADC_CHANNEL_DAC7_OUTPUT =  0x37, /**< DAC7_Output*/ 
    ADC_CHANNEL_DAC5_OUTPUT =  0x39, /**< DAC5_Output*/ 
    ADC_CHANNEL_DAC4_OUTPUT =  0x3a, /**< DAC4_Output*/ 
    ADC_CHANNEL_DAC3_OUTPUT =  0x3b, /**< DAC3_Output*/ 
    ADC_CHANNEL_DAC2_OUTPUT =  0x3c, /**< DAC2_Output*/ 
    ADC_CHANNEL_DAC1_OUTPUT =  0x3e, /**< DAC1_Output*/ 
    ADC_CHANNEL_TEMP =  0x3d, /**< Temp*/ 
    ADC_CHANNEL_ANA0 =  0x00,//undefined, /**< IO_RA0: RA0*/ 
    ADC_CHANNEL_ANA1 =  0x01,//undefined, /**< IO_RA1: RA1*/ 
    ADC_CHANNEL_ANA2 =  0x02,//undefined, /**< IO_RA2: RA2*/ 
    ADC_CHANNEL_ANA3 =  0x03,//undefined, /**< IO_RA3: RA3*/ 
    ADC_CHANNEL_ANA5 =  0x04,//undefined, /**< IO_RA5: RA5*/ 
    ADC_CHANNEL_AN0 =  0x0 /**< IO_R0: AN0*/ 
} adc_channel_t;

/**
 * @ingroup adc
 * @typedef adc_trigger_source_t 
 * @brief Lists the ADC auto-trigger sources.
 */
typedef enum
{
    ADC_TRIGGER_SOURCE_NO_AUTO_TRIGGER = 0x0, /**< No_auto_trigger*/  
    ADC_TRIGGER_SOURCE_ADCACT_PPS = 0x1, /**< ADCACT_PPS*/  
    ADC_TRIGGER_SOURCE_TMR0_OVERFLOW = 0x2, /**< TMR0_overflow*/  
    ADC_TRIGGER_SOURCE_TMR1_OVERFLOW = 0x3, /**< TMR1_overflow*/  
    ADC_TRIGGER_SOURCE_TMR2_POSTSCALED = 0x4, /**< TMR2_postscaled*/  
    ADC_TRIGGER_SOURCE_TMR3_OVERFLOW = 0x5, /**< TMR3_overflow*/  
    ADC_TRIGGER_SOURCE_TMR4_POSTSCALED = 0x6, /**< TMR4_postscaled*/  
    ADC_TRIGGER_SOURCE_TMR5_OVERFLOW = 0x7, /**< TMR5_overflow*/  
    ADC_TRIGGER_SOURCE_TMR6_POSTSCALED = 0x8, /**< TMR6_postscaled*/  
    ADC_TRIGGER_SOURCE_TMR8_POSTSCALED = 0x9, /**< TMR8_postscaled*/  
    ADC_TRIGGER_SOURCE_SYNCC1OUT = 0xa, /**< SYNCC1OUT*/  
    ADC_TRIGGER_SOURCE_SYNCC2OUT = 0xb, /**< SYNCC2OUT*/  
    ADC_TRIGGER_SOURCE_SYNCC3OUT = 0xc, /**< SYNCC3OUT*/  
    ADC_TRIGGER_SOURCE_SYNCC4OUT = 0xd, /**< SYNCC4OUT*/  
    ADC_TRIGGER_SOURCE_SYNCC5OUT = 0xe, /**< SYNCC5OUT*/  
    ADC_TRIGGER_SOURCE_SYNCC6OUT = 0xf, /**< SYNCC6OUT*/  
    ADC_TRIGGER_SOURCE_CLC1 = 0x12, /**< CLC1*/  
    ADC_TRIGGER_SOURCE_CLC2 = 0x13, /**< CLC2*/  
    ADC_TRIGGER_SOURCE_CLC3 = 0x14, /**< CLC3*/  
    ADC_TRIGGER_SOURCE_CLC4 = 0x15, /**< CLC4*/  
    ADC_TRIGGER_SOURCE_CCP1 = 0x16, /**< CCP1*/  
    ADC_TRIGGER_SOURCE_CCP2 = 0x17, /**< CCP2*/  
    ADC_TRIGGER_SOURCE_CCP7 = 0x18, /**< CCP7*/  
    ADC_TRIGGER_SOURCE_PWM3OUT = 0x1a, /**< PWM3OUT*/  
    ADC_TRIGGER_SOURCE_PWM4OUT = 0x1b, /**< PWM4OUT*/  
    ADC_TRIGGER_SOURCE_PWM9OUT = 0x1c, /**< PWM9OUT*/  
    ADC_TRIGGER_SOURCE_PWM5_DC5_MATCH = 0x1e, /**< PWM5_DC5_match*/  
    ADC_TRIGGER_SOURCE_PWM5_PR5_MATCH = 0x1f, /**< PWM5_PR5_match*/  
    ADC_TRIGGER_SOURCE_PWM5_PH5_MATCH = 0x20, /**< PWM5_PH5_match*/  
    ADC_TRIGGER_SOURCE_PWM5_OF5_MATCH = 0x21, /**< PWM5_OF5_match*/  
    ADC_TRIGGER_SOURCE_PWM6_DC6_MATCH = 0x22, /**< PWM6_DC6_match*/  
    ADC_TRIGGER_SOURCE_PWM6_PR6_MATCH = 0x23, /**< PWM6_PR6_match*/  
    ADC_TRIGGER_SOURCE_PWM6_PH6_MATCH = 0x24, /**< PWM6_PH6_match*/  
    ADC_TRIGGER_SOURCE_PWM6_OF6_MATCH = 0x25, /**< PWM6_OF6_match*/  
    ADC_TRIGGER_SOURCE_PWM11_DC11_MATCH = 0x26, /**< PWM11_DC11_match*/  
    ADC_TRIGGER_SOURCE_PWM11_PR11_MATCH = 0x27, /**< PWM11_PR11_match*/  
    ADC_TRIGGER_SOURCE_PWM11_PH11_MATCH = 0x28, /**< PWM11_PH11_match*/  
    ADC_TRIGGER_SOURCE_PWM11_OF11_MATCH = 0x29 /**< PWM11_OF11_match*/  
} adc_trigger_source_t ;

#endif // ADC_TYPES_H