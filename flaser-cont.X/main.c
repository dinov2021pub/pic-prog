
/* 
 * File:   main.c
 *
 * Laser Controller of GIP Technology ps-laser -> Fiber laser MPR-1000
 * 
 * Author: Shuichi Dejima
 *
 * Created at 2023/11/19
 * Modified at 2026/01/30
 * 
 * Analog output controller with RS-232C comunication
 * PIC16F1705 - FT234X USBシリアル変換モジュール
 * 
 * 
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <string.h>

// CONFIG1
#pragma config FOSC = INTOSC    //�?部クロ�?クを使�?
#pragma config WDTE = OFF       //ウォ�?チド�?クタイマ�?�無効
#pragma config PWRTE = ON       //パワーア�?プタイマ�?�を有効にする
#pragma config MCLRE = OFF      //MCLRピンをRA3として使用する
#pragma config CP = OFF         //プログラ�?メモリを保護しな�?
#pragma config BOREN = ON       //ブラウンアウトリセ�?トを有効にする
#pragma config CLKOUTEN = OFF   //クロ�?ク出力を無効とし�?�RA4ピンとして使用する
#pragma config IESO = OFF       //�?部・外部クロ�?クの�?り替えでの起動を行わな�?
#pragma config FCMEN = OFF      //外部クロ�?クを監視しな�?
 
// CONFIG2
#pragma config WRT = OFF        //フラ�?シュメモリを保護しな�?
#pragma config PPS1WAY = OFF    //ロ�?ク解除シーケンスで何度でもPPSLOCKをセ�?�?/クリアできる
#pragma config ZCDDIS = ON      //ゼロクロス検�?�回路無効
#pragma config PLLEN = ON       //�?4PLLを動作させる
#pragma config STVREN = ON      //スタ�?クオーバ�?�フローリセ�?トを行う
#pragma config BORV = HI        //ブラウンアウトリセ�?ト電圧を�?(2.7V)に設�?
#pragma config LPBOR = OFF      //低消費電力ブラウンアウトリセ�?ト無効
#pragma config LVP = OFF        //低電圧プログラミングを行わな�?

#define _XTAL_FREQ 32000000     //クロ�?ク32MHz
#define ACQ_US_DELAY 5
 
void serial_init(unsigned long BR){
    TX1STA = 0x24;   //SYNC=0 TXEN = 1 BRGH = 1
    BRG16 = 1;       //BRG 16bit mode
    RC1STA = 0x90;   //非同期�?�継続受信可
    unsigned int X= _XTAL_FREQ/BR/4 - 1;
    SP1BRGH = X / 256;
    SP1BRGL = X % 256;
}
 
/* ADconvert */
unsigned int AD_convert(unsigned char channel){
    //ADC チャンネルセレク�? AN4
    ADCON0bits.CHS0 = 0;   //ADC チャンネルセレク�?
    ADCON0bits.CHS1 = 0;   //ADC チャンネルセレク�?
    ADCON0bits.CHS2 = 1;   //ADC チャンネルセレク�?
    ADCON0bits.CHS3 = 0;   //ADC チャンネルセレク�?
    ADCON0bits.CHS4 = 0;   //ADC チャンネルセレク�?
    __delay_us(20);         // 20us�?つ
    ADCON0bits.GO_nDONE = 1;   //ADC start
    while(ADCON0bits.GO_nDONE){};   // Wait for the conversion to finish
    
	return (ADRESH<<8) + ADRESL;
}

 void PICinit(){
    OSCCON = 0b01110000 ;     // �?部クロ�?ク8MHz�?�?4=32MHz
    ANSELA = 0b00000000 ;     // AN0-AN3を使わな�?
    ANSELC = 0b00000001 ;     // PORTC ANALOG SELECT REGISTER  RC0(=AN4):analog input
    TRISA  = 0b00000010 ;     // RA1は入力�?�他�?�出�?
    TRISC  = 0b00000001 ;     // RC0は入力�?�他�?�出�?
    PORTA  = 0b00000000 ;     // PORTAクリア
    PORTC  = 0b00000000 ;     // PORTCクリア
    
    ADCON0 = 0b00010001;       //ADC CONTROL REGISTER 0
    ADCON1 = 0b10100011;    // bit7(ADFM)=1(右詰�?),bit<6:4>=010 Fosc/32=1.0us
                            // bit<1:0>=00 VREF+=FVR
    FVRCON = 0b10000010;    // bit7(FVRON)=1,bit<1:0>=10 ADFVR�?2=2.048V

    ADRESL = 0x00;  // ADRESL 0; 
    ADRESH = 0x00;  // ADRESH 0; 
    ADCON0 = 0x01;    // GO_nDONE stop; ADON enabled; CHS AN0; 

    DAC1CON0bits.DAC1EN = 1;   // DAC �L��
    DAC1CON0bits.DAC1OE2 = 1; // DAC �o�͂��s��RA2��
}
 
enum command {
  SA1,
  SA2,
  SA3,
  SF1,
  SF2,
  SF3,
  SF4,
  SF5,
  SF6,
  LEP,
  LDS,
  LPE,
  LDR,
  LON,
  LOF,
  PLS,
  SPO,
  SIN,
  AIN,
  VER
};


int ap1_dat[200];
int ap2_dat[2];

void main() {

    static char tmp[300];
    char rcmd[4];
    int fp1_time;
    int fp1_amp;
    int fp2_time;
    int fp2_amp;
    int fp3_time;
    int fp3_amp;
    int fp4_time;
    int fp4_amp;
    int fp5_time;
    int fp5_amp;
    int fp6_time;
    int fp6_amp;
    
    int num_ap1 = 300;
    int num_ap2 = 20;
    int num_ap1_cnt = 0;
    int num_ap2_cnt = 0;
    
    int max_v;  // Analog max voltage

    unsigned int val;
    
    char *ptr; 
    
    PICinit();
    
    /* TX RXピンの割り当て*/
    RA0PPS = 0x14;            //RA0にTXを割り当てる�??
    RXPPS = 0x01;             //RXをRA1に割り当てる�??
   
    serial_init(9600);        // Serial通信初期化とBaud Rateの設�?
   
    while(1){
        
        DAC1CON1 = 0 ;

        rcmd[0] = 'Q'; 
        rcmd[1] = 'Q'; 
        rcmd[2] = 'Q'; 
        rcmd[3] = '\0'; 

        tmp[0] = 'Q';
        tmp[1] = 'Q';
        tmp[2] = 'Q';
        tmp[3] = '\0';

        gets(tmp);
//        printf("%s\n", tmp);
        if (strlen(tmp) < 3) continue;
        
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';


        enum command cmd; // enum型�?�オブジェクトを定義

//        cmd = AIN;
        
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
        }else if(strcmp(rcmd,"SF4") == 0){
            cmd = SF4;
        }else if(strcmp(rcmd,"SF5") == 0){
            cmd = SF5;
        }else if(strcmp(rcmd,"SF6") == 0){
            cmd = SF6;
        }else if(strcmp(rcmd,"LEP") == 0){
            cmd = LEP;
        }else if(strcmp(rcmd,"LPE") == 0){
            cmd = LPE;
        }else if(strcmp(rcmd,"LDR") == 0){
            cmd = LDR;
        }else if(strcmp(rcmd,"LON") == 0){
            cmd = LON;
        }else if(strcmp(rcmd,"LOF") == 0){
            cmd = LOF;
        }else if(strcmp(rcmd,"PLS") == 0){
            cmd = PLS;
        }else if(strcmp(rcmd,"SPO") == 0){
            cmd = SPO;
        }else if(strcmp(rcmd,"SIN") == 0){
            cmd = SIN;
        }else if(strcmp(rcmd,"AIN") == 0){
            cmd = AIN;
        }else if(strcmp(rcmd,"VER") == 0){
            cmd = VER;
        }
        ptr = strtok(tmp, "/");

//        getche();
        switch(cmd){

            case SA1 : 
                    for (int i=0 ; i < num_ap1 ; i++){
                        ap1_dat[i] = 0;
                    }
                    for (int i=0 ; i < num_ap1 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            ap1_dat[i] = atoi(ptr);
                            printf("%d\n", ap1_dat[i]);
                        }else{
                            num_ap1_cnt = i;
                            break;
                        }
                    }
                    printf("C\tSA1\r\n");
                    break;

            case SA2 : 
                    for (int i=0 ; i < num_ap2 ; i++){
                        ap2_dat[i] = 0;
                    }
                    for (int i=0 ; i < num_ap2 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            ap2_dat[i] = atoi(ptr);
                        }else{
                            num_ap2_cnt = i;
                            break;
                        }
                    }
                    printf("C\tSA2\r\n");
                    break;

            case SA3 : 
//                    for (int i=0 ; i < 30 ; i++){
//                        ptr = strtok(NULL, "/");
//                        if(ptr != NULL) {
//                            ap3_dat[i] = atoi(ptr);
//                        }
//                    }
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
                    printf("C\tSF1\r\n");
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
                    printf("C\tSF2\r\n");
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
                    printf("C\tSF3\r\n");
                    break;

            case SF4 : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        fp4_time = atoi(ptr);
                    }
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        fp4_amp = atoi(ptr);
                    }
                    printf("C\tSF4\r\n");
                    break;

            case SF5 : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        fp5_time = atoi(ptr);
                    }
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        fp5_amp = atoi(ptr);
                    }
                    printf("C\tSF5\r\n");
                    break;

            case SF6 : 
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        fp6_time = atoi(ptr);
                    }
                    ptr = strtok(NULL, "/");
                    if(ptr != NULL) {
                        fp6_amp = atoi(ptr);
                    }
                    printf("C\tSF6\r\n");
                    break;

            case LEP : 

                    for (int k=0 ; k < 6 ; k++){
                        ptr = strtok(NULL, "/");
                        if(strcmp(ptr,"A1") == 0) {
                            for (int i=0 ; i < num_ap1_cnt ; i++){
                                DAC1CON1 = ap1_dat[i] ;
                                __delay_us(5) ;
                            }
                        }else if(strcmp(ptr,"A2") == 0) {
                            for (int i=0 ; i < num_ap2_cnt ; i++){
                                DAC1CON1 = ap2_dat[i] ;
                                __delay_us(5) ;
                            }
//                        }else if(strcmp(ptr,"A3") == 0) {
//                            for (int i=0 ; i < 30 ; i++){
//                                DAC1CON1 = ap3_dat[i] ;
//                                __delay_us(18) ;
//                            }
                        }else if(strcmp(ptr,"F1") == 0) {
                            DAC1CON1 = fp1_amp ;
                            for (int i=0 ; i < fp1_time ; i++){
                                __delay_us(20) ;  //original
                            }
                        }else if(strcmp(ptr,"F2") == 0) {
                            DAC1CON1 = fp2_amp ;
                            for (int i=0 ; i < fp2_time ; i++){
                                __delay_us(20) ; //original
                            }
                        }else if(strcmp(ptr,"F3") == 0) {
                            DAC1CON1 = fp3_amp ;
                            for (int i=0 ; i < fp3_time ; i++){
                                __delay_us(20) ; //original
                            }
                        }else if(strcmp(ptr,"F4") == 0) {
                            DAC1CON1 = fp4_amp ;
                            for (int i=0 ; i < fp4_time ; i++){
                                __delay_us(20) ;
                            }
                        }else if(strcmp(ptr,"F5") == 0) {
                            DAC1CON1 = fp5_amp ;
                            for (int i=0 ; i < fp5_time ; i++){
                                __delay_us(20) ;
                            }
                        }else if(strcmp(ptr,"F6") == 0) {
                            DAC1CON1 = fp6_amp ;
                            for (int i=0 ; i < fp6_time ; i++){
                                __delay_us(20) ;
                            }
                        }
                    }

//                    ap_out(ap1_dat);
                    printf("C\tLEP\n");
                    break;

            case SPO :
                DAC1CON1 = fp1_amp ;
                for (int i=0 ; i < fp1_time ; i++){
                    __delay_us(15) ;
                }
                DAC1CON1 = fp2_amp ;
                for (int i=0 ; i < fp2_time ; i++){
                    __delay_us(15) ;
                }
                DAC1CON1 = fp3_amp ;
                for (int i=0 ; i < fp3_time ; i++){
                    __delay_us(15) ;
                }
                DAC1CON1 = fp4_amp ;
                for (int i=0 ; i < fp4_time ; i++){
                    __delay_us(15) ;
                }
                DAC1CON1 = fp5_amp ;
                for (int i=0 ; i < fp5_time ; i++){
                    __delay_us(15) ;
                }
                DAC1CON1 = fp6_amp ;
                for (int i=0 ; i < fp6_time ; i++){
                    __delay_us(15) ;
                }
                DAC1CON1 = 0 ;
                break;

                
            case LON : 
                    DAC1CON1 = 200 ;
                    break;

            case LOF : 
                    DAC1CON1 = 0 ;
                    break;

            case LDS : 
                    break;

            case LPE : 
                    break;
                    
            case PLS :
                for (int k = 0; k < 1000 ; k++){     
                    DAC1CON1 = 200 ;
                    for (int i=0 ; i < 1 ; i++){
                        __delay_us(10) ;
                    }
                    DAC1CON1 = 0 ;
                    for (int i=0 ; i < 1 ; i++){
                        __delay_us(10) ;
                    }
                }
                break;
                
            case SIN :
                ptr = strtok(NULL, "/");
                if(ptr != NULL) {
                    max_v = atoi(ptr);
                }
                DAC1CON1 = 0 ;
                int v_cnt = 0;
                for (int k = 0; k < max_v ; k++){     
                    DAC1CON1 = v_cnt ;
                    __delay_us(250) ;
                    v_cnt += 1;
                }
                for (int k = 0; k < max_v ; k++){     
                    DAC1CON1 = v_cnt ;
                    __delay_us(250) ;
                    v_cnt -= 1;
                }
                printf("C\tSIN\n");

                break;

           case AIN :
                
                val = 0;
                for (int k = 0; k < 10 ; k++){     
                    // val = adconv();
					val = AD_convert(1);
                    printf("C\tAIN = %u\n", val);                    
                    __delay_ms(500) ;
                }
                break;
                 
            case VER : 
                    printf("FLASER-CONT VERSION 1.1\r\n");
                    break;
                                                                
            default : break;
        }

    }
}