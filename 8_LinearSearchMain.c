#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Linear Search Function
int search(int arr[], int key, int size){
    for (int i=0; i<size; i++){
        if (key == arr[i]){
            return i+1;
        }
    }
    return size;
}

void main(){
    FILE *fp, *b, *w, *a;
    int arr[100], count = 0, key;
    system("rm Rand.txt");
    system("rm Linear_B.txt");
    system("rm Linear_A.txt");
    system("rm Linear_W.txt");
    fp = fopen("Rand.txt", "a");
    b = fopen("Linear_B.txt", "a");
    a = fopen("Linear_A.txt", "a");
    w = fopen("Linear_W.txt", "a");
    fprintf(fp, "Random Number Generated and Key of array>>\n");

    for (int i = 10; i<=100; i+=10){
        srand(time(0));
        for (int j = 0; j<i; j+=1)
            arr[j]= rand()%100;

        // Best case
        key = arr[0];
        fprintf(b, "%d  %d\n", i, search(arr, key, i));

        // Average Case
        key = arr[i/2] = 9999;
        fprintf(a, "%d  %d\n", i, search(arr, key, i));

        // Worst Case
        key = 44444;
        fprintf(w, "%d  %d\n", i, search(arr, key, i));

        for (int j = 0; j<i; j++)
            fprintf(fp, "%d  ", arr[j]);
            fprintf(fp, "Key >> %d\n\n", key);
    }

    fclose(a);
    fclose(b);
    fclose(w);
    fclose(fp);
}