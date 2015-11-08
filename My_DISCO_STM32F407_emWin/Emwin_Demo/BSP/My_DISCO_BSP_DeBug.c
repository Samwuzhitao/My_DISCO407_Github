#include "My_DISCO_BSP_Debug.h"
#include "My_DISCO_BSP.h"
#include "string.h"

/*
typedef struct 
{
	char * PeripheralName;
	uint8_t PeripheralRegisterBit;
	char * PeripheralRegisterName[100];
	uint8_t PeripheralRegisterNumber;
}DebugPeripheralTypedef;
*/

const DebugPeripheralTypedef DeBugSPI =
{
	"SPI",
	16,
	{
		"CR1",     "NOTUSE",
		"CR2",     "NOTUSE",
		"SR",      "NOTUSE",
		"DR",      "NOTUSE",
		"CRCPR",   "NOTUSE",
		"RXCRCR",  "NOTUSE",
		"TXCRCR",  "NOTUSE",
		"I2SCFGR", "NOTUSE",
		"I2SPR",   "NOTUSE",
	},
	18,
};

const DebugPeripheralTypedef DeBugGPIO =
{
	"GPIO",
	32,
	{
		"MODER",     
		"OTYPER",
		"OSPEEDR",     
		"PUPDR",
		"IDR",      
		"NOTUSE",
		"DR",      
		"ODR",
		"BSRR",   
		"LCKR",
		"AFR[1]",  
		"AFR[2]",  
	},
	12,
};

/***************************************************************************** 
  * @name   
	*       Debug_LCDShowRegister
  * @brief  
	*       Display the peripheral register to Screen
  * @param  
	*       ulStartAddress: Debug peripheral's start address
  *       DebugPeripheral:Debug peripheral's struct pointer
  * @retval 
	*       None
  **************************************************************************/
void Debug_LCDShowRegister( uint32_t ulStartAddress, DebugPeripheralTypedef *DebugPeripheral )
{
	uint8_t i = 0;
	
	GUI_DispStringAt( "Debug Peripheral Name: ", 0, 0);
	GUI_DispString( DebugPeripheral->PeripheralName );
	GUI_DispNextLine();
	
	for( i = 0; i < DebugPeripheral->PeripheralRegisterNumber; i++ )
	{
		if( strncmp(DebugPeripheral->PeripheralRegisterName[i], "NOTUSE", 6))
		{
			GUI_DispString( DebugPeripheral->PeripheralName );
			GUI_DispString( "->" );
			GUI_DispString( DebugPeripheral->PeripheralRegisterName[i] );
			GUI_DispString( ":" );
			if( DebugPeripheral->PeripheralRegisterBit == 16 )
			{
			  GUI_DispHex( *(uint16_t *)( ulStartAddress + 2*i ), 8 );
			}
			else
			{
				GUI_DispHex( *(uint32_t *)( ulStartAddress + 4*i ), 8 );
			}
			GUI_DispNextLine();
		}
	}
	
	GUI_DispString( "Press Key1 Debug Next Step !");
	
	while( BSP_GetKeyState( BSP_KEY1, BSP_KEY1_GPIO_PORT ) == 0 )
	{

	}
	
}
