#include <xc.h>
#include <stdio.h>
 
#include "uart.h"
 

void initUART()
{   
    SPBRG = SPBRG_DATA; // Baud rate
    TXSTA = (TX9_RX9_DATA | BRGH_DATA | 0x20); // 8or9bit, Low speed or High speed
    RCSTA = (TX9_RX9_DATA | 0x90); // low speed or high speed
    //RCSTA = 0b10010000;
    //TXSTA = 0b00100000;
    
    //SPBRG = 51;           // 9600 bps @8MHz
    //TXSTAbits.BRGH = 0;
    //BAUDCTLbits.BRG16 = 0;
    
    TXSTAbits.SYNC = 0;   // 非同期通信
    TXSTAbits.TXEN = 1;   // 送信有効
    RCSTAbits.SPEN = 1;   // シリアルポート有効
    RCSTAbits.CREN = 1;   // 連続受信O
    
    // UART受信割り込み設定
    PIE1bits.RCIE = 1;    // 受信割り込み有効
//    INTCONbits.PEIE = 0;  // 周辺機器割り込み無効
    INTCONbits.PEIE = 1;  // 周辺機器割り込み有効
    INTCONbits.GIE = 1;   // 全体割り込み有効
}
    
void putch(unsigned char byte) // 1byte send
{
    while(!TXIF){
    }
    TXREG = byte;
}
 
unsigned char getch() // 1byte send
{
    while(!RCIF){
    }
 
    return RCREG;
}
 
unsigned char getche() // getch and echo
{
    unsigned char c;
 
    c = getch();
    putch(c);
 
    return c;
}
