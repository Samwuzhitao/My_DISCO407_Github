#ifndef  __BSP_H__
#define  __BSP_H__

#ifdef   BSP_GLOBALS
#define  BSP_EXT
#else
#define  BSP_EXT  extern
#endif

#define TP_CS	PBout(12)

void BSP_Init(void);
void Touch_Init(void);
void SysTick_Init(void);

#endif     
