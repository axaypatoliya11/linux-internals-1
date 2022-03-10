#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(void){
    pid_t pid1;
    pid1 = fork();

    if(pid1==0){
        sleep(5);
        printf("I'm a child with the delay od 5 sec and my child process pid = %d\n", getpid());
    } else{
        int pid2; //store return value from wait()
        pid2 = wait(0);
        printf("i'm parent process, pid = %d\n", getpid());
        // sleep(2);
        printf("parent saying.. child %d exited/terminated normally\n", pid2);
        printf("I'm parent process, pid = %d\n", getpid());
    }

    return 0;
}