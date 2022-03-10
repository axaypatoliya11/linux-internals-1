#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void){
    int pid1, status;
    pid1 = fork();

    // if(pid1==0){
    //     sleep(5);
    //     printf("I'm a child with the delay od 5 sec and my child process pid = %d\n", getpid());
    // } else{
        int pid2;
        if(pid1!=0){
            printf("i'm parent process, pid = %d\n", waitpid(pid1, &status, 0));
            // sleep(2);
            pid2 = wait(0);
            printf("parent saying.. child %d exited/terminated normally\n", pid2);
            printf("I'm parent process, pid = %d\n", getpid());
        } 
    // }

    return 0;
}