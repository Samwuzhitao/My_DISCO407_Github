/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "SSD1963.h"

#include "ENC28J60.h"
//#include "ip_arp_udp_tcp.h"
//#include "net.h"
//#include "web_server.h"

#include "GUI.h"
#include "My_DISCO_BSP.h"
#include "My_DISCO_BSP_Debug.h"
#include "My_DISCO_BSP_Config.h"

#include "string.h"

#include "stdarg.h"
#include "stdio.h"


#include "lwip/err.h"
#include "netif/etharp.h"
	
#include "netconfig.h"

#include "cmd.h"
#include "httpd.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/



/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;
static __IO uint32_t TimingDelay;
extern __IO uint32_t LocalTime;

/* Private function prototypes -----------------------------------------------*/
static void Delay(__IO uint32_t nTime); 

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
		void uart_init(u32 bound);
int main(void)
{
	
	SystemInit();
	
	SSD1963_Init();

	SSD1963_Clear(Red);
	Delay(100);
	SSD1963_Clear(Blue);
	Delay(100);
	SSD1963_Clear(Red);
	SSD1963_Fill(0, 0, 50, 50, Blue);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
	GUI_Init();
	GUI_SetColor(GUI_RED);
	GUI_Clear();
	
	BSP_KeyInit( BSP_KEY1, BSP_KEY1_GPIO_PORT );

	BSP_USART_Init( );
	
	BSP_SPI_Init( );
	BSP_SPI_CS_Init( );
	
	//Debug_ShowRegister( GPIOA_BASE, (DebugPeripheralTypedef *)&DeBugGPIO );
	//Debug_ShowRegister( BSP_USARTx_BASE, (DebugPeripheralTypedef *)&DeBugUART );
	//Debug_ShowRegister( RCC_BASE, (DebugPeripheralTypedef *)&DeBugRCC );
	//Debug_ShowSpecificRegister( RCC_BASE, (DebugPeripheralTypedef *)&DeBugRCC, "APB2ENR" );
	
  /* 初始化LWIP协议栈*/
	LwIP_Init(); 

	/*初始化web server 显示网页程序*/
	httpd_init();
  
  /* 初始化telnet   远程控制 程序 */   
  CMD_init();                                       

  /* Infinite loop */
  while ( 1 )
	{	
		/*轮询*/  
		LwIP_Periodic_Handle(LocalTime);		          	  
  }

}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0)
  { 
    TimingDelay--;
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
