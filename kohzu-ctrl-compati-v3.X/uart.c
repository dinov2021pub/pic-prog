#include <xc.h>
#include <stdio.h>
 
#include "uart.h"
 
void initUART()
{   
    SPBRG = SPBRG_DATA; // ボーレート設定
    //TXSTA = (TX9_RX9_DATA | BRGH_DATA | 0x20); // 8or9bit, 低速or高速サンプル指定
    //RCSTA = (TX9_RX9_DATA | 0x90); // 低速or高速サンプル指定
    RCSTA = 0b10010000;
    TXSTA = 0b00100000;
}
 
void putch(unsigned char byte) // 1byte送信
{
    while(!TXIF){
    }
    TXREG = byte;
}
 
unsigned char getch() // 1byte受信
{
    while(!RCIF){
    }
 
    return RCREG;
}
 
unsigned char getche() // getchしてecho
{
    unsigned char c;
 
    c = getch();
    putch(c);
 
    return c;
}
