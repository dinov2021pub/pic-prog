/* 
 * File:   main.c
 *
 * Author: Shuichi Dejima
 *
 * Created on 2023/04/29, 15:26
 * Compatible to Kohzu Controller for femto-spotter
 * Ref: Operation_ManualJ_for_SC210_410_rev2.pdf
 *  */

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
#define ROLL_P4 RA3 // ROLLER Phase4
#define ROLL_P3 RA2 // ROLLER Phase3
#define ROLL_P2 RA1 // ROLLER Phase2
#define ROLL_P1 RA0 // ROLLER Phase1
//#define M_IN1 RA2 // H-bridge IN1
#//define M_IN2 RA3 // H-bridge IN2
#define TR RB3 // Transistor
#define MAX_VALUE 32767
#define MIN_VALUE 1


enum command {
  RPS,
  WTB,
  OSC,
  VE
};

void main(void) {
    
    PORTA = 0x00;           // PORTAを初期化
    PORTB = 0x00;           // PORTBを初期化
    TRISA = 0b00000000;     // PORTAの入出力設定 全て出力
    TRISB = 0b00000010;     // PORTBの入出力設定 RB1はRX
    CMCON = 0b00000111;     // コンパレータは使用しない(RA0-RA4はデジタルピンで使用)
    
    initUART();             // 調歩同期式シリアル通信設定
 
    char tmp[40];
    int j = 10;
    int k = 0;
    int cnt = 10;
    int dist = 10;
    int intvl = 50;
    char rcmd[4];
    int mx_spd = 20250;
    int set_spd;
    char ln[4];
    
    char *ptr;
    
    while(1){
        rcmd[0] = 'Q'; 
        rcmd[1] = 'Q'; 
        rcmd[2] = 'Q'; 
        rcmd[3] = '\0'; 

        tmp[0] = 'Q';
        tmp[1] = 'Q';
        tmp[2] = 'Q';
        tmp[3] = '\0';

        gets(tmp);
        printf("%s\n", tmp);
        
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';


        enum command cmd; // enum型のオブジェクトを定義

        cmd = VE;
        
        if(strcmp(rcmd,"RPS") == 0) {
            cmd = RPS;
        }else if(strcmp(rcmd,"WTB") == 0){
            cmd = WTB;
        }else if(strcmp(rcmd,"OSC") == 0){
            cmd = OSC;
        }
        ptr = strtok(tmp, "/");

          
        switch(cmd){

            case RPS : 
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        dist = atoi(ptr);
                    }
                    printf("dist = %d\n", dist);
                    
                    if (dist > 0){
                        for(k = 0 ; k < dist ; k++){
                            ROLL_P1 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            ROLL_P1 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    } else {
                        dist *= -1;
                        for(k = 0 ; k < dist ; k++){
                            ROLL_P2 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            ROLL_P2 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    }

                    puts("C");
                    printf("C\r\n"); // 送信
                    break;
                        
            case WTB : 
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        set_spd = atoi(ptr);
                    }
                    intvl = mx_spd / set_spd;
                    if (intvl == 0){
                        intvl = 1;
                    }
                    break;
 
            case OSC : 
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        dist = atoi(ptr);
                    }
                    printf("dist = %d\n", dist);
                    
                    if (dist > 0){
                        for(k = 0 ; k < dist ; k++){
                            ROLL_P1 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            ROLL_P1 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                        for(k = 0 ; k < dist ; k++){
                            ROLL_P2 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            ROLL_P2 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    } else {
                        dist *= -1;
                        for(k = 0 ; k < dist ; k++){
                            ROLL_P2 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            ROLL_P2 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                        for(k = 0 ; k < dist ; k++){
                            ROLL_P1 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            ROLL_P1 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    }

                    puts("C");
                    printf("C\r\n"); // 送信
                    break;
                        
            case VE : cnt=10;
                        break;
                        
            default : break;
        }
    }
}

