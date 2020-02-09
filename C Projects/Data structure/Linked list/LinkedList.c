#include "stdio.h"
#include "stdlib.h"
#include "STDTYPES.h"
#include "LinkedList.h"

/*Linked list functions*/
ll_ret_type createList(ST_list *list , data_type head_data)
{
    /*Returned flag indicates the status of the list*/
    ll_ret_type ret_status = ZERO;

    /*Initializing the linked list */
    list -> ll_head_ptr = calloc(NODE_DEFAULT_SIZE , sizeof(ST_node));

    /*Validation of linked list creation*/
    if( (list -> ll_head_ptr) != NULL)
    {
        list -> ll_head_ptr -> ll_next_ptr = NULL;
        list -> ll_head_ptr -> ll_data = head_data;

        ret_status = LIST_CREATION_SUCCESS;
        printf("List head was created successfully!\n");
    }
    else
    {
        ret_status = LIST_CREATION_ERROR;
        printf("Error in the list creation\n");
    }

    return ret_status;
}

void insertToList(ST_node *listHead, pos_type position, data_type data)
{
    /*Variable used in looping operations*/
    uint8_t au8_looping_var = ZERO;
   
   /* Three node pointers used in the insertion operation that:
    * prev_node -> new_node -> next_node
    * They all initialized by the list header address value
    */
    ST_node *prev_node = listHead;
    ST_node *new_node  = listHead;
    ST_node *next_node = listHead;

    /*New node creation*/
    new_node = calloc(NODE_DEFAULT_SIZE , sizeof(ST_node));

    /*Validating that the node selected isn't the header*/
    if(position == HEAD_NODE_POSITION)
    {
        printf("Invalid insertion, You can't insert before the head node!\n");
    }
    else
    {
        /*Getting the node that will be previous for the new one*/
        for(au8_looping_var = FIRST_NODE_POSITION ; au8_looping_var < position ; au8_looping_var++)
        {
            prev_node = prev_node -> ll_next_ptr;  
        }            
        
        /*Setting the next node for the new one*/
        next_node = prev_node -> ll_next_ptr;
        
        /*Previous node points for the new node*/
        prev_node -> ll_next_ptr = new_node;

        /*New node points to the next one and data is assigned to it*/
        new_node -> ll_next_ptr = next_node;
        new_node -> ll_data = data;  
    }
    return;
}

void deleteFromList(ST_node *listHead, pos_type position, data_type* data)
{
    /*Variable used in looping operations*/
    uint8_t au8_looping_var = ZERO;
    
    /* Three node pointers used in the deleting operation that:
     * prev_node -> curr_node -> next_node
     * They all initialized by the list header address value
     */
    ST_node *prev_node = listHead;
    ST_node *curr_node = listHead;
    ST_node *next_node = listHead;

    /*Validating that the node selected isn't the header*/
    if(position == HEAD_NODE_POSITION)
    {
        printf("Invalid deleting process, You can't delete the head node!\n");
    }
    else
    {
        /*Getting the previous node for the one that will be deleted*/
        for (au8_looping_var = FIRST_NODE_POSITION ; au8_looping_var < position ; au8_looping_var++)
        {
            prev_node = prev_node -> ll_next_ptr;
        }

        /*Getting the node that will be deleted*/
        curr_node = prev_node -> ll_next_ptr;
        
        /*Making sure the node is existed*/
        if( curr_node == NULL)
        {
            printf("Invalid deleting process, You can't delete node that doesn't exist!\n");
        }
        else
        {
            /*Setting the next node of the node will be deleted*/
            next_node = curr_node -> ll_next_ptr;

            /*Previous node of the deleted node points to the next one of it*/
            prev_node -> ll_next_ptr = next_node;
            
            /*Getting the data of the deleted node*/
            *data = curr_node -> ll_data;    
            
            /*Getting rid of the deleted node*/
            free(curr_node);            
        }

    }
    return;
}

ST_node* searchIntoList(ST_node *listHead, data_type data)
{
    /*Variable used in looping operations*/
    uint8_t au8_looping_var = ZERO;
    
    /*Flag indicates that search key is found or not*/
    uint8_t au8_search_flag = ZERO;
    
    /*Pointer used in searching operation for the kay node, Initialized by header address value*/
    ST_node *key_node = listHead;

    while( key_node != NULL )
    {
        /*Key node data validation*/
        if( (key_node -> ll_data) == data)
        {
            au8_search_flag++;
            break;
        }
        else
        {
            /*Do nothing*/
        }

        /*Setting the pointer to the next node*/
        key_node = key_node -> ll_next_ptr;
    }

    /*Node found or not*/
    if(au8_search_flag == ZERO)
    {
        key_node = NULL;
        printf("Node with value %d is not found!\n", data);
    }
    else
    {
        printf("Node with value %d is found!\n", data);
    }

    return key_node;
}