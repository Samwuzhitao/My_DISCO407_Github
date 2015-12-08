#include "cc.h"
#include "sys_arch.h"
#include "stm32f4xx.h"

extern __IO uint32_t LocalTime;

u32_t sys_now( void )
{
	return LocalTime;
}
