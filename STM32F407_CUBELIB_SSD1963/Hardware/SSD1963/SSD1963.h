//*****************************************************************************
//
//! \file    SSD1963.h
//! \brief   Driver for Character LCD SSD1963.
//! \version 2.1.1.0
//! \date    12/11/2014
//! \author  Sam.Wu
//! \Note    
//!
//!       1.Display feature 
//!-    Built-in 1215K bytes frame buffer.  Support up to 864 x 480 at 24bpp display 
//!-    Support TFT 18/24-bit generic RGB interface panel 
//!-    Support 8-bit serial RGB interface 
//!-    Hardware rotation of 0, 90, 180, 270 degree 
//!-    Hardware display mirroring 
//!-    Hardware windowing 
//!-    Programmable brightness, contrast and saturation control 
//!-    Dynamic Backlight Control (DBC) via PWM signal 
//!
//!       2.MCU connectivity 
//!-    8/9/16/18/24-bit MCU interface 
//!-    Tearing effect signal 
//!
//!       3.I/O Connectivity 
//!-    4 GPIO pins 
//!
//!       4.Built-in clock generator
//!
//!       5.Deep sleep mode for power saving 
//!
//!       6.Core supply power (V DDPLL  and V DDD ): 1.2V±0.1V 
//!
//!       7.I/O supply power(V DDIO ): 1.65V to 3.6V 
//!
//!       8.LCD interface supply power (V DDLCD ): 1.65V to 3.6V 
//
//*****************************************************************************
#ifndef _SSD1963_H
#define _SSD1963_H

//*****************************************************************************
//
//! \addtogroup ILI9325_COLOR_MACRO Color Macro
//! \brief  Set the color of a macro definition
//! @{ 
//
//*****************************************************************************
#define BLACK                                     0x0000 ///< Black:      0, 0, 0
#define NAVY                                      0x000F ///< Navy:       0, 0, 128
#define DGREEN                                    0x03E0 ///< Dark green: 0, 128, 0
#define DCYAN                                     0x03EF ///< Deep blue:  0, 128, 128
#define MAROOON                                   0x7800 ///< Deep red:   128, 0, 0
#define PURPLE                                    0x780F ///< Purple:     128, 0, 128
#define OLIVE                                     0x7BE0 ///< Olive green:128, 128, 0
#define LGRAY                                     0xC618 ///< Light grey: 192, 192, 192
#define DGRAY                                     0x7BEF ///< Dark grey:  128, 128, 128
#define BLUE                                      0x001F ///< Blue:       0, 0, 255
#define GREEN                                     0x07E0 ///< Green:      0, 255, 0
#define CYAN                                      0x07FF ///< Cyan:       0, 255, 255
#define RED                                       0xF800 ///< Red:        255, 0, 0
#define Magenta                                   0xF81F ///< Magenta:    255, 0, 255          
#define YELLOW                                    0xFFE0 ///< Yellow:     255, 255, 0
#define WHITE                                     0xFFFF ///< White:      255, 255, 255

//*****************************************************************************
//
//! @}
//
//*****************************************************************************



#endif