#include<stdio.h>
#include<string.h>

int main(){
    char buf1[10], buf2[10];
    int ret;

    memcpy(buf1, "madam", 5); //madam---97--108
    memcpy(buf2, "mad at you", 5); //mad--65--76

    ret = memcmp(buf1, buf2, 5);

    if(ret>0){
        printf("buf1 is greater than buf2\n");
    } else if(ret<0){
        printf("buf1 is less than buf2\n");
    } else{
        printf("buf1 is equal to buf2\n");
    }

    // ret = -1: buf2 > buf1
    // ret = 0: buf1 = buf2
    // ret =  1: buf2 < buf1

    return 0;
}