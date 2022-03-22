// for upper boundry violation

#include <stdio.h>
#include <stdlib.h>
void buggy()
{
    int *intptr;
    int i;
    intptr = (int *)malloc(sizeof(int)); //intptr = 4 bytes
    printf("malloc checking addr=%08x and size = %d\n", intptr, sizeof(int));
    *intptr = 100;
    printf("value at the ptr int ptr = %ld\n", (*intptr));
    free(intptr);
    *intptr = 99;
}
int main()
{
    buggy();
    return 0;
}