#ifndef __ENC28J60_CONDIG_H__
#define __ENC28J60_CONDIG_H__
#include "My_DISCO_BSP.h"


/* 移植相关的接口函数 */
#define ENC28J60_SPI_Write( data ) 		SPI_I2S_SendData( BSP_SPIx, data )
#define ENC28J60_SPI_Read( ) 		      SPI_I2S_ReceiveData( BSP_SPIx )
#define ENC28J60_CSL()                GPIO_WriteBit(BSP_SPIx_NSS_GPIO_PORT, BSP_SPIx_NSS_PIN, 0)
#define ENC28J60_CSH()                GPIO_WriteBit(BSP_SPIx_NSS_GPIO_PORT, BSP_SPIx_NSS_PIN, 1)


#endif
