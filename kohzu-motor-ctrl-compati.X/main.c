/* 
 * File:   main.c
 * Author: Dejima_desktop
 *
 * Author: Shuichi Dejima
 *
 * Created on 2019/06/03, 15:26
 */

// CONFIG1
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTRC oscillator; port I/O function on both RA6/OSC2/CLKO pin and RA7/OSC1/CLKI pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include <stdio.h>
#include "uart.h"
#include <stdlib.h>
#include <string.h>

#define _XTAL_FREQ 4000000      // 4MHz

#define MOTOR_P4 RB7 // MOTOR Phase4
#define MOTOR_P3 RB6 // MOTOR Phase3
#define MOTOR_P2 RB5 // MOTOR Phase2
#define MOTOR_P1 RB4 // MOTOR Phase1
#define M_IN1 RA2 // H-bridge IN1
#define M_IN2 RA3 // H-bridge IN2
#define TR RB3 // Transistor
#define MAX_VALUE 32767
#define MIN_VALUE 1


char my_pop_back(char *str)
{
    int len = strlen(str);
//    const int len = strlen(str);
    if( len == 0 ) {
        return '\0';      // str ���󕶎���̏ꍇ�́A'\0' ��Ԃ�
    } else {
        char c = str[len-1];     // ���������� c �ɑ��
        str[len-1] = '\0';       // �I�[�L���̃k�����������̈ʒu�ɏ�������
        return c;                      // ����������Ԃ�
    }
}

enum week {
  RTS,
  BTS
};

void main(void) {
    
    PORTA = 0x00;           // PORTA��������
    PORTB = 0x00;           // PORTB��������
    TRISA = 0b00000011;     // PORTA�̓��o�͐ݒ� RA0��A��, RA1��B��
    TRISB = 0b00000010;     // PORTB�̓��o�͐ݒ� RB1��RX
    CMCON = 0b00000111;     // �R���p���[�^�͎g�p���Ȃ�(RA0-RA4�̓f�W�^���s���Ŏg�p)
    
    initUART();             // �����������V���A���ʐM�ݒ�
 
    char tmp[20];
    int j = 10;
    int k = 0;
    int cnt = 10;
    int intvl = 10;
//    char cmd[10];
    
    char *ptr;
    
    while(1){

        gets(tmp);
        
        // �J���}����؂�ɕ�����𕪊�
        // 1���
        ptr = strtok(tmp, "/");
//        cmd = my_pop_back(*ptr);
        printf("%s\n", ptr);
        printf("%s\n", ptr[0]);        
        char c;
        int len = strlen(ptr);
//    const int len = strlen(str);
        if( len == 0 ) {
            c = '\0';      // str ���󕶎���̏ꍇ�́A'\0' ��Ԃ�
        } else {
//            c = ptr[len-1];     // ���������� c �ɑ��
            ptr[len-1] = '\0';       // �I�[�L���̃k�����������̈ʒu�ɏ�������
            c = '\0';      // str ���󕶎���̏ꍇ�́A'\0' ��Ԃ�
            
        }
        
        char cmd[];
        enum week wk; // enum�^�̃I�u�W�F�N�g���`
        wk = RTS; // enum�^�̒萔����
        
        if(strcmp(ptr,"RTS") == 0)
        {
            wk = RTS;
//        }else if(strcmp(tmp,"BTS") == 0){
//            cmd = 'b';      
        }else{
            wk = BTS;
        }

        printf("%s\n", tmp);
        printf("%d\n", wk);
          
        switch(wk){
//        switch(ptr[0]){
            case RTS : cnt=20;
                        intvl=5;
//                        ptr = strtok(NULL, ",");
//                        if(ptr != NULL) {
//                            cnt = atoi(ptr);
//                        }
//                        printf("cnt = %d\n", cnt);
//                        ptr = strtok(NULL, ",");
//                        if(ptr != NULL) {
//                            intvl = atoi(ptr);
 //                       }
  //                      printf("intvl = %d\n", intvl);
                        for(k = 0 ; k < cnt ; k++){
                            MOTOR_P1 = 1;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 1;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 1;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                        }

                        puts("MOTOR = F  OK");
                        printf("MOTOR = F  OK\r\n"); // ���M
                        break;
                        
            case BTS :  cnt = 20;
                        for(k = 0 ; k < cnt ; k++){
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 1;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 1;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 0;
                            MOTOR_P2 = 1;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                            MOTOR_P1 = 1;
                            MOTOR_P2 = 0;
                            MOTOR_P3 = 0;
                            MOTOR_P4 = 0;
                            for(j = 0 ; j < intvl ; j++){
                                __delay_ms(1);
                            }
                        }
                        puts("MOTOR = B  OK");
                        printf("MOTOR = B  OK\r\n"); // ���M
                        break;
                        
            default : break;
        }

    }
}

