//execute mul_msg_queue_write.c first then execute this one

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<fcntl.h>
#include<string.h>

int main(){
    int qid;
    struct msqid_ds buf;

    qid = msgget(32, IPC_CREAT|0664);

    printf("qid = %d\n", qid);
    msgctl(qid, IPC_STAT, &buf);

    printf("here are the details of the queue\n");
    printf("no of msg's in q = %hi\n", buf.msg_qnum);
    printf("max no of bytes in q = %hi\n", buf.msg_qbytes); //msg_qbytes

    return 0;
}