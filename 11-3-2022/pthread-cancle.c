#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t ttid;

void * thread1(void *arg){
    printf("newly created thread is executing\n");
    return NULL;
}

int main(){
    int ret = pthread_create(&ttid, NULL, thread1, NULL);
    int rc, t=0;

    pthread_t tid = pthread_self();

    if(ret){
        printf("thread is not created\n");
    } else{
        printf("thread is created, thread ID = %u\n", tid);
        // sleep(2);
        pthread_join(ttid, NULL); //making a parent to wait for the child
    }
    t = pthread_cancel(tid);
    if(t==0){ //returns 0 after successful
        printf("cancle thread %u\n", tid);
    }
    return 0;
}
