#include<stdio.h>
#include<stdlib.h>

int sort(int arr[], int n){
    int count = 0, index, temp;

    for(int i = 0; i<n-1; ++i){
        index = i;

        for(int j = 0; j<n; ++j){
            ++count;
            if ( arr[index] > arr[j] )
                index = j;
        }

        temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
    return count;
}

void main(){
    FILE *a, *w, *b;
    system("rm avg.txt;    rm worst.txt;    rm best.txt");
    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(int n = 10; n<=100; n+=10){
        int arr[n];

        // best case
        for(int i = 0; i<n; ++i)
            arr[i] = i;
        fprintf(b, "%d  %d\n", n, sort(arr, n));

        // worst case
        for(int i = 0; i<n; ++i)
            arr[i] = n-i;
        fprintf(w, "%d  %d\n", n, sort(arr, n));

        // avg case
        for(int i = 0; i<n; ++i)
            arr[i] = rand()%100;
        fprintf(a, "%d  %d\n", n, sort(arr, n));
    }
    fclose(a);  fclose(b);  fclose(w);
    system("gnuplot -p -c plot.txt");
}