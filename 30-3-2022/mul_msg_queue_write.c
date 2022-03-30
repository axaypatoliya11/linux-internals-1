//run this file first
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<fcntl.h>
#include<string.h>

#define KEY 8979

typedef struct{
    long msgtype;
    char buffer[100];
}msg;

int main(){
    int qid;
    int i;
    msg m1, m2;

    qid = msgget(32, IPC_CREAT|0644);

    m1.msgtype = 10;
    for(int i=0; i<100; i++){
        m1.buffer[i] = 'a';
    }

    m2.msgtype = 20;
    for(int i=0; i<100; i++){
        m2.buffer[i] = 'b';
    }

    i = msgsnd(qid, &m1, sizeof(msg), 0);
    printf("retuen value of msgsnd of As = %d\n", i);

    i = msgsnd(qid, &m2, sizeof(msg), 0); //m2 is pointing to the structure with data and message_type
    printf("retuen value of msgsnd of Bs = %d\n", i);

    return 0;
}