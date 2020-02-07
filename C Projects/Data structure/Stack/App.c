#include "STDTYPES.h"
#include "Stack.h"
#include "App.h"

/*Zero definition*/
#define ZERO  (0)

/*Stack object*/
ST_stackInfo api_stack;

/*API*/
api_ret_type checkForBalancedParantheses(api_str_type expression)
{

    api_ret_type ret_val = ZERO;
    uint8_t au8_exp_loop = ZERO;
    uint8_t au8_popped_element = ZERO;

    createStack(&api_stack,DEFAULT_STACK_SIZE);

    while (expression[au8_exp_loop])
    {
        /*Pushing expression element*/
        if( (expression[au8_exp_loop] == '{') )
        {
            push(&api_stack , '{');
        }
        else if( (expression[au8_exp_loop] == '[') )
        {
            push(&api_stack , '[');
        }
        else if( (expression[au8_exp_loop] == '(') )
        {
            push(&api_stack , '(');
        }

        /*Poping expression element*/
        if( (expression[au8_exp_loop] == '}') )
        {
            pop(&api_stack , &au8_popped_element);
        }
        else if( (expression[au8_exp_loop] == ']') )
        {
            pop(&api_stack , &au8_popped_element);
        }
        else if( (expression[au8_exp_loop] == ')') )
        {
            pop(&api_stack , &au8_popped_element);
        }
        
        au8_exp_loop++;
    }
    
    return ret_val;
}
