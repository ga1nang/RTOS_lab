/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define LED_RED_1_Pin GPIO_PIN_1
#define LED_RED_1_GPIO_Port GPIOA
#define LED_YELLOW_1_Pin GPIO_PIN_2
#define LED_YELLOW_1_GPIO_Port GPIOA
#define LED_GREEN_1_Pin GPIO_PIN_3
#define LED_GREEN_1_GPIO_Port GPIOA
#define LED_RED_2_Pin GPIO_PIN_4
#define LED_RED_2_GPIO_Port GPIOA
#define LED_YELLOW_2_Pin GPIO_PIN_5
#define LED_YELLOW_2_GPIO_Port GPIOA
#define LED_GREEN_2_Pin GPIO_PIN_6
#define LED_GREEN_2_GPIO_Port GPIOA
#define LED_RED_3_Pin GPIO_PIN_7
#define LED_RED_3_GPIO_Port GPIOA
#define DIGIT1_Pin GPIO_PIN_0
#define DIGIT1_GPIO_Port GPIOB
#define DIGIT2_Pin GPIO_PIN_1
#define DIGIT2_GPIO_Port GPIOB
#define DIGIT3_Pin GPIO_PIN_2
#define DIGIT3_GPIO_Port GPIOB
#define DIGIT11_Pin GPIO_PIN_10
#define DIGIT11_GPIO_Port GPIOB
#define DIGIT12_Pin GPIO_PIN_11
#define DIGIT12_GPIO_Port GPIOB
#define DIGIT13_Pin GPIO_PIN_12
#define DIGIT13_GPIO_Port GPIOB
#define DIGIT14_Pin GPIO_PIN_13
#define DIGIT14_GPIO_Port GPIOB
#define LED_YELLOW_3_Pin GPIO_PIN_8
#define LED_YELLOW_3_GPIO_Port GPIOA
#define LED_GREEN_3_Pin GPIO_PIN_9
#define LED_GREEN_3_GPIO_Port GPIOA
#define LED_RED_4_Pin GPIO_PIN_10
#define LED_RED_4_GPIO_Port GPIOA
#define LED_YELLOW_4_Pin GPIO_PIN_11
#define LED_YELLOW_4_GPIO_Port GPIOA
#define LED_GREEN_4_Pin GPIO_PIN_12
#define LED_GREEN_4_GPIO_Port GPIOA
#define DIGIT4_Pin GPIO_PIN_3
#define DIGIT4_GPIO_Port GPIOB
#define DIGIT5_Pin GPIO_PIN_4
#define DIGIT5_GPIO_Port GPIOB
#define DIGIT6_Pin GPIO_PIN_5
#define DIGIT6_GPIO_Port GPIOB
#define DIGIT7_Pin GPIO_PIN_6
#define DIGIT7_GPIO_Port GPIOB
#define DIGIT8_Pin GPIO_PIN_7
#define DIGIT8_GPIO_Port GPIOB
#define DIGIT9_Pin GPIO_PIN_8
#define DIGIT9_GPIO_Port GPIOB
#define DIGIT10_Pin GPIO_PIN_9
#define DIGIT10_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
