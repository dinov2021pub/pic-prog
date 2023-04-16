/* 
 * File:   main.c
 * Author: Dejima_desktop
 *
 * Author: Shuichi Dejima
 *
 * Created on 2019/06/03, 15:26
 */

// CONFIG1
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTRC oscillator; port I/O function on both RA6/OSC2/CLKO pin and RA7/OSC1/CLKI pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include <stdio.h>
#include "uart.h"
#include <stdlib.h>
#include <string.h>

#define _XTAL_FREQ 4000000      // 4MHz

#define LASER RB5 // True ON LASER
#define MOTOR RB4 // True ON MOTOR
#define M_IN1 RA2 // H-bridge IN1
#define M_IN2 RA3 // H-bridge IN2
#define TR RB3 // Transistor
#define MAX_VALUE 32767
#define MIN_VALUE 1

void main(void) {
    
    PORTA = 0x00;           // PORTAを初期化
    PORTB = 0x00;           // PORTBを初期化
    TRISA = 0b00000011;     // PORTAの入出力設定 RA0はA相, RA1はB相
    TRISB = 0b00000010;     // PORTBの入出力設定 RB1はRX
    CMCON = 0b00000111;     // コンパレータは使用しない(RA0-RA4はデジタルピンで使用)
    
    initUART();             // 調歩同期式シリアル通信設定
 
    char tmp[20];
    unsigned int val = 0;
    int pre_RA0 = 0;
    int pre_RA1 = 0;
//    int no_loop;
//    int no_step = 1;
//    int length;
    int p = 1;   //エンコーダスリットピッチ 
    int dist = 0;  // 測長距離
    int d = 1;
//    float d = 1 / 4;
    
    while(1){

        __delay_ms(500);
        MOTOR = 1;
        __delay_ms(500);
        MOTOR = 0;
        
        if (pre_RA0 == 0 && pre_RA1 == 0) {
                if(RA0 == 1){
                    dist += d; 
                }
                if(RA1 == 1){
                    dist -= d;
                }
        }
 
        if (pre_RA0 == 1 && pre_RA1 == 0) {
                if(RA0 == 0){
                    dist -= d; 
                }
                if(RA1 == 1){
                    dist += d;
                }
        }
 
        if (pre_RA0 == 0 && pre_RA1 == 1) {
                if(RA0 == 1){
                    dist -= d; 
                }
                if(RA1 == 0){
                    dist += d;
                }
        }
                
        if (pre_RA0 == 1 && pre_RA1 == 1) {
                if(RA0 == 0){
                    dist += d; 
                }
                if(RA1 == 0){
                    dist -= d;
                }
        }
        
        pre_RA0 = RA0;
        pre_RA1 = RA1;
        printf("%d, %d, %d, %d\r\n", pre_RA0, RA0, pre_RA1, RA1);
        printf("%d\r\n", dist);
//        printf("dist = %f\r\n", dist); // 送信

    }
}
