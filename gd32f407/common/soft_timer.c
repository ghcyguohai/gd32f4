

#include"soft_timer.h"

#define  TIIMER_NUM_MAX  255



static app_timer  timer_table[TIIMER_NUM_MAX];


void app_timer_init(void)
{
     uint16_t i=0;
    for ( i = 0; i < TIIMER_NUM_MAX; i++)
    {
    
       timer_table[i].used_flag=0;
       timer_table[i].enable_flag=FALSE ;  
       timer_table[i].id=0x00;            
       timer_table[i].tick=0x00;
       timer_table[i].interval_time=0x00;
       timer_table[i].p_timeout_handler=NULL;      
    }
}


app_timer* app_timer_create(uint16_t  time,app_timer_timeout_handler_t   timeout_handler )
{
    uint16_t i=0;
    for ( i = 0; i < TIIMER_NUM_MAX; i++)
    {
    
       if(timer_table[i].used_flag==0)
       {
            timer_table[i].used_flag=1;
            timer_table[i].enable_flag=FALSE ;  
            timer_table[i].id=i;            
            timer_table[i].tick=0x00;
            timer_table[i].interval_time=time;
            timer_table[i].p_timeout_handler=timeout_handler;
            return &timer_table[i];      
       }
    }

 return NULL;   
}

void app_timer_delete( app_timer* timer )
{
    if(timer->id<TIIMER_NUM_MAX)
    {
      if(timer->used_flag==1)
      {
        timer->used_flag=0;
        timer->enable_flag=FALSE ;  
        timer->id=0;            
        timer->tick=0x00;
        timer->interval_time=0x00;
        timer->p_timeout_handler=NULL;     
      }  
    }
}

void app_timer_enable(app_timer* timer)
{
    if(timer->id<TIIMER_NUM_MAX)
    {
        if(timer->used_flag==TRUE)
        {
            timer->enable_flag=TRUE;
        }    
    }
}

void app_timer_disable(app_timer* timer)
{
    if(timer->id<TIIMER_NUM_MAX)
    {
      if(timer->used_flag==TRUE)
      {
          timer->enable_flag=FALSE;
      }    
    }
}

void app_timer_tick(void)
{
    uint16_t i=0;
   for (i = 0; i < TIIMER_NUM_MAX; i++)
    {
       if(timer_table[i].used_flag==1)
       {
            if(timer_table[i].enable_flag==TRUE)
            {
                timer_table[i].tick++;
                if(timer_table[i].tick==timer_table[i].interval_time-1)
                {
                  timer_table[i].tick=0;
                  if(timer_table[i].p_timeout_handler!=NULL)
                  {
                    timer_table[i].p_timeout_handler();
                  }
                }
            }
                 
       }
    }         
}
