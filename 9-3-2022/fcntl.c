// fcntl system call is used to control the attributes or the peroperties of the file
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int fd1, fd2, fd3;
    fd1 = open("fd1.txt", O_WRONLY|O_TRUNC, 0777); //3

    fd3 = fcntl(fd1, F_DUPFD); //create a duplicate(copy) of the file(just as we can do using dup and dup2) [same as dup2]
    fd3 = fcntl(fd1, F_DUPFD, 99); //this will creates the copy of a file with the defined file descriptor 99
    printf("duplicate value of fd1 is fd3 = %d\n", fd3);

    close(fd1);
    close(fd3);
}