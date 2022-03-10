
#include<stdio.h>
#include<stdlib.h>

void callBack1(){
    printf("callback 1\n");
}
void callBack2(){
    printf("callback 2\n");
}
void callBack3(){
    printf("callback 3\n");
}

int main(){
    printf("registering callback1\n");
    atexit(callBack1);
    printf("registering callback2\n");
    atexit(callBack2);
    printf("registering callback3\n");
    atexit(callBack3);
    printf("exit() main exiting now...\n");
    exit(0); //_exit() is not calling the functions which are previously registered using atexit function
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    int pid, fd;

    pid = fork();
    if(pid==0){
        // run this as s child process
        fd = open("linux400.txt", O_CREAT | O_RDWR, 777);
        char to_write[] = "this lines will be added to file. this one is also be added";
        int leng = strlen(to_write);
        char to_read[leng];
        int i;
        if (fd>0){
            if((i = write(fd, to_write, leng)) < 0){
                perror("error occured while writing to a file");
            }
        }
        read(fd, to_read, leng);
    } else{
        // run this as a parent process
        wait(0);
        printf("parent process\n");
    }
    return 0;
}