#include<stdlib.h>
#include<stdio.h>

int stringMatch(int txt[], int pat[], int n, int m){
    int count = 0, j = 0;

    for(int i = 0; i<n-m; ++i){
        j = 0;
        while ( j<m && txt[i+j] == pat[j] ){
            ++count;
            ++j;
        }

        if ( j==m )
            return count;
    }
    return count;
}

void main(){
    FILE *a, *b, *w;
    system("rm avg.txt;    rm best.txt;    rm worst.txt");
    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(int n = 10; n<=100; n+=10){
        int *txt = (int *)calloc(sizeof(int), n);

        // best case
        int pat[4] = {0, 0, 0, 0};
        fprintf(b, "%d  %d\n", n, stringMatch(txt, pat, n, 4));

        // worst case
        txt[n-1] = pat[3] = 1;
        fprintf(w, "%d  %d\n", n, stringMatch(txt, pat, n, 4));

        // avg case
        txt[n/2] = txt[n/2 + 1] = pat[2] = 1;
        fprintf(a, "%d  %d\n", n, stringMatch(txt, pat, n, 4));
    }
    fclose(a);  fclose(b);  fclose(w);
    system("gnuplot -p -c plot.txt");
}