#ifndef _SSD1963_CONFIG_H
#define _SSD1963_CONFIG_H

//*****************************************************************************
//
//! \addtogroup ILI9325_LCD_SIZE LCD Size
//! @{
//
//*****************************************************************************
#define LCD_WIDTH	                                    480 ///< LCD_WIDTH
#define LCD_HEIGHT	                                  272 ///< LCD_HEIGHT

//*****************************************************************************
//
//! @}
//
//*****************************************************************************


#define HDP                                          479 ///< Horizontal Display Period
#define HT                                           531 ///< Horizontal Total
#define HPS                                           43 ///< LLINE Pulse Start Position
#define LPS                                            8 ///< Horizontal Display Period Start Position
#define HPW                                           10 ///< LLINE Pulse Width
#define VDP                                          271 ///< Vertical Display Period
#define VT                                           288 ///< Vertical Total
#define VPS                                           12 ///< LFRAME Pulse Start Position
#define FPS                                            4 ///< Vertical Display Period Start Positio
#define VPW                                           10 ///< LFRAME Pulse Width

#define LCD_RAM                 *(vu16*)((u32)0x60020000) ///< disp Data ADDR
#define LCD_REG                 *(vu16*)((u32)0x60000000)	///< disp Reg  ADDR

#endif