// run the fifoserver.c file first(open 2 saperate terminals for this)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
    printf("client process writing\n");
    char clientmsg[] = " Linux System Kernel Programming";

    // open fifo for write
    int fd = open("cli_ser_fifo", O_WRONLY);
    if(fd == -1){
        perror("cannot open fifo\n");
        return EXIT_FAILURE;
    }

    write(fd, clientmsg, strlen(clientmsg));

    close(fd);

    return 0;

    return 0;
}