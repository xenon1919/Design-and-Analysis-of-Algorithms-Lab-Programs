#include<stdio.h>

int cost[10][10], i, j, k, n, m, stack[10], top = -1, v;
int visited[10];

void DFS() {
    printf("Enter the initial vertex: ");
    scanf("%d", &v);
    printf("Visited vertices:\n");
    stack[++top] = v;
    while (top != -1) {
        v = stack[top--];
        if (visited[v] == 0) {
            printf("%d ", v);
            visited[v] = 1;
        } else {
            continue;
        }
        for (j = n; j >= 1; j--)
            if (!visited[j] && cost[v][j] == 1)
                stack[++top] = j;
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    for (i = 1; i <= 10; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            cost[i][j] = 0;
    printf("\nEnter edges:\n");
    for (k = 1; k <= m; k++) {
        scanf("%d%d", &i, &j);
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    DFS();
}
