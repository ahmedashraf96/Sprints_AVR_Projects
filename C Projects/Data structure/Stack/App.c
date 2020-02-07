#include "STDTYPES.h"
#include "Stack.h"
#include "App.h"

/*Stack object*/
ST_stackInfo api_stack;

/*API*/
api_ret_type checkForBalancedParantheses(api_str_type expression)
{
    /*Variable holds return status for checking*/
    api_ret_type ret_val = ZERO;
    
    
    /*Variable used for dummy popping*/
    stack_element_t popped_element = ZERO;

    /*Variable used for looping on expression*/
    uint8_t au8_exp_loop = ZERO;

    /*Pushing operation counters*/
    uint8_t au8_curly_bracket_push = ZERO;
    uint8_t au8_square_bracket_push = ZERO;
    uint8_t au8_parenthese_push = ZERO;
    
    /*Popping operation counters*/
    uint8_t au8_curly_bracket_pop = ZERO;
    uint8_t au8_square_bracket_pop = ZERO;
    uint8_t au8_parenthese_pop = ZERO;

    /*Stack creation*/
    createStack(&api_stack,DEFAULT_STACK_SIZE);

    while (expression[au8_exp_loop])
    {
        /*Pushing expression element*/
        if( (expression[au8_exp_loop] == '{') )
        {
            push(&api_stack , '{');
            au8_curly_bracket_push++;
        }
        else if( (expression[au8_exp_loop] == '[') )
        {
            push(&api_stack , '[');
            au8_square_bracket_push++;
        }
        else if( (expression[au8_exp_loop] == '(') )
        {
            push(&api_stack , '(');
            au8_parenthese_push++;
        }

        /*Popping expression element*/
        if( (expression[au8_exp_loop] == '}') )
        {
            pop(&api_stack , &popped_element);
            au8_curly_bracket_pop++;
        }
        else if( (expression[au8_exp_loop] == ']') )
        {
            pop(&api_stack , &popped_element);
            au8_square_bracket_pop++;
        }
        else if( (expression[au8_exp_loop] == ')') )
        {
            pop(&api_stack , &popped_element);
            au8_parenthese_pop++;
        }
        
        au8_exp_loop++;
    }
    
    if((au8_curly_bracket_push != au8_curly_bracket_pop) || (au8_square_bracket_push != au8_square_bracket_pop) || (au8_parenthese_push != au8_parenthese_pop))
    {
        ret_val = UNBALANCED_EXP;
    }
    else
    {
        ret_val = BALANCED_EXP;
    }
    
    return ret_val;
}
