#include "Stack.h"

int main(void){

    stack_t * my_stack = create_stack(10);

   for(uint32_t i = 0; i < 100; i++){
       push(my_stack, (float)i);
   }

   printStack(my_stack);

   pop(my_stack);
   pop(my_stack);
   pop(my_stack);
   pop(my_stack);

   printf("SIZE: %d\n", my_stack -> size);

   printStack(my_stack);



    return 0;
}
