/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define debounce 75
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
int contadorP1 = 0;
int contadorP2 = 0;
uint8_t luces = 0;
uint8_t datos = 0;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
uint8_t buffer [1];
volatile uint8_t contador = 0;
volatile uint8_t contador2 = 0;
volatile uint8_t juego =0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart2, buffer, sizeof(buffer));
  HAL_GPIO_EXTI_Callback(BP1_Pin);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	HAL_UART_Receive_IT(&huart2, &datos, 1);
		if(datos == 'S'){
			HAL_GPIO_WritePin(lr_GPIO_Port, lr_Pin, 1);
			HAL_Delay(500);
			HAL_GPIO_WritePin(la_GPIO_Port, la_Pin, 1);
			HAL_Delay(500);
			HAL_GPIO_WritePin(lg_GPIO_Port, lg_Pin, 1);
			HAL_Delay(500);
			juego = 1;
		}

			if (juego == 1){
			switch(contador){
			case 0:
				HAL_GPIO_WritePin(L1P1_GPIO_Port, L1P1_Pin, 0);
				HAL_GPIO_WritePin(L2P1_GPIO_Port, L2P1_Pin, 0);
				HAL_GPIO_WritePin(L3P1_GPIO_Port, L3P1_Pin, 0);
				HAL_GPIO_WritePin(L4P1_GPIO_Port, L4P1_Pin, 0);
				break;
			case 1:
				HAL_GPIO_WritePin(L1P1_GPIO_Port, L1P1_Pin, 1);
				HAL_GPIO_WritePin(L2P1_GPIO_Port, L2P1_Pin, 0);
				HAL_GPIO_WritePin(L3P1_GPIO_Port, L3P1_Pin, 0);
				HAL_GPIO_WritePin(L4P1_GPIO_Port, L4P1_Pin, 0);
				break;
			case 2:
				HAL_GPIO_WritePin(L1P1_GPIO_Port, L1P1_Pin, 1);
				HAL_GPIO_WritePin(L2P1_GPIO_Port, L2P1_Pin, 1);
				HAL_GPIO_WritePin(L3P1_GPIO_Port, L3P1_Pin, 0);
				HAL_GPIO_WritePin(L4P1_GPIO_Port, L4P1_Pin, 0);
				break;
			case 3:
				HAL_GPIO_WritePin(L1P1_GPIO_Port, L1P1_Pin, 1);
				HAL_GPIO_WritePin(L2P1_GPIO_Port, L2P1_Pin, 1);
				HAL_GPIO_WritePin(L3P1_GPIO_Port, L3P1_Pin, 1);
				HAL_GPIO_WritePin(L4P1_GPIO_Port, L4P1_Pin, 0);
				break;
			case 4:
				HAL_GPIO_WritePin(L1P1_GPIO_Port, L1P1_Pin, 1);
				HAL_GPIO_WritePin(L2P1_GPIO_Port, L2P1_Pin, 1);
				HAL_GPIO_WritePin(L3P1_GPIO_Port, L3P1_Pin, 1);
				HAL_GPIO_WritePin(L4P1_GPIO_Port, L4P1_Pin, 1);
				juego = 0;
				HAL_UART_Transmit(&huart2, (int*)"El jugador 1 Gana !!", 20, 500);
				break;
			}
			switch(contador2){
						case 0:
							HAL_GPIO_WritePin(L1P2_GPIO_Port, L1P2_Pin, 0);
							HAL_GPIO_WritePin(L2P2_GPIO_Port, L2P2_Pin, 0);
							HAL_GPIO_WritePin(L3P2_GPIO_Port, L3P2_Pin, 0);
							HAL_GPIO_WritePin(L4P2_GPIO_Port, L4P2_Pin, 0);
							break;
						case 1:
							HAL_GPIO_WritePin(L1P2_GPIO_Port, L1P2_Pin, 1);
							HAL_GPIO_WritePin(L2P2_GPIO_Port, L2P2_Pin, 0);
							HAL_GPIO_WritePin(L3P2_GPIO_Port, L3P2_Pin, 0);
							HAL_GPIO_WritePin(L4P2_GPIO_Port, L4P2_Pin, 0);
							break;
						case 2:
							HAL_GPIO_WritePin(L1P2_GPIO_Port, L1P2_Pin, 1);
							HAL_GPIO_WritePin(L2P2_GPIO_Port, L2P2_Pin, 1);
							HAL_GPIO_WritePin(L3P2_GPIO_Port, L3P2_Pin, 0);
							HAL_GPIO_WritePin(L4P2_GPIO_Port, L4P2_Pin, 0);
							break;
						case 3:
							HAL_GPIO_WritePin(L1P2_GPIO_Port, L1P2_Pin, 1);
							HAL_GPIO_WritePin(L2P2_GPIO_Port, L2P2_Pin, 1);
							HAL_GPIO_WritePin(L3P2_GPIO_Port, L3P2_Pin, 1);
							HAL_GPIO_WritePin(L4P2_GPIO_Port, L4P2_Pin, 0);
							break;
						case 4:
							HAL_GPIO_WritePin(L1P2_GPIO_Port, L1P2_Pin, 1);
							HAL_GPIO_WritePin(L2P2_GPIO_Port, L2P2_Pin, 1);
							HAL_GPIO_WritePin(L3P2_GPIO_Port, L3P2_Pin, 1);
							HAL_GPIO_WritePin(L4P2_GPIO_Port, L4P2_Pin, 1);
							HAL_UART_Transmit(&huart2, (int*)"El jugador 2 Gana !!", 20, 500);
							juego = 0;
							break;
						}
			HAL_GPIO_WritePin(lr_GPIO_Port, lr_Pin, 0);
			HAL_GPIO_WritePin(la_GPIO_Port, la_Pin, 0);
			HAL_GPIO_WritePin(lg_GPIO_Port, lg_Pin, 0);
			datos = 0;
		}

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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, lr_Pin|lg_Pin|la_Pin|L1P1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, L1P2_Pin|L4P1_Pin|L3P1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, L4P2_Pin|L3P2_Pin|L2P1_Pin|L2P2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : lr_Pin lg_Pin la_Pin L1P1_Pin */
  GPIO_InitStruct.Pin = lr_Pin|lg_Pin|la_Pin|L1P1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : L1P2_Pin L4P1_Pin L3P1_Pin */
  GPIO_InitStruct.Pin = L1P2_Pin|L4P1_Pin|L3P1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : L4P2_Pin L3P2_Pin L2P1_Pin L2P2_Pin */
  GPIO_InitStruct.Pin = L4P2_Pin|L3P2_Pin|L2P1_Pin|L2P2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BP1_Pin BP2_Pin */
  GPIO_InitStruct.Pin = BP1_Pin|BP2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

    if (GPIO_Pin == BP1_Pin){
                static uint32_t last_tick = 0;
                uint32_t now = HAL_GetTick();
                if ((now - last_tick) >= debounce){
                    if (HAL_GPIO_ReadPin(BP1_GPIO_Port, BP1_Pin) == 1){
                    if (juego == 1){
                    	contador++;
                    }
                    }
                    }
                    last_tick = now;
                }
    if (GPIO_Pin == BP2_Pin){
            static uint32_t last_tick2 = 0;
            uint32_t now2 = HAL_GetTick();
            if ((now2 - last_tick2) >= debounce){
                if (HAL_GPIO_ReadPin(BP2_GPIO_Port, BP2_Pin) == 1){
                if (juego == 1){
                	contador2++;
                }
                }
                }
                last_tick2 = now2;
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
#ifdef USE_FULL_ASSERT
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
