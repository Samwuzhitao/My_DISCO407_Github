#ifndef __MY_DISCO_BSP_DEBUG_H__
#define __MY_DISCO_BSP_DEBUG_H__
/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Exported typedef ----------------------------------------------------------*/
typedef struct 
{
	char * PeripheralName;
	uint8_t PeripheralRegisterBit;
	char * PeripheralRegisterName[100];
	uint8_t PeripheralRegisterNumber;
}DebugPeripheralTypedef;

/* Exported constants --------------------------------------------------------*/
extern const DebugPeripheralTypedef DeBugSPI;
extern const DebugPeripheralTypedef DeBugGPIO;

/* Exported functions ------------------------------------------------------- */
void Debug_LCDShowRegister( uint32_t ulStartAddress, DebugPeripheralTypedef *DebugPeripheral );

#endif
