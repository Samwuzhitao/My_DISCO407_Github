/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "TFT.h"
#include "GUI.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;
static __IO uint32_t TimingDelay;

/* Private function prototypes -----------------------------------------------*/
static void Delay(__IO uint32_t nTime);   
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	SSD1963_Init();
	SSD1963_Clear(Red);
	Delay(100);
	SSD1963_Clear(Blue);
	Delay(100);
	SSD1963_Clear(Red);
	SSD1963_Fill(0, 0, 50, 50, Blue);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
	GUI_Init();
	GUI_SetBkColor(GUI_BLUE);
	GUI_SetColor(GUI_RED);
	GUI_Clear();
	GUI_SetFont(&GUI_Font24_ASCII);
	GUI_DispStringAt("Hello Word!", 0, 0);
	
  while (1)
  {

  }
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0)
  { 
    TimingDelay--;
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
