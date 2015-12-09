//V1.0.0
#include "stm32f4xx_it.h"
#include "main.h"

//NMI exception handler
void NMI_Handler(void)
{
}

//Hard Fault exception handler
void HardFault_Handler(void)
{
  	while (1)
  	{
  	}
}

//Memory Manage exception handler
void MemManage_Handler(void)
{
  	while (1)
  	{
  	}
}

//Bus Fault exception handler
void BusFault_Handler(void)
{
  	while (1)
  	{
  	}
}

//Usage Fault exception handler
void UsageFault_Handler(void)
{
  	while (1)
  	{
  	}
}

//SVCall exception handler
void SVC_Handler(void)
{
}

//Debug Monitor exception handler
void DebugMon_Handler(void)
{
}

//PendSVC exception handler
//void PendSV_Handler(void)
//{
//}

//SysTick handler
void SysTick_Handler(void)
{
   	OS_CPU_SR  cpu_sr;
    OS_ENTER_CRITICAL();//����ȫ���жϱ�־,�����ж�,��֪uC/OS-II��Ҫ�����ж�
    OSIntNesting++;
    OS_EXIT_CRITICAL();//�ָ�ȫ���жϱ�־
    OSTimeTick();     //����uC/OS-II��OSTimeTick()����,��os_core.c�ļ��ﶨ��,��Ҫ�ж���ʱ�������Ƿ��ʱ��
    OSIntExit();  //��os_core.c�ļ��ﶨ��,����и������ȼ������������,��ִ��һ�������л�            
}


