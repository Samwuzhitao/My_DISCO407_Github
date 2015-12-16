#ifndef __HTTP_YEELINK_H__
#define __HTTP_YEELINK_H__
#include "stm32f4xx.h"
#include "lwip/tcp.h"

#include "My_DISCO_BSP.h"
#include "YeeLink_html.h"

#include <string.h>
#include <stdio.h>

/* ECHO protocol states */
enum echoclient_states
{
  ES_TCPCLIENT_NONE = 0,
  ES_TCPCLIENT_CONNECTED,
  ES_TCPCLIENT_CLOSING,
};


/* structure to be passed as argument to the tcp callbacks */
struct tcp_client_struct
{
  u8 state;                  /* connection status */
  struct tcp_pcb *pcb;       /* pointer on the current tcp_pcb */
  struct pbuf *p;            /* pointer on pbuf to be transmitted */
};

//void http_YeeLink_init(void);
void tcp_client_connect(void);

#endif
