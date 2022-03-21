// 5.Write a program that implements threads synchronization using mutex techniques.


// we can perform threading operations using posix
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

// globally shared variable
int shaerdVar = 5; //we have to use lock because this variable can be accessed by both the threads at same time

pthread_mutex_t my_mutex; //creating a semaphore lock

void * thread1_inc(void *arg){
    pthread_mutex_lock(&my_mutex); //take semaphore
    shaerdVar++; //critical section
    pthread_mutex_unlock(&my_mutex); //release semaphore
    printf("after increment=%d\n", shaerdVar);
}

void * thread2_dec(void *arg){
    pthread_mutex_lock(&my_mutex); //take semaphore
    shaerdVar--; //critical section
    pthread_mutex_unlock(&my_mutex); //release semaphore
    printf("after decrement=%d\n", shaerdVar);
}

int main(){
    pthread_t ttid, ttid1;

    pthread_mutex_init(&my_mutex, NULL); //initialize semaphore

    pthread_create(&ttid, NULL, thread1_inc, NULL);
    pthread_create(&ttid1, NULL, thread2_dec, NULL);

    pthread_join(ttid, NULL); //making a parent to wait for the child
    pthread_join(ttid1, NULL); //making a parent to wait for the child
    
    printf("shared variable: %d\n", shaerdVar);
    return 0;
}
