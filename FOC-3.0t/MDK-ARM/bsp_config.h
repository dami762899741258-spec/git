#ifndef BSP_CONFIG_H
#define BSP_CONFIG_H


//1.pwm自举
#define BSP_Max_DUTY 0.97f //pwm最大占空比

//2.死区时间 
#define BSP_DEAD_TIME 0x95U  //寄存器写法 等于1s

/* 电流换算公式：
 *   I(A) = (ADC原始值 - 零漂) * VREF / 4096 / (采样电阻 * 运放增益)
 * 例：VREF=3.3V，采样电阻 0.01Ω，运放增益 10
 *     → 每 LSB 对应 3.3/4096/(0.01*10) = 0.008056 A
 */
 //3.电流采样配置
#define BSP_ADC_VREF 3.3f    //adc的基准电压
#define BSP_SHUNT_OHM 0.01f //采样电阻阻值
#define BSP_AMP_GAIN  10.0f  //运放增益
#define BSP_I_GAIN_A_PER_LSB \
                         (BSP_ADC_VREF / 4096.0f / (BSP_SHUNT_OHM * BSP_AMP_GAIN)) //每LSB对应的电流值

//将复杂数学公式优化下次直接调用I(A) = (ADC原始值 - 零漂) * BSP_I_GAIN_A_PER_LSB                         
#define BSP_ADC_OFFSET_TIMES 200U //adc零漂次数

//4.AS5600编码器
#define BSP_ENC_USE_SPI1 1  
#define BSP_ENC_CPR 4096f  //编码器一圈脉冲数

#define BSP_ENC_DIR   (+1.0f) //编码器方向，正转为+1，反转为-1
#define BSP_ENC_SPEED_MIN_RPM 10.0f //最小速度阈值(RPM)

//5.电机参数
#define BSP_POLE_PAIRS 10U //电机极对数

//6.母线电压
#define BSP_VBUS_ENABLE 0 //使能母线电压采样  一般采用电压比较稳的情况下不采样  

#define BSP_VBUS_GAIN_V_PER_LSB 0.001f //母线电压增益，单位V/LSB
#define BSP_VBUS_NOMINAL_V 12.0f //母线电压标称值，单位V

//7.保护阈值
#define BSP_PROT_OV_V    15.0f //过压保护阈值，单位V
#define BSP_PROT_UV_V    9.0f //欠压保护阈值，单位V
#define BSP_PROT_V_TIME_MS 200U //过压/欠压持续时间，单位ms
#define BSP_PROT_TEMP_C  100.0f //过温保护阈值，单位摄氏度
#define BSP_PROT_TEMP_TIME_MS 200U //过温持续时间，单位ms


#endif // BSP_CONFIG_H