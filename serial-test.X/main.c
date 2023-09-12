/* 
 * File:   main.c
 *
 * Author: Shuichi Dejima
 *
 * Created at 2023/09/12
 * Analog output controller with RS-232C comunication
 * PIC16F1705 - FT234X USB�V���A���ϊ����W���[��
 * 
 * Ref: Operation_ManualJ_for_SC210_410_rev2.pdf
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <string.h>

// CONFIG1
#pragma config FOSC = INTOSC    //�����N���b�N���g��
#pragma config WDTE = OFF       //�E�H�b�`�h�b�N�^�C�}�[����
#pragma config PWRTE = ON       //�p���[�A�b�v�^�C�}�[��L���ɂ���
#pragma config MCLRE = OFF      //MCLR�s����RA3�Ƃ��Ďg�p����
#pragma config CP = OFF         //�v���O������������ی삵�Ȃ�
#pragma config BOREN = ON       //�u���E���A�E�g���Z�b�g��L���ɂ���
#pragma config CLKOUTEN = OFF   //�N���b�N�o�͂𖳌��Ƃ��ARA4�s���Ƃ��Ďg�p����
#pragma config IESO = OFF       //�����E�O���N���b�N�̐؂�ւ��ł̋N�����s��Ȃ�
#pragma config FCMEN = OFF      //�O���N���b�N���Ď����Ȃ�
 
// CONFIG2
#pragma config WRT = OFF        //�t���b�V����������ی삵�Ȃ�
#pragma config PPS1WAY = OFF    //���b�N�����V�[�P���X�ŉ��x�ł�PPSLOCK���Z�b�g/�N���A�ł���
#pragma config ZCDDIS = ON      //�[���N���X���o��H����
#pragma config PLLEN = ON       //�~4PLL�𓮍삳����
#pragma config STVREN = ON      //�X�^�b�N�I�[�o�[�t���[���Z�b�g���s��
#pragma config BORV = HI        //�u���E���A�E�g���Z�b�g�d������(2.7V)�ɐݒ�
#pragma config LPBOR = OFF      //�����d�̓u���E���A�E�g���Z�b�g����
#pragma config LVP = OFF        //��d���v���O���~���O���s��Ȃ�

#define _XTAL_FREQ 32000000     //�N���b�N32MHz
 
void serial_init(unsigned long BR){
    TX1STA = 0x24;   //SYNC=0 TXEN = 1 BRGH = 1
    BRG16 = 1;       //BRG 16bit mode
    RC1STA = 0x90;   //�񓯊��A�p����M��
    unsigned int X= _XTAL_FREQ/BR/4 - 1;
    SP1BRGH = X / 256;
    SP1BRGL = X % 256;
}
 
 void PICinit(){
    OSCCON = 0b01110000 ;     // �����N���b�N8MHz�@�~4=32MHz
    ANSELA = 0b00000000 ;     // AN0-AN3���g��Ȃ�
    ANSELC = 0b00000000 ;     // AN4-AN6���g��Ȃ�
    TRISA  = 0b00000010 ;     // RA1�͓��͑��͏o��
    TRISC  = 0b00000000 ;     // �S�ďo��
    PORTA  = 0b00000000 ;     // PORTA�N���A
    PORTC  = 0b00000000 ;     // PORTC�N���A
  
    DAC1CON0 = 0b10010000;
    DAC1CON1 = 0;
}
 
enum command {
  SA1,
  SA2,
  SA3,
  SF1,
  SF2,
  SF3,
  LEP,
  LDS,
  LPE,
  LDR,
  VER
};

void ap_out(int ap_dat[]){

    for (int i=0 ; i < 20 ; i++){
        DAC1CON1 = ap_dat[i] ;
        __delay_us(18) ;
    }
    
}


void main() {
    char tmp[40];
    char rcmd[4];
    int dat0[20];
    int ap1_dat[20];
    int ap2_dat[20];
    int ap3_dat[20];
    int fp1_time;
    int fp1_amp;
    int fp2_time;
    int fp2_amp;
    int fp3_time;
    int fp3_amp;
    int intvl1;
    int intvl2;
    int intvl3;
    
    char *ptr; 
    
    PICinit();
    
    /* TX RX�s���̊��蓖��*/
    RA0PPS = 0x14;            //RA0��TX�����蓖�Ă�B
    RXPPS = 0x01;             //RX��RA1�Ɋ��蓖�Ă�B
   
    serial_init(9600);        // Serial�ʐM��������Baud Rate�̐ݒ�
   
    while(1){
        
        rcmd[0] = 'Q'; 
        rcmd[1] = 'Q'; 
        rcmd[2] = 'Q'; 
        rcmd[3] = '\0'; 

        tmp[0] = 'Q';
        tmp[1] = 'Q';
        tmp[2] = 'Q';
        tmp[3] = '\0';

        gets(tmp);
        printf("%s\n", tmp);
        
        rcmd[0] = tmp[1];
        rcmd[1] = tmp[2];
        rcmd[2] = tmp[3];
        rcmd[3] = '\0';


        enum command cmd; // enum�^�̃I�u�W�F�N�g���`

        cmd = VER;
        
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
        }else if(strcmp(rcmd,"LEP") == 0){
            cmd = LEP;
        }else if(strcmp(rcmd,"LPE") == 0){
            cmd = LPE;
        }else if(strcmp(rcmd,"LDR") == 0){
            cmd = LDR;
        }else if(strcmp(rcmd,"VER") == 0){
            cmd = VER;
        }
        ptr = strtok(tmp, "/");

//        getche();
        switch(cmd){

            case SA1 : 
                    for (int i=0 ; i < 20 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            ap1_dat[i] = atoi(ptr);
                        }
                    }
                    printf("SA1 OK\n");
                    break;

            case SA2 : 
                    for (int i=0 ; i < 20 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            ap2_dat[i] = atoi(ptr);
                        }
                    }
                    printf("SA2 OK\n");
                    break;

            case SA3 : 
                    for (int i=0 ; i < 20 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            ap3_dat[i] = atoi(ptr);
                        }
                    }
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
                    printf("SF1 OK\n");
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
                    printf("SF2 OK\n");
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
                    printf("SF3 OK\n");
                    break;

            case LEP : 

                    for (int k=0 ; k < 6 ; k++){
                        ptr = strtok(NULL, "/");
                        if(strcmp(ptr,"A1") == 0) {
                            for (int i=0 ; i < 20 ; i++){
                                DAC1CON1 = ap1_dat[i] ;
                                __delay_us(18) ;
                            }
                        }else if(strcmp(ptr,"A2") == 0) {
                            for (int i=0 ; i < 20 ; i++){
                                DAC1CON1 = ap2_dat[i] ;
                                __delay_us(18) ;
                            }
                        }else if(strcmp(ptr,"A3") == 0) {
                            for (int i=0 ; i < 20 ; i++){
                                DAC1CON1 = ap3_dat[i] ;
                                __delay_us(18) ;
                            }
                        }else if(strcmp(ptr,"F1") == 0) {
                            DAC1CON1 = fp1_amp ;
                            for (int i=0 ; i < fp1_time ; i++){
                                __delay_us(20) ;
                            }
                            DAC1CON1 = 0 ;
                        }else if(strcmp(ptr,"F2") == 0) {
                            DAC1CON1 = fp2_amp ;
                            for (int i=0 ; i < fp2_time ; i++){
                                __delay_us(20) ;
                            }
                            DAC1CON1 = 0 ;
                        }else if(strcmp(ptr,"F3") == 0) {
                            DAC1CON1 = fp1_amp ;
                            for (int i=0 ; i < fp3_time ; i++){
                                __delay_us(20) ;
                            }
                            DAC1CON1 = 0 ;
                        }
                    }

//                    ap_out(ap1_dat);
                    printf("___P_OK\n");
                    break;

            case LDS : 
                    for (int i=0 ; i < 10 ; i++){
                        ptr = strtok(NULL, "/");
                        if(ptr != NULL) {
                            dat0[i] = atoi(ptr);
                        }
                    }
                    break;

            case LPE : 
                    for (int i=0 ; i < 10 ; i++){
                        DAC1CON1 = dat0[i] ;
                        __delay_us(18) ;
                    }
                    break;

            case VER : 
                    printf("VERSION 10");
                    break;
                                                                
            default : break;
        }
        
    }
}