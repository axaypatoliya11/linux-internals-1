#include<stdio.h>
#include<unistd.h>

int main(){
    printf("I'm going to open a info1.txt from vim\n");
    int ret = execl("/home/axay/LINUX-INTERNALS/10-3-2022/prob3", "", 0);
    if(ret == -1){
        printf("execl returned error %d\n", ret);
    }
    return 0;
}