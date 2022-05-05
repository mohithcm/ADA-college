#include<stdio.h>
#include<stdlib.h>

void main(){
    int a, b, min = 0, temp, count = 0;
    printf("Enter the 2 non negative integers>> ");
    scanf("%d%d", &a, &b);

    min = (a<b)?a:b;
    while(min != 1){
        count += 1;
        temp = a%min;
        if (temp ==0){
            temp = b%min;
            if (temp == 0){
                break;
            }
        }
        min--;
    }

    printf("GCD is >> %d\n", min);
    printf("Count >> %d", count);
}