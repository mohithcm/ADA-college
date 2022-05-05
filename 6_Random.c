#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    FILE *p;
    system("rm Random.txt");
    p = fopen("Random.txt", "a");
    fprintf(p, "Generated from 6_Random.c\n");
    srand(time(0));
    for (int i =0; i<50; i++){
        fprintf(p, "%d  ", rand()%100);
    }
    fclose(p);
}