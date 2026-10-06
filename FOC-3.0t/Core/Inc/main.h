/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_RES_Pin GPIO_PIN_14
#define LCD_RES_GPIO_Port GPIOC
#define LCD_DC_Pin GPIO_PIN_15
#define LCD_DC_GPIO_Port GPIOC
#define VA_Pin GPIO_PIN_0
#define VA_GPIO_Port GPIOC
#define VB_Pin GPIO_PIN_1
#define VB_GPIO_Port GPIOC
#define VC_Pin GPIO_PIN_2
#define VC_GPIO_Port GPIOC
#define IC_Pin GPIO_PIN_0
#define IC_GPIO_Port GPIOA
#define IB_Pin GPIO_PIN_1
#define IB_GPIO_Port GPIOA
#define IA_Pin GPIO_PIN_2
#define IA_GPIO_Port GPIOA
#define IBUS_Pin GPIO_PIN_3
#define IBUS_GPIO_Port GPIOA
#define RGB_Pin GPIO_PIN_5
#define RGB_GPIO_Port GPIOA
#define VBUS_Pin GPIO_PIN_5
#define VBUS_GPIO_Port GPIOC
#define NTC1_Pin GPIO_PIN_1
#define NTC1_GPIO_Port GPIOB
#define NTC2_Pin GPIO_PIN_2
#define NTC2_GPIO_Port GPIOB
#define NTC3_Pin GPIO_PIN_12
#define NTC3_GPIO_Port GPIOB
#define LIN1_Pin GPIO_PIN_13
#define LIN1_GPIO_Port GPIOB
#define LIN2_Pin GPIO_PIN_14
#define LIN2_GPIO_Port GPIOB
#define LIN3_Pin GPIO_PIN_15
#define LIN3_GPIO_Port GPIOB
#define HIN1_Pin GPIO_PIN_8
#define HIN1_GPIO_Port GPIOA
#define HIN2_Pin GPIO_PIN_9
#define HIN2_GPIO_Port GPIOA
#define HIN3_Pin GPIO_PIN_10
#define HIN3_GPIO_Port GPIOA
#define SPI3_CSN_Pin GPIO_PIN_15
#define SPI3_CSN_GPIO_Port GPIOA
#define SPI1_CSN_Pin GPIO_PIN_2
#define SPI1_CSN_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
