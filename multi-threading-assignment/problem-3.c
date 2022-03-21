// 3. Write a program that changes the default properties of newly created posix
// threads.(ex: to change default pthread stack size )

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
    void *Stk;
    size_t Siz; //size_t int
    int err;

    size_t my_stksize = 0x3000000;
    void * my_stack;

    pthread_attr_init(&Attr); //2.pthread_attr_init(pthread_attr_t *ptr)

    pthread_attr_getstacksize(&Attr, &Siz); //default stack size 8mb..pthd lib
    pthread_attr_getstackaddr(&Attr, &Stk); //def stack(crtn) stack(0000) addr before thd

    printf("default: addr=%08x    default size=%d\n", Stk, Siz); //p
                                                                 // phtd lib Size to thread

    my_stack = (void*)malloc(my_stksize); //we are saying that my_stksize var's memory allocate as a dynamic memory and return that allocated mamoery's address to the my_stack
    pthread_attr_setstack(&Attr, my_stack, my_stksize);

    pthread_create(&Id, &Attr, Proc, NULL);

    pthread_attr_getstacksize(&Attr, &Siz); //default stack size 8mb..pthd lib
    pthread_attr_getstackaddr(&Attr, &Stk); //def stack(crtn) stack(0000) addr before thd
    printf("modified: addr=%08x    modified size=%d\n", Stk, Siz); 


    pthread_join(Id, NULL);
    return 0;
}