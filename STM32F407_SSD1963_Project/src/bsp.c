//board support package:����Ӳ���Ͳ���ϵͳ�����������֮���һ��
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

void  SysTick_Init(void)//����uC/OS-II��ʱ�����
{
    INT32U  cnts;
    RCC_ClocksTypeDef  rcc_clocks;

    RCC_GetClocksFreq(&rcc_clocks);
    cnts=(INT32U)rcc_clocks.HCLK_Frequency/OS_TICKS_PER_SEC;
    SysTick_Config(cnts);
}


