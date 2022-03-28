#include<pthread.h>
#include<stdio.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *onlyOnce(){ //executes only once for first method
    printf("I will execute only once\n");
}

void *mythread(void *i){
    printf("I'm in mythread: %d\n", (int *)i);
    pthread_once(&once, (void *)onlyOnce);
    printf("Exit from mythread: %d\n", (int *)i);
}

int main(){
    pthread_t thread, thread1, thread2;
    pthread_create(&thread, NULL, mythread, (void *)1);

    pthread_create(&thread1, NULL, mythread, (void *)2);

    pthread_create(&thread2, NULL, mythread, (void *)3);

    pthread_exit(NULL);

    return 0;
}