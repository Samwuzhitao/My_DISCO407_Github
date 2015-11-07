#ifndef __TFT_H
#define __TFT_H

#include "stm32f4xx_conf.h"

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

/***********************************************************************************
设置颜色宏定义
***********************************************************************************/
#define   Black        0x0000                    // 黑色： 0, 0, 0              
#define   Navy         0x000F                    // 深蓝色： 0, 0, 128          
#define   Dgreen       0x03E0                    // 深绿色： 0, 128, 0          
#define   Dcyan        0x03EF                    // 深青色： 0, 128, 128        
#define   Marooon      0x7800                    // 深红色：128, 0, 0           
#define   Purple       0x780F                    // 紫色： 128, 0, 128          
#define   Olive        0x7BE0                    // 橄榄绿：128, 128, 0         
#define   Lgray        0xC618                    // 灰白色：192, 192, 192        
#define   Dgray        0x7BEF                    // 深灰色：128, 128, 128        
#define   Blue         0x001F                    // 蓝色： 0, 0, 255            
#define   Green        0x07E0                 	 // 绿色： 0, 255, 0             
#define   Cyan         0x07FF                    // 青色： 0, 255, 255           
#define   Red          0xF800                    // 红色： 255, 0, 0             
#define   Magenta      0xF81F                    // 品红： 255, 0, 255          
#define   Yellow       0xFFE0                    // 黄色： 255, 255, 0           
#define   White        0xFFFF                    // 白色： 255, 255, 255   


#define LCD_RAM   *(vu16*)((u32)0x60020000)  //disp Data ADDR
#define LCD_REG   *(vu16*)((u32)0x60000000)	 //disp Reg  ADDR

#define LCD_WIDTH	     480
#define LCD_HEIGHT	   272
 
void SSD1963_Init(void);
void SSD1963_FSMCInit( void );
void SSD1963_Rest( void );
void SSD1963_GPIOInit( void );
void SSD1963_Delayms( uint32_t ms );
void SSD1963_Clear(u16 Color);
void SSD1963_Point(u16 xpos, u16 ypos,u16 color);
void SSD1963_Fill(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);

void LCD_Circle(u16 Xpos, u16 Ypos, u16 Radius, u16 color);


#endif
