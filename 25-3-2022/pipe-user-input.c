#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
    int p[2];

    pipe(p);
    printf("read end of pipe = %d\t write end of pipe = %d\n", p[0], p[1]);
    if(fork()){
        // parent
        char s[20];
        printf("in parent enter data...\n");
        scanf("%s", s); //wait user enter "15 + 1"
        write(p[1], s, strlen(s)+1);
    } else{
        // child
        char buf[20];
        printf("in child...\n");
        read(p[0], buf, sizeof(buf));
        printf("child pro printing..Data. of the parent process..%s\n", buf);
    }

    return 0;
}