#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

static void signal_handler(int signo){
    if(signo == SIGINT){
        printf("caught SIGINT\n");
    } else if(signo == SIGALRM){
        printf("caught SIGALRM\n");
    } else{
        printf("caught SIGABRT\n");

        // this should never happen
        fprintf(stderr, "unexpected signal\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);

}

int main(){
    if(signal(SIGINT, signal_handler)==SIG_ERR){
        fprintf(stderr, "cannot handle SIGINT\n");
        exit(EXIT_FAILURE);
    }


    if(signal(SIGALRM, signal_handler)==SIG_ERR){
        fprintf(stderr, "cannot handle SIGTERM\n");
        exit(EXIT_FAILURE);
    }
    alarm(4);

    if(signal(SIGABRT, SIG_IGN)==SIG_ERR){
        fprintf(stderr, "cannot reset SIGPROF\n");
        exit(EXIT_FAILURE);
    }
    
    // abort(); //when this will not be commented then this will executes first
    if(signal(SIGABRT, SIG_IGN)==SIG_ERR){
        fprintf(stderr, "cannot ignore SIGPROF\n");
        exit(EXIT_FAILURE);
    }

    for(;;){
        pause();
    }



    return 0;
}