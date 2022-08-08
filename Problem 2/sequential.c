#include<stdio.h>
#include<stdlib.h>

int search(int arr[], int n, int key){
    int count = 0;
    for(int i = 0; i<n; ++i){
        ++count;   
        if (arr[i] == key)  
            return count;
    }
    return count;
}

void main(){
    FILE *a, *b, *w;
    system("rm best.txt");
    system("rm worst.txt");
    system("rm avg.txt");

    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(int n = 10; n<=100; n+=10){
        int * arr = (int *)calloc(sizeof(int), n);

        // best case
        int key = 0;
        fprintf(b, "%d  %d\n", n, search(arr, n, key));

        // worst case
        key = 1;
        fprintf(w, "%d  %d\n", n, search(arr, n, key));

        // avg case
        key = arr[n/2] = 1;
        fprintf(a, "%d  %d\n", n, search(arr, n, key));
    }
    fclose(w);  fclose(a);  fclose(b);
    system("gnuplot -p -c plot.txt");
}