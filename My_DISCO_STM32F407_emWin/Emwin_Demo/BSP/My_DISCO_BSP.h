/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_DISCO_BSP_H__
#define __MY_DISCO_BSP_H__
/* Includes ------------------------------------------------------------------*/
#include "My_DISCO_BSP_Config.h"
#include "SSD1963.h"
#include "GUI.h"

/* Exported define -----------------------------------------------------------*/
          

/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Led Bsp function */

/* Key Bsp fuction */
void BSP_KeyInit( uint32_t ulKeyPin, GPIO_TypeDef *ulKeyPort);
uint8_t BSP_GetKeyState( uint32_t ulKeyPin, GPIO_TypeDef *ulKeyPort );

/* SPI Bsp fuction */
void BSP_SPI_Init( void );
void BSP_USART_Init( void );

#endif
