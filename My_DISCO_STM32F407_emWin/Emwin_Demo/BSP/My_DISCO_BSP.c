/* Includes ------------------------------------------------------------------*/
#include "My_DISCO_BSP.h"
#include "My_DISCO_BSP_Debug.h"
#include "string.h"

/***************************************************************************** 
  * @name   
	*       BSP_KeyInit
  * @brief  
	*       Configures the GPIO Peripheral as Key.
  * @param  
	*       ulKeyPin: The keys of the GPIO pin
  *	      ulKeyPort: The keys of the GPIO port
  * @retval 
	*       None
  **************************************************************************/
void BSP_KeyInit( uint32_t ulKeyPin, GPIO_TypeDef *ulKeyPort )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	/* Configure Key1 Pin */
	GPIO_InitStructure.GPIO_Pin = ulKeyPin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;  
	GPIO_Init(ulKeyPort, &GPIO_InitStructure);
}

/***************************************************************************** 
  * @name   
	*       BSP_GetKeyState
  * @brief  
	*       Configures the SPI Peripheral and initialize it.
  * @param  
	*       ulKeyPin: The keys of the GPIO pin
  *	      ulKeyPort: The keys of the GPIO port
  * @retval 
	*       ubKeyState: Current Key State
  **************************************************************************/
uint8_t BSP_GetKeyState( uint32_t ulKeyPin, GPIO_TypeDef *ulKeyPort )
{
	uint8_t ubKeyState;
	
	ubKeyState = GPIO_ReadInputDataBit( ulKeyPort, ulKeyPin );
	
	return ubKeyState;
}


/***************************************************************************** 
  * @name   
	*       BSP_SPI_Init
  * @brief  
	*       Configures the SPI Peripheral and initialize it.
  * @param  
	*       None
  * @retval 
	*       None
  **************************************************************************/
     uint8_t aTxBuffer[BUFFERSIZE] = "SPI Master/Slave : Communication between two SPI using Interrupts";
__IO uint8_t aRxBuffer [BUFFERSIZE];
__IO uint8_t ubRxIndex = 0;
__IO uint8_t ubTxIndex = 0;


void BSP_SPI_Init( void )
{
  GPIO_InitTypeDef GPIO_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	SPI_InitTypeDef  SPI_InitStructure;
	
  /* Peripheral Clock Enable -------------------------------------------------*/
  /* Enable the SPI clock */
  BSP_SPIx_CLK_INIT(BSP_SPIx_CLK, ENABLE);
  
  /* Enable GPIO clocks */
  RCC_AHB1PeriphClockCmd( BSP_SPIx_SCK_GPIO_CLK | BSP_SPIx_MISO_GPIO_CLK | BSP_SPIx_MOSI_GPIO_CLK, ENABLE);

  /* SPI GPIO Configuration --------------------------------------------------*/
  /* GPIO Deinitialisation */
	GPIO_DeInit(BSP_SPIx_NSS_GPIO_PORT);
  GPIO_DeInit(BSP_SPIx_SCK_GPIO_PORT);
  GPIO_DeInit(BSP_SPIx_MISO_GPIO_PORT);
  GPIO_DeInit(BSP_SPIx_MOSI_GPIO_PORT);
	
  /* Connect SPI pins to AF5 */  
	GPIO_PinAFConfig(BSP_SPIx_NSS_GPIO_PORT,  BSP_SPIx_NSS_SOURCE,  BSP_SPIx_NSS_AF);
  GPIO_PinAFConfig(BSP_SPIx_SCK_GPIO_PORT,  BSP_SPIx_SCK_SOURCE,  BSP_SPIx_SCK_AF);
  GPIO_PinAFConfig(BSP_SPIx_MISO_GPIO_PORT, BSP_SPIx_MISO_SOURCE, BSP_SPIx_MISO_AF);    
  GPIO_PinAFConfig(BSP_SPIx_MOSI_GPIO_PORT, BSP_SPIx_MOSI_SOURCE, BSP_SPIx_MOSI_AF);

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;

  /* SPI NSS pin configuration */
  GPIO_InitStructure.GPIO_Pin = BSP_SPIx_NSS_PIN;
  GPIO_Init(BSP_SPIx_NSS_GPIO_PORT, &GPIO_InitStructure);
	
  /* SPI SCK pin configuration */
  GPIO_InitStructure.GPIO_Pin = BSP_SPIx_SCK_PIN;
  GPIO_Init(BSP_SPIx_SCK_GPIO_PORT, &GPIO_InitStructure);
  
  /* SPI  MISO pin configuration */
  GPIO_InitStructure.GPIO_Pin =  BSP_SPIx_MISO_PIN;
  GPIO_Init(BSP_SPIx_MISO_GPIO_PORT, &GPIO_InitStructure);  

  /* SPI  MOSI pin configuration */
  GPIO_InitStructure.GPIO_Pin =  BSP_SPIx_MOSI_PIN;
  GPIO_Init(BSP_SPIx_MOSI_GPIO_PORT, &GPIO_InitStructure);
 
  /* SPI configuration -------------------------------------------------------*/
  SPI_I2S_DeInit(BSP_SPIx);
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  
  /* Configure the Priority Group to 1 bit */                
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* Configure the SPI interrupt priority */
  NVIC_InitStructure.NVIC_IRQChannel = BSP_SPIx_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
  /* Master board configuration */    
  /* Initializes the SPI communication */
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_Init(BSP_SPIx, &SPI_InitStructure);
  
	//Debug_ShowRegister( SPI2_BASE, (DebugPeripheralTypedef *)&DeBugSPI );
	
  /* Enable the SPI peripheral */
  SPI_Cmd(BSP_SPIx, ENABLE);
	
  /* The Data transfer is performed in the SPI interrupt routine */
  /* Initialize Buffer counters */
  ubTxIndex = 0;
  ubRxIndex = 0;
	
	//Debug_ShowRegister( SPI2_BASE, (DebugPeripheralTypedef *)&DeBugSPI );
	
  /* Enable the Rx buffer not empty interrupt */
  SPI_I2S_ITConfig(BSP_SPIx, SPI_I2S_IT_RXNE, ENABLE);
	
  //Debug_ShowRegister( SPI2_BASE, (DebugPeripheralTypedef *)&DeBugSPI );
	
  /* Enable the Tx buffer empty interrupt */
  SPI_I2S_ITConfig(BSP_SPIx, SPI_I2S_IT_TXE, ENABLE);
	
	//Debug_ShowRegister( SPI2_BASE, (DebugPeripheralTypedef *)&DeBugSPI );
}

/**
  * @brief  This function handles SPI interrupt request.
  * @param  None
  * @retval None
  */
void BSP_SPIx_IRQHANDLER(void)
{
	//Debug_ShowRegister( SPI2_BASE, (DebugPeripheralTypedef *)&DeBugSPI );
  /* SPI in Receiver mode */
  if (SPI_I2S_GetITStatus(BSP_SPIx, SPI_I2S_IT_RXNE) == SET)
  {
    if (ubRxIndex < BUFFERSIZE)
    {
      /* Receive Transaction data */
      aRxBuffer[ubRxIndex++] = SPI_I2S_ReceiveData(BSP_SPIx);
    }
    else
    {
      /* Disable the Rx buffer not empty interrupt */
      SPI_I2S_ITConfig(BSP_SPIx, SPI_I2S_IT_RXNE, DISABLE);
    }
  }
  /* SPI in Transmitter mode */
  if (SPI_I2S_GetITStatus(BSP_SPIx, SPI_I2S_IT_TXE) == SET)
  {
    if (ubTxIndex < BUFFERSIZE)
    {
      /* Send Transaction data */
      SPI_I2S_SendData(BSP_SPIx, aTxBuffer[ubTxIndex++]);
    }
    else
    {
      /* Disable the Tx buffer empty interrupt */
      SPI_I2S_ITConfig(BSP_SPIx, SPI_I2S_IT_TXE, DISABLE);
    }
  }
}


void BSP_USART_Init( void )
{
    GPIO_InitTypeDef GPIO_InitStructure;
	  USART_InitTypeDef USART_InitStructure;
	
		/* Enable GPIO clock */
		RCC_AHB1PeriphClockCmd(BSP_USARTx_TX_GPIO_CLK | BSP_USARTx_RX_GPIO_CLK, ENABLE);
		
		/* Enable USART clock */
		RCC_APB2PeriphClockCmd(BSP_USARTx_CLK, ENABLE);
		
		/* Connect USART pins to AF7 */
		GPIO_PinAFConfig(BSP_USARTx_TX_GPIO_PORT, BSP_USARTx_TX_SOURCE, BSP_USARTx_TX_AF);
		GPIO_PinAFConfig(BSP_USARTx_RX_GPIO_PORT, BSP_USARTx_RX_SOURCE, BSP_USARTx_RX_AF);
		
		/* Configure USART Tx and Rx as alternate function push-pull */
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
		GPIO_InitStructure.GPIO_Pin = BSP_USARTx_TX_PIN;
		GPIO_Init(BSP_USARTx_TX_GPIO_PORT, &GPIO_InitStructure);
		Debug_ShowRegister( GPIOA_BASE, (DebugPeripheralTypedef *)&DeBugGPIO );
		//while(1);
		
		GPIO_InitStructure.GPIO_Pin = BSP_USARTx_RX_PIN;
		GPIO_Init(BSP_USARTx_RX_GPIO_PORT, &GPIO_InitStructure);
		Debug_ShowRegister( GPIOA_BASE, (DebugPeripheralTypedef *)&DeBugGPIO );
		//while(1);
		
	  /* USARTx configuration ----------------------------------------------------*/
    USART_InitStructure.USART_BaudRate = BSP_UARTx_BAUNDRATE;
	
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		
    //Debug_ShowRegister( USART1_BASE, (DebugPeripheralTypedef *)&DeBugUART );
		/* Configure and enable the USART */
    USART_Init(USART1, &USART_InitStructure);
		Debug_ShowRegister( USART1_BASE, (DebugPeripheralTypedef *)&DeBugUART );
		
//  /* NVIC configuration */
//  /* Configure the Priority Group to 2 bits */
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//  /* Enable the USARTx Interrupt */
//  NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
	
	  USART_Cmd(USART1, ENABLE);
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
int fputc( int ch ) 
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART1, (uint8_t) ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
  {}

  return ch;
}
