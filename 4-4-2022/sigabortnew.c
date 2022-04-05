#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void abort_handler(int i){
    fprintf(stderr, "caought SIGABRT, existing application\n");
    exit(1);
}

int main(){
    int x;
    if((x=signal(SIGABRT, abort_handler))==SIG_ERR){ //sinal() returns 0 on successfull execution 
        fprintf(stderr, "couldn't set signal handler\n");
        exit(1);
    }
    printf("%d", x);
    abort();
    exit(0);

    return 0;
}