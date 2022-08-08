#include<stdio.h>
#include<stdlib.h>

int count = 0;

void search(int arr[], int key, int first, int last){
    if (first <= last){
        ++count;
        int mid = (first + last)/2;

        if (arr[mid] == key)
            return;
        else if ( arr[mid] > key )
            return search(arr, key, first, mid - 1);
        else
            return search(arr, key, mid + 1, last);
    }
}

void main(){
    FILE *a, *b, *w;
    system("rm worst.txt; rm best.txt; rm avg.txt");

    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(int n = 10; n<=100; n+=10){
        int arr[n];
        for(int i = 0; i<n; ++i)
            arr[i] = i;

        // best case
        int key = arr[n/2];
        search(arr, key, 0, n);
        fprintf(b, "%d  %d\n", n, count);
        count = 0;

        // avg case
        key = arr[n/4];
        search(arr, key, 0, n);
        fprintf(a, "%d  %d\n", n, count);
        count = 0;

        // worst case
        key = n+1;
        search(arr, key, 0, n);
        fprintf(w, "%d  %d\n", n, count);
        count = 0;
    }
    fclose(a);  fclose(w);  fclose(b);
    system("gnuplot -p -c plot.txt");
}