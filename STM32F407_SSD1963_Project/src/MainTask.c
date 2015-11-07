#include "GUI.h"
#include "PROGBAR.h"
#include "LISTBOX.h"
#include "FRAMEWIN.h"
#include "BUTTON.h"
//#include "APP.h"
#include "Mylogos.h"

static BUTTON_Handle   _ahButton[4];//���尴ť
static int  _ButtonSizeX,_ButtonSizeY;//��ť�ߴ�

int CheckKEY(void)//��ⰴ��
{
	int c=GUI_GetKey();
	WM_ExecIdle();
//	switch(c)
//	{
//		case 'A':Main_Botton1();break;
//		case 'B':Main_Botton2();break; 
//		case 'C':Main_Botton3();break;
//		case 'D':Main_Botton4();break;
//	}	
	return c;
}


void APP_main(void)//�û�������
{
    GUI_CURSOR_Show();//��ʾ���ָ��
  	GUI_Clear(); 								 
    WM_SetCreateFlags(WM_CF_MEMDEV); //�Զ������д�����ʹ�ô洢�豸
	_ButtonSizeX=50;//�����ߴ�
	_ButtonSizeY=50;
	_ahButton[0]=BUTTON_Create(0,0,_ButtonSizeX,_ButtonSizeY,'A',WM_CF_SHOW|WM_CF_STAYONTOP|WM_CF_MEMDEV);
	BUTTON_SetBkColor(_ahButton[0],0,GUI_GRAY);
	BUTTON_SetBkColor(_ahButton[0],1,GUI_DARKGRAY);
	BUTTON_SetBitmapEx(_ahButton[0],0,&bm111,2,2);
	
	_ahButton[1]=BUTTON_Create(0,50,_ButtonSizeX,_ButtonSizeY,'B',WM_CF_SHOW|WM_CF_STAYONTOP|WM_CF_MEMDEV);
	BUTTON_SetBkColor(_ahButton[1],0,GUI_GRAY);
	BUTTON_SetBkColor(_ahButton[1],1,GUI_DARKGRAY);
	BUTTON_SetBitmapEx(_ahButton[1],0,&bm222,2,2);
	
	_ahButton[2]=BUTTON_Create(0,100,_ButtonSizeX,_ButtonSizeY,'C',WM_CF_SHOW|WM_CF_STAYONTOP|WM_CF_MEMDEV);
	BUTTON_SetBkColor(_ahButton[2],0,GUI_GRAY);
	BUTTON_SetBkColor(_ahButton[2],1,GUI_DARKGRAY);
	BUTTON_SetBitmapEx(_ahButton[2],0,&bm333,2,2);
	
	_ahButton[3]=BUTTON_Create(0,150,_ButtonSizeX,_ButtonSizeY,'D',WM_CF_SHOW|WM_CF_STAYONTOP|WM_CF_MEMDEV);
	BUTTON_SetBkColor(_ahButton[3],0,GUI_GRAY);
	BUTTON_SetBkColor(_ahButton[3],1,GUI_DARKGRAY);
	BUTTON_SetBitmapEx(_ahButton[3],0,&bm444,2,2);

	GUI_SetBkColor(GUI_BLUE);//���ñ�����ɫ
  	GUI_Clear();
    WM_ExecIdle();
//	GUI_DrawBitmapEx(&bmDGUT,160,100,bmDGUT.XSize/2,bmDGUT.YSize/2,2000,2000);//��DGUTλͼ
	while(1){CheckKEY();}
}
//////////////////////////////////////////////////////////////////////////////////////////////

void MainTask(void)
{
  	GUI_Init();
  	while(1)
	{
		APP_main();
  	}
}

