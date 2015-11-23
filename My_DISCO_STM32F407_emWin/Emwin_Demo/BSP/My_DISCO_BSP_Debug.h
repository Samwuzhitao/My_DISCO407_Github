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
extern const DebugPeripheralTypedef DeBugRCC;
extern const DebugPeripheralTypedef DeBugUART;

/* Exported functions ------------------------------------------------------- */
void Debug_ShowRegister( uint32_t ulStartAddress, DebugPeripheralTypedef *DebugPeripheral );
void Debug_ShowSpecificRegister( uint32_t ulStartAddress, 
                                 DebugPeripheralTypedef *DebugPeripheral, 
                                 char * SpecificPeripheralRegisterName );
#endif
