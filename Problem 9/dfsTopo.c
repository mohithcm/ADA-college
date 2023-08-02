#include <stdio.h>
#include <stdlib.h>
#define n1 4
#define n2 8
int graph[10][10], visited[10], indegree[10], n, cnt;
void sourcetopo() {
for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            indegree[i] += graph[j][i];

    printf("Topological sorting >> \n");
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            cnt++;
            if (!indegree[j] && !visited[j]){
                printf("%d  ", j);
                visited[j] = 1;

                for(int k = 0; k<n; ++k){
                    if ( graph[j][k] ){
                        --indegree[k];
                        graph[j][k] = 0;
                    }
                }
            }
        }
    }
}
void correctness() {
printf("Enter no. of vertices: ");

scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
scanf("%d", &graph[i][j]);
for (int i = 0; i < n; i++) {
visited[i] = 0;
indegree[i] = 0;
}
sourcetopo();
}
void analysis() {
int i, j;
FILE *f;
f = fopen("BC.txt", "a");
for (n = n1; n <= n2; n += 1) {
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
if (i == j - 1)
graph[i][j] = 1;
else
graph[i][j] = 0;
for (i = 0; i < n; i++) {
visited[i] = 0;
indegree[i] = 0;
}
cnt = 0;
sourcetopo();
fprintf(f, "%d\t%d\n", n, cnt);
} //system("gnuplot>load 'command.txt'");
fclose(f);
}
void main() {
int ch;
printf("1.analysis\t\t2.correctness\t\t0.exit\n");
for (;;) {
printf("\nenter choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
analysis();
break;
case 2:
correctness();
break;
case 0:
printf("exiting..\n");
exit(0);
default:
printf("wrong choice!!\n");
break;
}
}
}
