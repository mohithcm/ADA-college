#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void main(){
    int n, key, mid , start, end;
    int *arr;
    srand(time(0));

    printf("Enter the size of array>> ");
    scanf("%d", &n);

    arr = (int *)calloc(n,sizeof(int));

    for (int i = 0; i<n; i++){
        *(arr+i) = rand()%100;
        printf("%d  ", *(arr+i));
    }

    printf("\nEnter key>> ");
    scanf("%d", &key);
    start = 0;
    end = n-1;
    while(start<=end){
        mid = (start+end)/2;
        if (*(arr+mid)==key){
            printf("Key found");
            exit(0);
        }
        else if (key>*(arr+mid))
            start = mid+1;
        else
            end = mid -1;
    }
    printf("Key not found");
}