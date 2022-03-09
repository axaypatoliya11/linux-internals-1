#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int fd1, fd2, fd3;
    fd1 = open("fd1.txt", O_WRONLY|O_TRUNC);
    fd2 = open("fd2.txt", O_WRONLY|O_TRUNC);
    printf("fd1=%d\n", fd1);
    printf("fd2=%d\n", fd2);
    fd3 = dup2(fd1, 11); //generating descriptor our own required value...11

    printf("fd3_dup of fd1=%d\n", fd3);

    close(fd1);
    close(fd2);
    close(fd3);
}