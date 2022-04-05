#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void printSignalSet(sigset_t *set){
    const int siglist[] = {SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGABRT, SIGFPE, SIGKILL, SIGSEGV};

    const char * sigNames[] = {"SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGABRT", "SIGFPE", "SIGKILL", "SIGSEGV"};

    const int sigLen = 8;

    for(int i=0; i<sigLen; i++){
        int ret = sigismember(set, siglist[i]);
        if(ret == -1){
            perror("sigsmember: ");
            exit(EXIT_FAILURE);
        } else if(ret == 1){
            printf("signal %s=%d is in the set.\n", sigNames[i], siglist[i]);
        } else{
            printf("signal %s=%d is not in the set.\n", sigNames[i], siglist[i]);
        }
    }
}

int main(){
    sigset_t set;

    if(sigprocmask(0, NULL, &set)!=0){
        perror("sigsmember: ");
        exit(EXIT_FAILURE);
    }

    printf("--- initial signal mask for this process: ---\n");
    printSignalSet(&set);


    if(sigaddset(&set, SIGINT)!=0){
        perror("sigprocmask: ");
        exit(EXIT_FAILURE);
    }


    if(sigprocmask(SIG_SETMASK, &set, NULL)!=0){
        perror("sigprocmask: ");
        exit(EXIT_FAILURE);
    }

    printf("--- NEW signal mask for this process: ---\n");
    printSignalSet(&set);


    int secToSleep = 20;
    printf("ctrl+c. Try killing this program with 'kill -kill %d'. Going to sleep form %d seconds.\n", getpid(), secToSleep);
    sleep(secToSleep);
    printf("sleep returned\n");

    printf("removing all signals from mask\n");
    sigfillset(&set);

    sigprocmask(SIG_SETMASK, &set, NULL);

    printSignalSet(&set);

    sleep(1);
    printf("excited normally\n");



    return 0;
}