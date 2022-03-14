#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

#define NUM_THREDS 3
int i = 0;


void * thread1(void *arg){
    i++;
    int result = 0;
    result = result + i*1000;
    printf("result = %d\n", result);

    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t thread[NUM_THREDS];
    pthread_attr_t attr;

    int rc, t, status, detach_state;

    pthread_attr_init(&attr);

    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    for(t=0; t<NUM_THREDS; t++){
        printf("creating thread %d\n", t);
        pthread_create(&thread[t], &attr, thread1, NULL);
    }

    pthread_attr_getdetachstate(&attr, &detach_state);
    printf("\nDetach state: %d\n", (int *)detach_state);

    printf("\nexiting from main thread\n");
    pthread_exit(NULL);


    return 0;
}
