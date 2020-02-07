#ifndef __QUEUE_H__
#define __QUEUE_H__

/*User configurations*/
#define DEFAULT_QUEUE_SIZE  (100)

/*Queue data types*/
typedef sint32_t queue_element_t;
typedef uint32_t queue_size_t;

typedef struct 
{
    queue_size_t q_size;
    queue_element_t q_front_counter;
    queue_element_t q_rear_counter;
    queue_element_t* q_data;
}ST_queueInfo;

/*
* Description : Creates Queue by dynamic memory allocation.
* @param pointer to queue
* @param maximum size of the queue   
*/
void createQueue(ST_queueInfo* info, queue_size_t maxSize);

/*
* Description : Inserts data in the last of the queue.
* @param pointer to queue
* @param data to be inserted  
*/
void enqueue(ST_queueInfo *info, queue_element_t data);

/*
* Description : Serves the data that is in the front of the queue.
* @param pointer to queue
* @param pointer to the served data   
*/
void dequeue(ST_queueInfo *info, queue_element_t* data);

#endif