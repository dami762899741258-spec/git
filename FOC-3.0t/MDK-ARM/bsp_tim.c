#include "bsp_tim.h"
#include "main.h"

void Bsp_Time_Init(void)
{
      /* 第 1 步：使能跟踪调试模块（不开这个，DWT 根本不计数） */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

    /* 第 2 步：计数器清零 */
    DWT->CYCCNT = 0U;

    /* 第 3 步：启动计数 */
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

// 获取微秒级时间戳,从上电开始计时
uint32_t Bsp_Time_MicroSec(void){
      

    uint32_t cycle_per_us = SystemCoreClock / 1000000U; //每微秒的时钟周期数  每170个T = 1us
    if (cycle_per_us == 0) {
        return 0; // 避免除以零
    }

    return DWT->CYCCNT / cycle_per_us;


}
void Bsp_Time_Delay_Us(uint32_t us){
    uint32_t cycle_per_us = SystemCoreClock / 1000000U; //每微秒的时钟周期数  每170个T = 1us
    uint32_t start;
    uint32_t need;

    if (cycle_per_us == 0) {
        return; // 避免除以零
    }
    need = us * cycle_per_us;
    start = DWT->CYCCNT;
    while (DWT->CYCCNT - start < need) {
        // 等待
    }
}