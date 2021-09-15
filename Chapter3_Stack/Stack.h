/* INCLUDE GUARDS */
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>



/* DEFINES */
#define stack_data_type_t float
#define NOVALUE (queue_data_type_t)INFINITY

/* TYPEDEFS */
typedef struct stack
{
    uint32_t size;
    uint32_t capacity;
    stack_data_type_t * data;

}stack_t;

typedef enum{
    false = 0,
    true = 1
}bool;




/* STACK FUNCTIONS */

stack_t * create_stack(uint32_t capacity);

void *free_stack(stack_t * stack);

bool isEmpty(stack_t * stack);

bool isFull(stack_t * stack);

stack_data_type_t push(stack_t * stack, stack_data_type_t value);

stack_data_type_t pop(stack_t * stack);

void printStack(stack_t * stack);


#endif //STACK_H
