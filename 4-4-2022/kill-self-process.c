// kill signal sends signal to process(kills the process)
// kill will takes the 2 args, 1)pid of the process which we want to kill. 2)signal number
// program to kill the self process
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

void sig_handler(int signum){
    printf("inside handler function\n");
}

int main(){
    pid_t pid;
    signal(SIGUSR1, sig_handler); //register signal handler
    printf("inside main function\n");
    pid = getpid(); //process ID itself
    kill(pid, SIGUSR1); //send SIGUSR1 to itself
    printf("inside main function\n");
}

