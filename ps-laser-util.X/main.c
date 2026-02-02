/* 
 * File:   main.c
 *
 * Author: Shuichi Dejima
 *
 * Created on 2023/10/16, 14:00
 * Controller for Suruga seiki motor driver 
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

#define _XTAL_FREQ 4000000      // システムクロック4MHz

#define S_SHT RA0               //フォトインタラプタ入力信号
#define P_DCF RA1               // DC fan ON/OFF
#define P_LD RA2                // LD red pointer ON/OFF
////Version 2.0
//#define P_SHT_CW RB3            // シャッター CW
//#define P_SHT_CCW RA3           // シャッター CCW
//Version 3.0
#define P_SHT_CW RB0            // シャッター CW
#define P_SHT_CCW RA3           // シャッター CCW

enum command {
  VER, 
  LDP,  //レーザー
  DCF,  //DCファン
  SHT,  //シャッター
  PHO,  //フォトインタラプタ
  NON
};

void main(void) {
    
    PORTA = 0x00;           // PORTAを初期化
    PORTB = 0x00;           // PORTBを初期化
//    //Version 2.0
//    TRISA = 0b00000001;     // PORTAの入出力設定 RA0はフォトインタラプタ、RA1はDCファン、RA2は位置合わせレーザー
//    TRISB = 0b00000010;     // PORTBの入出力設定  RB1はUART受信(RX)、RB2はUART送信(TX)、RB3はシャッターCW、RA3はシャッターCCW
    //Version 3.0  
    TRISA = 0b00000001;     // PORTAの入出力設定 RA0はフォトインタラプタ、RA1はDCファン、RA2は位置合わせレーザー
    TRISB = 0b00000010;     // PORTBの入出力設定  RB1はUART受信(RX)、RB2はUART送信(TX)、RB0はシャッターCW、RA3はシャッターCCW、RB3はPWM出力
    CMCON = 0b00000111;     // コンパレータは使用しない(RA0-RA3はデジタルピンで使用)

    initUART();             // 調歩同期式シリアル通信設定
 
    char tmp[40];
    int axis = 0;
    char rcmd[4];
    char rps_cmd[6];    // For tmp strings of RPS command
    char wtb_cmd[6];    // For tmp strings of WTB command

    unsigned char ld_on_off = 0;
    unsigned char dcf_on_off = 0;
    unsigned char sht_on_off = 0;
    unsigned char pho_status = 0;
    
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
        }else if(strcmp(rcmd,"PHO") == 0){
            cmd = PHO;          
        }else{   
            cmd = NON;
        }
        
        ptr = strtok(tmp, "/");
        rps_cmd[0]='\0';
        rps_cmd[1]='\0';
        rps_cmd[2]='\0';
        rps_cmd[3]='\0';
        
        int i;
        
        for (i = 0; ptr[i] != '\0'; i++) {
            rps_cmd[i] = ptr[i];
        }

        for (i = 0; ptr[i] != '\0'; i++) {
            wtb_cmd[i] = ptr[i];
        }
 
        switch(cmd){
            
            case VER :
//                    // Version 2.0
//                    printf("C\tVERSION 2.0\r\n");
                    // Version 3.0
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
                // Version 2.0
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    sht_on_off = atoi(ptr);
                }
                if(sht_on_off == 0){
                    P_SHT_CW = 1;
                    P_SHT_CCW = 0;
                    __delay_ms(30);
                    P_SHT_CW = 0;
                    P_SHT_CCW = 0;
                    pho_status = S_SHT;
                }else if(sht_on_off == 1){
                    P_SHT_CW = 0;
                    P_SHT_CCW = 1;
                    __delay_ms(30);
                    P_SHT_CW = 0;
                    P_SHT_CCW = 0;
                    pho_status = S_SHT;
                }
                printf("C\tSHT\t%d\tPHO\t%d\r\n", sht_on_off,pho_status);
                break;
                // Version 3.0
                      
                case PHO :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    pho_status = atoi(ptr);
                }
                printf("C\tPHO\t%d\r\n", pho_status);
                break;
                    
            default : break;
        }
    }
}

