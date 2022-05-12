#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Bubble Sort Function
int bubble(int arr[], int key, int size){
    int count = 0, flag = 0;
    for (int i=0; i<size-1; i++){
        for (int j=0; j<size-1-i; j++){
            if (arr[j] > arr[j+1]){
                count+=1;
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (flag == 0)
            return 0;
    }
    return count;
}

void main(){
    FILE *rb, *rw, *ra, *b, *w, *a;
    int arr[1000], count = 0, key;
    
    // Deleles previously generated files
    system("rm Rand_B.txt");
    system("rm Rand_A.txt");
    system("rm Rand_W.txt");
    system("rm Bubble_B.txt");
    system("rm Bubble_A.txt");
    system("rm Bubble_W.txt");

    ra = fopen("Rand_A.txt", "a");
    rb = fopen("Rand_B.txt", "a");
    rw = fopen("Rand_W.txt", "a");
    b = fopen("Bubble_B.txt", "a");
    a = fopen("Bubble_A.txt", "a");
    w = fopen("Bubble_W.txt", "a");
    fprintf(ra, "Random Number Generated (Average Case) >>\n");
    fprintf(rb, "Random Number Generated (Best Case) >>\n");
    fprintf(rw, "Random Number Generated (Worst Case) >>\n");

    for (int i = 10; i<=1000; i+=10){
        srand(time(0));

        // Worst Case
        for (int j = 0; j<i; j+=1)
            arr[j]= (j==0) ? rand()%10 : arr[j-1] - rand()%10;
        fprintf(w, "%d  %d\n", i, bubble(arr, key, i));

        for (int j = 0; j<i; j++)
            fprintf(rw, "%d  ", arr[j]);

        // Best case
        for (int j = 0; j<i; j+=1)
            arr[j]= (j==0) ? rand()%10 : arr[j-1] + rand()%10;
        fprintf(b, "%d  %d\n", i, bubble(arr, key, i));

        for (int j = 0; j<i; j++)
            fprintf(rb, "%d  ", arr[j]);

        // Average Case
        for (int j=i/2; j<i; j++)
            arr[j] = rand()%10;
        fprintf(a, "%d  %d\n", i, bubble(arr, key, i));

        for (int j = 0; j<i; j++)
            fprintf(ra, "%d  ", arr[j]);
        
        fprintf(ra, "\n\n");
        fprintf(rb, "\n\n");
        fprintf(rw, "\n\n");
    }

    fclose(a);
    fclose(b);
    fclose(w);
    fclose(ra);
    fclose(rb);
    fclose(rw);
}