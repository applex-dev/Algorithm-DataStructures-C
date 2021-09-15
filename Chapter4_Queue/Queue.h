/* INCLUDE GUARDS */
#ifndef QUEUE_H
#define QUEUE_H


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>


/* DEFINES */
#define queue_data_type_t float
#define NOVALUE (queue_data_type_t)INFINITY


/* TYPEDEFS */
typedef enum {
    false = 0,
    true = 1
}bool;

typedef struct queue
{
    //indicies are necesarry for implementation with array. Pushed values can be stored at real index 0 in memory to use the whole allocated memory.
    uint32_t front_index;
    uint32_t back_index;

    uint32_t size;
    uint32_t capacity;
    queue_data_type_t * data;

}queue_t;

/* STACK FUNCTIONS */

queue_t * create_queue(uint32_t capacity);

void *free_queue(queue_t * queue);

bool isEmpty(queue_t * queue);

bool isFull(queue_t * queue);

queue_data_type_t push(queue_t * queue, queue_data_type_t value);

queue_data_type_t pop(queue_t * queue);

queue_data_type_t front(queue_t * queue);

queue_data_type_t back(queue_t * queue);

void print_queue(queue_t * queue);




#endif //QUEUE_H
