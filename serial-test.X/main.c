
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
 
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
 
void main() {
   
    PICinit();
    
    /* TX RX�s���̊��蓖��*/
    RA0PPS = 0x14;            //RA0��TX�����蓖�Ă�B
    RXPPS = 0x01;             //RX��RA1�Ɋ��蓖�Ă�B
   
    serial_init(9600);        // Serial�ʐM��������Baud Rate�̐ݒ�
   
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