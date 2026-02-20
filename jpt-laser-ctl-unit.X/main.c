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
#define LED1 LATBbits.LATB5
#define LED2 LATBbits.LATB4
#define L_LATCH LATCbits.LATC2
#define L_MOD  LATCbits.LATC1
#define L_PA LATCbits.LATC0
#define L_AMP LATA

#define DELAY_LATCH 40
#define DELAY_PA_START 4000
#define DELAY_MOD_START 1000
#define DELAY_PA_END 1000
#define DELAY_MOD_END 1000

/* ===========================
 * 型の宣言
 * =========================== */
enum command {
  SF1,
  SF2,
  SF3,
  SF4,
  SF5,
  SF6,
  SPO,
  TON,
  TOF,
  VEW,
  VER
};

/* ===========================
 * プロトタイプの宣言
 * =========================== */
void jpt_laser_init(void);
void emission_on(void);
void emission_off(void);
bool get_emission_status(void);
//void Start_Latch_Pulse(void);
void my_gets(char *buffer, uint16_t max_len);
unsigned char getche(void);

/* ===========================
 * グローバル変数定義
 * =========================== */
volatile bool emission_status = 0;  // 0: OFF, 1: ON

/* ===========================
 * メイン処理
 * =========================== */
int main(void)
{
    SYSTEM_Initialize();
    EUSART_Initialize();
    TMR1_Initialize();
//    CCP1_Initialize();
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
    int fp1_time;
    int fp1_amp;
    int fp2_time;
    int fp2_amp;
    int fp3_time;
    int fp3_amp;
    int fp4_time;
    int fp4_amp;
    int fp5_time;
    int fp5_amp;
    int fp6_time;
    int fp6_amp;
    
    char *ptr;
    
    jpt_laser_init();

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
        
        if(strcmp(rcmd,"SF1") == 0){
            cmd = SF1;
        }else if(strcmp(rcmd,"SF2") == 0){
            cmd = SF2;
        }else if(strcmp(rcmd,"SF3") == 0){
            cmd = SF3;
        }else if(strcmp(rcmd,"SF4") == 0){
            cmd = SF4;
        }else if(strcmp(rcmd,"SF5") == 0){
            cmd = SF5;
        }else if(strcmp(rcmd,"SF6") == 0){
            cmd = SF6;
        }else if(strcmp(rcmd,"SPO") == 0){
            cmd = SPO;
        }else if(strcmp(rcmd,"TON") == 0){
            cmd = TON;
        }else if(strcmp(rcmd,"TOF") == 0){
            cmd = TOF;
        }else if(strcmp(rcmd,"VEW") == 0){
            cmd = VEW;            
        }else if(strcmp(rcmd,"VER") == 0){
            cmd = VER;
        }
        ptr = strtok(tmp, "/");

//        getche();
        
        switch(cmd){
            
            case SF1 : 
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp1_time = atoi(ptr);
                }
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp1_amp = atoi(ptr);
                }
                printf("C\tSF1\r\n");
                break;

            case SF2 : 
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp2_time = atoi(ptr);
                }
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp2_amp = atoi(ptr);
                }
                printf("C\tSF2\r\n");
                break;

            case SF3 : 
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp3_time = atoi(ptr);
                }
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp3_amp = atoi(ptr);
                }
                printf("C\tSF3\r\n");
                break;

            case SF4 : 
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp4_time = atoi(ptr);
                }
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp4_amp = atoi(ptr);
                }
                printf("C\tSF4\r\n");
                break;

            case SF5 : 
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp5_time = atoi(ptr);
                }
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp5_amp = atoi(ptr);
                }
                printf("C\tSF5\r\n");
                break;

            case SF6 : 
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp6_time = atoi(ptr);
                }
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    fp6_amp = atoi(ptr);
                }
                printf("C\tSF6\r\n");
                break;

            case SPO :
                if(get_emission_status() == 1){
                    L_AMP = fp1_amp;
                    L_LATCH = 1;
                    __delay_us(DELAY_LATCH);
                    L_LATCH = 0;
                    for (int i=0 ; i < fp1_time ; i++){
                        __delay_us(15) ;
                    }
                    L_AMP = fp2_amp;
                    L_LATCH = 1;
                    __delay_us(DELAY_LATCH);
                    L_LATCH = 0;
                    for (int i=0 ; i < fp2_time ; i++){
                        __delay_us(15) ;
                    }
                    L_AMP = fp3_amp;
                    L_LATCH = 1;
                    __delay_us(DELAY_LATCH);
                    L_LATCH = 0;
                    for (int i=0 ; i < fp3_time ; i++){
                        __delay_us(15) ;
                    }
                    L_AMP = fp4_amp;
                    L_LATCH = 1;
                    __delay_us(DELAY_LATCH);
                    L_LATCH = 0;
                    for (int i=0 ; i < fp4_time ; i++){
                        __delay_us(15) ;
                    }
                    L_AMP = fp5_amp;
                    L_LATCH = 1;
                    __delay_us(DELAY_LATCH);
                    L_LATCH = 0;
                    for (int i=0 ; i < fp5_time ; i++){
                        __delay_us(15) ;
                    }
                    L_AMP = fp6_amp;
                    L_LATCH = 1;
                    __delay_us(DELAY_LATCH);
                    L_LATCH = 0;
                    for (int i=0 ; i < fp6_time ; i++){
                        __delay_us(15) ;
                    }
                    //L_AMP = 0x00;
                    printf("C\tSPO\r\n");      
                    }else if(get_emission_status() == 0){
                        printf("C\tEmission is already disabled.!!\n");
                    }
                break;         

            case TON :
                emission_on();
                printf("C\tTON\r\n");
                break;                
                
            case TOF :
                emission_off();
                printf("C\tTOF\r\n");
                break;                

            case VEW :
                printf("C\tFP1_TIME\t%6d   FP1_AMP\t%6d\r\n", fp1_time, fp1_amp);
                printf("C\tFP2_TIME\t%6d   FP2_AMP\t%6d\r\n", fp2_time, fp2_amp);
                printf("C\tFP3_TIME\t%6d   FP3_AMP\t%6d\r\n", fp3_time, fp3_amp);
                printf("C\tFP4_TIME\t%6d   FP4_AMP\t%6d\r\n", fp4_time, fp4_amp);
                printf("C\tFP5_TIME\t%6d   FP5_AMP\t%6d\r\n", fp5_time, fp5_amp);
                printf("C\tFP6_TIME\t%6d   FP6_AMP\t%6d\r\n", fp6_time, fp6_amp);
                printf("C\tEMISSION\t%6d\r\n", emission_status);
                break;
                
            case VER :
                printf("C\tVERSION 1.0\r\n");
                break;

            default : break;
        }
    }
}

void jpt_laser_init(void){
    L_PA = 0;
    L_MOD = 0;
    L_AMP = 0x00;
    LED1 = 0;
    for(int i=0 ; i < 20 ; i++){
        __delay_ms(50);
        LED1 ^= 1;
    }       
    LED1 = 1;
    printf("System initialization has been completed.!!\r\n");
}

void emission_on(void){
    L_MOD = 1;
    __delay_us(DELAY_MOD_START);
    L_PA = 1;
    __delay_us(DELAY_PA_START);
    emission_status = 1;
}

void emission_off(void){
    L_PA = 0;
    __delay_us(DELAY_PA_END);
    L_MOD = 0;
    __delay_us(DELAY_MOD_END);
    L_AMP = 0x00;
    emission_status = 0;
}

bool get_emission_status(void){
    return emission_status;
}

//void Start_Latch_Pulse(void){
//    // Timer1リセット
//    TMR1_CounterSet(0);
//    
//    // 40μsec後にL_LATCHをLowにする比較値設定
//    CCP1_SetCompareCount(320);  // 32MHz時
//    
//    // パルス開始
//    L_LATCH = 1;
//    TMR1_Start();
//}

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




