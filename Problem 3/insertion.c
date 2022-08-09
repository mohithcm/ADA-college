#include<stdio.h>
#include<stdlib.h>

int sort(int arr[], int n, int isBest){
    int count = 0, temp, j;

    for(int i = 1; i<n; ++i){
        j = i-1;
        temp = arr[i];

        if ( isBest == 1 ) ++count;

        while ( j>-1 && arr[j]>temp){
            ++count;
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = temp;
    }
    return count;
}

void main(){
    FILE *a, *b, *w;
    system("rm best.txt;    rm worst.txt;   rm avg.txt");
    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(int n = 10; n<=100; n+=10){
        int arr[n];

        // best case
        for(int i = 0; i<n; ++i)
            arr[i] = i;
        fprintf(b, "%d  %d\n", n, sort(arr, n, 1));

        // worst case
        for(int i = 0; i<n; ++i)
            arr[i] = n-i;
        fprintf(w, "%d  %d\n", n, sort(arr, n, 0));

        // avg case
        for(int i = 0; i<n; ++i)
            arr[i] = rand()%100;
        fprintf(a, "%d  %d\n", n, sort(arr, n, 0));
    }
    fclose(a);  fclose(b);  fclose(w);
    system("gnuplot -p -c plot.txt");
}