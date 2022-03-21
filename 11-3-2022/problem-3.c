#include<stdio.h>
#include<unistd.h>

int main(){
    printf("I'm going to display a process tree\n");
    // int ret = execl("/usr/bin/vim", "vim","info1.txt", 0);
    int ret = execl("/usr/bin/pstree", "pstree", 0, 0);
    if(ret == -1){
        printf("execl returned error %d\n", ret);
    }
    return 0;
}