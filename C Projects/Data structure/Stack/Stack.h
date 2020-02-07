#ifndef __STACK_H__
#define __STACK_H__

/*User configurations*/
#define DEFAULT_STACK_SIZE      (100)

/*Stack data types*/
typedef sint32_t stack_element_t;
typedef uint32_t stack_size_t;

typedef struct 
{
	stack_size_t ST_size;
	stack_element_t ST_stack_counter;
	stack_element_t* ST_data;
}ST_stackInfo;


/*
* Description : Creates stack by using dynamic memory allocation.
* @param pointer to stack
* @param size of the stack
*/
void createStack(ST_stackInfo *info, stack_size_t size);

/*
* Description : Push data into stack.
* @param pointer to stack
* @param data to be pushed
*/
void push(ST_stackInfo *info, stack_element_t data);

/*
* Description : Pop data from stack.
* @param pointer to stack
* @param popped data
*/
void pop(ST_stackInfo *info, stack_element_t* data);

#endif