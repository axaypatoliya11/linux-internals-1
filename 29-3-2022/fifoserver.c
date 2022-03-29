// run this file first

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
    printf("server - listening\n");

    // create fifo
    int code = mkfifo("cli_ser_fifo", 0764);
    if(code == -1){
        perror("mkfifo returned an error - file may already exist\n"); //this will returns the error to standard error device
    }

    // open and read
    int fd = open("cli_ser_fifo", O_RDONLY);
    if(fd == -1){
        perror("cannot open file for read only\n");
        return 0;
    }
    printf("FIFO open\n");

    // read string (upto 100 characters)
    char serverrcv[100];
    memset(serverrcv, 0, 100); //initializing characters with the 0

    int res;
    char Len;

    while(1){
        res = read(fd, &Len, 1);
        if(res==0){
            break;
        }
        read(fd, serverrcv, Len);
        printf("server recieved: %s\n", serverrcv);
    }

    printf("EOF Reached\n");
    close(fd);
    printf("FIFO closed\n");

    return 0;
}