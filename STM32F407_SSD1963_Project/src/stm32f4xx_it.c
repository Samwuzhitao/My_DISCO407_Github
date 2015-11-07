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
    OS_ENTER_CRITICAL();//保存全局中断标志,关总中断,告知uC/OS-II正要进入中断
    OSIntNesting++;
    OS_EXIT_CRITICAL();//恢复全局中断标志
    OSTimeTick();     //调用uC/OS-II的OSTimeTick()函数,在os_core.c文件里定义,主要判断延时的任务是否计时到
    OSIntExit();  //在os_core.c文件里定义,如果有更高优先级的任务就绪了,则执行一次任务切换            
}


