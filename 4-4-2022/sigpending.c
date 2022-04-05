// this program will tell us that which signal is blocked

#include<stdio.h>
#include<signal.h>

void check_pending_signals(sigset_t s){
    int i, res;
    // sigprocmask(SIG_BLOCK, NULL, &s); //first param is not considered
    for(int i=1; i<5; i++){
        res = sigismember(&s, i);
        if(res){
            printf("signal %d is pending\n", i);
        } else{
            printf("signal %d is not pending\n", i);
        }
    }
}

int main(){
    sigset_t s_set, s;
    sigemptyset(&s_set);
    sigaddset(&s_set, 2);
    sigaddset(&s_set, 4);
    sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
    printf("send me signal one and see the effect now\n");
    getchar();
    getchar();
    sigpending(&s); //returns the signals which are pending in the process
    check_pending_signals(s);
    getchar();
    sigprocmask(SIG_UNBLOCK, &s_set, NULL);
    printf("now signals are unblocked\n");
    while(1);


    return 0;
}