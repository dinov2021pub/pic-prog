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

#define MOTOR_P4 RB7 // MOTOR Phase4
#define MOTOR_P3 RB6 // MOTOR Phase3
#define MOTOR_P2 RB5 // MOTOR Phase2
#define MOTOR_P1 RB4 // MOTOR Phase1
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
    int j = 10;
    int k = 0;
    int cnt = 0;
    int intvl = 10;
    
    while(1){

        puts("OK");
        printf("OK\r\n"); // 送信

        gets(tmp);

        switch(tmp[0]){
            case 'f' : cnt = 20;
                        for(k = 0 ; k < cnt ; k++){
                            MOTOR_P1 = 1;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 1;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 1;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                        }

                        puts("MOTOR = F  OK");
                        printf("MOTOR = F  OK\r\n"); // 送信
                        break;
                        
            case 'b' :  cnt = 20;
                        for(k = 0 ; k < cnt ; k++){
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 1;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 1;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 1;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                        }
                        puts("MOTOR = B  OK");
                        printf("MOTOR = B  OK\r\n"); // 送信
                        break;

            case 'p' :  intvl = 1;
                        break;
            case 'o' :  intvl = 2;
                        break;
            case 'i' :  intvl = 5;
                        break;
            case 'u' :  intvl = 10;
                        break;
            case 'y' :  intvl = 20;
                        break;
            case 't' :  intvl = 50;
                        break;
                        
            default : break;
        }

        printf("%d\r\n", dist);
//        printf("dist = %f\r\n", dist); // 送信

    }
}
