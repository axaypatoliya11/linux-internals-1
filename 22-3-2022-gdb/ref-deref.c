// derefferencing

#include<stdio.h>
#include<stdlib.h>

int main(){
    int *i;
    float *f;
    char *c;

    int k = 5;
    i = &k;

    float h = 2.30;
    f = &h;

    char y = 'S';
    c = &y;

    printf("value of i = %d\n", i);
    printf("value of f = %d\n", f);
    printf("value of c = %d\n", c);

    i = NULL;
    f = NULL;
    c = NULL;

    printf("after dereferencing value of i = %d\n", i);
    printf("after dereferencing value of f = %d\n", f);
    printf("after dereferencing value of c = %d\n", c);

    


    return 0;
}