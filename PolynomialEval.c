#include<stdio.h>
#include<stdlib.h>

int poly(int arr[], int n ,int x){
    double result = arr[0];
    int i , power = 1, count=0;
    for(i=1; i<n; i++){
        power *= x;
        result += arr[i]*power;
        count += 1;
    }
    return count;
}

void main(){
    FILE *fp;
    int i,x, n, *arr;
    system("rm Poly.txt");
    fp = fopen("Poly.txt", "a");

    printf("Enter x >>");
    scanf("%d", &x);

    for (n = 10; n<=100; n+=10){
        arr = (int *)malloc(n*sizeof(int));
        for (i =0; i<n; i++)
            arr[i]= i+1;

        fprintf(fp, "%d  %d\n", n, poly(arr, n, x));
    }
    fclose(fp);
}