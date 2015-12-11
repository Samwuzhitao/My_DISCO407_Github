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
#include "http_YeeLink.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/


#define SYSTEMTICK_PERIOD_MS  10
extern u8_t data[1024];
extern char wendu[5];
extern struct tcp_pcb *echoclient_pcb;
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


int main(void)
{
  int i_counter = 160;	
	
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

	/* 初始化web server 显示网页程序 */
	//httpd_init();
  
  /* 初始化telnet 远程控制程序 */   
  //CMD_init();                                       

  /* 初始化web celient远程控制程序 */  
  //tcp_client_connect();
	tcp_echoclient_connect();
	
  /* Infinite loop */
  while ( 1 )
	{	
		/*轮询*/ 
		//tcp_echoclient_connect();		
		Delay(500);
		LwIP_Periodic_Handle(LocalTime);

		if(i_counter++ > 1000)
			i_counter = 101;
		
		wendu[0] = i_counter/100%10 + 0x30;
		wendu[1] = i_counter/10%10 + 0x30;
		wendu[3] = i_counter%10 + 0x30;
	
		printf(wendu);
		
		printf("\r\n");
		
		Delay(500);
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
