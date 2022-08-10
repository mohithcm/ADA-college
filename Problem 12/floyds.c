#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("Enter num of vertices >> ");
    scanf("%d", &n);
    int graph[n][n];

    printf("Enter matrix>> \n");
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            scanf("%d", &graph[i][j]);

    for(int k = 0; k<n; ++k){
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if ( graph[k][j] + graph[i][k] < graph[i][j] )
                    graph[i][j] = graph[k][j] + graph[i][k];
            }
        }
    }

    printf("All pair shortest path matrix >> \n");
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j)
            printf("%d  ", graph[i][j]);
        printf("\n");
    }
}