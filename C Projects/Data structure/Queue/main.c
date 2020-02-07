#include "stdio.h"
#include "STDTYPES.h"
#include "App.h"


api_str_type expression = "{9-(5+7)+9}";

int main(void)
{ 
    printf("%d\n",evaluate(expression));
    return 0; 
}