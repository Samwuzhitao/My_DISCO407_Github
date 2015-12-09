#include "touch.h" 
#include "TFT.h"
#include "delay.h"	 
#include "spi.h"
#include "GUI.h"
#include "GUI_X.h"
#include "bsp.h"
	 	   
u16 ADS_Read(u8 CMD)	  
{ 	 	  
	u16 Num=0,temp;  	 
	TCS_LOW; 
	SPI1_RWByte(CMD);
	delay_us(6);	 
	temp=SPI1_RWByte(0x00); 
	Num=temp<<8; 
	delay_us(1); 
	temp=SPI1_RWByte(0x00); 
	Num|=temp;  	
	Num>>=4;
	TCS_HIGH; 
	return(Num);  
} 

u16 Read_XY(u8 CMD)
{
	u16 i, j;
	u16 buf[10];
	u16 sum=0;
	u16 temp;
	for(i=0;i<10;i++)buf[i]=ADS_Read(CMD);				    
	for(i=0;i<9; i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(buf[i]>buf[j])
			{
				temp=buf[i];
				buf[i]=buf[j];
				buf[j]=temp;
			}
		}
	}	  
	for(i=3;i<7;i++)sum+=buf[i];
	temp=sum/(4);
	return temp;   
} 

void Touch_Init(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;

  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//pen_int:PD6   
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  	GPIO_Init(GPIOD, &GPIO_InitStructure);		   
		SPI1_Init();
		CSPin_init();
	//GUI_TOUCH_Calibrate(0,0,319,1855,90);//X轴校准
	//GUI_TOUCH_Calibrate(1,0,239,80,1895);//Y轴校准
}

void GUI_TOUCH_X_ActivateX(void){}
void GUI_TOUCH_X_ActivateY(void){}

int  GUI_TOUCH_X_MeasureX(void) 
{
	unsigned char t=0,t1,count=0;
	unsigned short int databuffer[10]={5,7,9,3,2,6,4,0,3,1};//数据组
	unsigned short temp=0,X=0;
		 	
	while(count<10)//循环读数10次
	{	   	  
		databuffer[count]=ADS_Read(CMD_RDX);
		count++; 
	}  
	if(count==10)//一定要读到10次数据,否则丢弃
	{  
	    do//将数据X升序排列
		{	
			t1=0;		  
			for(t=0;t<count-1;t++)
			{
				if(databuffer[t]>databuffer[t+1])//升序排列
				{
					temp=databuffer[t+1];
					databuffer[t+1]=databuffer[t];
					databuffer[t]=temp;
					t1=1; 
				}  
			}
		}while(t1); 	    		 	 		  
		X=(databuffer[3]+databuffer[4]+databuffer[5])/3;	  
	}
	return(X);  
}

int  GUI_TOUCH_X_MeasureY(void)
{
  	unsigned char t=0,t1,count=0;
	unsigned short int databuffer[10]={5,7,9,3,2,6,4,0,3,1};//数据组
	unsigned short temp=0,Y=0;	
 
    while(count<10)	//循环读数10次
	{	   	  
		databuffer[count]=ADS_Read(CMD_RDY);
		count++;  
	}  
	if(count==10)//一定要读到10次数据,否则丢弃
	{  
	    do//将数据X升序排列
		{	
			t1=0;		  
			for(t=0;t<count-1;t++)
			{
				if(databuffer[t]>databuffer[t+1])//升序排列
				{
					temp=databuffer[t+1];
					databuffer[t+1]=databuffer[t];
					databuffer[t]=temp;
					t1=1; 
				}  
			}
		}while(t1); 	    		 	 		  
		Y=(databuffer[3]+databuffer[4]+databuffer[5])/3;	  
	}
	return(Y); 
}
