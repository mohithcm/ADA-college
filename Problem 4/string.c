#include<stdlib.h>
#include<stdio.h>

int stringMatch(char *txt, char *pat, int n, int m){
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
        char *txt = (char *)calloc(sizeof(char), n);
        for(int i=0;i<n;i++)
          txt[i]='a';
        // best case
        char* pat = "aaaa";
        fprintf(b, "%d  %d\n", n, stringMatch(txt, pat, n, 4));

        // worst case
        pat = "aaab";
        fprintf(w, "%d  %d\n", n, stringMatch(txt, pat, n, 4));

        // avg case
        pat= "abab";
        fprintf(a, "%d  %d\n", n, stringMatch(txt, pat, n, 4));
    }
    fclose(a);  fclose(b);  fclose(w);
}
