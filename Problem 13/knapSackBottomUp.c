#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
    if (a > b) return a;
    else  return b;
}

void main(){
    int n, m;
    printf("Enter numb of items >> ");
    scanf("%d", &n);

    int V[n] , W[n];
    printf("Enter weight and value of each item>> ");
    for(int i = 0; i<n; ++i)
        scanf("%d%d", &W[i], &V[i]);

    printf("Enter the weight of sack >>");
    scanf("%d", &m);

    int T[n+1][m+1];

    for(int i = 0; i<n+1; ++i){
        for(int j = 0; j<m+1; ++j){
            if ( j==0 || i==0)
                T[i][j] = 0;

            else if ( j < W[i-1] )
                T[i][j] = T[i-1][j];
            
            else
                T[i][j] = max(T[i-1][j], V[i-1] + T[i-1][j - W[i-1]]);
        }
    }

    printf("Value of the elements >> %d\n", T[n][m]);
    printf("Composition of sack >>\n");
    for(int i = n; i>0; --i){
        if ( T[i][m] != T[i-1][m] ){
            printf("%d  ", i );
            m = m - W[i-1];
        }
    }
}