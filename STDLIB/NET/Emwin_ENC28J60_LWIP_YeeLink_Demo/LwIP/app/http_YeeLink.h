#ifndef __HTTP_YEELINK_H__
#define __HTTP_YEELINK_H__
#include "stm32f4xx.h"
#include "lwip/tcp.h"

#include "My_DISCO_BSP.h"
#include "YeeLink_html.h"

#include <string.h>
#include <stdio.h>

//void http_YeeLink_init(void);
void tcp_echoclient_connect(void);

#endif
