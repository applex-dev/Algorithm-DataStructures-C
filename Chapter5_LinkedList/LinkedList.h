/* INCLUDE GUARDS */
#ifndef LINKED_LIST_H
#define LINEKD_LIST

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/* DEFINES */
#define linked_list_value_type float
#define NO_VALUE (linked_list_value_type)INFINITY

/* TYPEDEFS */
typedef enum {
    false = 0,
    true = 1
}bool;

typedef struct node{

    struct node * previous;
    linked_list_value_type value;
    struct node * next;

}node_t;

typedef struct linked_list{

    node_t * start;
    node_t * end;
    uint32_t size;

}linked_list_t;

/* FUNCTIONS */

node_t *createNode(linked_list_value_type value);

node_t *freeNode(node_t *node);

linked_list_t *createList(void);

linked_list_t *freeList(linked_list_t *list);

void pushBack(linked_list_t *list, node_t *node);

linked_list_value_type popBack(linked_list_t *list);

void pushFront(linked_list_t *list, node_t *node);

linked_list_value_type popFront(linked_list_t *list);

linked_list_value_type popNode(linked_list_t *list, uint32_t idx);

void pushNode(linked_list_t *list, node_t *node, uint32_t idx);

linked_list_value_type valueAtIdx(linked_list_t *list, uint32_t idx);

void printList(linked_list_t *list);


#endif //LINKED_LIST_H
