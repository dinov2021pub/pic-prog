/* 
 * File:   main.c
 *
 * Author: Shuichi Dejima
 *
 * Created at 2023/09/12
 * Analog output controller with RS-232C comunication
 * PIC16F1705 - FT234X USBシリアル変換モジュール
 * 
 * Ref: Operation_ManualJ_for_SC210_410_rev2.pdf
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <string.h>

// CONFIG1
#pragma config FOSC = INTOSC    //内部クロックを使う
#pragma config WDTE = OFF       //ウォッチドックタイマー無効
#pragma config PWRTE = ON       //パワーアップタイマーを有効にする
#pragma config MCLRE = OFF      //MCLRピンをRA3として使用する
#pragma config CP = OFF         //プログラムメモリを保護しない
#pragma config BOREN = ON       //ブラウンアウトリセットを有効にする
#pragma config CLKOUTEN = OFF   //クロック出力を無効とし、RA4ピンとして使用する
#pragma config IESO = OFF       //内部・外部クロックの切り替えでの起動を行わない
#pragma config FCMEN = OFF      //外部クロックを監視しない
 
// CONFIG2
#pragma config WRT = OFF        //フラッシュメモリを保護しない
#pragma config PPS1WAY = OFF    //ロック解除シーケンスで何度でもPPSLOCKをセット/クリアできる
#pragma config ZCDDIS = ON      //ゼロクロス検出回路無効
#pragma config PLLEN = ON       //×4PLLを動作させる
#pragma config STVREN = ON      //スタックオーバーフローリセットを行う
#pragma config BORV = HI        //ブラウンアウトリセット電圧を高(2.7V)に設定
#pragma config LPBOR = OFF      //低消費電力ブラウンアウトリセット無効
#pragma config LVP = OFF        //低電圧プログラミングを行わない

#define _XTAL_FREQ 32000000     //クロック32MHz
 
void serial_init(unsigned long BR){
    TX1STA = 0x24;   //SYNC=0 TXEN = 1 BRGH = 1
    BRG16 = 1;       //BRG 16bit mode
    RC1STA = 0x90;   //非同期、継続受信可
    unsigned int X= _XTAL_FREQ/BR/4 - 1;
    SP1BRGH = X / 256;
    SP1BRGL = X % 256;
}
 
 void PICinit(){
    OSCCON = 0b01110000 ;     // 内部クロック8MHz　×4=32MHz
    ANSELA = 0b00000000 ;     // AN0-AN3を使わない
    ANSELC = 0b00000000 ;     // AN4-AN6を使わない
    TRISA  = 0b00000010 ;     // RA1は入力他は出力
    TRISC  = 0b00000000 ;     // 全て出力
    PORTA  = 0b00000000 ;     // PORTAクリア
    PORTC  = 0b00000000 ;     // PORTCクリア
  
    DAC1CON0 = 0b10010000;
    DAC1CON1 = 0;
}
 
enum command {
  SA1,
  SA2,
  SA3,
  SF1,
  SF2,
  SF3,
  LEP,
  LDS,
  LPE,
  LDR,
  VER
};

void ap_out(int ap_dat[]){

    for (int i=0 ; i < 20 ; i++){
        DAC1CON1 = ap_dat[i] ;
        __delay_us(18) ;
    }
    
}


void main() {
    char tmp[40];
    char rcmd[4];
    int dat0[20];
    int ap1_dat[20];
    int ap2_dat[20];
    int ap3_dat[20];
    int fp1_time;
    int fp1_amp;
    int fp2_time;
    int fp2_amp;
    int fp3_time;
    int fp3_amp;
    int intvl1;
    int intvl2;
    int intvl3;
    
    char *ptr; 
    
    PICinit();
    
    /* TX RXピンの割り当て*/
    RA0PPS = 0x14;            //RA0にTXを割り当てる。
    RXPPS = 0x01;             //RXをRA1に割り当てる。
   
    serial_init(9600);        // Serial通信初期化とBaud Rateの設定
   
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

        cmd = VER;
        
        if(strcmp(rcmd,"LDS") == 0) {
            cmd = LDS;
        }else if(strcmp(rcmd,"SA1") == 0){
            cmd = SA1;
        }else if(strcmp(rcmd,"SA2") == 0){
            cmd = SA2;
        }else if(strcmp(rcmd,"SA3") == 0){
            cmd = SA3;
        }else if(strcmp(rcmd,"SF1") == 0){
            cmd = SF1;
        }else if(strcmp(rcmd,"SF2") == 0){
            cmd = SF2;
        }else if(strcmp(rcmd,"SF3") == 0){
            cmd = SF3;
        }else if(strcmp(rcmd,"LEP") == 0){
            cmd = LEP;
        }else if(strcmp(rcmd,"LPE") == 0){
            cmd = LPE;
        }else if(strcmp(rcmd,"LDR") == 0){
            cmd = LDR;
        }else if(strcmp(rcmd,"VER") == 0){
            cmd = VER;
        }
        ptr = strtok(tmp, "/");

//        getche();
        switch(cmd){

            case SA1 : 
                    for (int i=0 ; i < 20 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            ap1_dat[i] = atoi(ptr);
                        }
                    }
                    printf("SA1 OK\n");
                    break;

            case SA2 : 
                    for (int i=0 ; i < 20 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            ap2_dat[i] = atoi(ptr);
                        }
                    }
                    printf("SA2 OK\n");
                    break;

            case SA3 : 
                    for (int i=0 ; i < 20 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            ap3_dat[i] = atoi(ptr);
                        }
                    }
                    printf("SA3 OK\n");
                    break;

            case SF1 : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        fp1_time = atoi(ptr);
                    }
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        fp1_amp = atoi(ptr);
                    }
                    printf("SF1 OK\n");
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
                    printf("SF2 OK\n");
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
                    printf("SF3 OK\n");
                    break;

            case LEP : 

                    for (int k=0 ; k < 6 ; k++){
                        ptr = strtok(NULL, "/");
                        if(strcmp(ptr,"A1") == 0) {
                            for (int i=0 ; i < 20 ; i++){
                                DAC1CON1 = ap1_dat[i] ;
                                __delay_us(18) ;
                            }
                        }else if(strcmp(ptr,"A2") == 0) {
                            for (int i=0 ; i < 20 ; i++){
                                DAC1CON1 = ap2_dat[i] ;
                                __delay_us(18) ;
                            }
                        }else if(strcmp(ptr,"A3") == 0) {
                            for (int i=0 ; i < 20 ; i++){
                                DAC1CON1 = ap3_dat[i] ;
                                __delay_us(18) ;
                            }
                        }else if(strcmp(ptr,"F1") == 0) {
                            DAC1CON1 = fp1_amp ;
                            for (int i=0 ; i < fp1_time ; i++){
                                __delay_us(20) ;
                            }
                            DAC1CON1 = 0 ;
                        }else if(strcmp(ptr,"F2") == 0) {
                            DAC1CON1 = fp2_amp ;
                            for (int i=0 ; i < fp2_time ; i++){
                                __delay_us(20) ;
                            }
                            DAC1CON1 = 0 ;
                        }else if(strcmp(ptr,"F3") == 0) {
                            DAC1CON1 = fp1_amp ;
                            for (int i=0 ; i < fp3_time ; i++){
                                __delay_us(20) ;
                            }
                            DAC1CON1 = 0 ;
                        }
                    }

//                    ap_out(ap1_dat);
                    printf("___P_OK\n");
                    break;

            case LDS : 
                    for (int i=0 ; i < 10 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            dat0[i] = atoi(ptr);
                        }
                    }
                    break;

            case LPE : 
                    for (int i=0 ; i < 10 ; i++){
                        DAC1CON1 = dat0[i] ;
                        __delay_us(18) ;
                    }
                    break;

            case VER : 
                    printf("VERSION 10");
                    break;
                                                                
            default : break;
        }
        
    }
}