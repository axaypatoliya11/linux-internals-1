#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("my process pid = %d\n", getpid()); //given PIDs of current process
    printf("my process pid = %d\n", getppid()); //given PIDs of parent process
    while(1);
    return 0;
}