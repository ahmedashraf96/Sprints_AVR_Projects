#include "stdio.h"
#include "STDTYPES.h"
#include "LinkedList.h"

ST_list list;
data_type data = ZERO;

int main(void)
{
    createList(&list,50);

    insertToList( (list.ll_head_ptr) , 1 , 60);
    insertToList( (list.ll_head_ptr) , 2 , 80);
    
    searchIntoList( (list.ll_head_ptr) , 80);

    deleteFromList( (list.ll_head_ptr) , 1 , &data);

    searchIntoList( (list.ll_head_ptr) , 60);
    return 0;
}