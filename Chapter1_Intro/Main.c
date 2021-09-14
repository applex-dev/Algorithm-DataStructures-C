#include <stdio.h>
#include <stdint.h>

int main(void){

    uint32_t array[3][2] = {

        {1, 3},
        {4, 9},
        {1, 3}
    };

    for(uint8_t i = 0; i < 3; i++){
        for(uint8_t j = 0; j < 2; j++){

            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
