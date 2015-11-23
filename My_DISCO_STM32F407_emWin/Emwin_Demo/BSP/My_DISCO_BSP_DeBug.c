/* Includes ------------------------------------------------------------------*/
#include "My_DISCO_BSP_Debug.h"
#include "My_DISCO_BSP.h"
#include "string.h"
#include "stdio.h"

/* variables ----------------------------------------------------------------*/
const DebugPeripheralTypedef DeBugUART =
{
	"USART",
	16,
	{
		"SR",     "NOTUSE",
		"DR",     "NOTUSE",
		"BRR",    "NOTUSE",
		"CR1",    "NOTUSE",
		"CR2",    "NOTUSE",
		"CR3",    "NOTUSE", 
		"GTPR",   "NOTUSE",
	},
	14,
};

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
		"ODR",
		"BSRR",   
		"LCKR",
		"AFR[1]",  
		"AFR[2]",  
	},
	10,
};

const DebugPeripheralTypedef DeBugRCC =
{
	"RCC",
	32,
	{
		"CR",
		"PLLCFGR",
		"CFGR",
		"CIR",
		"AHB1RSTR",
		"AHB2RSTR",
		"AHB3RSTR",
		"NOTUSE",
		"APB1RSTR",
		"APB2RSTR",
		"NOTUSE",
		"NOTUSE",
		"AHB1ENR",
		"AHB2ENR",
		"AHB3ENR",
		"NOTUSE",
		"APB1ENR",
		"APB2ENR",
		"NOTUSE",
		"NOTUSE",
		"AHB1LPENR",
		"AHB2LPENR",
		"AHB3LPENR",
		"NOTUSE",
		"APB1LPENR",
		"APB2LPENR",
		"NOTUSE",
		"NOTUSE",
		"BDCR",
		"CSR",
		"NOTUSE",
		"NOTUSE",
		"SSCGR",
		"PLLI2SCFGR",
	},
	34,
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
void Debug_ShowRegister( uint32_t ulStartAddress, DebugPeripheralTypedef *DebugPeripheral )
{
#ifdef Open_Debug
	uint8_t i = 0;
	static uint32_t ulShowTimes = 0;
	
	#ifdef DeBug_Mode_LCD
		GUI_DispStringAt( "Debug Peripheral Name: ", 0, 0);
		GUI_DispString( DebugPeripheral->PeripheralName );
		GUI_DispNextLine();
	#endif
	
	#ifdef DeBug_Mode_UART
		printf("\r\n Debug Peripheral Name: %s\r\n", DebugPeripheral->PeripheralName );
	#endif
	
	for( i = 0; i < DebugPeripheral->PeripheralRegisterNumber; i++ )
	{
		if( strncmp(DebugPeripheral->PeripheralRegisterName[i], "NOTUSE", 6))
		{
			#ifdef DeBug_Mode_LCD
				GUI_DispString( DebugPeripheral->PeripheralName );
				GUI_DispString( "->" );
				GUI_DispString( DebugPeripheral->PeripheralRegisterName[i] );
				GUI_DispString( ":" );
				GUI_DispHex(  ulStartAddress + i*((DebugPeripheral->PeripheralRegisterBit)/8) , 8 );
				GUI_DispString( ":" );
			#endif
			if( DebugPeripheral->PeripheralRegisterBit == 16 )
			{
				#ifdef DeBug_Mode_LCD
					GUI_DispHex( *(uint16_t *)( ulStartAddress + i*2 ), 8 );
				#endif
				#ifdef DeBug_Mode_UART
					printf("%8s -> %10s ( %8x ): %8x \r\n", DebugPeripheral->PeripheralName,
								DebugPeripheral->PeripheralRegisterName[i],
								ulStartAddress +  i*2,
								*(uint16_t *)( ulStartAddress +  i*2 ) );
				#endif
			}
			else
			{
				#ifdef DeBug_Mode_LCD
					GUI_DispHex( *(uint32_t *)( ulStartAddress +  i*4 ), 8 );
				#endif
				#ifdef DeBug_Mode_UART
					printf("%8s -> %10s ( %8x ): %8x \r\n", DebugPeripheral->PeripheralName,
								DebugPeripheral->PeripheralRegisterName[i],
								 ulStartAddress +  i*4,
								*(uint32_t *)( ulStartAddress +  i*4) ) );
				#endif
			}
			#ifdef DeBug_Mode_LCD
				GUI_DispNextLine();
			#endif
		}
	}
	#ifdef DeBug_Mode_LCD
		GUI_DispString( "Run times :" );
		GUI_DispHex( ulShowTimes++, 8 );
	#endif
	
	//GUI_DispString( "Press Key1 Debug Next Step !");

	//while( BSP_GetKeyState( BSP_KEY1, BSP_KEY1_GPIO_PORT ) == 0 )
	//{

	//}
#endif
}


void Debug_ShowSpecificRegister( uint32_t ulStartAddress, 
                                 DebugPeripheralTypedef *DebugPeripheral, 
                                 char * SpecificPeripheralRegisterName )
{
#ifdef Open_Debug
	uint8_t i = 0;
	static uint32_t ulShowTimes = 0;
	
	#ifdef DeBug_Mode_LCD
		GUI_DispStringAt( "Debug Peripheral Name: ", 0, 0);
		GUI_DispString( DebugPeripheral->PeripheralName );
		GUI_DispNextLine();
	#endif
	
	#ifdef DeBug_Mode_UART
		printf("\r\n Debug Peripheral Name: %s\r\n", DebugPeripheral->PeripheralName );
	#endif
	
	for( i = 0; i < DebugPeripheral->PeripheralRegisterNumber; i++ )
	{
		if( 0 == strcmp(DebugPeripheral->PeripheralRegisterName[i], SpecificPeripheralRegisterName))
		{
			#ifdef DeBug_Mode_LCD
				GUI_DispString( DebugPeripheral->PeripheralName );
				GUI_DispString( "->" );
				GUI_DispString( DebugPeripheral->PeripheralRegisterName[i] );
				GUI_DispString( ":" );
				GUI_DispHex(  ulStartAddress + i*((DebugPeripheral->PeripheralRegisterBit)/8) , 8 );
				GUI_DispString( ":" );
			#endif
			if( DebugPeripheral->PeripheralRegisterBit == 16 )
			{
				#ifdef DeBug_Mode_LCD
					GUI_DispHex( *(uint16_t *)( ulStartAddress + i*2 ), 8 );
				#endif
				#ifdef DeBug_Mode_UART
					printf("%8s -> %10s ( %8x ): %8x \r\n", DebugPeripheral->PeripheralName,
								DebugPeripheral->PeripheralRegisterName[i],
								ulStartAddress +  i*2,
								*(uint16_t *)( ulStartAddress +  i*2 ) );
				#endif
			}
			else
			{
				#ifdef DeBug_Mode_LCD
					GUI_DispHex( *(uint32_t *)( ulStartAddress +  i*4 ), 8 );
				#endif
				#ifdef DeBug_Mode_UART
					printf("%8s -> %10s ( %8x ): %8x \r\n", DebugPeripheral->PeripheralName,
								DebugPeripheral->PeripheralRegisterName[i],
								ulStartAddress +  i*4,
								*(uint32_t *)( ulStartAddress +  i*4) ) );
				#endif
			}
			#ifdef DeBug_Mode_LCD
				GUI_DispNextLine();
			#endif
		}
	}
	#ifdef DeBug_Mode_LCD
		GUI_DispString( "Run times :" );
		GUI_DispHex( ulShowTimes++, 8 );
	#endif
	
	//GUI_DispString( "Press Key1 Debug Next Step !");
	//while( BSP_GetKeyState( BSP_KEY1, BSP_KEY1_GPIO_PORT ) == 0 )
	//{
	//}
#endif
}
