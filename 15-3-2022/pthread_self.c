#include <stdio.h>
#include <pthread.h>
#include <string.h>

struct my_thread{
    int thread_id;
    char msg[100];
};

void *PrintHello(void *thereadobj){
    pthread_t thread_ID;
    struct my_thread *t1;
    t1 = (struct my_thread *) thereadobj;
    thread_ID = pthread_self();
    printf("Thread ID: %u\n", thread_ID);
    printf("%d Thread Message : %s\n", t1->thread_id, t1->msg);
}

int main(){
    pthread_t thread2, thread_ID;
    int rc;
    struct my_thread t2;

    t2.thread_id = 2;
    strcpy(t2.msg, "I'm second thread\n");

    thread_ID = pthread_self();

    printf("MAIN Thread ID: %u\n", thread_ID);

    pthread_create(&thread2, NULL, PrintHello, (void *)&t2);

    printf("exit from main thread\n");

    pthread_exit(NULL);

    // return 0;
}