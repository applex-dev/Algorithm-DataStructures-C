#include "Stack.h"

stack_t * create_stack(uint32_t capacity){

    stack_t * stack = (stack_t *)malloc(sizeof(stack_t));

    if(stack == NULL){
        return NULL;
    }

    stack -> capacity = capacity;
    stack -> size = 0;
    stack -> data = (stack_data_type_t *)malloc(capacity * sizeof(stack_data_type_t));

    if(stack -> data == NULL){
        return NULL;
    }
    return stack;
}

void *free_stack(stack_t * stack){

    if(stack != NULL){
        stack = NULL;
        if (stack ->data != NULL){
            stack -> data = NULL;
        }
    }
}

bool isEmpty(stack_t * stack){
    return stack -> size == 0;
}

bool isFull(stack_t * stack){
    return (stack -> size == stack -> capacity);
}

stack_data_type_t push(stack_t * stack, stack_data_type_t value){

    if(isFull(stack) == false){
        stack -> data[stack -> size] = value;
        stack -> size ++;
    }else{
        return NOVALUE
    }

    return value;
}

stack_data_type_t pop(stack_t * stack){

   if(isEmpty(stack) == true){
        printf("Stack is now empty.\n");
        return NOVALUE;
    }

    stack_data_type_t temp = stack -> data[stack -> size -1];
    stack -> size --;

    return &temp;
}

void printStack(stack_t * stack){

    if(stack == NULL){
        printf("Stack is now full.\n");
        return NULL;
    }

    for(uint32_t i = 0; i < stack -> size; i++){
    printf("%f\n", stack -> data[i]);
    }

    printf("\n");
}
