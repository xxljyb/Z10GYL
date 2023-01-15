/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, KB6D_Pin|KB6C_Pin|KB6B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, KB6A_Pin|KB5D_Pin|KB5C_Pin|KB5B_Pin
                          |KB7C_Pin|KB7B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, KB5A_Pin|KB8B_Pin|KB8A_Pin|KB7D_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, KB7A_Pin|KB13A_Pin|KB16B_Pin|KB16A_Pin
                          |KB15D_Pin|KB15C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, KB4D_Pin|KB21A_Pin|KB14B_Pin|KB14A_Pin
                          |KB13D_Pin|KB13C_Pin|KB13B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, KB4C_Pin|KB4B_Pin|KB4A_Pin|KB15B_Pin
                          |KB15A_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, KB22B_Pin|KB22A_Pin|KB21D_Pin|KB21C_Pin
                          |KB21B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PFPin PFPin PFPin */
  GPIO_InitStruct.Pin = KB6D_Pin|KB6C_Pin|KB6B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin
                           PCPin PCPin */
  GPIO_InitStruct.Pin = KB6A_Pin|KB5D_Pin|KB5C_Pin|KB5B_Pin
                          |KB7C_Pin|KB7B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = KB5A_Pin|KB8B_Pin|KB8A_Pin|KB7D_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin
                           PBPin PBPin */
  GPIO_InitStruct.Pin = KB7A_Pin|KB13A_Pin|KB16B_Pin|KB16A_Pin
                          |KB15D_Pin|KB15C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin PGPin PGPin
                           PGPin PGPin PGPin */
  GPIO_InitStruct.Pin = KB4D_Pin|KB21A_Pin|KB14B_Pin|KB14A_Pin
                          |KB13D_Pin|KB13C_Pin|KB13B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin
                           PEPin */
  GPIO_InitStruct.Pin = KB4C_Pin|KB4B_Pin|KB4A_Pin|KB15B_Pin
                          |KB15A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin
                           PDPin */
  GPIO_InitStruct.Pin = KB22B_Pin|KB22A_Pin|KB21D_Pin|KB21C_Pin
                          |KB21B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
//½«ËùÓÐIOÖÃµÍ
void All_GPIO_RESET(uint8_t mode)
{
	#if LINK_IO_ENABLE
	if(mode == 0)
	{
		HAL_GPIO_WritePin(KB4A_GPIO_Port,KB4A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB4B_GPIO_Port,KB4B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB4C_GPIO_Port,KB4C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB4D_GPIO_Port,KB4D_Pin,GPIO_PIN_RESET);
	}
	else if(mode == 1)
	{
		HAL_GPIO_WritePin(KB6A_GPIO_Port,KB6A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB6B_GPIO_Port,KB6B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB6C_GPIO_Port,KB6C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB6D_GPIO_Port,KB6D_Pin,GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(KB7A_GPIO_Port,KB7A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB7B_GPIO_Port,KB7B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB7C_GPIO_Port,KB7C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB7D_GPIO_Port,KB7D_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB8A_GPIO_Port,KB8A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB8B_GPIO_Port,KB8B_Pin,GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(KB13A_GPIO_Port,KB13A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB13B_GPIO_Port,KB13B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB13C_GPIO_Port,KB13C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB13D_GPIO_Port,KB13D_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB14A_GPIO_Port,KB14A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB14B_GPIO_Port,KB14B_Pin,GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(KB15A_GPIO_Port,KB15A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB15B_GPIO_Port,KB15B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB15C_GPIO_Port,KB15C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB15D_GPIO_Port,KB15D_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB16A_GPIO_Port,KB16A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB16B_GPIO_Port,KB16B_Pin,GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(KB21A_GPIO_Port,KB21A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB21B_GPIO_Port,KB21B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB21C_GPIO_Port,KB21C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB21D_GPIO_Port,KB21D_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB22A_GPIO_Port,KB22A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB22B_GPIO_Port,KB22B_Pin,GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(KB5A_GPIO_Port,KB5A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB5B_GPIO_Port,KB5B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB5C_GPIO_Port,KB5C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB5D_GPIO_Port,KB5D_Pin,GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(KB6A_GPIO_Port,KB6A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB6B_GPIO_Port,KB6B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB6C_GPIO_Port,KB6C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB6D_GPIO_Port,KB6D_Pin,GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(KB7A_GPIO_Port,KB7A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB7B_GPIO_Port,KB7B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB7C_GPIO_Port,KB7C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB7D_GPIO_Port,KB7D_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB8A_GPIO_Port,KB8A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB8B_GPIO_Port,KB8B_Pin,GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(KB13A_GPIO_Port,KB13A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB13B_GPIO_Port,KB13B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB13C_GPIO_Port,KB13C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB13D_GPIO_Port,KB13D_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB14A_GPIO_Port,KB14A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB14B_GPIO_Port,KB14B_Pin,GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(KB15A_GPIO_Port,KB15A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB15B_GPIO_Port,KB15B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB15C_GPIO_Port,KB15C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB15D_GPIO_Port,KB15D_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB16A_GPIO_Port,KB16A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB16B_GPIO_Port,KB16B_Pin,GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(KB21A_GPIO_Port,KB21A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB21B_GPIO_Port,KB21B_Pin,GPIO_PIN_RESET);  
		HAL_GPIO_WritePin(KB21C_GPIO_Port,KB21C_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB21D_GPIO_Port,KB21D_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB22A_GPIO_Port,KB22A_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(KB22B_GPIO_Port,KB22B_Pin,GPIO_PIN_RESET);
	}
	#endif
}
/* USER CODE END 2 */
