#include<stdio.h>
#include<signal.h>

void sighand(int signum){
    if(signum == SIGINT){ //checking that only ctrl+c is pressed
        printf("you just pressed ctrl+c : %d\n", signum);
    }
}

int main(){
    signal(SIGINT, sighand);
    alarm(5);
    while(1){};


    return 0;
}