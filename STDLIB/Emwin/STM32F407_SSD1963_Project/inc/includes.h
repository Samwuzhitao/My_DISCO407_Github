#ifndef  __INCLUDES_H__
#define  __INCLUDES_H__

#define   DEF_FALSE 0
#define   DEF_TRUE  1

#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdlib.h>
#include    <stdarg.h>
#include    <ucos_ii.h>
#include    <cpu.h>
#include    <lib_def.h>
#include    <lib_mem.h>
#include    <lib_str.h>
#include    <app_cfg.h>
#include    <bsp.h>
#include    <GUI.h>
#include    "main.h"


#if(uC_PROBE_OS_PLUGIN>0)
#include    <os_probe.h>
#endif

#if(uC_PROBE_COM_MODULE>0)
#include    <probe_com.h>
#if(PROBE_COM_METHOD_RS232>0)
#include    <probe_rs232.h>
#endif
#endif



#endif
