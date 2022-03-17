// we are mapping a file region

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(){
    int fd;
    char *c;

    struct stat file_info;

    fd = open("kernel.txt", O_CREAT|O_RDWR, 0777); 
    write(fd, "Linux Kernel Technology", 25);

    fstat(fd, &file_info);
    printf("file size is: %d\n", file_info.st_size);

    c = mmap(0, file_info.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
    perror("mmap");

    printf("%s\n", c);


    // deallocate all the resources
    munmap(c, file_info.st_size);
    close(fd);

    return 0;
}

// mmap is afunctin that maps the kernel memory region or random region into calling function address space