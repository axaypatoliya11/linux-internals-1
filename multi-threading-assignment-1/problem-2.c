// 2.Write a program where a structure of information passed to pthread task function, and
// display structure of information.

#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t ttid1, ttid2, ttid3;

struct my_struc{
    int s;
};


void * threadWithAttr(void *arg){
    struct my_struc *ms;
    ms = (struct my_struc *) arg;
    printf("newly created thread is executing(inside thread function)\n");
    printf("structure message(inside thread function): %d\n", ms->s);
    return NULL;
}

int main(){
    struct my_struc ms1;
    ms1.s = 10;
    int ret3 = pthread_create(&ttid3, NULL, threadWithAttr, (void *)&ms1);

    if(ret3){
        printf("failure to create a thread\n");
    } else{
        printf("successfully created a thread\n");
        pthread_join(ttid3, NULL); 
    }

    return 0;
}