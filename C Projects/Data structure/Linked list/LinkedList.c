#include "stdio.h"
#include "stdlib.h"
#include "STDTYPES.h"
#include "LinkedList.h"

/*Zero definition*/
#define ZERO    (0)

/*NULL definition*/
#define NULL     ( (void*)(0) )


/*Linked list functions*/
ll_ret_type createList(ST_list *list)
{
    ll_ret_type ret_status = ZERO;

    /*Initializing the linked list */
    list -> ll_head_ptr = calloc(NODE_DEFAULT_SIZE , sizeof(ST_node));

    /*Validation of linked list creation*/
    if( (list -> ll_head_ptr) != NULL)
    {
        list -> ll_head_ptr -> ll_next_ptr = NULL;
        list -> ll_head_ptr -> ll_data = ZERO;

        ret_status = LIST_CREATION_SUCCESS;
    }
    else
    {
        ret_status = LIST_CREATION_ERROR;
    }

    return ret_status;
}

void insertToList(ST_node *listHead, pos_type position, data_type data)
{
    listHead -> ll_next_ptr = calloc(NODE_DEFAULT_SIZE , sizeof(ST_node));
     
    return;
}