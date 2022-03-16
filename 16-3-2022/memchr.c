#include<stdio.h>
#include<string.h>

int main(){

    const char str[] = "linuxkernel.com";
    const char ch = '.';
    char *ret;

    printf("string before chr/scan is: %s\n", str);

    ret = memchr(str, ch, strlen(str)); //finc & array...name itself is address
    printf("string after **%c** set is: %s\n", ch, ret-7); //ret-7 means -> 7 character before the "."(ch)

    return 0;
}