#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("before invoking the fork()\n");
    fork();
    fork();
    fork();
    printf("after invoking the fork()\n");
    return 0;
}