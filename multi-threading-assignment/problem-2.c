// 2.Write a program where thread cancel itself.(use pthread_cancel())

#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t ttid;

void * thread1(void *arg){
    printf("newly created thread is executing\n");
    int t;
    t = pthread_cancel(ttid);
    pthread_t tid = pthread_self();
    if(t==0){ //returns 0 after successful
        printf("cancle thread %u\n", tid);
    }
    return NULL;
}

int main(){
    int ret = pthread_create(&ttid, NULL, thread1, NULL);
    int rc, t;


    if(ret){
        printf("thread is not created\n");
    } else{
        printf("thread is created, thread ID = %u\n", ttid);
        // sleep(2);
        pthread_join(ttid, NULL); //making a parent to wait for the child
    }
    return 0;
}
