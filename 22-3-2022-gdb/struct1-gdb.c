#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{ //structure defination
    int roll;
    char name[40], gender;
    float height;
}first; //declaring structure

int main(){
    struct student second; //declaring structure
    struct student third = {103, "Hari Prasad", 'M', 5.11}; //declaring and initialising structure variables

    printf("\nRoll\tName\t\t\t\t\tGender\tHeight\n");
    first.roll = 101;
    strcpy(first.name, "Phaneendra Kumar");
    first.gender = 'M';
    first.height = 5.6;

    printf("\n %3d\t%40s\t%c\t%1.2f",first.roll,first.name,first.gender,first.height);
    printf("\n %3d\t%40s\t%c\t%1.2f",third.roll,third.name,third.gender,third.height);
    return 0;
}