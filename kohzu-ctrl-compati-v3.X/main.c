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
#pragma config FOSC = INTOSC  // Oscillator Selection bits (INTRC oscillator; port I/O function on both RA6/OSC2/CLKO pin and RA7/OSC1/CLKI pin)
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


#define LEDON RA7 // Needle Stop
#define N_STOP RB2 // Needle Stop
#define N_NTD RB1 // Needle Touch Detection
#define N_NSD RB5 // Needle Start Position Drawback
#define N_NDD RB4 // Needle Touch Detection Drawback
#define SLCT RB3 // Modeselec, 0:External IO mode, 1:InternalRS-232C command
#define NTCH RB0 // Needle Touch detect
#define ROLL_P4 RA3 // ROLLER Phase4
#define ROLL_P3 RA2 // ROLLER Phase3
#define FS_CW RA1 // FS_CW
#define FS_CCW RA0 // FS_CCW
#define TR RB3 // Transistor
#define MAX_VALUE 32767
#define MIN_VALUE 1


enum command {
  RPS,
  WTB,
  OSC,
  NTD,
  NDO,
  NDD,
  NPD,
  NSP,
  NSD,
  VER,
  STS,
  NON
};

void main(void) {
    
    PORTA = 0x00;           // PORTAを初期化
    PORTB = 0x00;           // PORTBを初期化
    TRISA = 0b00000000;     // PORTAの入出力設定 全て出力 0:出力, 1:入力
    TRISB = 0b10000000;     // PORTBの入出力設定 RB0:NTCH は接触検知入力, RB1:NTD入力, RB2:STOP入力, RB4:NDO入力, RB5:NSD入力, RB6:RxD入力, RB7:TxD出力　 0:出力, 1:入力
//    TRISB = 0b01111111;     // PORTBの入出力設定 RB0:NTCH は接触検知入力, RB1:NTD入力, RB2:STOP入力, RB4:NDO入力, RB5:NSD入力, RB6:RxD入力, RB7:TxD出力　 0:出力, 1:入力
    APFCON1 = 0b00000110;   // RB7=>RxD, RB6=>TxD
    PIE1 = 0b00110000;  //PERIPHERAL INTERRUPT ENABLE REGISTER 1
    
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
    int npd = 2500;
    int nsp = 1000;
    char ln[4];
    
    char *ptr;

    enum command cmd; // enum型のオブジェクトを定義

    N_NTD = 1;
    N_NSD = 1;
    N_NDD = 1;
    SLCT = 1;

    
    while(1){

        cmd = NON;
        
        rcmd[0] = 'Q'; 
        rcmd[1] = 'Q'; 
        rcmd[2] = 'Q'; 
        rcmd[3] = '\0'; 

        tmp[0] = 'Q';
        tmp[1] = 'Q';
        tmp[2] = 'Q';
        tmp[3] = '\0';

//        if (SLCT == 0){
//            if(N_NTD == 0){
//                cmd = NTD;
//            }else if(N_NSD == 0){
//                cmd = NSD;
///            }else if(N_NDD == 0){
//                cmd = NDD;
//            }
//        } else {
//            gets(tmp);
//        }

//        gets(tmp);
        tmp[0]= '1';
        tmp[1]= 'E';
        tmp[2]= '2';
        tmp[3]= 'T';
        printf("%s\n", tmp);
        printf("TEST\n");
        
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';


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
        }else if(strcmp(rcmd,"NDD") == 0){
            cmd = NDD;
        }else if(strcmp(rcmd,"VER") == 0){
            cmd = VER;
        }else if(strcmp(rcmd,"STS") == 0){
            cmd = STS;
        }else if(strcmp(rcmd,"NPD") == 0){
            cmd = NPD;
        }else if(strcmp(rcmd,"NSP") == 0){
            cmd = NSP;
        }else if(strcmp(rcmd,"NSD") == 0){
            cmd = NSD;
        }
        ptr = strtok(tmp, "/");

        LEDON = 1;
        __delay_ms(500);
        LEDON = 0;
        __delay_ms(500);
  
          
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
                    } else {
                        dist *= -1;
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
                    }

//                    puts("C");
                    printf("C\tOSC\r\n"); // 送信
                    break;

            case NTD : 
                    dist = 10000;
                    for(k = 0 ; k < dist ; k++){
                        FS_CCW = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CCW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(NTCH == 0){
                            break;
                        }

                    }
//                    puts("C");
                    printf("C\tNTD\r\n"); // 送信

                    break;
                        
            case NDO : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        dist = atoi(ptr);
                    }
                    
                    for(k = 0 ; k < 10000 ; k++){
                        FS_CCW = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CCW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(NTCH == 0){
                            break;
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

//                    puts("C");
                    printf("C\tNDO\r\n"); // 送信
                    break;

            case NDD : 
                    for(k = 0 ; k < 10000 ; k++){
                        FS_CCW = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CCW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }

                        if(NTCH == 0){
                            break;
                        }
                    }
                    
                    for(k = 0 ; k < npd ; k++){
                        FS_CW = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }

//                    puts("C");
                    printf("C\tNDD\r\n"); // 送信
                    break;

            case NSD : 
                    
                    for(k = 0 ; k < nsp ; k++){
                        FS_CW = 1;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                        FS_CW = 0;
                        for(j = 0 ; j < intvl ; j++){
                            __delay_us(1);
                        }
                    }

//                    puts("C");
                    printf("C\tNSD\r\n"); // 送信
                    break;

            case NPD : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        npd = atoi(ptr);
                    }
                    printf("C\tNPD\r\n");
                    break;

            case NSP : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        nsp = atoi(ptr);
                    }
                    printf("C\tNSP\r\n");
                    break;

            case STS : 
                    printf("C\tREADY\r\n");
                    break;

            case VER : 
                    printf("C\tVERSION 3\r\n");
                    break;
                        
            default : break;
        }
        
//        if(NTCH == 0){
//            printf("SW OFF");
//        }else{
//            printf("SW ON");
//        }
    }
}

