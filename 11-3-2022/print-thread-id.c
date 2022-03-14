// we can perform threading operations using posix
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t ttid;

static void * thread1(void *arg){
    char *s = (char *)arg;
    pid_t pid = getpid(); //process id
    pthread_t tid = pthread_self(); //thread id
    printf("newly created thread is executing-1\nprocess id = %u\nthread id = %u\n", pid, tid);
    printf("%s\n", s);
    return NULL;
}

int main(int argc, char *argv[]){
    int ret = pthread_create(&ttid, NULL, thread1, "this is an argument");

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
