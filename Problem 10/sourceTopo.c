#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("Enter num of vertices >> ");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter matrix for DAG>> \n");
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            scanf("%d", &graph[i][j]);

    int *vis = (int *)calloc(sizeof(int), n);
    int *indeg = (int *)calloc(sizeof(int), n);

    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            indeg[i] += graph[j][i];

    printf("Topological sorting >> \n");
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            if (!indeg[j] && !vis[j]){
                printf("%d  ", j);
                vis[j] = 1;

                for(int k = 0; k<n; ++k){
                    if ( graph[j][k] ){
                        --indeg[k];
                        graph[j][k] = 0;
                    }
                }
            }
        }
    }
}