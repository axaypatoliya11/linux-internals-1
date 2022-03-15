#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

int main(){

    int ret, ret1, cnt=0, cnt1=0;
    errno = 0;

    ret = nice(1); //nice() used to assign nice values to a particular(incr/decr the priority of a process)
    ret1 = nice(2);

    if(ret == -1 && errno != 0){
        perror("nice");
    } else{
        printf("nice value is low %d\n", ret);
    }

    while(1){
        printf("Process with nice value %d count = %d\n", ret, cnt);
        for(int i=0; i<10000000; i++){
            cnt++;
        }
    }

    while(1){
        printf("Process with nice value %d count = %d\n", ret1, cnt1);
        for(int i=0; i<10000000; i++){
            cnt1++;
        }
    }

    return 0;

}