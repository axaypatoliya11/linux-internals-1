// own custom function to copy the string(just same as memcpy)

#include<stdio.h>
#include<string.h>

void my_mem_cpy(char * src, char * dest, size_t nbytes){
    for(int i=0; i<nbytes; i++){
        *dest = *src;
        dest++;
        src++;
    }
}


int main(){
    
    char buf1[] = "this is a first string";
    printf("%d\n", strlen(buf1));
    char buf2[strlen(buf1)];


    my_mem_cpy(buf1, buf2, strlen(buf1));
    printf("%s\n", buf2);

    return 0;
}