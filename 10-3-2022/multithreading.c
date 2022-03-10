#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t ttid, ttid1;

void * thread1(void *arg){
    printf("newly created thread is executing-1\n");
    return NULL;
}

void * thread2(void *arg){
    printf("newly created thread is executing-2\n");
    return NULL;
}

int main(){
    int ret = pthread_create(&ttid, NULL, thread1, NULL);
    int ret1 = pthread_create(&ttid1, NULL, thread2, NULL);

    if(ret){
        printf("thread-1 is not created\n");
    } else{
        printf("thread-1 is created\n");
        // sleep(2);
        pthread_join(ttid, NULL); //making a parent to wait for the child
    }

    if(ret1){
        printf("thread-2 is not created\n");
    } else{
        printf("thread-2 is created\n");
        // sleep(2);
        pthread_join(ttid1, NULL); //making a parent to wait for the child
    }
    return 0;
}
