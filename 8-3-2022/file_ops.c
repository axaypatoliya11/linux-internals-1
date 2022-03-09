#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fd1, fd2, fd3, fd4;

    // fd1 = creat("linux100.txt", 777);
    // fd2 = creat("linux200.txt", 777);
    // fd3 = creat("linux300.txt", 777);
    // fd4 = creat("linux400.txt", 777);

    // range of the file descriptors is 0 to 1023(we can open these much file in a single program)

    fd4 = open("linux400.txt", O_CREAT | O_RDWR, 777); //to read the file(in readonly mode)

    char to_write[] = "this lines will be added to file. this one is also be added";
    int leng = strlen(to_write);
    char to_read[leng];
    int i;
    if (fd4>0) //fd4 returns -1 if file realted to that FD does not exists
    {
        if((i = write(fd4, to_write, leng)) < 0){
            perror("error occured while writing to a file");
            // exit(1);
        }
    }
    
    lseek(fd4, 0, SEEK_SET); //once data written to the file from buffer, pointer will be at the end of the file so we have to reset the buffer pointer to the starting 
    read(fd4, to_read, leng);
    printf("read buffer value is: %s\n", to_read);

    // printf("file descriptor for file1 is: %d", fd1);
    // printf("\nfile descriptor for file2 is: %d", fd2);
    // printf("\nfile descriptor for file3 is: %d\n", fd3);

    // int close(int fd1);
    // int close(int fd2);
    // int close(int fd3);
    int close(int fd4);

    return 0;
}
