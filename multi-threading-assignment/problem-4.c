// 4. Write a program where pthread task displays the thread id and also prints the calling
// process pid.

#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t ttid;

void * thread1(void *arg){
    printf("newly created thread is executing\n");
    printf("thread is created, thread ID = %u\n", ttid);
    return NULL;
}

int main(){
    int ret = pthread_create(&ttid, NULL, thread1, NULL);
    int rc, t;

    pthread_t tid = pthread_self();
    printf("calling process process ID = %u\n", tid);

    if(ret){
        printf("thread is not created\n");
    } else{
        pthread_join(ttid, NULL); //making a parent to wait for the child
    }
    return 0;
}
