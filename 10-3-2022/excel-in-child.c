#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    pid_t pid;
    int option, set;

    while(1){
        scanf("enter 1 to execute 'ls' and 0 to exit: ");
        scanf("%d", &option);
        if(!option){
            exit(0);
        }
        printf("\n");
        if(fork()==0){
            // run this as s child process
            printf("this is a child process\n");
            execl("/bin/ls", "ls", 0);
            exit(0);
        }

    return 0;
}