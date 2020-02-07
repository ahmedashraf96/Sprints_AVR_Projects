#include "stdio.h"
#include "STDTYPES.h"
#include "Queue.h"

ST_queueInfo queue;
queue_element_t x = 0;

int main(void)
{
    createQueue(&queue , DEFAULT_QUEUE_SIZE);
    enqueue(&queue , 20);
    enqueue(&queue , 40);
    enqueue(&queue , 60);

    dequeue(&queue,&x);
    printf("%d\n",x);  

    dequeue(&queue,&x);
    printf("%d\n",x);   

    dequeue(&queue,&x);
    printf("%d\n",x);   

    return 0; 
}