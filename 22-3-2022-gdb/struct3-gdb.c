#include <stdio.h>
#include <string.h>

struct A
{
    int roll __attribute__((aligned(8))); //int by default consumes 4 bits so we want to aligned() then we have to do it in multiplication of 4(alignment should always be less than 4)
    char name[40], gender __attribute__((aligned(2)));
    float height;
}__attribute__((packed));

int main(){
    struct A first;
    printf("\n Size of struct A %3d\n", sizeof(first));
    
    return 0;
}

// aligned is an structure attribute that specifies please provide minimum memory alignment for my structure variable. based on alignment it's paking the structure with given alignment 