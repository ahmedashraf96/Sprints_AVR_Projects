#include "stdio.h"
#include "stdlib.h"
#include "STDTYPES.h"
#include "Queue.h"
#include "App.h"

/*Important macros*/
#define MUL_BY_10      (10)
#define COUNTER_START  (-1)

/*Queue object*/
ST_queueInfo api_queue;

/*API*/
api_ret_type evaluate(api_str_type expression)
{
    uint8_t au8_looping_var = ZERO;
    uint8_t au8_enqueue_counter = ZERO;
    sint8_t su8_var_counter = COUNTER_START;
    
    queue_element_t var = ZERO;
    queue_element_t dequeue_var = ZERO;
    queue_element_t result_var = ZERO;

    createQueue(&api_queue , DEFAULT_QUEUE_SIZE);

    /*Searching for numbers in the expression and enqueuing them*/
    while (expression[au8_looping_var])
    {
        if( (expression[au8_looping_var] >= '0' && expression[au8_looping_var] <= '9' ) )
        {
            enqueue(&api_queue , expression[au8_looping_var]);
            au8_enqueue_counter++;
        }
        else if( (expression[au8_looping_var] == '+') || (expression[au8_looping_var] == '-') || (expression[au8_looping_var] == '*') || (expression[au8_looping_var] == '/'))
        {
           enqueue(&api_queue , expression[au8_looping_var]); 
           au8_enqueue_counter++;
        }
        else
        {
            /*Do nothing*/
        }
        au8_looping_var++;
    }

    /*Dequeuing elements and process them*/
    for(au8_looping_var = ZERO ; au8_looping_var < au8_enqueue_counter ; au8_looping_var++)
    {
        dequeue(&api_queue , &dequeue_var);

        if(dequeue_var >= '0' && dequeue_var <= '9')
        {
            su8_var_counter++;

            dequeue_var = dequeue_var - '0';
            
            if(su8_var_counter > ZERO)
            {
                var = (var * MUL_BY_10) + dequeue_var;
            }
            else if(su8_var_counter > 1)
            {
                var = (var * MUL_BY_10) + dequeue_var;
                su8_var_counter = ZERO;
            }
            
        }
        else if(dequeue_var == '+')
        {
            result_var += var;
        }
        else if(dequeue_var == '-')
        {
            result_var -= var;
        }
        else if(dequeue_var == '/')
        {
            result_var /= var;
        }
        else
        {
            result_var *= var;
        }
               
    }

    free(api_queue.q_data);
    return result_var;
}