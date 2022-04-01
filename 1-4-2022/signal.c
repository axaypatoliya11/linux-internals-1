#include<stdio.h>
#include<signal.h>

void sighand(int signum){ //this function will take int as an arg and return type will be void
    printf("interrupt signal rec'd...but no termination on ctrl+c\n");
}

int main(){
    // signal(SIGINT, SIG_DFL); //when evenr ctrl+c pressed on a terminal default action will called
    signal(SIGINT, sighand); //SIGINT will work like ctrl+c. when evenr ctrl+c pressed on a terminal sighand function will called
    for(int i=0; ; i++){
        printf("%d\n", i);
        sleep(1);
    }


    return 0;
}