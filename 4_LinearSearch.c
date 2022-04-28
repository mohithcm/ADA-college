#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    int n, key;
    int * arr;
    srand(time(0));

    printf("Enter the size of array>> ");
    scanf("%d", &n);

    arr = (int *)calloc(n,sizeof(int));

    for (int i = 0; i<n; i++){
        *(arr+i) = rand()%100;
        printf("%d  ",*(arr+i));
    }

    printf("\nEnter key>> ");
    scanf("%d", &key);

    for (int i = 0; i<n; i++){
        if (*(arr+i) == key){
            printf("Key found");
            exit(0);
        }
    }
    printf("Key is not found");
}