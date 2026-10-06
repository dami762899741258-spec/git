#ifndef _BSP_TIM_H_
#define _BSP_TIM_H_

void Bsp_Time_Init(void);


// 获取微秒级时间戳,从上电开始计时
uint32_t Bsp_Time_MicroSec(void);

void Bsp_Time_DelayUs(uint32_t us);


#endif // !_BSP_TIM_H_