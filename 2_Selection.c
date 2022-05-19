#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Selection Sort Function
int selection(int arr[], int size){
    int count = 0, flag , index, temp,min, i, j;

    for(i = 0; i<size-1; i++){
        min = arr[i];
        flag = 0;
        index = i;

        for(j = i+1; j<size; j++){
            count+=1;  // Incrementing count
            if (min > arr[j]){
                flag = 1;
                min = arr[j];
                index = j;     // Finding index of minimum element   
            }
        }

        // Swapping with minimun element
        if (index != i){
            temp = arr[index];  
            arr[index] = arr[i];
            arr[i] = temp;
        }

        if(flag == 0)    // If array becomes sorted
            return count;
    }
    return count;
}

void main(){
    FILE *rb, *rw, *ra, *b, *w, *a;
    int arr[100], count = 0, key;
    
    // Deleles previously generated files
    system("rm Rand_B.txt");
    system("rm Rand_A.txt");
    system("rm Rand_W.txt");
    system("rm Selection_B.txt");
    system("rm Selection_A.txt");
    system("rm Selection_W.txt");

    ra = fopen("Rand_A.txt", "a");
    rb = fopen("Rand_B.txt", "a");
    rw = fopen("Rand_W.txt", "a");
    b = fopen("Selection_B.txt", "a");
    a = fopen("Selection_A.txt", "a");
    w = fopen("Selection_W.txt", "a");
    fprintf(ra, "Random Number Generated (Average Case) >>\n");
    fprintf(rb, "Random Number Generated (Best Case) >>\n");
    fprintf(rw, "Random Number Generated (Worst Case) >>\n");

    for (int i = 10; i<=100; i+=10){
        srand(time(0));

        // Worst Case
        arr[0] = rand()%100;
        for (int j = 1; j<i; j+=1){
            arr[j]= arr[j-1] - rand()%100;
            fprintf(rw, "%d  ", arr[j]);
        }
        fprintf(w, "%d  %d\n", i, selection(arr, i));

        // Best case
        arr[0] = rand()%100;
        for (int j = 1; j<i; j+=1){
            arr[j] = arr[j-1] + rand()%100;
            fprintf(rb, "%d  ", arr[j]);
        }
        fprintf(b, "%d  %d\n", i, selection(arr, i));

        // Average Case
        for (int j=i/2; j<i; j++){
            arr[j] = rand()%100;
            fprintf(ra, "%d  ", arr[j]);
        }
        fprintf(a, "%d  %d\n", i, selection(arr, i));
        
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