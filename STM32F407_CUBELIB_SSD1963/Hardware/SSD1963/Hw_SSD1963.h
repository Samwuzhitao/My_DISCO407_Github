#ifndef _HW_SSD1963_H
#define _HW_SSD1963_H

#define SSD1963_NOP_REG                             0x00 ///< No operation 
#define SSD1963_SOFT_RESET_REG                      0x01 ///< Software Reset 
#define SSD1963_GET_POWER_MODE_REG                  0x0A ///< Get the current power mode 
#define SSD1963_GET_ADDRESS_MODE_REG                0x0B ///< Get the frame buffer to the display panel read order 
#define SSD1963_GET_DISPLAY_MODE_REG                0x0D ///< The SSD1963 returns the Display Image Mode
#define SSD1963_GET_TEAR_EFFECT_STATUS_REG          0x0E ///< Get the Tear Effect status 
#define SSD1963_ENTER_SLEEP_MODE_REG                0x10 ///< Turn off the panel.  This command will pull low the GPIO0.  If GPIO0 is configured as normal GPIO or LCD miscellaneous signal with command set_gpio_conf, this command will be ignored. 
#define SSD1963_EXIT_SLEEP_MODE_REG                 0x11 ///< Turn on the panel.  This command will pull high the GPIO0.  If GPIO0 is configured as normal GPIO or LCD miscellaneous signal with command set_gpio_conf, this command will be ignored. 
#define SSD1963_ENTER_PEATIAL_MODE_REG              0x12 ///< Part of the display area is used for image display.
#define SSD1963_ENTER_NORMAL_MODE_REG               0x13 ///< The whole display area is used for image display. 
#define SSD1963_EXIT_INVERT_MODE_REG                0x20 ///< Displayed image colors are not inverted. 
#define SSD1963_ENTER_INVERT_MODE_REG               0x21 ///< Displayed image colors are inverted. 
#define SSD1963_SET_GAMMA_CURVE_REG                 0x26 ///< Selects the gamma curve used by the display panel. 
#define SSD1963_SET_DISPLAY_OFF_REG                 0x28 ///< Blanks the display panel 
#define SSD1963_SET_DISPLAY_ON_REG                  0x29 ///< Show the image on the display panel 
#define SSD1963_SET_COLUMN_ADDRESS_REG              0x2A ///< Set the column address 
#define SSD1963_SET_PAGE_ADDRESS_REG                0x2B ///< Set the page address
#define SSD1963_WRITE_MEMORY_START_REG              0x2C ///< Transfer image information from the host processor interface to the SSD1963 starting at the location provided by set_column_address and set_page_address 
#define SSD1963_READ_MEMORY_START_REG               0x2E ///< Transfer image data from the SSD1963 to the host processor interface starting at the location provided by set_column_address and set_page_address 
#define SSD1963_SET_PARTIAL_AREA_REG                0x30 ///< Defines the partial display area on the display panel
#define SSD1963_SET_SCROLL_AREA_REG                 0x33 ///< Defines the vertical scrolling and fixed area on display area
#define SSD1963_SET_TEAR_OFF_REG                    0x34 ///< Synchronization information is not sent from the SSD1963 to the host processor 
#define SSD1963_SET_TEAR_ON_REG                     0x35 ///< Synchronization information is sent from the SSD1963 to the host processor at the start of VFP
#define SSD1963_SET_ADDRESS_MODE_REG                0x36 ///< Set the read order from frame buffer to the display panel 
#define SSD1963_SET_SCOLL_START_REG                 0x37 ///< Defines the vertical scrolling starting point 
#define SSD1963_EXIT_IDLE_MODE_REG                  0x38 ///< Full color depth is used for the display panel 
#define SSD1963_ENTER_IDLE_MODE_REG                 0x39 ///< Reduce color depth is used on the display panel. 
#define SSD1963_WRITE_MEMORY_CONTINUE_REG           0x3C ///< Transfer image information from the host processor interface to the SSD1963 from the last written location 
#define SSD1963_READ_MEMORY_CONTINUE_REG            0x3E ///< Read image data from the SSD1963 continuing after the last read_memory_continue or read_memory_start 



















#endif