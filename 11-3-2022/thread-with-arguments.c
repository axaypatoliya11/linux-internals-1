// we can perform threading operations using posix
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t ttid, ttid1;

static void * thread1(void *arg){
    char *s = (char *)arg;
    printf("newly created thread is executing-1\n");
    printf("%s\n", s);
    return NULL;
}

int main(int argc, char *argv[]){
    int ret = pthread_create(&ttid, NULL, thread1, "Hello world!");

    printf("message from the main\n");

    if(ret){
        printf("thread-1 is not created\n");
    } else{
        printf("thread-1 is created\n");
        // sleep(2);
        pthread_join(ttid, NULL); //making a parent to wait for the child
    }

    return 0;
}
