#include<stdio.h>
#include<stdlib.h>

void main(){
    int a,r, b;
    printf("Enter 2 Non - negative integers>> ");
    scanf("%d%d", &a, &b);

    while(r != 0){
        r = a%b;
        a = b;
        b=r;
    }

    printf("GCD >> %d", a);
}