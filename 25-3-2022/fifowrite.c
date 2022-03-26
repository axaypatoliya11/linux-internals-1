#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

    char s[20];
    int fd;

    mkfifo("newfifo", 0644); //newfifo is a pipe i.e. a file named pipe create fifo(named pipe)

    perror("mkfifo");

    printf("Before open()...\n");
    fd = open("newfifo", O_WRONLY); //open fifo for write only
    printf("Enter data...\n");
    scanf("%s", s);

    write(fd, s, strlen(s)+1); //std wt(); internally filewrite data to fifo

    return 0;
}