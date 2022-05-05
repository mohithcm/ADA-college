#include<stdio.h>
#include<stdlib.h>

void main(){
    int a,r, b, count = 0;
    printf("Enter 2 Non - negative integers>> ");
    scanf("%d%d", &a, &b);

    while(r != 0){
        count+=1;
        r = a%b;
        a = b;
        b=r;
    }

    printf("GCD >> %d\n", a);
    printf("Count >> %d", count);
}