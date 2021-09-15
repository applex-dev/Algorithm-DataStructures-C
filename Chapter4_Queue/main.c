#include "Queue.h"

int main(void){

    queue_t * my_queue = create_queue(10);

    for(uint16_t i = 0; i < 4; i++){
       printf("PUSHED: %f\n", push(my_queue, (float)i));
    }


    print_queue(my_queue);

    pop(my_queue);

    print_queue(my_queue);

    printf("PUSHED: %f\n", push(my_queue,8.8));
    printf("SIZE: %d\n", my_queue -> size);

    print_queue(my_queue);

    printf("FRONT: %f\n", front(my_queue));
    printf("BACK: %f\n", back(my_queue));


    return 0;
}
