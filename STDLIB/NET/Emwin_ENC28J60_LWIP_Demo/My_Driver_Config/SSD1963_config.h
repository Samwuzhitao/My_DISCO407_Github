#ifndef __SSD1963_CONDIG_H__
#define __SSD1963_CONDIG_H__
/*****************************************************************************
 * 引用头文件
 ****************************************************************************/
#include "stm32f4xx.h"

/*****************************************************************************
 * LCD内部配置参数宏定义
 ****************************************************************************/
#define  HDP  479 //Horizontal Display Period
#define  HT   531 //Horizontal Total
#define  HPS  43  //LLINE Pulse Start Position
#define  LPS  8   //Horizontal Display Period Start Position
#define  HPW  10  //LLINE Pulse Width

#define  VDP  271	//Vertical Display Period
#define  VT   288	//Vertical Total
#define  VPS  12	//LFRAME Pulse Start Position
#define  FPS  4	  //Vertical Display Period Start Positio
#define  VPW  10 	// LFRAME Pulse Width

/*****************************************************************************
 * LCD地址线参数定义
 ****************************************************************************/
#define LCD_RAM              *(vu16*)((u32)0x60020000)   //disp Data ADDR
#define LCD_REG              *(vu16*)((u32)0x60000000)	 //disp Reg  ADDR

/*****************************************************************************
 * LCD像素参数宏定义
 ****************************************************************************/
#define LCD_WIDTH	           480
#define LCD_HEIGHT	         272
 
#endif
