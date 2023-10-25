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

#define FS_CCW RA1 // femto-Spotter axis CCW
#define FS_CW RA0 // femto-Spotter axis CW
#define NTCH RB0 // femto-Spotter Needle Touch detect
#define TR RB3 // Transistor
#define MAX_VALUE 32767
#define MIN_VALUE 1


enum command {
  RPS,
  WTB,
  OSC,
  NTD,
  NDO,
  VER,
  STS,
  NON
};

void main(void) {
    
    PORTA = 0x00;           // PORTAを初期化
    PORTB = 0x00;           // PORTBを初期化
    TRISA = 0b00000000;     // PORTAの入出力設定 全て出力
    TRISB = 0b00000011;     // PORTBの入出力設定 RB1はRX, RB0 は入力
    CMCON = 0b00000111;     // コンパレータは使用しない(RA0-RA4はデジタルピンで使用)
    
    initUART();             // 調歩同期式シリアル通信設定
 
    char tmp[40];
    int j = 10;
    int k = 0;
    int cnt = 10;
    int dist = 10;
    int intvl = 20;
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
        
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';

        enum command cmd; // enum型のオブジェクトを定義

        cmd = VER;
        
        if(strcmp(rcmd,"RPS") == 0) {
            cmd = RPS;
        }else if(strcmp(rcmd,"WTB") == 0){
            cmd = WTB;
        }else if(strcmp(rcmd,"OSC") == 0){
            cmd = OSC;
        }else if(strcmp(rcmd,"NTD") == 0){
            cmd = NTD;
        }else if(strcmp(rcmd,"NDO") == 0){
            cmd = NDO;
        }else if(strcmp(rcmd,"VER") == 0){
            cmd = VER;
        }else if(strcmp(rcmd,"STS") == 0){
            cmd = STS;
        }else{
            cmd = NON;
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
                    
                    if (dist > 0){
                        for(k = 0 ; k < dist ; k++){
                            FS_CW = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    } else {
                        dist *= -1;
                        for(k = 0 ; k < dist ; k++){
                            FS_CCW = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CCW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    }

//                    puts("C");
                    printf("C\tRPS\r\n"); // 送信
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
                    printf("C\tWTB\r\n"); // 送信

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
                    
                    if (dist > 0){
                        for(k = 0 ; k < dist ; k++){
                            FS_CW = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                        for(k = 0 ; k < dist ; k++){
                            FS_CCW = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CCW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    } else {
                        dist *= -1;
                        for(k = 0 ; k < dist ; k++){
                            FS_CCW = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CCW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                        for(k = 0 ; k < dist ; k++){
                            FS_CW = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            FS_CW = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    }

//                    puts("C");
                    printf("C\tOSC\r\n"); // 送信
                    //printf("C\r\n"); // 送信
                    break;

            case NTD : 
                    dist = 10000;
                    for(k = 0 ; k < dist ; k++){
                        FS_CW = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(RB0 == 0){
                            printf("Detected\n");
                            break;
                        }

                    }
//                    puts("C");
//                    printf("C\r\n"); // 送信
                    printf("C\tNTD\r\n"); // 送信

                    break;
                        
            case NDO : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        dist = atoi(ptr);
                    }
                    
                    for(k = 0 ; k < 10000 ; k++){
                        FS_CW = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(RB0 == 0){
                            break;
                        }

                    }
                    
                    for(k = 0 ; k < dist ; k++){
                        FS_CCW = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CCW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }

//                    puts("C");
                    printf("C\tNDO\r\n"); // 送信
                    break;

            case STS : 
                    printf("C\tREADY\r\n");
                    break;

            case VER : 
                    printf("C\tVERSION 0\r\n");
                    break;
                        
            default : break;
        }
 
    }
}

