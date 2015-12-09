#include <includes.h>

static OS_STK AppTaskStartStk[APP_TASK_START_STK_SIZE];
static OS_STK AppTaskUserIFStk[APP_TASK_USER_IF_STK_SIZE];
static OS_STK AppTaskKbdStk[APP_TASK_KBD_STK_SIZE];
int ExTick;

static void AppTaskCreate(void);
static void AppTaskStart(void *p_arg);
static void AppTaskUserIF(void *p_arg);
static void AppTaskKbd(void *p_arg);
u32 sd_Capacity;
volatile  INT32U  SoftTimer;
/********************************************************************************************
                                        main()
********************************************************************************************/
void MainTask(void);
		 
int  main (void)
{
    INT8U  err;	 
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);//设置矢量表起始地址为0x08000000   
    OSInit();//初始化uC/OSII,实时内核             */
   //建立开始任务
	OSTaskCreateExt(AppTaskStart,(void *)0,(OS_STK *)&AppTaskStartStk[APP_TASK_START_STK_SIZE-1],APP_TASK_START_PRIO,APP_TASK_START_PRIO,(OS_STK *)&AppTaskStartStk[0],APP_TASK_START_STK_SIZE,(void *)0,OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);

	#if (OS_TASK_NAME_SIZE > 13)
    OSTaskNameSet(APP_TASK_START_PRIO, "Start Task", &err);
	#endif
    OSStart();//开始多任务                              
}

/**********************************************************************************************
*                                          STARTUP TASK
* Description :you MUST initialize the ticker only once multitasking has started.
* Arguments   : p_arg是OSTaskCreate()传递给AppTaskStart()的参数
* Notes       :第一条语句是用来防止在没有使用p_arg的情况下编译器产生警告,编译器不应为这条语句产生任何代码
**********************************************************************************************/
static  void  AppTaskStart (void *p_arg)
{
  	(void)p_arg;
   	BSP_Init();//初始化BSP函数
   	#if(OS_TASK_STAT_EN > 0)
    OSStatInit();//定制CPU容量(通过调用来统计CPU使用率)
   	#endif
 	  AppTaskCreate();//建立用户任务   
   	while(DEF_TRUE)//任务体,通常为一个无限循环
	  {  
	   	OSTaskSuspend(OS_PRIO_SELF);//挂起任务 
    }
}												 

/**********************************************************************************************
*                                      CREATE APPLICATION TASKS
* Description:用于建立用户任务
**********************************************************************************************/
static  void  AppTaskCreate(void)
{
  	INT8U  err;
  	OSTaskCreateExt(AppTaskUserIF,(void *)0,(OS_STK *)&AppTaskUserIFStk[APP_TASK_USER_IF_STK_SIZE-1],APP_TASK_USER_IF_PRIO,APP_TASK_USER_IF_PRIO,(OS_STK *)&AppTaskUserIFStk[0],APP_TASK_USER_IF_STK_SIZE,(void *)0,OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);
	#if (OS_TASK_NAME_SIZE > 8)
  	OSTaskNameSet(APP_TASK_USER_IF_PRIO, "User I/F", &err);
	#endif
  	OSTaskCreateExt(AppTaskKbd,(void *)0,(OS_STK *)&AppTaskKbdStk[APP_TASK_KBD_STK_SIZE-1],APP_TASK_KBD_PRIO,APP_TASK_KBD_PRIO,(OS_STK *)&AppTaskKbdStk[0],APP_TASK_KBD_STK_SIZE,(void *)0,OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);
	#if (OS_TASK_NAME_SIZE > 8)
  	OSTaskNameSet(APP_TASK_KBD_PRIO, "Keyboard", &err);
	#endif													  
}

/**********************************************************************************************
*                                         USER INTERFACE TASK
* Description :该任务根据AppTaskKbd()传来的信息更新屏幕
* Arguments   : p_arg是OSTaskCreate()传递给AppStartUserIF()的参数
***********************************************************************************************/
static  void  AppTaskUserIF (void *p_arg)
{
 
 	(void)p_arg;
 	while(DEF_TRUE) 
	{
		MyLCD_Init();
		LCD_Clear(Dgreen);
	//LCD_Char(u16 Xpos, u16 Ypos, u8 Ascii, u16 color)
  //LCD_String(0, 0, "SSD1963 Driver Test", Red);
	  OSTimeDlyHMSM (0, 0, 1, 0);
		LCD_Clear(Red);
  //LCD_String(0, 240, "SSD1963 Driver Test", Dgreen);
	  OSTimeDlyHMSM (0, 0, 1, 0);
		LCD_Clear(Blue);
	//LCD_String(0, 240, "SSD1963 Driver Test", Dgreen);
	//LCD_Clear(Red);
	 OSTimeDlyHMSM (0, 0, 1, 0);
	}
}

/********************************************************************************************
*                                    KEYBOARD RESPONSE TASK
* Description :该任务用于监视按键状态并传递信息给AppTaskUserIF()
* Arguments   : p_arg是OSTaskCreate()传递给AppStartKbd()的参数
*********************************************************************************************/
static  void  AppTaskKbd (void *p_arg)
{
   u8 tick=0;
  (void)p_arg;
  while(DEF_TRUE) 
	{
		//MyLCD_Init();
		//LCD_Clear( Red);
		OSTimeDlyHMSM (0, 0, 10, 0);
  }
}
