#include "stdio.h"
#include "stdlib.h"
#include "STDTYPES.h"
#include "Queue.h"

/*Important macros*/
#define ZERO              (0)
#define QUEUE_OVERFLOW    DEFAULT_QUEUE_SIZE
  
void createQueue(ST_queueInfo* info, queue_size_t maxSize)
{
    /*Initializing queue with the provided parameters*/
    info -> q_size = maxSize;
    info -> q_front_counter = ZERO;
    info -> q_rear_counter = ZERO;
    info -> q_data = (queue_element_t *)calloc( maxSize , sizeof(queue_element_t) );

    return;
}

void enqueue(ST_queueInfo *info, queue_element_t data)
{
    if(info -> q_rear_counter < QUEUE_OVERFLOW)
    {
        info -> q_data[info -> q_rear_counter] = data;
        info -> q_rear_counter++;
    }
    else
    {
        printf("The indexed queue is full !\n");
    }
    return;
}

void dequeue(ST_queueInfo *info, queue_element_t* data)
{
    if( (info -> q_front_counter) == (info -> q_rear_counter) ) 
    {
        printf("The indexed queue is empty !\n");
        info -> q_front_counter = ZERO;
        info -> q_rear_counter  = ZERO;        
    }
    else
    {
        *data = (info -> q_data[info -> q_front_counter]);
        info -> q_front_counter++;  
    }    
    return;
}