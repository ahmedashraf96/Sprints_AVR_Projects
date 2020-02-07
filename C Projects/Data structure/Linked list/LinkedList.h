#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/*Linked list and node sizes*/
#define LINKED_LIST_DEFAULT_SIZE    (10)
#define NODE_DEFAULT_SIZE           (1)

/*User defined status macros*/
#define LIST_CREATION_SUCCESS       (1)
#define LIST_CREATION_ERROR         (-1)

/*User defined data types*/
typedef sint8_t ll_ret_type;
typedef uint8_t pos_type;
typedef sint32_t data_type;

/*Linked list data types*/
typedef struct 
{
    data_type ll_data;
    ST_node * ll_next_ptr;
}ST_node;

typedef struct 
{
    ST_node * ll_head_ptr;
}ST_list;

/*
* Description : Creates and initializes linked list head
* @param pointer to linked list structure
* @ret linked list creation status
*/
ll_ret_type createList(ST_list *list);

/*
* Description : Insertes a node in a certain position in the created linked list with data.
* @param pointer to linked list head
* @param position of the node
* @param node data
*/
void insertToList(ST_node *listHead, pos_type position, data_type data);

/*
* Description : Deletes a node from a certain position and returns data through pointer.
* @param pointer to linked list head
* @param position of the node
* @param pointer to  the data that deleted
*/
void deleteFromList(ST_node *listHead, pos_type position, data_type* data);

/*
* Description : Searches for a certain node in the linked list by its data.
* @param pointer to linked list head
* @param node data
*/
ST_node* searchIntoList(ST_node *listHead, data_type data); 
void sortList(ST_node *listHead);	//Bonus
void reverseList(ST_node *listHead);	//Bonus

#endif