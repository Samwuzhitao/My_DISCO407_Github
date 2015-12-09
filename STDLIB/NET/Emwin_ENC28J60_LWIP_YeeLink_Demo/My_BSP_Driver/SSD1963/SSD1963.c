#include "SSD1963.h"

/******************************************************************************
  Function: SSD1963_Delayms
  Description:Complete the millisecond delay in the drive
  Input : ms : Need to delay the number of milliseconds
  Output: None
  Others: None
******************************************************************************/
void SSD1963_Delayms( uint32_t ms )
{	
		uint16_t i;
	  for( i = 0; i < 10000; i++);
}

/******************************************************************************
  Function: SSD1963_GPIOInit
  Description:Used to complete the initialization of GPIO
  Input : None
  Output: None
  Others: None
******************************************************************************/
void SSD1963_GPIOInit( void )
{
  GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable FSMC and GPIO peripheral's clock */
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);

	/* 设置 PD.00(D2), PD.01(D3), PD.04(NOE), PD.05(NWE), PD.08(D13), PD.09(D14),
	 PD.10(D15), PD.14(D0), PD.15(D1) 为复用推挽输出 */

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource4, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FSMC);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 |
	                            GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 |
	                            GPIO_Pin_15;
															
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* 设置 PE.07(D4), PE.08(D5), PE.09(D6), PE.10(D7), PE.11(D8), PE.12(D9), PE.13(D10),
	 PE.14(D11), PE.15(D12) 为复用推挽输出 */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource7 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource8 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource10 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource15 , GPIO_AF_FSMC);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 |
	                            GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 |
	                            GPIO_Pin_15;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/* 设置 PD.11(A16 (RS))  为复用推挽输出 */
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource11, GPIO_AF_FSMC);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* 设置 PD.7(NE1 (LCD/CS)) 为复用推挽输出 */
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource7, GPIO_AF_FSMC);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	/* Configure LCD REST Pin */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/******************************************************************************
  Function: SSD1963_Rest
  Description: Reset LCD SSD1963 
  Input : None
  Output: None
  Others: None
******************************************************************************/
void SSD1963_Rest( void )
{
	GPIO_ResetBits(GPIOE, GPIO_Pin_1);
	SSD1963_Delayms(50);
	GPIO_SetBits(GPIOE, GPIO_Pin_1);
}

/******************************************************************************
  Function: SSD1963_FSMCInit
  Description: complete the FSMC configure 
  Input : None
  Output: None
  Others: None
******************************************************************************/
void SSD1963_FSMCInit( void )
{
  	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
  	FSMC_NORSRAMTimingInitTypeDef  p;

	
  	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);
  	p.FSMC_AddressSetupTime = 5;
  	p.FSMC_AddressHoldTime = 0;
  	p.FSMC_DataSetupTime = 9;
  	p.FSMC_BusTurnAroundDuration = 0;
  	p.FSMC_CLKDivision = 0;
  	p.FSMC_DataLatency = 0;
  	p.FSMC_AccessMode = FSMC_AccessMode_B;
  	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
  	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
  	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
  	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
  	FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
  	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
  	FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
  	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;
  	FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);   
  	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);
}

/******************************************************************************
  Function: SSD1963_Init
  Description: complete the LCD init
  Input : None
  Output: None
  Others: None
******************************************************************************/
void SSD1963_Init(void)
{ 
	/* Initialize FSMC interface */
	SSD1963_GPIOInit();
	SSD1963_FSMCInit();
	SSD1963_Rest();
  
	/* Initialize SSD1963 LCD */
	LCD_REG=(0x00E2);	//PLL multiplier, set PLL clock to 120M
	LCD_RAM=(0x002d);	    //N=0x36 for 6.5M, 0x23 for 10M crystal
	LCD_RAM=(0x0002);
	LCD_RAM=(0x0004);
	LCD_REG=(0x00E0);  // PLL enable
	LCD_RAM=(0x0001);
	SSD1963_Delayms(1);
	LCD_REG=(0x00E0);
	LCD_RAM=(0x0003);
	SSD1963_Delayms(5);
	LCD_REG=(0x0001);  // software reset
	SSD1963_Delayms(5);
	LCD_REG=(0x00E6);	//PLL setting for PCLK, depends on resolution
	LCD_RAM=(0x0000);
	LCD_RAM=(0x00ff);
	LCD_RAM=(0x00be);

	LCD_REG=(0x00B0);	//LCD SPECIFICATION
	LCD_RAM=(0x0020);
	LCD_RAM=(0x0000);
	LCD_RAM=((HDP>>8)&0X00FF);  //Set HDP
	LCD_RAM=(HDP&0X00FF);
	LCD_RAM=((VDP>>8)&0X00FF);  //Set VDP
	LCD_RAM=(VDP&0X00FF);
	LCD_RAM=(0x0000);
	SSD1963_Delayms(5);
	LCD_REG=(0x00B4);	//HSYNC
	LCD_RAM=((HT>>8)&0X00FF);  //Set HT
	LCD_RAM=(HT&0X00FF);
	LCD_RAM=((HPS>>8)&0X00FF);  //Set HPS
	LCD_RAM=(HPS&0X00FF);
	LCD_RAM=(HPW);			   //Set HPW
	LCD_RAM=((LPS>>8)&0X00FF);  //SetLPS
	LCD_RAM=(LPS&0X00FF);
	LCD_RAM=(0x0000);

	LCD_REG=(0x00B6);	//VSYNC
	LCD_RAM=((VT>>8)&0X00FF);   //Set VT
	LCD_RAM=(VT&0X00FF);
	LCD_RAM=((VPS>>8)&0X00FF);  //Set VPS
	LCD_RAM=(VPS&0X00FF);
	LCD_RAM=(VPW);			   //Set VPW
	LCD_RAM=((FPS>>8)&0X00FF);  //Set FPS
	LCD_RAM=(FPS&0X00FF);


	LCD_REG=(0x0036); //rotation
	LCD_RAM=(0x0000);

	LCD_REG=(0x00F0); //pixel data interface
	LCD_RAM=(0x0003);
	SSD1963_Delayms(5);

	LCD_REG=(0x0029); //display on

	LCD_REG=(0x00BE); //set PWM for B/L
	LCD_RAM=(0x0006);
	LCD_RAM=(0x00f0);
	LCD_RAM=(0x0001);
	LCD_RAM=(0x00f0);
	LCD_RAM=(0x0000);
	LCD_RAM=(0x0000);

	LCD_REG=(0x00d0); 
	LCD_RAM=(0x000d);

	//----------LCD RESET---GPIO0-------------------//
	LCD_REG=(0x00B8);
	LCD_RAM=(0x0000);    //GPIO3=input, GPIO[2:0]=output
	LCD_RAM=(0x0001);    //GPIO0 normal

	LCD_REG=(0x00BA);
	LCD_RAM=(0x0000);  	
}

/******************************************************************************
  Function: SSD1963_Clear
  Description: Complete LCD CLS operations
  Input : Color: The color of the CLS 
  Output: None
  Others: None
******************************************************************************/
void SSD1963_Clear(u16 Color)
{
	u32 count=0;
	LCD_REG=(0x002a);	
	LCD_RAM=(0);	    
	LCD_RAM=(0);
	LCD_RAM=(HDP>>8);	    
	LCD_RAM=(HDP&0x00ff);
	LCD_REG=(0x002b);	
	LCD_RAM=(0);	    
	LCD_RAM=(0);
	LCD_RAM=(VDP>>8);	    
	LCD_RAM=(VDP&0x00ff);
	LCD_REG=0x2C;
	for(count=0;count<(HDP+1)*(VDP+1);count++)
	{
		LCD_RAM=Color;
	}
}

/******************************************************************************
  Function: SSD1963_Cursor
  Description: Sets the position of pixels
  Input : None
  Output: None
  Others: None
******************************************************************************/
void SSD1963_Cursor(u16 Xpos, u16 Ypos)
{
	LCD_REG=(0x002a);	
	LCD_RAM=(Xpos>>8);	    
	LCD_RAM=(Xpos&0x00ff);
	LCD_RAM=(HDP>>8);	    
	LCD_RAM=(HDP&0x00ff);
	LCD_REG=(0x002b);	
	LCD_RAM=(Ypos>>8);	    
	LCD_RAM=(Ypos&0x00ff);
	LCD_RAM=(VDP>>8);	    
	LCD_RAM=(VDP&0x00ff);
	LCD_REG=(0x002C);
}

/******************************************************************************
  Function: SSD1963_Init
  Description: Set a screen pixels
  Input : xpos: The x coordinate
          ypos: The y coordinate
         color: The color of pixel
  Output: None
  Others: None
******************************************************************************/
void SSD1963_Point(u16 xpos, u16 ypos,u16 color)
{
	SSD1963_Cursor(xpos,ypos);
	LCD_RAM = color;
}

/******************************************************************************
  Function: SSD1963_Fill
  Description: Fill a rectangular block
  Input : x1: The x Start coordinate
          y1: The y Start coordinate
					x2: The x end coordinate
          y2: The y end coordinate
         color: The color of pixel
  Output: None
  Others: None
******************************************************************************/
void SSD1963_Fill(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{          
	u32 count = 0;
	LCD_REG = ( 0x002a );	
	LCD_RAM = ( x1 );	    
	LCD_RAM = ( x1 );
	LCD_RAM = ( x2 >> 8 );	    
	LCD_RAM = ( x2 & 0x00ff );
	LCD_REG = ( 0x002b );	
	LCD_RAM = ( y1 );	    
	LCD_RAM = ( y1 );
	LCD_RAM = ( y2 >> 8 );	    
	LCD_RAM = ( y2 & 0x00ff );
	LCD_REG = 0x2C;
	for( count = 0; count < (y2-y1+1)*(x2-x1+1); count++ )
	{
		LCD_RAM = color;
	}				  	    
}  



u16 LCD_BGR2RGB(u16 c)
{
	u16 r,g,b,rgb;
	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;
	rgb=(b<<11)+(g<<5)+(r<<0);
  	return( rgb );
}


void LCD_Circle(u16 Xpos, u16 Ypos, u16 Radius, u16 color)
{
  	s32  Dec;
  	u32  CurX;
  	u32  CurY;
	 
  	CurX=0;
  	CurY=Radius;   
  	Dec=3-(Radius<<1);
  	while(CurX<=CurY)
  	{
			SSD1963_Point(Xpos+CurX,Ypos+CurY,color);
			SSD1963_Point(Xpos+CurX,Ypos-CurY,color);
			SSD1963_Point(Xpos-CurX,Ypos+CurY,color);
			SSD1963_Point(Xpos-CurX,Ypos-CurY,color);
			SSD1963_Point(Xpos+CurY,Ypos+CurX,color);
			SSD1963_Point(Xpos+CurY,Ypos-CurX,color);
			SSD1963_Point(Xpos-CurY,Ypos+CurX,color);
			SSD1963_Point(Xpos-CurY,Ypos-CurX,color);
			if(Dec<0)Dec+=(CurX<<2)+6;
	    else
	    {
	      	Dec+=((CurX-CurY)<<2)+10;
	      	CurY--;
	    }
	    CurX++;
  	}
}


