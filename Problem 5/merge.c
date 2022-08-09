#include<stdio.h>
#include<stdlib.h>

int count = 0;

void merge(int arr[], int first, int mid, int last){
    int k = first;
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int a[n1], b[n2];

    for(int i = 0; i<n1; ++i)   
        a[i] = arr[first+i];
    for(int j = 0; j<n2; ++j)   
        b[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    while (i<n1 && j<n2){
        ++count;

        if (a[i] >= b[j])   
            arr[k++] = a[i++];
        else    
            arr[k++] = b[j++];
    }

    while (i<n1)    
        arr[k++] = a[i++];
    while (j<n2)
        arr[k++] = b[j++];
}

void divide(int arr[], int first, int last){
    if ( first < last ){
        int mid = (first + last)/2;
        divide(arr, first, mid);
        divide(arr, mid+1, last);

        merge(arr, first, mid, last);
    }
}

void worst(int arr[], int first, int last){
    if (first < last){
        int mid = (first + last)/2;
        int n1 = mid - first + 1;
        int n2 = last - mid;

        int a[n1], b[n2];
        for(int i = 0; i<n1; ++i)
            a[i] = arr[2*i];
        for(int j = 0; j<n2; ++j)
            b[j] = arr[2*j + 1];

        worst(a, first, mid);
        worst(b, mid + 1, last);

        int i, j;
        for(i = 0; i<n1; ++i)
            arr[i] = a[i];
        for(j = 0; j<n2; ++j) 
            arr[i+j] = b[j];
    }
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
        divide(arr, 0, n-1);
        fprintf(b, "%d  %d\n", n, count);
        count = 0;

        // worst case
        worst(arr, 0, n-1);
        divide(arr, 0, n-1);
        fprintf(w, "%d  %d\n", n, count);
        count = 0;

        // avg case
        for(int i = 0; i<n/2; ++i)
            arr[i] = rand()%100;
        divide(arr, 0, n-1);
        fprintf(a, "%d  %d\n", n, count);
        count = 0;
    }
    fclose(a);  fclose(b);  fclose(w);
    system("gnuplot -p -c plot.txt");
}