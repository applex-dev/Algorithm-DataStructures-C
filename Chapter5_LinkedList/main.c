#include "LinkedList.h"

int main(void){

    linked_list_t * my_list = createList();

    pushBack(my_list, createNode(1.0f));
    pushBack(my_list, createNode(2.0f));
    pushBack(my_list, createNode(3.0f));
    pushBack(my_list, createNode(4.0f));

    printList(my_list);


    pushNode(my_list, createNode(8.7f), 3);
    pushNode(my_list, createNode(5.7f), 0);

    printList(my_list);

    printf("Val at index 0 = %f\n", valueAtIdx(my_list, 0));
    printf("Val at index 3 = %f\n", valueAtIdx(my_list, 3));
    printf("Val at index 5 = %f\n", valueAtIdx(my_list, 5));

    return 0;
}


