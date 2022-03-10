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

    if(ret){
        printf("thread is not created\n");
    } else{
        printf("thread is created\n");
        // sleep(2);
        pthread_join(ttid, NULL); //making a parent to wait for the child
    }
    return 0;
}

// gcc threads.c -l pthread ->run this command in order to compile the code because there's no pthread.h header file in system by default