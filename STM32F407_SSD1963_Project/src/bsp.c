//board support package:介于硬件和操作系统中驱动层程序之间的一层
#define  BSP_GLOBALS
#include <includes.h>

static volatile ErrorStatus HSEStartUpStatus = SUCCESS;
						   

void  BSP_Init(void)
{
	Key_Init();
	LED_Init();
	//MyLCD_Init();
  Touch_Init();
  SysTick_Init();
}

void  SysTick_Init(void)//配置uC/OS-II的时间节拍
{
    INT32U  cnts;
    RCC_ClocksTypeDef  rcc_clocks;

    RCC_GetClocksFreq(&rcc_clocks);
    cnts=(INT32U)rcc_clocks.HCLK_Frequency/OS_TICKS_PER_SEC;
    SysTick_Config(cnts);
}


