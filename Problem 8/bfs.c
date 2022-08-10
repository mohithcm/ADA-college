#include<stdio.h>
#include<stdlib.h>

int Q[20], f = -1, r = -1;

void enq(int node){
    if (f == r && r == -1)
        ++f;
    Q[++r] = node;
}

int deq(){
    if ( f==r){
        int a = f;
        f = r = -1;
        return Q[a];
    }
    return Q[f++];
}

int isEmpty(){
    if ( f == r && f == -1)
        return 1;
    else
        return 0;
}

void main(){
    int n, cyclic = 0, sum = 1, connect = 1;
    printf("Enter num of vertices >> ");
    scanf("%d", &n);
    int graph[n][n];

    printf("Enter the matrix >> \n");
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            scanf("%d", &graph[i][j]);

    int * vis = (int *)calloc(sizeof(int), n);
    int parent[n];
    for(int i = 0; i<n; ++i)
        parent[i] = -1;

    printf("BFS Traversal >> \n");
    for(int i = 0; i<n; ++i){
        if ( !vis[i] ){
            vis[i] = 1;
            parent[i] = i;
            enq(i);
            printf("%d  ", i);

            while ( !isEmpty() ){
                int cur = deq();

                for(int next = 0; next<n; ++next){
                    if ( graph[cur][next] && vis[next] && parent[cur] != next)
                        cyclic = 1;
                    if ( graph[cur][next] && !vis[next] ){
                        enq(next);
                        vis[next] = 1;
                        parent[next] = cur;
                        ++sum;
                        printf("%d  ", next);
                    }
                }
            }
            if ( sum != n && i == 0)
                connect = 0;
            printf("\n");
        }
    }

    if ( connect )
        printf("Graph is connected\n");
    else    
        printf("Graph is disconnected\n");

    if ( cyclic )
        printf("Graph is cyclic\n");
    else    
        printf("Graph is acyclic\n");
}