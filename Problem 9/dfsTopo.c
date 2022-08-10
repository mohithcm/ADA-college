#include<stdio.h>
#include<stdlib.h>

int n, stk[20], tos = -1;

void dfs(int graph[][n], int cur, int *vis){
    vis[cur] = 1;
    for(int next = 0; next<n; ++next){
        if ( graph[cur][next] && !vis[next] )
            dfs(graph, next, vis);
    }
    stk[++tos] = cur;
}

void main(){
    printf("Enter num of vertices >>");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter adjacency matrix of DAG >>");
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            scanf("%d", &graph[i][j]);

    int *vis = (int *)calloc(sizeof(int), n);

    for(int i = 0; i<n; ++i)
        if ( !vis[i] )
            dfs(graph, i, vis);

    printf("Topological sorting >> \n");
    for(int i = tos; i>-1; --i)
        printf("%d  ", stk[i]);
}