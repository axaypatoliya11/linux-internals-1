#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

pthread_t ttid, ttid1;
int fd, ret, ret1;

void * thread1(void *arg){
    printf("newly created thread is executing-1\n");
    char * str, buff[100];
    int n, pid;
    str = (char *)arg;
    pid = getpid();
    printf("%s: \t started now: \t for process %d \n\n", str, pid);

    do{
        n = read(fd, buff,100);
        printf("%s: \t read: \t %d \n\n", str, pid);
        printf("\n-----------------------\n");
        write(1, buff, n);
        printf("\n-----------------------\n");
        sleep(3);
    } while(n);

    printf("%s: \t finished: \t for process %d \n\n", str, pid);
}

void * thread2(void *arg){
    printf("newly created thread is executing-1\n");
    char * str, buff[100];
    int n, pid;
    str = (char *)arg;
    pid = getpid();
    printf("%s: \t started now: \t for process %d \n\n", str, pid);

    do{
        n = read(fd, buff,100);
        printf("%s: \t read: \t %d \n\n", str, pid);
        printf("\n-----------------------\n");
        write(1, buff, n);
        printf("\n-----------------------\n");
        sleep(3);
    } while(n);

    printf("%s: \t finished: \t for process %d \n\n", str, pid);
}

int main(){
    // open file
    fd = open("/etc/passwd", O_RDONLY);
    printf("file openend with id: %d\n", fd); //FD=3 returned kernel

    // creating threads
    int ret = pthread_create(&ttid, NULL, thread1, "THREAD-1");
    int ret1 = pthread_create(&ttid1, NULL, thread2, "THREAD-2");

    pthread_join(ttid, NULL);
    pthread_join(ttid1, NULL);

    return 0;
}