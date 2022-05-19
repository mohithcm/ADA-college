#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("Enter the number of elements>> ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements>> ");
    for(int i =0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Before Sorting>> ");
    for(int i = 0; i<n; i++)
        printf("%d  ", arr[i]);

    for(int i = 0; i<n-1; i++){
        int min = arr[i], k = i, flag = 0;

        for(int j = i+1; j<n; j++){
            if (min> arr[j]){
                min = arr[j];  // Selects minimum
                k = j;  // Selects index of minimum
                flag = 1;
            }
        }

        if (k != i){
            int temp = arr[k];
            arr[k]= arr[i];
            arr[i]=temp;
        }

        if (flag == 0)
            break;
    }

    printf("\n\nAfter Sorting>> ");
    for(int i = 0; i<n; i++)
        printf("%d  ", arr[i]);
}