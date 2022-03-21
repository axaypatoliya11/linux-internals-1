#include<stdio.h>
#include<stdlib.h>

int main(int argc, int *argv[]){
    printf("file name: %s\n", argv[0]);
    printf("total number of arguments: %d\n", argc);
    printf("argument passed\n");
    for(int i=1; i<argc; i++){
        printf("%s\n", argv[i]);
    }

    return 0;
}