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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===========================
 * マクロの宣言
 * =========================== */
#define SHT_CW LATBbits.LATB1
#define SHT_CCW LATBbits.LATB0
#define HALL PORTBbits.RB2
#define P_LD LATBbits.LATB3
#define P_LED LATBbits.LATB5

#define SHT_LOW 10
#define SHT_MIDDLE 100
#define SHT_HIGH 1000

/* ===========================
 * 型の宣言
 * =========================== */
enum command {
    LDP,
    SHT,
    HAL,
    COA,
    RG1,
    RG2,
    RG3,
    RG4,
    VER
};

/* ===========================
 * プロトタイプの宣言
 * =========================== */
void ctl_unit_init(void);
void shutter_on(void);
void shutter_off(void);
bool get_hall_status(void);
void my_gets(char *buffer, uint16_t max_len);
unsigned char getche(void);

/* ===========================
 * グローバル変数定義
 * =========================== */
volatile bool hall_status = 0;  // 0: OFF, 1: ON

//static volatile bool tmr2_done = false;
unsigned char ld_on_off = 0;
unsigned char sht_on_off = 0;

/* ===========================
 * メイン処理
 * =========================== */

int main(void)
{
    SYSTEM_Initialize();
    EUSART_Initialize();
    TMR2_Initialize();
    TMR4_Initialize();
    CCP1_Initialize();
    CCP2_Initialize();
    CCP7_Initialize();
    PWM3_Initialize();
    PWM4_Initialize();
    PWM9_Initialize();
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

    /* ===========================
     * ローカル変数
     * =========================== */
    static char tmp[300];
    char rcmd[4];
    
    uint32_t coa_val;
    uint8_t ring1_val;
    uint8_t ring2_val;
    uint8_t ring3_val;
    uint8_t ring4_val;
    uint8_t sht_spped;
    
    char *ptr;
    
    ctl_unit_init();

    while(1)
    {
       /* ===========================
        * ブロックローカル変数
        * =========================== */
        rcmd[0] = 'Q'; 
        rcmd[1] = 'Q'; 
        rcmd[2] = 'Q'; 
        rcmd[3] = '\0'; 

        tmp[0] = 'Q';
        tmp[1] = 'Q';
        tmp[2] = 'Q';
        tmp[3] = '\0';

//        gets(tmp);
        my_gets(tmp, sizeof(tmp));
//        printf("%s\n", tmp);
        if (strlen(tmp) < 3) continue;
        
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';       
        
        enum command cmd; // enum列挙型とオブジェクトの定義
        
        if(strcmp(rcmd,"LDP") == 0){
            cmd = LDP;
        }else if(strcmp(rcmd,"SHT") == 0){
            cmd = SHT;
        }else if(strcmp(rcmd,"HAL") == 0){
            cmd = HAL;
        }else if(strcmp(rcmd,"COA") == 0){
            cmd = COA;
        }else if(strcmp(rcmd,"RG1") == 0){
            cmd = RG1;
        }else if(strcmp(rcmd,"RG2") == 0){
            cmd = RG2;
        }else if(strcmp(rcmd,"RG3") == 0){
            cmd = RG3;
        }else if(strcmp(rcmd,"RG4") == 0){
            cmd = RG4;           
        }else if(strcmp(rcmd,"VER") == 0){
            cmd = VER;
        }
        ptr = strtok(tmp, "/");
        
//        getche();
        
        switch(cmd){
            
            case LDP :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    ld_on_off = atoi(ptr);
                }
                if(ld_on_off == 0){
                    P_LD = 0;                
                }else if(ld_on_off == 1){
                    P_LD = 1;                
                }
                printf("C\tLDP\t%d\r\n", ld_on_off);
                break;

            case SHT :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    sht_on_off = atoi(ptr);
                }
                if(sht_on_off == 0){
                    SHT_CW = 1;
                    SHT_CCW = 0;
                    PWM9_LoadDutyValue(60);
//                    SHT_CW = 0;
//                    SHT_CCW = 0;
                }else if(sht_on_off == 1){
                    SHT_CW = 0;
                    SHT_CCW = 1;
                    PWM9_LoadDutyValue(60);
//                    SHT_CW = 0;
//                    SHT_CCW = 0;
                }
                printf("C\tSHT\t%d\tHAL\t%d\r\n", sht_on_off,hall_status);
                break;

            case HAL :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    hall_status = atoi(ptr);
                }
                printf("C\tHAL\t%d\r\n", hall_status);
                break;

            case COA :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    coa_val = atoi(ptr);
                    if(coa_val > 255)
                        coa_val = 255;
                    coa_val = ((coa_val*290)>>8)+30;
                    CCP1_LoadDutyValue(coa_val);
                }
                printf("C\tCOA\t%d\r\n", coa_val);
                break;

            case RG1 :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    ring1_val = atoi(ptr);
                    ring1_val = (ring1_val*200)>>8;
                    CCP2_LoadDutyValue(ring1_val);
                }
                printf("C\tRG1\t%d\r\n", ring1_val);
                break;

            case RG2 :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    ring2_val = atoi(ptr);
                    ring2_val = (ring2_val*200)>>8;
                    CCP7_LoadDutyValue(ring2_val);
                }
                printf("C\tRG2\t%d\r\n", ring2_val);
                break;

            case RG3 :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    ring3_val = atoi(ptr);
                    ring3_val = (ring3_val*200)>>8;
                    PWM3_LoadDutyValue(ring3_val);
                }
                printf("C\tRG3\t%d\r\n", ring3_val);
                break;         

            case RG4 :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    ring4_val = atoi(ptr);
                    ring4_val = (ring4_val*200)>>8;
                    PWM4_LoadDutyValue(ring4_val);
                }
                printf("C\tRG4\t%d\r\n", ring4_val);
                break;                
                
            case VER :
                printf("C\tVERSION 1.0\r\n");
                break;

            default : break;
        }
    }
}

void ctl_unit_init(void){
    for(int i=0 ; i < 20 ; i++){
        __delay_ms(50);
        P_LED ^= 1;
    }
    P_LED = 1;
    printf("System initialization has been completed.!!\r\n");
}

//void shutter_on(void){
//    SHT_CW = 1;
//    SHT_CCW = 0;
//    sht_spped = atoi(ptr);
//    PWM9_LoadDutyValue(sht_spped);
//    SHT_CW = 0;
//    SHT_CCW = 0;
//    //hall_status = HAL;
//}
//
//void shutter_off(void){
//    SHT_CW = 0;
//    SHT_CCW = 1;
//    sht_spped = atoi(ptr);
//    PWM9_LoadDutyValue(sht_spped);
//    SHT_CW = 0;
//    SHT_CCW = 0;
//    //hall_status = HAL;
//}

//// 初期化（MCCが生成するPWM5_Initialize()で済む部分もある）
//PWM5_PeriodSet(65535);
//PWM5_DutyCycleSet(49151);   // 75% = 65535 * 0.75 ? 49151
//PWM5_LoadBufferSet();        // バッファ転送
//PWM5_Start();                // PWM開始
//
//// 動作中に値を変えるとき
//PWM5_DutyCycleSet(32767);   // 50%に変更
//PWM5_LoadBufferSet();        // ← これを忘れると反映されない


bool get_hall_status(void){
    return hall_status;
}





void my_gets(char *buffer, uint16_t max_len){
    uint16_t idx = 0;
    char c;
    
    memset(buffer, 0, max_len);
    
    while(idx < max_len - 1) {
        c = getch();
        putch(c);
        
        if(c == '\r' || c == '\n') {
            buffer[idx] = '\0';
            putch('\n');
            return;
        }
        
        buffer[idx++] = c;
    }
    buffer[idx] = '\0';
}

unsigned char getche(void){
    unsigned char c;
    c = getch();   // 1文字受信
    putch(c);      // 受信した文字をそのまま送り返す（エコー）
    return c;
}
