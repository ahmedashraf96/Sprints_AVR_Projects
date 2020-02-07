#include "stdio.h"
#include "stdlib.h"
#include "STDTYPES.h"
#include "Stack.h"

/*Important macros*/
#define STACK_UNDERFLOW		(-1)
#define STACK_OVERFLOW  	DEFAULT_STACK_SIZE

void createStack(ST_stackInfo *info, stack_size_t size)
{
	/*Initializing stack with the provided parameters*/
	info -> ST_size = size;
	info -> ST_stack_counter = ZERO;
	info -> ST_data = (stack_element_t *)calloc( size , sizeof(stack_element_t) );
	return;
}

void push(ST_stackInfo *info, stack_element_t data)
{
	/*Stack counter equal to zero in case of underflow*/
	if( (info -> ST_stack_counter) == STACK_UNDERFLOW)
	{
		info -> ST_stack_counter = ZERO;
	}
	else
	{
		/*Do nothing*/
	}
	
	/*Stack overflow validation and pushing operation*/
	if( (info -> ST_stack_counter) < STACK_OVERFLOW )
	{
		info -> ST_data[info -> ST_stack_counter] = data;
		info -> ST_stack_counter++;
	}
	else
	{
		printf("The indexed stack is full !\n");
		info -> ST_stack_counter = STACK_OVERFLOW;
	}
	
	return;
}

void pop(ST_stackInfo *info, stack_element_t* data)
{
	/*Popping operation*/
	info -> ST_stack_counter--;	

	/*Stack underflow validation*/
	if( (info -> ST_stack_counter) > STACK_UNDERFLOW )
	{
		*data = info -> ST_data[info -> ST_stack_counter];
	}
	else
	{
		printf("The indexed stack is empty !\n");
		info -> ST_stack_counter = STACK_UNDERFLOW;
	}
	return;
}