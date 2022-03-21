#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int fd;
    fd = open("/home/axay/LINUX-INTERNALS/10-3-2022/prob2", O_RDONLY, 777);
    printf("file descriptor of a open system call is %d\n", fd);
    return 0;
}