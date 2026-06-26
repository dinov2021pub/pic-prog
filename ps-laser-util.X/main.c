/* 
 * File:   main.c
 *
 * Author: Shuichi Dejima
 *
 * Created on 2023/10/16, 14:00
 * Controller for Suruga seiki motor driver 
 *  */

#define _XTAL_FREQ 4000000      // システムクロック4MHz

#include <xc.h>        // 1. デバイス固有（最優先）
#include <stdint.h>    // 2. 型定義
#include <stdbool.h>   // 3. bool型
#include <string.h>    // 4. 文字列操作
#include <stdio.h>     // 5. 標準I/O
#include <stdlib.h>    // 6. 標準ライブラリ

// CONFIG1
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTRC oscillator; port I/O function on both RA6/OSC2/CLKO pin and RA7/OSC1/CLKI pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include "uart.h"
#include "pwm.h"

/* ===========================
 * マクロの宣言
 * =========================== */
#define P_LED PORTAbits.RA0              
#define P_DCF PORTAbits.RA1               
#define P_LD PORTAbits.RA2                
#define S_HAL PORTAbits.RA3
#define P_SHT_CW PORTBbits.RB0
#define P_SHT_CCW PORTBbits.RB5

#define CLOSE_DUTY_STG1 50
#define CLOSE_DUTY_STG2 30
#define OPEN_DUTY_STG1 80
#define OPEN_DUTY_STG2 40
#define SHT_DUTY_OFF 0

#define CLOSE_TIME_INIT 17
#define CLOSE_TIME_STG1 3
//#define CLOSE_TIME_STG2 3
#define OPEN_TIME_INIT 18
#define OPEN_TIME_STG1 5
//#define OPEN_TIME_STG2 5

/* ===========================
 * 型の宣言
 * =========================== */
enum command {
  VER, 
  LDP,
  DCF,
  SHT,
  HAL,
  SAF
};

/* ===========================
 * プロトタイプの宣言
 * =========================== */
void uart_init(void);
void pwm_init(void);
void tmr0_init(void);
void ps_laser_util_init(void);
void shutter_open(void);
void shutter_close(void);
uint8_t get_hall_status(void);
uint8_t shutter_safe(void);

/* ===========================
 * グローバル変数定義
 * =========================== */
static uint8_t ld_on_off = 0;
static uint8_t dcf_on_off = 0;
static uint8_t sht_on_off = 0;
static uint8_t hall_status = 0;  // 0: OPEN, 1: CLOSE
static uint8_t sht_status = 0;
static uint8_t safe_status = 0;

/* ===========================
 * メイン処理
 * =========================== */
void main(void) {
    
    CMCON = 0b00000111;     // RA0-RA3はデジタルピン設定、コンパレータは使用しない
    TRISA = 0b00001000;     // PORTAの入出力設定 RA3はホール素子、RA0はLED、RA1はDCファン、RA2はレッドレーザー
    TRISB = 0b00000010;     // PORTBの入出力設定  RB1はUART受信(RX)、RB2はUART送信(TX)、RB0はシャッターCW、RB5はシャッターCCW、RB3はPWM出力
    PORTA = 0x00;           // PORTAを初期化
    PORTB = 0x00;           // PORTBを初期化
 
    char tmp[40];
    int axis = 0;
    char rcmd[4];
    char *ptr;
    
    uart_init();
    pwm_init();
    ps_laser_util_init();
    
    while(1){
        rcmd[0] = 'Q'; 
        rcmd[1] = 'Q'; 
        rcmd[2] = 'Q'; 
        rcmd[3] = '\0'; 

        tmp[0] = 'Q';
        tmp[1] = 'Q';
        tmp[2] = 'Q';
        tmp[3] = 'Q';
        tmp[4] = '\0';

        //gets(tmp);
        uart_gets(tmp, sizeof(tmp));
        
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';

        axis = atoi(&tmp[4]);

        enum command cmd; // enum列挙型とオブジェクトの定義

        if(strcmp(rcmd,"VER") == 0) {
            cmd = VER;
        }else if(strcmp(rcmd,"LDP") == 0){
            cmd = LDP;
        }else if(strcmp(rcmd,"DCF") == 0){
            cmd = DCF;
        }else if(strcmp(rcmd,"SHT") == 0){
            cmd = SHT;
        }else if(strcmp(rcmd,"HAL") == 0){
            cmd = HAL; 
        }else if(strcmp(rcmd,"SAF") == 0){
            cmd = SAF;
        }else {
            continue;// 一致する文字がないならwhileの先頭に戻る
        }
        
        ptr = strtok(tmp, "/");

        switch(cmd){
            
            case VER :
                printf("C\tVERSION 3.0\r\n");
                break;
                
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
                    
            case DCF : 
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    dcf_on_off = atoi(ptr);
                }
                if(dcf_on_off == 0){
                    P_DCF = 0;                
                }else if(dcf_on_off == 1){
                    P_DCF = 1;                
                }
                printf("C\tDCF\t%d\r\n", dcf_on_off);
                break;
                    
            case SHT : 
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    sht_on_off = atoi(ptr);
                }
                if(sht_on_off == 0){
                    shutter_close();//シャッター閉
                }else if(sht_on_off == 1){
                    shutter_open();//シャッター開
                }
                hall_status = get_hall_status();
                printf("C\tSHT\t%d\tHAL\t%d\r\n", sht_on_off,hall_status);
                break;
   
            case HAL :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    hall_status = atoi(ptr);
                }
                hall_status = get_hall_status();
                printf("C\tHAL\t%d\r\n", hall_status);
                break;
                
            case SAF :
                safe_status = shutter_safe();
                if(safe_status == 1){
                    // シャッター異常動作
                    printf("C\tShutter error. Do NOT emmition the laser.\r\n");
                    printf("C\tSHT\t%d\tHAL\t%d\r\n", sht_on_off,hall_status);
                    P_LED = 0;
                }else{
                    // シャッター正常動作
                    printf("C\tThe shutter is operating normally.\r\n");
                    printf("C\tSHT\t%d\tHAL\t%d\r\n", sht_on_off,hall_status);
                    P_LED = 1;
                }
                break;
                
            default : break;
        }
    }
}

void ps_laser_util_init(void){
    sht_on_off = 1;
    shutter_open();
    for(int i=0 ; i < 50 ; i++){
        __delay_ms(50);
        P_LED ^= 1;
    }
    safe_status = shutter_safe();
    if(safe_status == 1){
        // シャッター異常動作
        printf("Shutter error. Do NOT emmition the laser.\r\n");
        printf("C\tSHT\t%d\tHAL\t%d\r\n", sht_on_off,hall_status);
        P_LED = 0;
    }else{
        // シャッター正常動作
        printf("System initialization has been completed!!\r\n");
        printf("C\tSHT\t%d\tHAL\t%d\r\n", sht_on_off,hall_status);
        P_LED = 1;
    }
}

void shutter_open(void){
    pwm_percent(SHT_DUTY_OFF);
    __delay_ms(10);
    P_SHT_CW = 1;
    P_SHT_CCW = 0;
    __delay_ms(10);
    __delay_ms(OPEN_TIME_INIT);
    pwm_percent(OPEN_DUTY_STG1);
    __delay_ms(OPEN_TIME_STG1);
    pwm_percent(OPEN_DUTY_STG2);
}

void shutter_close(void){
    pwm_percent(SHT_DUTY_OFF);
    __delay_ms(10);
    P_SHT_CW = 0;
    P_SHT_CCW = 1;
    __delay_ms(10);
    __delay_ms(CLOSE_TIME_INIT);
    pwm_percent(CLOSE_DUTY_STG1);
    __delay_ms(CLOSE_TIME_STG1);
    pwm_percent(CLOSE_DUTY_STG2);
}

uint8_t get_hall_status(void){
    return S_HAL;
}

uint8_t shutter_safe(void) {
    /*
     * シャッター開(SHT/1)のときホール素子L、LED消灯
     * シャッター閉(SHT/0)のときホール素子H、LED点灯
     */
    hall_status = get_hall_status();
    if (hall_status ^ sht_on_off == 0) {
        // シャッター異常動作
        return 1;
    } else {
        // シャッター正常動作
        return 0;
    }
}