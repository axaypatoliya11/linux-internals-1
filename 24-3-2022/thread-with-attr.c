#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void* Proc(void* param){
    sleep(2);
    return 0;
}

int main(){
    pthread_attr_t Attr; //1
    pthread_t Id;
    void *Stkaddr;
    size_t Siz; //size_t int

    size_t my_stksize = 0x3000000;
    void * my_stack;

    // getting the initial stack address and stack size
    pthread_attr_init(&Attr); //2.pthread_attr_init(pthread_attr_t *ptr)
    pthread_attr_getstacksize(&Attr, &Siz); //default stack size 8mb..pthd lib
    pthread_attr_getstackaddr(&Attr, &Stkaddr); //def stack(crtn) stack(0000) addr before thd
    printf("default: addr=%08x || default size=%d\n", Stkaddr, Siz); //p

    // setting and getting the modified stack address and stack size
    my_stack = (void *)malloc(my_stksize);
    pthread_attr_setstack(&Attr, &my_stack, &my_stksize);
    pthread_attr_getstacksize(&Attr, &Siz);
    pthread_attr_getstackaddr(&Attr, &Stkaddr);
    printf("modified: addr=%08x || modified size=%d\n", Stkaddr, Siz); //p
                                                                 // phtd lib Size to thread
}