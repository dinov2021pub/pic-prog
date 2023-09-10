// PIC16F1705 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PPS1WAY = OFF    // Peripheral Pin Select one-way control (The PPSLOCK bit can be set and cleared repeatedly by software)
#pragma config ZCDDIS = OFF     // Zero-cross detect disable (ZCD always enabled)
#pragma config PLLEN = OFF      // Phase Lock Loop enable (4x PLL is disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config DEBUG = OFF      // In-Circuit Debugger Mode (In-Circuit Debugger disabled, ICSPCLK and ICSPDAT are general purpose I/O pins)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 8000000

void PICinit(){
    OSCCON = 0b01110000;
    
    ANSELA = 0b00000000;//Analog or Digital??
    ANSELC = 0b00000000;
    
    TRISA = 0b00000000;//input or output??
    TRISC = 0b00000000;
    
    PORTA = 0b00000000;//?????
    PORTC = 0b00000000;
    
    DAC1CON0 = 0b10110000;
    DAC1CON1 = 0;
}

void serial_init(unsigned long BR){
    TX1STA = 0b00100100;   //??????, ???????
    BRG16 = 1;       //???????, BRG 16bit mode 
    RC1STA = 0b10010000;   //??????, ???????
    
    unsigned int X= _XTAL_FREQ/BR/4 - 1;
    SP1BRGH = X / 256;
    SP1BRGL = X % 256;
}


void putch(unsigned char byte){//????
    while(!TXIF); //TXIF???????????, 0?Busy?1?Ready
    TXREG = byte; //??????????????
}
 
unsigned char getch(){//??????????
    while(!RCIF); //RCIF???????????
    return RCREG; //????????????????
}
 
unsigned char getche(){//??????????????????
    unsigned char c;
    c = getch();
    putch(c);
    return c;
}

int main(){
    PICinit();
    
    RA5PPS = 0b00010100;            //RA5?TX??????
    RXPPS = 0b00000001;             //RX?RA1??????
   
    serial_init(9600);        // Serial??????Baud Rate???
   
    while(1){
        getche();
    }
    
    return 0;
}
