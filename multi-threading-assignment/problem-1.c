// 1.Write a multithreading program, where threads runs same shared golbal variable of
// the process between them.

// we can perform threading operations using posix
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

// globally shared variable
int shaerdVar = 5; //we have to use lock because this variable can be accessed by both the threads at same time

void * thread1_inc(void *arg){
    shaerdVar++; //critical section
    printf("after increment=%d\n", shaerdVar);
}

void * thread2_dec(void *arg){
    shaerdVar--; //critical section
    printf("after decrement=%d\n", shaerdVar);
}

int main(){
    pthread_t ttid, ttid1;


    pthread_create(&ttid, NULL, thread1_inc, NULL);
    pthread_create(&ttid1, NULL, thread2_dec, NULL);

    pthread_join(ttid, NULL); //making a parent to wait for the child
    pthread_join(ttid1, NULL); //making a parent to wait for the child
    
    printf("shared variable: %d\n", shaerdVar);
    return 0;
}
