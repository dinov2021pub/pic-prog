 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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
#include "mcc_generated_files/system/system.h"

/*
    Main application
*/

uint16_t an0;
uint16_t an1;
uint16_t an2;
uint16_t an3;
uint16_t an4;

int main(void)
{
    SYSTEM_Initialize();
    TMR2_Initialize();
    CCP1_Initialize();
    CCP2_Initialize();
    CCP7_Initialize();
    PWM3_Initialize();
    PWM4_Initialize();
    ADC_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

    while(1)
    {
        // AD値を読み込む
        an0 = ADC_ChannelSelectAndConvert(ADC_CHANNEL_ANA0);
        an1 = ADC_ChannelSelectAndConvert(ADC_CHANNEL_ANA1);
        an2 = ADC_ChannelSelectAndConvert(ADC_CHANNEL_ANA2);
        an3 = ADC_ChannelSelectAndConvert(ADC_CHANNEL_ANA3);
        an4 = ADC_ChannelSelectAndConvert(ADC_CHANNEL_ANA5);
        
        // 入力を一度だけ読み取り、変数に保持
        uint8_t rb0_state = PORTBbits.RB0;//同軸照明 ON/OFF
        uint8_t rb1_state = PORTBbits.RB1;//リング照明 ON/OFF
        uint8_t rb2_state = PORTBbits.RB2;//リング照明 同期/非同期
        
        // 同軸照明
        if(rb0_state == 1){
            CCP1_LoadDutyValue(an0);
        }else{
            CCP1_LoadDutyValue(0);
        }
        
        // リング照明 上下左右独立動作
        if(rb1_state == 1 && rb2_state == 0){
            CCP2_LoadDutyValue(an1);
            CCP7_LoadDutyValue(an2);
            PWM3_LoadDutyValue(an3);
            PWM4_LoadDutyValue(an4); 
        // リング照明 上下左右をan1に同期
        }else if(rb1_state == 1 && rb2_state == 1){
            CCP2_LoadDutyValue(an1);
            CCP7_LoadDutyValue(an1);
            PWM3_LoadDutyValue(an1);
            PWM4_LoadDutyValue(an1);
        }else{
            CCP2_LoadDutyValue(0);
            CCP7_LoadDutyValue(0);
            PWM3_LoadDutyValue(0);
            PWM4_LoadDutyValue(0);
        }  
    }    
}
