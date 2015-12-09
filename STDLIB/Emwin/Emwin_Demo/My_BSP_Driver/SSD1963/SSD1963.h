#ifndef __TFT_H
#define __TFT_H
/*****************************************************************************
 * ����ͷ�ļ�
 ****************************************************************************/
#include "SSD1963_config.h"

/*****************************************************************************
 * ������ɫ�궨��
 ****************************************************************************/
#define   Black        0x0000                    // ��ɫ�� 0, 0, 0              
#define   Navy         0x000F                    // ����ɫ�� 0, 0, 128          
#define   Dgreen       0x03E0                    // ����ɫ�� 0, 128, 0          
#define   Dcyan        0x03EF                    // ����ɫ�� 0, 128, 128        
#define   Marooon      0x7800                    // ���ɫ��128, 0, 0           
#define   Purple       0x780F                    // ��ɫ�� 128, 0, 128          
#define   Olive        0x7BE0                    // ����̣�128, 128, 0         
#define   Lgray        0xC618                    // �Ұ�ɫ��192, 192, 192        
#define   Dgray        0x7BEF                    // ���ɫ��128, 128, 128        
#define   Blue         0x001F                    // ��ɫ�� 0, 0, 255            
#define   Green        0x07E0                 	 // ��ɫ�� 0, 255, 0             
#define   Cyan         0x07FF                    // ��ɫ�� 0, 255, 255           
#define   Red          0xF800                    // ��ɫ�� 255, 0, 0             
#define   Magenta      0xF81F                    // Ʒ�죺 255, 0, 255          
#define   Yellow       0xFFE0                    // ��ɫ�� 255, 255, 0           
#define   White        0xFFFF                    // ��ɫ�� 255, 255, 255   

/*****************************************************************************
 * ��������
 ****************************************************************************/
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
