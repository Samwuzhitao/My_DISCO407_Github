#ifndef __LWIP_INIT_H
#define __LWIP_INIT_H

#include "stm32f4xx.h"
#include "lwip/err.h"  
#include "lwip/init.h"
#include "netif/etharp.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"


void LwIP_Init( void );
void Time_Update(void);
void LwIP_Periodic_Handle(__IO uint32_t localtime);

#endif






