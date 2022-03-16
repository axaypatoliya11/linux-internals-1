#include<stdio.h>
#include<string.h>

int main(){

    const char str[] = "linuxkernel.com";
    const char ch = '#';

    printf("string before set/initialization is: %s\n", str);

    memset(str, ch, strlen(str)); //finc & array...name itself is address
    printf("string after set is: %s\n", str);

    return 0;
}