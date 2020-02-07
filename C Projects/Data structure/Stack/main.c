#include "stdio.h"
#include "STDTYPES.h"
#include "Stack.h"

ST_stackInfo stack;
stack_element_t x = 0;

int main(void)
{
    createStack(&stack , DEFAULT_STACK_SIZE);

    push(&stack , 20);
    push(&stack , 40);
    push(&stack , 60);

    pop(&stack , &x);
    printf("%d\n",x);

    pop(&stack , &x);
    printf("%d\n",x);

    pop(&stack , &x);
    printf("%d\n",x);

    return 0;
}