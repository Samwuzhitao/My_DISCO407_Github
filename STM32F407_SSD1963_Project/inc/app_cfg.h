#ifndef  __APP_CFG_H__
#define  __APP_CFG_H__

//ADDITIONAL uC/MODULE ENABLES  额外的使能单元
#define  uC_PROBE_OS_PLUGIN              DEF_DISABLED //DEF_ENABLED:阻止,DEF_DISABLED:不阻止
#define  uC_PROBE_COM_MODULE             DEF_DISABLED
//TASK PRIORITIES 任务优先级
#define  APP_TASK_START_PRIO                   3
#define  APP_TASK_KBD_PRIO                     4
#define  APP_TASK_USER_IF_PRIO                 5
#define  APP_TASK_PROBE_STR_PRIO               6
#define  OS_PROBE_TASK_PRIO                    8
#define  OS_PROBE_TASK_ID                      8
#define  OS_TASK_TMR_PRIO              (OS_LOWEST_PRIO - 2)
//TASK STACK SIZES(堆栈大小)
#define  APP_TASK_START_STK_SIZE             128
#define  APP_TASK_USER_IF_STK_SIZE           256
#define  APP_TASK_KBD_STK_SIZE               256
#define  APP_TASK_PROBE_STR_STK_SIZE         64
#define  OS_PROBE_TASK_STK_SIZE              64
//uC/Probe plug-in for uC/OS-II CONFIGURATION
#define  OS_PROBE_TASK                         1 // Task will be created for uC/Probe OS Plug-In
#define  OS_PROBE_TMR_32_BITS                  0 //uC/Probe OS Plug-In timer is a 16-bit timer              */
#define  OS_PROBE_TIMER_SEL                    2
#define  OS_PROBE_HOOKS_EN                     1

#endif
