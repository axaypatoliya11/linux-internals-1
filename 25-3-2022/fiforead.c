#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char s[20];
    int fd;
    mkfifo("newfifo", 0644);
    perror("newfifo");
    printf("before open()\n");
    fd = open("newfifo", O_RDONLY);
    read(fd, s, sizeof(s));
    printf("data:%s\n", s);
    return 0;
}