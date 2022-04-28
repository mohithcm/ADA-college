#include<stdio.h>
#include<stdlib.h>

void main(){
    int a, b;
    printf("Enter 2 non-negative integers>> ");
    scanf("%d%d", &a, &b);

    while(b != 0){
        if(a>b)
            a = a-b;
        else
            b =b -a;
    }
    printf("GCd >> %d", a);
}