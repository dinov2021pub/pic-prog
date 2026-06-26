#include <xc.h>
#include "pwm.h"

#define PWM_HW_MAX 199  // ハードウェア最大値（PR2×4-1）

void pwm_init(void)
{
    CCP1CON = 0x0C;
    T2CON = 0x00;
    PR2 = 49;
    T2CONbits.TMR2ON = 1;
}

void pwm_percent(uint8_t percent)
{
    // 範囲チェック（0-100%）
    if (percent > 100) {
        percent = 100;
    }
    
    // 100% → 199 にスケーリング
    // percent × 199 / 100
    uint16_t hw_value = ((uint16_t)percent * PWM_HW_MAX) / 100U;
    
    // 10bitレジスタに設定
    CCPR1L = hw_value >> 2;
    CCP1CON = (CCP1CON & 0xCF) | ((hw_value & 0x03) << 4);
}
