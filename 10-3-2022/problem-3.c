#include<stdio.h>
#include<unistd.h>

int main(){
    printf("I'm going to open a info1.txt from vim\n");
    int ret = execl("/usr/bin/vim", "vim","info1.txt", 0);
    if(ret == -1){
        printf("execl returned error %d\n", ret);
    }
    return 0;
}