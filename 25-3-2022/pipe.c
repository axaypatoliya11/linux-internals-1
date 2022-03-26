// shows how pipes can be used

#include<stdio.h>
#include<unistd.h>

int main(){
    int fds[2];
    int res, i;
    char buf1[20] = "aaaaaaaaaaaaaaaaaaaaaaa";
    char buf2[20] = "bbbbbbbbbbbbbbbbbb";
    char buf_to_read[40];

    res = pipe(fds);

    // fds[0] for reading and fds[1] for writing

    if(res==-1){
        perror("pipe");
        exit(1);
    }

    write(fds[1], buf1, 20);
    write(fds[1], buf2, 20);

    read(fds[0], buf_to_read, 40);

    for(int i=0; i<32; i++){
        printf("%c", buf_to_read[i]);
    }
    printf("\n");

    return 0;
}