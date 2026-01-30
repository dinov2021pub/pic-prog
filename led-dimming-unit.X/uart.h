/* 
 * File:   uart.h
 * Author: shimi
 *
 * Created on 2026/01/15, 13:57
 */

#ifndef __UART_H__
#define __UART_H__
 
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 16000000UL // 16MHz
//#define _XTAL_FREQ 4000000UL // 4MHz
#endif
 
#define BAUDRATE 9600       // 9.6kbps
#define TX9_RX9_BIT 0       // 0: 8bit, 1: 9bit
#define BRGH_BIT 1          // 0: low speed sampling, 1:high speed sampling
 
#if TX9_RX9_BIT == 1
#define TX9_RX9_DATA 0x40 // 9bit
#else
#define TX9_RX9_DATA 0x00 // 8bit
#endif
 
#if BRGH_BIT == 1
#define BRGH_DATA 0x04
#define SPBRG_DATA ((unsigned char)(((_XTAL_FREQ / 16) / BAUDRATE) - 1))
#else
#define BRGH_DATA 0x00
#define SPBRG_DATA ((unsigned char)(((_XTAL_FREQ / 64) / BAUDRATE) - 1))
#endif
 
void initUART();
void my_putch(unsigned char byte);
unsigned char my_getch();
unsigned char my_getche();
 
#endif  // __UART_H__

