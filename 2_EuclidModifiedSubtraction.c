#include<stdio.h>
#include<stdlib.h>

void main(){
    int a, b, count = 0;
    printf("Enter 2 non-negative integers>> ");
    scanf("%d%d", &a, &b);

    while(b != 0){
        count += 1;
        if(a>b)
            a = a-b;
        else
            b =b -a;
    }
    printf("GCd >> %d\n", a);
    printf("Count >> %d", count);
}