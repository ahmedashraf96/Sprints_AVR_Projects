#include "stdio.h"
#include "STDTYPES.h"
#include "App.h"

api_str_type expression = "[({})]";
api_ret_type ret_val = ZERO;

int main(void)
{
    ret_val = checkForBalancedParantheses(expression);

    if(ret_val == BALANCED_EXP)
    {
        printf("Balanced expression !\n");
    }
    else
    {
        printf("Unbalanced expression !\n");
    }
    
    return 0;
}