#include<stdio.h>
#include<stdlib.h>

int sort(int arr[], int n){
    int flag = 1, count = 0;
    for(int i = 0; i<n-1; ++i){
        for(int j = 0; j<n-1-j; ++j){
            if ( arr[j] > arr[j+1] ){
                ++count;
                int t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
                flag = 0;
            }
        }
        if (flag == 1)
            return count;
    }
    return count;
}

void main(){
    FILE *a, *w, *b;
    system("rm best.txt; rm worst.txt; rm avg.txt");

    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(int n = 0; n<=100; n+=10){
        int * arr = (int *)calloc(sizeof(int), n);

        // best case
        fprintf(b, "%d  %d\n", n, sort(arr, n));

        // worst case
        for (int i = 0; i<n; ++i)
            arr[i] = n-i;
        fprintf(w, "%d  %d\n", n, sort(arr, n));

        // avg case
        for (int i = 0; i<n; ++i)
            arr[i] = rand()%100;
        fprintf(a, "%d  %d\n", n, sort(arr, n));    
    }
    fclose(a);  fclose(b);  fclose(w);
    system("gnuplot -p -c plot.txt");
}