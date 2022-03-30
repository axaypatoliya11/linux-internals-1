// 1.Write a pthread application where main task terminated but pending pthreads task still
// execute.

#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t ttid1, ttid2, ttid3;

struct my_struc{
    int s;
};

void * thread1(void *arg){
    printf("newly created thread1 is executing\n");
    return NULL;
}

void * thread2(void *arg){
    char *s = (char *)arg;
    printf("newly created thread2 is executing\n");
    printf("%s\n", s);
    return NULL;
}

void * thread3(void *arg){
    struct my_struc *mystru;
    mystru = (struct my_struc *) arg;
    printf("newly created thread3 is executing-1\n");
    printf("structure message: %d\n", mystru->s);
    return NULL;
}

int main(){
    struct my_struc stru;
    stru.s = 10;
    int ret1 = pthread_create(&ttid1, NULL, thread1, NULL);
    int ret2 = pthread_create(&ttid2, NULL, thread2, "this is passed to thread function");
    int ret3 = pthread_create(&ttid3, NULL, thread3, (void *)&stru);

    if(ret1){
        printf("thread1 is not created\n");
    } else{
        printf("thread1 is created\n");
    }

    if(ret2){
        printf("thread2 is not created\n");
    } else{
        printf("thread2 is created\n");
    }

    if(ret3){
        printf("thread3 is not created\n");
    } else{
        printf("thread3 is created\n");
    }
    pthread_exit(NULL);

    printf("if this executes then there's error in code!\n"); //this will not executes
    return 0;
}