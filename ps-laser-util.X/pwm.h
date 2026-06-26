/* 
 * File:   pwm.h
 * Author: shimi
 *
 * Created on 2026/06/25, 11:36
 */
/* ===========================
 * シャッター SHBH1T 制御用PWM信号
 * 内部クロック 4MHzを使用
 * PWM周波数(Hz) : 20kHz 5bit
 * PWM分解能（ビット数） = log?(PR2 + 1)
 * PR2 = (Fosc / (PWM周波数 × 4 × Prescaler)) - 1
 * ハードウェア分解能 = 200段階（0-199）
 * ユーザー入力 = 0-100%
 * =========================== */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

void pwm_init(void);
void pwm_percent(uint8_t percent);

#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */