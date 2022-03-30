// execute mul_msg_queue_write.c file first

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<fcntl.h>
#include<string.h>

typedef struct{
    long msgtype;
    char buffer[100];
}msg;

int main(){
    int qid;
    int i;
    msg m1, m2;

    qid = msgget(32, IPC_CREAT|0644);


    i = msgrcv(qid, &m1, sizeof(msg), 10, 0);
    printf("value of buffer1: ");
    for(int i=0; i<100; i++){
        printf("%c", m1.buffer[i]);
    }

    i = msgrcv(qid, &m2, sizeof(msg), 20, 0); //m2 is pointing to the empty structure
    printf("\nvalue of buffer2: ");
    for(int i=0; i<100; i++){
        printf("%c", m2.buffer[i]);
    }
    printf("\n");

    return 0;
}