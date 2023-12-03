#include <xc.h>
#include <stdio.h>
 
#include "uart.h"
 
void initUART()
{   
    SPBRG = SPBRG_DATA; // �{�[���[�g�ݒ�
    //TXSTA = (TX9_RX9_DATA | BRGH_DATA | 0x20); // 8or9bit, �ᑬor�����T���v���w��
    //RCSTA = (TX9_RX9_DATA | 0x90); // �ᑬor�����T���v���w��
    RCSTA = 0b10010000;
    TXSTA = 0b00100000;
}
 
void putch(unsigned char byte) // 1byte���M
{
    while(!TXIF){
    }
    TXREG = byte;
}
 
unsigned char getch() // 1byte��M
{
    while(!RCIF){
    }
 
    return RCREG;
}
 
unsigned char getche() // getch����echo
{
    unsigned char c;
 
    c = getch();
    putch(c);
 
    return c;
}
