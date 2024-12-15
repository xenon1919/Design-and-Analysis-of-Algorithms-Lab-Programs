#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define MAX 10

int G[MAX][MAX] = {
    {0, 19, 8},
    {21, 0, 13},
    {15, 18, 0}
};
int S[MAX][MAX], n = 3;

int prims() {
    int min_cost = 0, dist[MAX], from[MAX], visited[MAX] = {0};
    int i, j, ne = n - 1, u, v, min_dist;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        for (j = 0; j < n; j++) {
            S[i][j] = 0;
        }
    }

    dist[0] = 0;
    from[0] = 0;

    while (ne > 0) {
        min_dist = INF;
        for (i = 1; i < n; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                v = i;
                min_dist = dist[i];
            }
        }

        u = from[v];
        S[u][v] = S[v][u] = G[u][v];
        min_cost += G[u][v];
        visited[v] = 1;
        ne--;

        for (i = 1; i < n; i++) {
            if (!visited[i] && G[i][v] < dist[i]) {
                dist[i] = G[i][v];
                from[i] = v;
            }
        }
    }

    return min_cost;
}

int main() {
    int cost = prims();
    
    printf("\nSpanning tree:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", S[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum cost = %d\n", cost);
    return 0;
}
