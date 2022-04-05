#include<stdio.h>
#include<signal.h>

void sighand(int no){
    printf("I am in sighandler\n");
}

int main(){
    sigset_t s_set;
    signal(2, sighand); //run the function sighand on pressing of ctrl+c.
    sigemptyset(&s_set);
    sigaddset(&s_set, 2);
    perror("sig2");
    sigaddset(&s_set, 4);
    perror("sig4");
    sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
    perror("sigmask");
    printf("send me signal one and see the effect now\n");
    getchar();
    getchar();
    sigprocmask(SIG_UNBLOCK, &s_set, NULL);
    printf("now signals are unblocked\n");
    while(1);

    return 0;
}