

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