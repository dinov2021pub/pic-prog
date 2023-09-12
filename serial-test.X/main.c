
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
 
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
 
void main() {
   
    PICinit();
    
    /* TX RXピンの割り当て*/
    RA0PPS = 0x14;            //RA0にTXを割り当てる。
    RXPPS = 0x01;             //RXをRA1に割り当てる。
   
    serial_init(9600);        // Serial通信初期化とBaud Rateの設定
   
    while(1){
        getche();
        for (int i=0 ; i < 256 ; i++){
            DAC1CON1 = 200 ;
            __delay_us(10) ;
            DAC1CON1 = 0 ;
            __delay_us(10) ;
        }
    }
}