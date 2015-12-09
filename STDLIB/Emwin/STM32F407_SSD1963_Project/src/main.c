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
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);//����ʸ������ʼ��ַΪ0x08000000   
    OSInit();//��ʼ��uC/OSII,ʵʱ�ں�             */
   //������ʼ����
	OSTaskCreateExt(AppTaskStart,(void *)0,(OS_STK *)&AppTaskStartStk[APP_TASK_START_STK_SIZE-1],APP_TASK_START_PRIO,APP_TASK_START_PRIO,(OS_STK *)&AppTaskStartStk[0],APP_TASK_START_STK_SIZE,(void *)0,OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);

	#if (OS_TASK_NAME_SIZE > 13)
    OSTaskNameSet(APP_TASK_START_PRIO, "Start Task", &err);
	#endif
    OSStart();//��ʼ������                              
}

/**********************************************************************************************
*                                          STARTUP TASK
* Description :you MUST initialize the ticker only once multitasking has started.
* Arguments   : p_arg��OSTaskCreate()���ݸ�AppTaskStart()�Ĳ���
* Notes       :��һ�������������ֹ��û��ʹ��p_arg������±�������������,��������ӦΪ�����������κδ���
**********************************************************************************************/
static  void  AppTaskStart (void *p_arg)
{
  	(void)p_arg;
   	BSP_Init();//��ʼ��BSP����
   	#if(OS_TASK_STAT_EN > 0)
    OSStatInit();//����CPU����(ͨ��������ͳ��CPUʹ����)
   	#endif
 	  AppTaskCreate();//�����û�����   
   	while(DEF_TRUE)//������,ͨ��Ϊһ������ѭ��
	  {  
	   	OSTaskSuspend(OS_PRIO_SELF);//�������� 
    }
}												 

/**********************************************************************************************
*                                      CREATE APPLICATION TASKS
* Description:���ڽ����û�����
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
* Description :���������AppTaskKbd()��������Ϣ������Ļ
* Arguments   : p_arg��OSTaskCreate()���ݸ�AppStartUserIF()�Ĳ���
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
* Description :���������ڼ��Ӱ���״̬��������Ϣ��AppTaskUserIF()
* Arguments   : p_arg��OSTaskCreate()���ݸ�AppStartKbd()�Ĳ���
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
