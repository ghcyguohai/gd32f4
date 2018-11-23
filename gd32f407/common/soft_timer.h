

#ifndef  SOFT_TIMER_H
#define  SOFT_TIMER_H 



#include "stdint.h"
#include <stdbool.h>
#include <stdio.h> 
#include <stddef.h>

#define FALSE 0
#define TRUE  1

typedef void (*app_timer_timeout_handler_t)(void);
 
typedef  struct  app_timer 
{   uint8_t                      used_flag;
    uint8_t                      enable_flag ;
    uint8_t 		             id;                 
    uint16_t 		             tick;
    uint16_t 		             interval_time;
    app_timer_timeout_handler_t  p_timeout_handler;          
  
}app_timer;


void app_timer_init(void);
app_timer* app_timer_create(uint16_t  time,app_timer_timeout_handler_t   timeout_handler );
void app_timer_delete( app_timer* timer );
void app_timer_enable(app_timer* timer);
void app_timer_disable(app_timer* timer);
void app_timer_tick(void);

#endif 
