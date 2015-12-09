#include "tft.h"
#include "delay.h"

static u32 lcdid=0;

void LCD_LineConf(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;

	/* 使能FSMC时钟 */
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);

	/* 使能 GPIO时钟 */
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
		


}

void LCD_Rest(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	/* 使能 GPIO时钟 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOE, GPIO_Pin_1);
	delay_ms(50);
	GPIO_SetBits(GPIOE, GPIO_Pin_1);

}

void LCD_FSMCConf(void)
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

void LCD_WriteReg(u8 Reg, u16 Value)
{
  	LCD_REG=Reg;
  	LCD_RAM=Value;
}

u16 LCD_ReadReg(u8 Reg)
{
  	LCD_REG = Reg;
  	return (LCD_RAM);
}

void LCD_WriteRAM(u16 RGB_Code)
{
  	LCD_RAM=RGB_Code;
}


u16 LCD_ReadRAM(void)
{
  	u16 dummy;
  	LCD_REG=0x2c; 
		dummy=LCD_RAM;
  	return LCD_RAM;
}


void MyLCD_Init(void)
{ 
	LCD_LineConf();
	LCD_FSMCConf();
	LCD_Rest();
	lcdid=LCD_ReadReg(0x00);
	if(lcdid == 0x9325)
  	{
		LCD_WriteReg(0x00,0x0001);
		LCD_WriteReg(0x01,0x0100);
		LCD_WriteReg(0x02,0x0700);
		LCD_WriteReg(0x03,0x1018);
		LCD_WriteReg(0x04,0x0000);
		LCD_WriteReg(0x08,0x0202);
		LCD_WriteReg(0x09,0x0000);
		LCD_WriteReg(0x0A,0x0000);
		LCD_WriteReg(0x0C,0x0000);
		LCD_WriteReg(0x0D,0x0000);
		LCD_WriteReg(0x0F,0x0000);
		LCD_WriteReg(0x10,0x0000);
		LCD_WriteReg(0x11,0x0000);
		LCD_WriteReg(0x12,0x0000);
		LCD_WriteReg(0x13,0x0000);
		delay_ms(20);
		LCD_WriteReg(0x10,0x17B0);
		LCD_WriteReg(0x11,0x0137);
		delay_ms(5);
		LCD_WriteReg(0x12,0x0139);
		delay_ms(5);
		LCD_WriteReg(0x13,0x1d00);
		LCD_WriteReg(0x29,0x0013);
		delay_ms(5);
		LCD_WriteReg(0x20,0x0000);
		LCD_WriteReg(0x21,0x0000);
		LCD_WriteReg(0x30,0x0007);
		LCD_WriteReg(0x31,0x0302);
		LCD_WriteReg(0x32,0x0105);
		LCD_WriteReg(0x35,0x0206);
		LCD_WriteReg(0x36,0x0808);
		LCD_WriteReg(0x37,0x0206);
		LCD_WriteReg(0x38,0x0504);
		LCD_WriteReg(0x39,0x0007);
		LCD_WriteReg(0x3C,0x0105);
		LCD_WriteReg(0x3D,0x0808);
		LCD_WriteReg(0x50,0x0000);
		LCD_WriteReg(0x51,0x00EF);
		LCD_WriteReg(0x52,0x0000);
		LCD_WriteReg(0x53,0x013F);
		LCD_WriteReg(0x60,0xA700);
		LCD_WriteReg(0x61,0x0001);
		LCD_WriteReg(0x6A,0x0000);
		LCD_WriteReg(0x80,0x0000);
		LCD_WriteReg(0x81,0x0000);
		LCD_WriteReg(0x82,0x0000);
		LCD_WriteReg(0x83,0x0000);
		LCD_WriteReg(0x84,0x0000);
		LCD_WriteReg(0x85,0x0000);
		LCD_WriteReg(0x90,0x0010);
		LCD_WriteReg(0x92,0x0000);
		LCD_WriteReg(0x93,0x0003);
		LCD_WriteReg(0x95,0x0110);
		LCD_WriteReg(0x97,0x0000);
		LCD_WriteReg(0x98,0x0000);
		LCD_WriteReg(0x03,0x1018);
		LCD_WriteReg(0x07,0x0133);
  	}
	else
	{
		/****************************************************************
		LCD_REG=(0x00E2);					//PLL multiplier, set PLL clock to 120M
		LCD_RAM=(0x0023);					//N=0x36 for 6.5M, 0x23 for 10M crystal
		LCD_RAM=(0x0002);
		LCD_RAM=(0x0004);
		
		LCD_REG=(0x00E0);					//PLL enable
		LCD_RAM=(0x0001);
		delay_ms(10);
		
		LCD_REG=(0x00E2);					//PLL multiplier, set PLL clock to 120M
		LCD_RAM=(0x0023);					//N=0x36 for 6.5M, 0x23 for 10M crystal
		LCD_RAM=(0x0002);
		LCD_RAM=(0x0004);
		
		LCD_REG=(0x00E0);					//PLL enable
		LCD_RAM=(0x0001);
		delay_ms(10);
		LCD_REG=(0x00E0);
		LCD_RAM=(0x0003);
		delay_ms(10);
		
		LCD_REG=(0x0001);  				//software reset
		delay_ms(10);
		
		LCD_REG=(0x00E6);					//PLL setting for PCLK, depends on resolution
		LCD_RAM=(0x0000);
		LCD_RAM=(0x0047);
		LCD_RAM=(0x00BE);

		LCD_REG=(0x00B0);					//LCD SPECIFICATION
		LCD_RAM=(0x0024);
		LCD_RAM=(0x0000);
		LCD_RAM=((HDP>>8)&0X00FF);//Set HDP
		LCD_RAM=(HDP&0X00FF);
		LCD_RAM=((VDP>>8)&0X00FF);//Set VDP
		LCD_RAM=(VDP&0X00FF);
		LCD_RAM=(0x0000);
		//delay_ms(5);
		
		LCD_REG=(0x00B4);					//HSYNC
		LCD_RAM=((HT>>8)&0X00FF); //Set HT
		LCD_RAM=(HT&0X00FF);
		LCD_RAM=((HPS>>8)&0X00FF);//Set HPS
		LCD_RAM=(HPS&0X00FF);
		LCD_RAM=(HPW);						//Set HPW
		LCD_RAM=((LPS>>8)&0X00FF);//Set HPS
		LCD_RAM=(LPS&0X00FF);
		LCD_RAM=(0x0000);
		
		LCD_REG=(0x00B6);					//VSYNC
		LCD_RAM=((VT>>8)&0X00FF); //Set VT
		LCD_RAM=(VT&0X00FF);
		LCD_RAM=((VPS>>8)&0X00FF);//Set VPS
		LCD_RAM=(VPS&0X00FF);
		LCD_RAM=(VPW);						//Set VPW
		LCD_RAM=((FPS>>8)&0X00FF);//Set FPS
		LCD_RAM=(FPS&0X00FF);


		LCD_REG=(0x0036); //rotation
		LCD_RAM=(0x0008);
		LCD_RAM=(0x0000);
		LCD_REG=(0x00F0); //pixel data interface	
		LCD_RAM=(0x0003); //03:16位   02:24位
		delay_ms(50);
		
		LCD_REG=(0x0029); //display on
		**********************************************************/
		
		LCD_REG=(0x00E2);	//PLL multiplier, set PLL clock to 120M
		LCD_RAM=(0x002d);	    //N=0x36 for 6.5M, 0x23 for 10M crystal
		LCD_RAM=(0x0002);
		LCD_RAM=(0x0004);
		LCD_REG=(0x00E0);  // PLL enable
		LCD_RAM=(0x0001);
		delay_ms(1);
		LCD_REG=(0x00E0);
		LCD_RAM=(0x0003);
		delay_ms(5);
		LCD_REG=(0x0001);  // software reset
		delay_ms(5);
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
		delay_ms(5);
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
		delay_ms(5);

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
	//delay_ms(50); 
	LCD_Font(&Font16x24);	
}

void LCD_Font(sFONT *font)
{
  	Efont=font;
}

void LCD_Cursor(u16 Xpos, u16 Ypos)
{
		if(lcdid == 0x9325)
  	{
			LCD_WriteReg(0x20, Xpos);
			LCD_WriteReg(0x21, Ypos);
		}
		else
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
}

void LCD_Clear(u16 Color)
{
	if(lcdid == 0x9325)
	{
  	u32 index=0;
 
  	LCD_Cursor(0x00, 319); 
  	LCD_REG=0x22;//WriteRAM_Prepare 
  	for(index=0;index<76800;index++)LCD_RAM=Color;
		
	}
	else
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
}

void LCD_Point(u16 xpos, u16 ypos,u16 color)
{
	LCD_Cursor(xpos,ypos);
	LCD_REG=0x2c;//WriteRAM_Prepare 
	LCD_RAM=color;
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
			LCD_Point(Xpos+CurX,Ypos+CurY,color);
			LCD_Point(Xpos+CurX,Ypos-CurY,color);
			LCD_Point(Xpos-CurX,Ypos+CurY,color);
			LCD_Point(Xpos-CurX,Ypos-CurY,color);
			LCD_Point(Xpos+CurY,Ypos+CurX,color);
			LCD_Point(Xpos+CurY,Ypos-CurX,color);
			LCD_Point(Xpos-CurY,Ypos+CurX,color);
			LCD_Point(Xpos-CurY,Ypos-CurX,color);
			if(Dec<0)Dec+=(CurX<<2)+6;
	    else
	    {
	      	Dec+=((CurX-CurY)<<2)+10;
	      	CurY--;
	    }
	    CurX++;
  	}
}


void LCD_Fill(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{          
	u16 i,j;
	u16 xlen=0;

	xlen=y2-y1+1;	   
	for(i=x1;i<=x2;i++)
	{
	 	LCD_Cursor(i,y2);
		LCD_REG=0x2c;      	  
		for(j=0;j<xlen;j++)LCD_WriteRAM(color); 	  
	}						  	    
}  

void LCD_Char(u16 Xpos, u16 Ypos, u8 Ascii, u16 color)
{
	const u16 *c;
	u16 Xaddr=0; 
	u32 index=0,i=0;
				 
	Xaddr=Xpos;
	c=&Efont->table[(Ascii-32)*Efont->Height]; 
	LCD_Cursor(Xaddr, Ypos);  
	for(index=0;index<Efont->Height;index++)
	{
		LCD_REG=0x2c;//WriteRAM_Prepare
		for(i=0;i<Efont->Width;i++)
		{  
		if((((c[index]&((0x80<<((Efont->Width/12)*8))>>i))==0x00)&&(Efont->Width<=12))
		||(((c[index]&(0x1<<i))==0x00)&&(Efont->Width>12)))LCD_RAM=Blue;
				else LCD_RAM=color; 
		}
		Xaddr++;
		LCD_Cursor(Xaddr, Ypos);
	}
}

void LCD_String(u16 xpos, u16 ypos, u8 *ptr, u16 color)
{
  	u16 refypos=LCD_WIDTH-xpos;

  	while((*ptr!=0)&(((refypos+1)&0xFFFF)>=Efont->Width))
  	{
    	LCD_Char(ypos,refypos,*ptr,color);
    	refypos-=Efont->Width;
    	ptr++;
  	}
}

//m^n函数
u32 mypow(u8 m,u8 n)
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}			 
	 
void LCD_Num(u16 x, u16 y, s32 num, u8 len, u16 color)
{         	
	u8 t,temp;
	u8 enshow=0;
	t=0;
	if(num<0)
	{
		LCD_Char(y,LCD_WIDTH-x-(Efont->Width)*t,'-',color);
		num=-num;
		t++;
	}						   
	for(;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_Char(y,LCD_WIDTH-x-(Efont->Width)*t,' ',color);
				continue;
			}else enshow=1; 		 	 
		}
	 	LCD_Char(y,LCD_WIDTH-x-(Efont->Width)*t,temp+'0',color); 
	}
} 

