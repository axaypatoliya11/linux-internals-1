// 5.Write a program that implements threads synchronization using pthread spinlock
// techniques.

// we can perform threading operations using posix
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<semaphore.h>

static pthread_spinlock_t spinlock;
volatile int lock_s; //using volatile we can change the lock_s value aytime inbetween

void *spinLockThread(void *i){
    int rc;
    int count=0;

    printf("entered thread %d, getting spin lock\n", (int *)i);

    printf("%d thread complete\n", (int *)i);
    return NULL;
}

int main(){
    int rc=0;
    pthread_t thread;

    if(pthread_spin_init(&lock_s, PTHREAD_PROCESS_PRIVATE)!=0){
        perror("init");
    }

    printf("getting the spin lock\n");
    rc = pthread_spin_lock(&lock_s);

    printf("creating the spin lock\n");

    rc = pthread_create(&thread, NULL, spinLockThread, (int *)1);

    printf("hold the lock for 5 secs...\n");
    sleep(5);

    printf("unlocking the lock\n");
    rc = pthread_spin_unlock(&lock_s);

    if(rc==0){
        printf("\nunlock operation successful\n");
    } else{
        printf("\nunlock operation unsuccessful\n");
    }

    printf("main function, wait for the thread to end...\n");
    rc = pthread_join(thread, NULL);
    printf("main function executed\n");

    return 0;
}