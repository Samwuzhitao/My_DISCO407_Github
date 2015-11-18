/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_DISCO_BSP_CONFIG_H__
#define __MY_DISCO_BSP_CONFIG_H__

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* */
#define Open_Debug
/* if you want debug with UART, open this MICRO */
#define DeBug_Mode_UART
/* if you want debug with LCD, open this MICRO */
//#define DeBug_Mode_LCD

/* Key Define*/
#define BSP_KEY1                           GPIO_Pin_0
#define BSP_KEY1_CLK_INIT                  RCC_APB1PeriphClockCmd
#define BSP_KEY1_GPIO_PORT                 GPIOA

/* SPI Define */
#define BSP_SPIx                           SPI2
#define BSP_SPIx_CLK                       RCC_APB1Periph_SPI2
#define BSP_SPIx_CLK_INIT                  RCC_APB1PeriphClockCmd
#define BSP_SPIx_IRQn                      SPI2_IRQn
#define BSP_SPIx_IRQHANDLER                SPI2_IRQHandler

#define BSP_SPIx_NSS_PIN                   GPIO_Pin_12
#define BSP_SPIx_NSS_GPIO_PORT             GPIOB
#define BSP_SPIx_NSS_GPIO_CLK              RCC_AHB1Periph_GPIOB
#define BSP_SPIx_NSS_SOURCE                GPIO_PinSource12
#define BSP_SPIx_NSS_AF                    GPIO_AF_SPI2

#define BSP_SPIx_SCK_PIN                   GPIO_Pin_13
#define BSP_SPIx_SCK_GPIO_PORT             GPIOB
#define BSP_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
#define BSP_SPIx_SCK_SOURCE                GPIO_PinSource13
#define BSP_SPIx_SCK_AF                    GPIO_AF_SPI2

#define BSP_SPIx_MISO_PIN                  GPIO_Pin_14
#define BSP_SPIx_MISO_GPIO_PORT            GPIOB
#define BSP_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define BSP_SPIx_MISO_SOURCE               GPIO_PinSource14
#define BSP_SPIx_MISO_AF                   GPIO_AF_SPI2

#define BSP_SPIx_MOSI_PIN                  GPIO_Pin_15
#define BSP_SPIx_MOSI_GPIO_PORT            GPIOB
#define BSP_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define BSP_SPIx_MOSI_SOURCE               GPIO_PinSource15
#define BSP_SPIx_MOSI_AF                   GPIO_AF_SPI2

#define BUFFERSIZE                         100

/* UART Define */


#endif
