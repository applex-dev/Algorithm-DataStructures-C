#include "LinkedList.h"


node_t *createNode(linked_list_value_type value){
    node_t * temp_node = (node_t *)malloc(sizeof(node_t));

    temp_node -> next = NULL;
    temp_node -> previous = NULL;
    temp_node -> value = value;

    return temp_node;
}

node_t *freeNode(node_t *node){

    if(node == NULL){
        return NULL;
    }

    free(node);
    node = NULL;

    return node;
}

linked_list_t *createList(void){

    linked_list_t * temp_list = (linked_list_t *)malloc(sizeof(linked_list_t));

    temp_list -> end = NULL;
    temp_list -> size = 0;
    temp_list -> start = NULL;

    return temp_list;
}

linked_list_t *freeList(linked_list_t *list){

    if(list == NULL){
        return NULL;
    }

    free(list);
    list = NULL;

    return list;
}

static void push_first(linked_list_t *list, node_t *node){

    list -> size = 1;
    list -> start = node;
    list -> end = node;
}

static linked_list_value_type pop_last(linked_list_t * list){

    linked_list_value_type temp_val = list -> end -> value;

    list -> size = 0;
    freeNode(list -> start);
    list -> end = NULL,
    list -> start = NULL;

    printf("Last element was popped.\n");

    return temp_val;
}

void pushBack(linked_list_t *list, node_t *node){

    if(list -> size == 0){
        push_first(list, node);
        return;
    }

    list -> end -> next = node;
    node -> previous = list -> end;
    list -> end = node;
    list -> size++;
}

linked_list_value_type popBack(linked_list_t *list){

    if(list -> size == NULL){
        return NO_VALUE;
    }else if(list -> size == 1){
        return pop_last(list);
    }

    node_t * temp = list -> end;
    linked_list_value_type temp_val = list -> end -> value;

    list -> end = list -> end -> previous;
    list -> end -> next = NULL;

    freeNode(temp);

    list -> size--;

    return temp_val;
}

void pushFront(linked_list_t *list, node_t *node){

    if(list -> size == 0){
        push_first(list, node);
        return;
    }

    list -> start -> previous = node;
    node -> next = list -> start;
    list -> start = node;
    list -> size++;
}

linked_list_value_type popFront(linked_list_t *list){

    if(list -> size == NULL){
        return NO_VALUE;
    }else if(list -> size == 1){
       return pop_last(list);
    }
    node_t * temp = list -> start;
    linked_list_value_type temp_val = list -> start -> value;

    list -> start = list -> start -> next;
    list -> start -> previous = NULL;

    freeNode(temp);

    list -> size --;

    return temp_val;
}

linked_list_value_type popNode(linked_list_t *list, uint32_t idx){

    if(list == NULL){
        return NO_VALUE;
    }

    if(idx > (list -> size - 1)){
        return NO_VALUE;
    }

    if(idx == 0){
        return popFront(list);
    }

    if(idx == (list -> size - 1)){
        return popBack(list);
    }

    uint32_t i = 0;
    node_t * temp_node = list -> start;

    while(i < idx){
        i++;
        temp_node = temp_node -> next;
    }

   linked_list_value_type temp_val = temp_node -> value;

    list -> size--;

    temp_node -> previous -> next = temp_node -> next;
    temp_node -> next -> previous = temp_node -> previous;

    free(temp_node);

    return temp_val;
}

void pushNode(linked_list_t *list, node_t *node, uint32_t idx){

    if(list == NULL){
        return;
    }

    if(idx > (list -> size - 1)){
        return;
    }

    if(idx == 0){
        pushFront(list, node);
        return;
    }

    if(idx == (list -> size - 1)){
        pushBack(list, node);
        return;
    }

    uint32_t i = 0;
    node_t * temp_node = list -> start;

    while(i < idx){
        i++;
        temp_node = temp_node -> next;
    }

    list -> size++;

    node -> previous = temp_node -> previous;
    node -> next = temp_node;
    temp_node -> previous -> next = node;
    temp_node -> previous = node;

}

linked_list_value_type valueAtIdx(linked_list_t *list, uint32_t idx){

    if(list == NULL){
        return NO_VALUE;
    }

    if(idx > (list -> size - 1)){
        return NO_VALUE;
    }

    uint32_t i = 0;
    node_t * temp_node = list -> start;

    while(i < idx){
        i++;
        temp_node = temp_node -> next;
    }

    return temp_node -> value;
}

void printList(linked_list_t *list){

    if(list == NULL){
        return;
    }

    if( list -> size == 0){
        printf("List is empty.\n");
    }

    node_t * temp_node = list -> start;

     for(uint32_t i = 0; i < list -> size; i++){
         printf("%f\n", temp_node -> value);
         temp_node = temp_node -> next;
     }

     printf("\n");
}

