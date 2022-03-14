// pthread_join returns value
// we can perform threading operations using posix
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

pthread_t ttid;

static void * thread1(void *arg){
    char *s = (char *)arg;
    printf("newly created thread is executing-1\n");
    printf("%s\n", s);
    sleep(5);
    return (void*) strlen(s); //here (void*) means = void* thread_func_returned_value;
}

int main(int argc, char *argv[]){
    void* thread_func_returned_value;
    int ret = pthread_create(&ttid, NULL, thread1, "Hello world!");

    printf("message from the main\n");

    if(ret){
        printf("thread-1 is not created\n");
    } else{
        printf("thread-1 is created\n");
        // sleep(2);
        sleep(3);
        // pthread_join(ttid, NULL); //making a parent to wait for the child
        pthread_join(ttid, &thread_func_returned_value);
        printf("\n\n%d\n\n", (long)thread_func_returned_value);
    }

    return 0;
}
