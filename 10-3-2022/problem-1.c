// write a program such that parent process create two child processes
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    int pid;

    pid = fork();
    if(pid!=0){
        // run this as s parent process
        printf("this is a parent process\n");
        printf("parent Process pid = %d\n", getpid());
        printf("child Parent's parent Process pid = %d\n", getppid());
        fork();
        fork();
    }  else{
        // run this as s child process
        printf("this is a child process\n");
        printf("child Process pid = %d\n", getpid());
        printf("child Parent's parent Process pid = %d\n", getppid());
    }
    while(1);
    


    return 0;
}