/* 
 * File:   main.c
 *
 * Author: Shuichi Dejima
 *
 * Created on 2023/10/16, 14:00
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

//#define MOTOR_P4 RB7 // MOTOR Phase4
//#define MOTOR_P3 RB6 // MOTOR Phase3
#define X_P2 RB5 // X axis CW
#define X_P1 RB4 // X axis CCW
#define Y_P2 RA3 // Y axis CW
#define Y_P1 RA2 // Y axis CCW
#define NEEDLE_P2 RA1 // Needle axis CW
#define NEEDLE_P1 RA0 // Needle axis CCW
//#define M_IN1 RA2 // H-bridge IN1
//#define M_IN2 RA3 // H-bridge IN2
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
    int axis = 0;
    char rcmd[4];
    char rps_cmd[6];
    int mx_spd = 20250;
    int set_spd;
//    char ln[4];
    
    char *ptr;
    
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

        gets(tmp);
//        printf("%s\n", tmp);
        
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';

        axis = atoi(tmp[4]);

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
//        rps_cmd = ptr;
//        printf("axis= %d\r\n", axis); // 送信
        rps_cmd[0]='\0';
        rps_cmd[1]='\0';
        rps_cmd[2]='\0';
        rps_cmd[3]='\0';
        //rps_cmd[4]='\0';
        int i;
        for (i = 0; ptr[i] != '\0'; i++) {
            rps_cmd[i] = ptr[i];
        }
        
//        printf("tmp = %s\r\n", rps_cmd); // 送信
//        printf("rmd_d= %d\r\n", atoi(tmp[3])); // 送信

          
        switch(cmd){

            case RPS : 
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        dist = atoi(ptr);
                    }
                    
                    if(strstr(rps_cmd,"RPS1") != NULL){
                        if (dist > 0){
                            for(k = 0 ; k < dist ; k++){
                                X_P1 = 1;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                                X_P1 = 0;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                            }
                        } else {
                            dist *= -1;
                            for(k = 0 ; k < dist ; k++){
                                X_P2 = 1;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                                X_P2 = 0;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                            }
                        }
                        
                    }
                    else if(strstr(rps_cmd,"RPS2")  != NULL){
                        if (dist > 0){
                            for(k = 0 ; k < dist ; k++){
                                Y_P1 = 1;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                                Y_P1 = 0;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                            }
                        } else {
                            dist *= -1;
                            for(k = 0 ; k < dist ; k++){
                                Y_P2 = 1;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                                Y_P2 = 0;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                            }
                        }
                        
                    }
                    else if(strstr(rps_cmd,"RPS3")  != NULL){
                        if (dist > 0){
                            for(k = 0 ; k < dist ; k++){
                                NEEDLE_P1 = 1;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                                NEEDLE_P1 = 0;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                            }
                        } else {
                            dist *= -1;
                            for(k = 0 ; k < dist ; k++){
                                NEEDLE_P2 = 1;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                                NEEDLE_P2 = 0;
                                for(j = 0 ; j < intvl ; j++){
                                    __delay_us(1);
                                }
                            }
                        }
                        
                    }

//                    puts("C");
                    printf("C\tRPS%d\r\n", axis); // 送信
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
//                    printf("dist = %d\n", dist);
                    
                    if (dist > 0){
                        for(k = 0 ; k < dist ; k++){
                            NEEDLE_P1 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            NEEDLE_P1 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                        for(k = 0 ; k < dist ; k++){
                            NEEDLE_P2 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            NEEDLE_P2 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                    } else {
                        dist *= -1;
                        for(k = 0 ; k < dist ; k++){
                            NEEDLE_P2 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            NEEDLE_P2 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                        }
                        for(k = 0 ; k < dist ; k++){
                            NEEDLE_P1 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_us(1);
                            }
                            NEEDLE_P1 = 0;
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
//                    printf("NTD\n");
                    dist = 10000;
                    for(k = 0 ; k < dist ; k++){
                        NEEDLE_P1 = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        NEEDLE_P1 = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(RB0 == 0){
//                            printf("Detected\n");
                            break;
                        }

                    }
//                    puts("C");
//                    printf("C\r\n"); // 送信
                    printf("C\tNTD\r\n"); // 送信

                    break;
                        
            case NDO : 
//                    printf("NDO\n");
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        dist = atoi(ptr);
                    }
//                    printf("dist = %d\n", dist);
                    
                    for(k = 0 ; k < 10000 ; k++){
                        NEEDLE_P1 = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        NEEDLE_P1 = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(RB0 == 0){
//                            printf("Detected");
                            break;
                        }

                    }
                    
                    for(k = 0 ; k < dist ; k++){
                        NEEDLE_P2 = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        NEEDLE_P2 = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }

//                    puts("C");
//                    printf("C\r\n"); // 送信
                    printf("C\tNDO\r\n"); // 送信
                    break;

            case STS : 
                    printf("C\tREADY\r\n");
                    break;

            case VER : cnt=10;
                    printf("C\tVERSION 10\r\n");
                    break;
                        
            default : break;
        }
        
//        if(RB0 == 0){
//            printf("SW OFF");
//        }else{
//            printf("SW ON");
//        }
    }
}

