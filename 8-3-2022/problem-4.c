#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fd4;

    fd4 = open("linux400.txt", O_CREAT | O_RDWR, 777); //to read the file(in readonly mode)

    char to_write[] = "this lines will be added to file. this one is also be added";
    int leng = strlen(to_write);
    char to_read[leng];
    int i;
    if (fd4>0) //fd4 returns -1 if file realted to that FD does not exists
    {
        if((i = write(fd4, to_write, leng)) < 0){
            perror("error occured while writing to a file");
        }
    }
    
    lseek(fd4, 0, SEEK_SET); //once data written to the file from buffer, pointer will be at the end of the file so we have to reset the buffer pointer to the starting 
    read(fd4, to_read, leng);
    printf("read buffer value is: %s\n", to_read);

    int close(int fd4);

    return 0;
}
