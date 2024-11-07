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
