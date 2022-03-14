#include<stdio.h>
#include<stdlib.h>

void buggy(){
    int *intptr;
    intptr = (int *)malloc(5 * sizeof(int));
    printf("malloc checking: address=%08x and size=%d\n", intptr, sizeof(int)*5);

    for (int i = 0; i < 4; i++){
        *intptr = 100;
        printf("value at ptr intptr = %d\n", (*intptr));
        intptr++;
        // printf("after increment value at ptr intptr = %d\n", (*intptr));
    }
    
    
}

int main(){
    buggy();
    return 0;
}