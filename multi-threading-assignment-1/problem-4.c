// 4.write a program, which get and set pthread scheduling policy and priority.

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void* Proc(void * param){
    sleep(3);
    printf("inside thread function\n");
    return 0;
}

int main(int argc, char *argv[]){
    pthread_attr_t Attr;
    pthread_t Id;
    int err, info;

    pthread_attr_init(&Attr);
    pthread_attr_getinheritsched(&Attr, &info);

    // before setting the privacy and policy(default)
    printf("value of info: %d\n", info); //0 on inherit

    if(info==0){
        printf("INHERIT\n");
    } else{
        printf("EXPLICIT\n");
    }

    // after setting the privacy and policy(modified)
    pthread_attr_setinheritsched(&Attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_getinheritsched(&Attr, &info);

    printf("value of info: %d\n", info); //1 on explicit
    
    if(info==0){
        printf("INHERIT\n");
    } else{
        printf("EXPLICIT\n");
    }


    pthread_create(&Id, &Attr, Proc, NULL);
    return 0;

}