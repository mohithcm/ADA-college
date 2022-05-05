#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int search(int arr[], int key, int size){
    int start = 0, end = size -1, mid , count = 0;

    while(start<=end){
        mid = (start+end)/2;
        count +=1;
        if (arr[mid] ==  key)
            return count;
        else if (arr[mid]>key)
            end = mid -1;
        else
            start = mid + 1;
    }
    return count;
}

void main(){
    FILE *fp, *b, *w, *a;
    int arr[100], key;
    
    // Deleles previously generated files
    system("rm Rand.txt");
    system("rm Binary_B.txt");
    system("rm Binary_A.txt");
    system("rm Binary_W.txt");

    fp = fopen("Rand.txt", "a");
    b = fopen("Binary_B.txt", "a");
    a = fopen("Binary_A.txt", "a");
    w = fopen("Binary_W.txt", "a");
    fprintf(fp, "Random Number Generated and Key of array>>\n");

    for (int i = 10; i<=100; i+=10){
        srand(time(0));
        for (int j = 0; j<i; j+=1)
            arr[j]= (j==0)?rand()%100 : arr[j-1]+rand()%100;

        // Best case
        key = arr[(i-1)/2];
        fprintf(b, "%d  %d\n", i, search(arr, key, i));

        // Average Case
        key = arr[i/4];
        fprintf(a, "%d  %d\n", i, search(arr, key, i));

        // Worst Case
        key = arr[0] = 0;
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