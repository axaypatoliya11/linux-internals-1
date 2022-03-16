#include<stdio.h>
#include<unistd.h>

int main(){

    size_t i;
    const int alloc_size = 32 * 1024 * 1024;

    char * memory = malloc(alloc_size);
    mlock(memory, alloc_size); //it will return the allocated memory's first address pointer(base address). kernal will not touch from the memory to the alloc_size bytes

    for(i=0; i<alloc_size; i++){
        memory[i] = '#';
    }
    printf("allocated memory initialized with = %s\n", memory);
    munlock(memory, alloc_size);
    return 0;
}