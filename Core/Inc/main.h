/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define KB6D_Pin GPIO_PIN_8
#define KB6D_GPIO_Port GPIOF
#define KB6C_Pin GPIO_PIN_9
#define KB6C_GPIO_Port GPIOF
#define KB6B_Pin GPIO_PIN_10
#define KB6B_GPIO_Port GPIOF
#define KB6A_Pin GPIO_PIN_0
#define KB6A_GPIO_Port GPIOC
#define KB5D_Pin GPIO_PIN_1
#define KB5D_GPIO_Port GPIOC
#define KB5C_Pin GPIO_PIN_2
#define KB5C_GPIO_Port GPIOC
#define KB5B_Pin GPIO_PIN_3
#define KB5B_GPIO_Port GPIOC
#define KB5A_Pin GPIO_PIN_0
#define KB5A_GPIO_Port GPIOA
#define KB8B_Pin GPIO_PIN_5
#define KB8B_GPIO_Port GPIOA
#define KB8A_Pin GPIO_PIN_6
#define KB8A_GPIO_Port GPIOA
#define KB7D_Pin GPIO_PIN_7
#define KB7D_GPIO_Port GPIOA
#define KB7C_Pin GPIO_PIN_4
#define KB7C_GPIO_Port GPIOC
#define KB7B_Pin GPIO_PIN_5
#define KB7B_GPIO_Port GPIOC
#define KB7A_Pin GPIO_PIN_0
#define KB7A_GPIO_Port GPIOB
#define KB4D_Pin GPIO_PIN_1
#define KB4D_GPIO_Port GPIOG
#define KB4C_Pin GPIO_PIN_7
#define KB4C_GPIO_Port GPIOE
#define KB4B_Pin GPIO_PIN_8
#define KB4B_GPIO_Port GPIOE
#define KB4A_Pin GPIO_PIN_9
#define KB4A_GPIO_Port GPIOE
#define KB22B_Pin GPIO_PIN_11
#define KB22B_GPIO_Port GPIOD
#define KB22A_Pin GPIO_PIN_12
#define KB22A_GPIO_Port GPIOD
#define KB21D_Pin GPIO_PIN_13
#define KB21D_GPIO_Port GPIOD
#define KB21C_Pin GPIO_PIN_14
#define KB21C_GPIO_Port GPIOD
#define KB21B_Pin GPIO_PIN_15
#define KB21B_GPIO_Port GPIOD
#define KB21A_Pin GPIO_PIN_2
#define KB21A_GPIO_Port GPIOG
#define KB14B_Pin GPIO_PIN_11
#define KB14B_GPIO_Port GPIOG
#define KB14A_Pin GPIO_PIN_12
#define KB14A_GPIO_Port GPIOG
#define KB13D_Pin GPIO_PIN_13
#define KB13D_GPIO_Port GPIOG
#define KB13C_Pin GPIO_PIN_14
#define KB13C_GPIO_Port GPIOG
#define KB13B_Pin GPIO_PIN_15
#define KB13B_GPIO_Port GPIOG
#define KB13A_Pin GPIO_PIN_3
#define KB13A_GPIO_Port GPIOB
#define KB16B_Pin GPIO_PIN_6
#define KB16B_GPIO_Port GPIOB
#define KB16A_Pin GPIO_PIN_7
#define KB16A_GPIO_Port GPIOB
#define KB15D_Pin GPIO_PIN_8
#define KB15D_GPIO_Port GPIOB
#define KB15C_Pin GPIO_PIN_9
#define KB15C_GPIO_Port GPIOB
#define KB15B_Pin GPIO_PIN_0
#define KB15B_GPIO_Port GPIOE
#define KB15A_Pin GPIO_PIN_1
#define KB15A_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
