// 1.Test whether the process(exec() system call) that replaces old program data , will inherit the fds or not.

#include<stdio.h>
#include<unistd.h>

int main(){
    printf("I'm going to print the process tree on terminal\n");
    int ret = execl("/home/axay/LINUX-INTERNALS/10-3-2022/prob3", "", 0);
    if(ret == -1){
        printf("execl returned error %d\n", ret);
    }
    return 0;
}