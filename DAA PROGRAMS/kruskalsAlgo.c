#include <stdio.h>
#include <stdlib.h>

int comparator(const void* p1, const void* p2) {
    return ((int*)p1)[2] - ((int*)p2)[2];
}

void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component) {
    if (parent[component] != component)
        parent[component] = findParent(parent, parent[component]);
    return parent[component];
}

void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int vertices, int edges[][3], int numEdges) {
    qsort(edges, numEdges, sizeof(edges[0]), comparator);

    int parent[vertices], rank[vertices];
    makeSet(parent, rank, vertices);

    int minCost = 0;
    printf("Edges in the constructed MST:\n");

    for (int i = 0; i < numEdges; i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if (u != v) {
            unionSet(u, v, parent, rank);
            minCost += edges[i][2];
            printf("%d -- %d == %d\n", edges[i][0], edges[i][1], edges[i][2]);
        }
    }

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main() {
    int edges[][3] = { { 0, 1, 10 },
                       { 0, 2, 6 },
                       { 0, 3, 5 },
                       { 1, 3, 15 },
                       { 2, 3, 4 } };
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    int vertices = 4;
    kruskalAlgo(vertices, edges, numEdges);
    return 0;
}
