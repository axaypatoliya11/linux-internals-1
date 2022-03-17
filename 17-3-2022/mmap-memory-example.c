#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(){
    char *c;
    
    c = mmap(0, 50, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0); //msg success
    perror("mmap");

    strcpy(c, "linuxkernel"); //kernel region in U.s
    printf("%s\n", c);

    // deallocate all resources
    munmap(c, 50); //malloc after free

    return 0;
}

// first arg is0 that means: requesting the kernel please map size of region(file/device/random) into free PAS
// recommended technique
// not providing own addr