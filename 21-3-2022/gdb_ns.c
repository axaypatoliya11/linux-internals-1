#include<stdio.h>
#include<string.h>

void myprint(char *msg){
    if(msg!=NULL){
        printf("message: %s\n", msg);
    }
}

int main(){
    char buff[] = "linux";
    // myprint(buff);
    myprint(NULL);

    return 0;
}