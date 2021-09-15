#include "Queue.h"

queue_t * create_queue(uint32_t capacity){

    queue_t * queue = (queue_t *)malloc(sizeof(queue_t));

    if(queue == NULL){
        return NULL;
    }

    queue -> capacity = capacity;
    queue -> front_index = 0;
    queue -> back_index = queue -> capacity - 1;
    queue -> size = 0;
    queue -> data = (queue_data_type_t *)malloc(capacity * sizeof(queue_data_type_t));

    if(queue -> data == NULL){
        return NULL;
    }
    return queue;
}

void *free_queue(queue_t * queue){

    if(queue != NULL){
        queue = NULL;
        if (queue ->data != NULL){
            queue -> data = NULL;
        }
    }

    return NULL;
}

bool isEmpty(queue_t * queue){
    return queue -> size == 0;
}

bool isFull(queue_t * queue){
    return (queue -> size == queue -> capacity);
}

queue_data_type_t push(queue_t * queue, queue_data_type_t value){

    if(isFull(queue) == false){

        //Mapping the back index to the real place in memory.
        queue -> back_index = (queue -> back_index + 1u) % queue -> capacity;
        queue -> data[queue -> back_index] = value;
        queue -> size ++;
    }else{
        return NOVALUE;
    }

    return value;
}

queue_data_type_t pop(queue_t * queue){

   if(isEmpty(queue) == true){
        printf("Queue is now empty.\n");
        return NOVALUE;
    }

    //Mapping the back index to the real place in memory.

    queue -> front_index = (queue -> front_index + 1u) % queue -> capacity;
    queue_data_type_t temp = queue -> data[queue -> front_index];
    queue -> size --;

    return temp;
}

queue_data_type_t front(queue_t * queue){

    if(isEmpty(queue) == true){
        return NOVALUE;
    }

    return queue -> data[queue -> front_index];
}

queue_data_type_t back(queue_t * queue){

    if(isEmpty(queue) == true){
        return NOVALUE;
    }

    return queue -> data[queue -> back_index];
}

void print_queue(queue_t * queue){

    if(queue == NULL){
        return NULL;
    }

    for(uint32_t i = 0; i < queue -> size; i++){

        uint32_t index = (i + queue -> front_index) % queue -> capacity;
        printf("INDEX: %d: %f\n", i, queue -> data[index]);
    }

    printf("\n");
}
