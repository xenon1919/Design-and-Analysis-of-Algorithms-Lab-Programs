#include<stdio.h>

int cost[10][10], i, j, k, n, m, queue[10], front, rear, v;
int visited[10];

void BFS() {
    printf("Enter the initial vertex: ");
    scanf("%d", &v);
    printf("Visited vertices:\n");
    visited[v] = 1;
    queue[++rear] = v;
    while (front != rear) {
        v = queue[++front];
        printf("%d ", v);
        for (j = 1; j <= n; j++)
            if (!visited[j] && cost[v][j] == 1) {
                queue[++rear] = j;
                visited[j] = 1;
            }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    front = -1;
    rear = -1;
    for (i = 1; i <= 10; i++) 
        visited[i] = 0;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            cost[i][j] = 0;
    printf("\nEnter edges:\n");
    for (k = 1; k <= m; k++) {
        scanf("%d%d", &i, &j);
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    BFS();
}
