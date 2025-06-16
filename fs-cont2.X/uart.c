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
    
    TXSTAbits.SYNC = 0;   // �񓯊��ʐM
    TXSTAbits.TXEN = 1;   // ���M�L��
    RCSTAbits.SPEN = 1;   // �V���A���|�[�g�L��
    RCSTAbits.CREN = 1;   // �A����MO
    
    // UART��M���荞�ݐݒ�
    PIE1bits.RCIE = 1;    // ��M���荞�ݗL��
//    INTCONbits.PEIE = 0;  // ���Ӌ@�튄�荞�ݖ���
    INTCONbits.PEIE = 1;  // ���Ӌ@�튄�荞�ݗL��
    INTCONbits.GIE = 1;   // �S�̊��荞�ݗL��
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
