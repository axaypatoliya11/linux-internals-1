// kill signal sends signal to process(kills the process)
// kill will takes the 2 args, 1)pid of the process which we want to kill. 2)signal number

#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    int sig_no;
    printf("enter the pid of the process for which the signal need to be sent: ");
    scanf("%d", &pid);
    printf("enter the signal thay need to be sent: ");
    scanf("%d", &sig_no);
    kill(pid, sig_no);
    perror("sig_res:");
}

