/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32f4xx_it.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define USART_REC_LEN  			200  	//�����������ֽ��� 200
#define  UART_ENABLE_RE(USARTx)       USARTx.Instance->CR1|= (uint32_t)0x0004            
#define  UART_DISABLE_RE(USARTx)      USARTx.Instance->CR1&= (~(uint32_t)0x0004)  
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Data_Processing(void);  //�������ݴ�����
/* ��ڲ���
 * mode�� �������ģʽ 0������ 1�� ���
 * Number:  ѡ��򿪵���·
 */
void GPIO_CONTROL_STATUS(uint8_t mode ,uint8_t Number);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint8_t Recevice_Buff[USART_REC_LEN];   //���ջ�����
//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�֡ͷ
//bit13��  ���յ���ȷ��������
//bit12��  ���յ����ݳ���
//bit11��  ���յ�֡β
//bit10~0��	���յ�����Ч�ֽ���Ŀ
uint16_t USART_RX_STA = 0;       //����״̬���	
#define RXBUFFERSIZE  1
extern uint8_t aRxBuffer[RXBUFFERSIZE];
uint8_t Recevice_Len = 2;
uint8_t Recevice_Len_temp = 2;   //�������ݵĳ���  Ĭ��Ϊ2  һ������ һ�����
uint8_t Usart_Flag = 0;   //0: ����һ���͵����� 1�� ���ڶ����͵�����
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if(USART_RX_STA&0x8000) //���յ�����
		{
			//���ݽ��� �Է����ݸ��ǹرմ��ڽ���
			#if 1
			UART_DISABLE_RE(huart1);
			UART_DISABLE_RE(huart2);
			#endif
			//���ͽ��յ�������
			if(Usart_Flag == 0)
			{
				HAL_UART_Transmit(&huart1,(uint8_t *)Recevice_Buff,USART_RX_STA&0x0fff,1000);
				while(__HAL_UART_GET_FLAG(&huart1,UART_FLAG_TC)!=SET);		//�ȴ����ͽ���
			}
			else if(Usart_Flag == 1)
			{
				HAL_UART_Transmit(&huart2,(uint8_t *)Recevice_Buff,USART_RX_STA&0x0fff,1000);
				while(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_TC)!=SET);		//�ȴ����ͽ���
			}

			//������·ѡ��
			switch(Recevice_Buff[0])
			{
				case 0x00: All_GPIO_RESET(0); break;
				case 0x01: GPIO_CONTROL_STATUS(0,1); break;
				case 0x02: GPIO_CONTROL_STATUS(0,2); break;
				case 0x03: GPIO_CONTROL_STATUS(0,3); break;
				case 0x04: GPIO_CONTROL_STATUS(0,4); break;
				default :break;
			}
			//�����·ѡ��
			switch(Recevice_Buff[1])
			{
				case 0x00: All_GPIO_RESET(1); break;
				case 0x01: GPIO_CONTROL_STATUS(1,1); break;
				case 0x02: GPIO_CONTROL_STATUS(1,2); break;
				case 0x03: GPIO_CONTROL_STATUS(1,3); break;
				case 0x04: GPIO_CONTROL_STATUS(1,4); break;
				case 0x05: GPIO_CONTROL_STATUS(1,5); break;
				case 0x06: GPIO_CONTROL_STATUS(1,6); break;
				case 0x07: GPIO_CONTROL_STATUS(1,7); break;
				case 0x08: GPIO_CONTROL_STATUS(1,8); break;
				case 0x09: GPIO_CONTROL_STATUS(1,9); break;
				case 0x0a: GPIO_CONTROL_STATUS(1,10);break;
				case 0x0b: GPIO_CONTROL_STATUS(1,11);break;
				case 0x0c: GPIO_CONTROL_STATUS(1,12);break;
				case 0x0d: GPIO_CONTROL_STATUS(1,13);break;
				case 0x0e: GPIO_CONTROL_STATUS(1,14);break;
				case 0x0f: GPIO_CONTROL_STATUS(1,15);break;
				case 0x10: GPIO_CONTROL_STATUS(1,16);break;
				case 0x11: GPIO_CONTROL_STATUS(1,17);break;
				case 0x12: GPIO_CONTROL_STATUS(1,18);break;
				case 0x13: GPIO_CONTROL_STATUS(1,19);break;
				case 0x14: GPIO_CONTROL_STATUS(1,20);break;
				case 0x15: GPIO_CONTROL_STATUS(1,21);break;
				case 0x16: GPIO_CONTROL_STATUS(1,22);break;
				case 0x17: GPIO_CONTROL_STATUS(1,23);break;
				case 0x18: GPIO_CONTROL_STATUS(1,24);break;
				default :break;
			}
			//������ݼ����ձ�׼λ
			memset(Recevice_Buff,0x00,USART_RX_STA&0x0fff);
			USART_RX_STA = 0;
			Recevice_Len_temp = Recevice_Len;
			//ʹ�ܴ��ڽ���
			#if 1
			UART_ENABLE_RE(huart1);
			UART_ENABLE_RE(huart2);
			#endif
		}
		else
		{
			__WFI();  //δ���ܵ����ݽ���˯��ģʽ
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 15;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

//�����жϻص�����
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	UNUSED(huart);
	if(huart->Instance==USART1)//����Ǵ���1
	{
		Usart_Flag = 0;
		Data_Processing();
		HAL_UART_Receive_IT(&huart1, (uint8_t *)aRxBuffer, RXBUFFERSIZE);
	}
	else if(huart->Instance==USART2)
	{
		Usart_Flag = 1;
		Data_Processing();
		HAL_UART_Receive_IT(&huart2, (uint8_t *)aRxBuffer, RXBUFFERSIZE);
	}
}
//bit15��	������ɱ�־
//bit14��	���յ�֡ͷ
//bit11~0��	���յ�����Ч�ֽ���Ŀ
//���ڽ��մ�����
void Data_Processing(void)
{
	if((USART_RX_STA&0x8000)==0)//����δ���
	{
		if(USART_RX_STA&0x4000)//���յ���֡ͷ
		{
			if(Recevice_Len_temp>0)
			{
				Recevice_Buff[USART_RX_STA&0x0fff] = aRxBuffer[0];
				USART_RX_STA ++;
				Recevice_Len_temp--;
			}
			else
			{
				if(aRxBuffer[0]==0xC1)
				{
					USART_RX_STA|=0x8000;
				}
				else  //���մ���
				{
					memset(Recevice_Buff,0x00,USART_RX_STA&0x0fff);
					USART_RX_STA = 0;
				}
			}				
		}
		else //��û�յ�0XC0 ֡ͷ
		{	
			if(aRxBuffer[0]==0xC0)USART_RX_STA|=0x4000;
			else
			{
				USART_RX_STA = 0;  //���մ���
			}		 
		}
	}
}

void GPIO_CONTROL_STATUS(uint8_t mode, uint8_t Number)
{
	All_GPIO_RESET(mode);  //���Ͷ�ӦIO
	switch(mode)
	{
		case 0:
			switch(Number)
			{
				case 1: HAL_GPIO_WritePin(KB4A_GPIO_Port,KB4A_Pin,GPIO_PIN_SET); break;
				case 2: HAL_GPIO_WritePin(KB4B_GPIO_Port,KB4B_Pin,GPIO_PIN_SET); break;
				case 3: HAL_GPIO_WritePin(KB4C_GPIO_Port,KB4C_Pin,GPIO_PIN_SET); break;
				case 4: HAL_GPIO_WritePin(KB4D_GPIO_Port,KB4D_Pin,GPIO_PIN_SET); break;
				default : break;
			}break;
		case 1:
			switch(Number)
			{
				case 1: 
					HAL_GPIO_WritePin(KB6A_GPIO_Port,KB6A_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB7A_GPIO_Port,KB7A_Pin,GPIO_PIN_SET); break;
				case 2: 
					HAL_GPIO_WritePin(KB6A_GPIO_Port,KB6A_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB7B_GPIO_Port,KB7B_Pin,GPIO_PIN_SET); break;
				case 3: 
					HAL_GPIO_WritePin(KB6A_GPIO_Port,KB6A_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB7C_GPIO_Port,KB7C_Pin,GPIO_PIN_SET); break;
				case 4: 
					HAL_GPIO_WritePin(KB6A_GPIO_Port,KB6A_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB7D_GPIO_Port,KB7D_Pin,GPIO_PIN_SET); break;
				case 5: 
					HAL_GPIO_WritePin(KB6A_GPIO_Port,KB6A_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB8A_GPIO_Port,KB8A_Pin,GPIO_PIN_SET); break;
				case 6: 
					HAL_GPIO_WritePin(KB6A_GPIO_Port,KB6A_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB8B_GPIO_Port,KB8B_Pin,GPIO_PIN_SET); break;
				case 7: 
					HAL_GPIO_WritePin(KB6B_GPIO_Port,KB6B_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB13A_GPIO_Port,KB13A_Pin,GPIO_PIN_SET); break;
				case 8: 
					HAL_GPIO_WritePin(KB6B_GPIO_Port,KB6B_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB13B_GPIO_Port,KB13B_Pin,GPIO_PIN_SET); break;
				case 9: 
					HAL_GPIO_WritePin(KB6B_GPIO_Port,KB6B_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB13C_GPIO_Port,KB13C_Pin,GPIO_PIN_SET); break;
				case 10: 
					HAL_GPIO_WritePin(KB6B_GPIO_Port,KB6B_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB13D_GPIO_Port,KB13D_Pin,GPIO_PIN_SET); break;
				case 11: 
					HAL_GPIO_WritePin(KB6B_GPIO_Port,KB6B_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB14A_GPIO_Port,KB14A_Pin,GPIO_PIN_SET); break;
				case 12: 
					HAL_GPIO_WritePin(KB6B_GPIO_Port,KB6B_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB14B_GPIO_Port,KB14B_Pin,GPIO_PIN_SET); break;
				case 13: 
					HAL_GPIO_WritePin(KB6C_GPIO_Port,KB6C_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB15A_GPIO_Port,KB15A_Pin,GPIO_PIN_SET); break;
				case 14: 
					HAL_GPIO_WritePin(KB6C_GPIO_Port,KB6C_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB15B_GPIO_Port,KB15B_Pin,GPIO_PIN_SET); break;
				case 15: 
					HAL_GPIO_WritePin(KB6C_GPIO_Port,KB6C_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB15C_GPIO_Port,KB15C_Pin,GPIO_PIN_SET); break;
				case 16: 
					HAL_GPIO_WritePin(KB6C_GPIO_Port,KB6C_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB15D_GPIO_Port,KB15D_Pin,GPIO_PIN_SET); break;
				case 17: 
					HAL_GPIO_WritePin(KB6C_GPIO_Port,KB6C_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB16A_GPIO_Port,KB16A_Pin,GPIO_PIN_SET); break;
				case 18: 
					HAL_GPIO_WritePin(KB6C_GPIO_Port,KB6C_Pin,GPIO_PIN_SET);	
					HAL_GPIO_WritePin(KB16B_GPIO_Port,KB16B_Pin,GPIO_PIN_SET); break;
				case 19: 
					HAL_GPIO_WritePin(KB6D_GPIO_Port,KB6D_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB21A_GPIO_Port,KB21A_Pin,GPIO_PIN_SET); break;
				case 20: 
					HAL_GPIO_WritePin(KB6D_GPIO_Port,KB6D_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB21B_GPIO_Port,KB21B_Pin,GPIO_PIN_SET); break;
				case 21: 
					HAL_GPIO_WritePin(KB6D_GPIO_Port,KB6D_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB21C_GPIO_Port,KB21C_Pin,GPIO_PIN_SET); break;
				case 22: 
					HAL_GPIO_WritePin(KB6D_GPIO_Port,KB6D_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB21D_GPIO_Port,KB21D_Pin,GPIO_PIN_SET); break;
				case 23: 
					HAL_GPIO_WritePin(KB6D_GPIO_Port,KB6D_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB22A_GPIO_Port,KB22A_Pin,GPIO_PIN_SET); break;
				case 24: 
					HAL_GPIO_WritePin(KB6D_GPIO_Port,KB6D_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(KB22B_GPIO_Port,KB22B_Pin,GPIO_PIN_SET); break;
				default : break;
			};break;
		default :  break;
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
