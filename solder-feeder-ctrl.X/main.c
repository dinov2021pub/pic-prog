/* 
 * File:   main.c
 *
 * Author: Shuichi Dejima
 *
 * Created on 2023/04/22, 15:26
 *
 * Ref: フィーダーコントロールユニット仕様書 
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
  F,
  R,
  MF,
  MR,
  FC,
  VE
};

void main(void) {
    
    PORTA = 0x00;           // PORTAを初期化
    PORTB = 0x00;           // PORTBを初期化
    TRISA = 0b00000000;     // PORTAの入出力設定 全て出力
    TRISB = 0b00000010;     // PORTBの入出力設定 RB1はRX
    CMCON = 0b00000111;     // コンパレータは使用しない(RA0-RA4はデジタルピンで使用)
    
    initUART();             // 調歩同期式シリアル通信設定
 
    char tmp[20];
    int j = 10;
    int k = 0;
    int cnt = 10;
    int intvl = 10;
    
    char *ptr;
    
    while(1){

        gets(tmp);
        
        char rcmd[4];
        char speed[5];
        int mx_spd = 500;
        int set_spd;
        int spd;
        char ln[4];
        int hln;
        
        rcmd[0] = tmp[0];
        rcmd[1] = tmp[1];
        rcmd[2] = tmp[2];
        rcmd[3] = '\0';
       
        enum command cmd; // enum型のオブジェクトを定義
        
        if(strcmp(rcmd,"$7F") == 0) {
            cmd = F;
        }else if(strcmp(rcmd,"$7R") == 0) {
            cmd = R;
        }else if(strcmp(rcmd,"$MF") == 0) {
            cmd = MF;
        }else if(strcmp(rcmd,"$MR") == 0) {
            cmd = MR;
        }else if(strcmp(rcmd,"$FC") == 0) {
            cmd = FC;
        }else if(strcmp(rcmd,"$VE") == 0) {
            cmd = VE;
        }

        printf("%s\n", tmp);
        printf("%d\n", cmd);
          
        switch(cmd){

            case F : speed[0] = tmp[3];
                    speed[1] = tmp[4];
                    speed[2] = tmp[5];
                    speed[3] = tmp[6];
                    speed[4] = '\0';
                    spd = atoi(speed);
                    printf("speed = %d\r", spd);
                    ln[0] = tmp[8];
                    ln[1] = tmp[9];
                    ln[2] = tmp[10];
                    ln[4] = '\0';
                    hln = atoi(ln);
                    printf("length = %d\r", hln);
                    
                    cnt=20;
                        intvl = (int)(mx_spd / spd);
                        for(k = 0 ; k < hln ; k++){
                            MOTOR_P1 = 1;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(100);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 1;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(100);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 1;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(100);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(100);
                            }
                        }

                        puts("MOTOR = F  OK");
                        printf("MOTOR = F  OK\r\n"); // 送信
                        break;
                        
            case R : speed[0] = tmp[3];
                    speed[1] = tmp[4];
                    speed[2] = tmp[5];
                    speed[3] = tmp[6];
                    speed[4] = '\0';
                    spd = atoi(speed);
                    printf("speed = %d\r", spd);
                    ln[0] = tmp[8];
                    ln[1] = tmp[9];
                    ln[2] = tmp[10];
                    ln[4] = '\0';
                    hln = atoi(ln);
                    printf("length = %d\r", hln);
                     cnt = 20;
                        intvl = (int)(mx_spd / spd);
                        for(k = 0 ; k < hln ; k++){
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(100);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 1;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(100);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 1;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(100);
                            }
                            MOTOR_P1 = 1;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(100);
                            }
                        }
                        puts("MOTOR = B  OK");
                        printf("MOTOR = B  OK\r\n"); // 送信
                        break;
 
            case MF :  cnt = 60;
                       printf("MF\r"); // 送信
                        break;
            case MR :  cnt = 60;
                       printf("MR\r"); // 送信
                        break;
            case FC :  cnt = 60;
                       printf("FCr"); // 送信
                        break;
            case VE : puts("$1.0\r");
                       printf("$1.0\r"); // 送信
                        break;
                        
            default : break;
        }

    }
}

