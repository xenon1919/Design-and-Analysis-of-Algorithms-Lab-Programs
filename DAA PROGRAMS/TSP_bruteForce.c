#include <stdio.h>
#include <limits.h>

#define NUM_CITIES 4

int graph[NUM_CITIES][NUM_CITIES] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[NUM_CITIES];
int minCost = INT_MAX;

void tsp(int currentCity, int visitedCount, int costSoFar) {
    if (visitedCount == NUM_CITIES && graph[currentCity][0] != 0) {
        int totalCost = costSoFar + graph[currentCity][0];
        if (totalCost < minCost) {
            minCost = totalCost;
        }
        return;
    }
    
    for (int i = 0; i < NUM_CITIES; i++) {
        if (!visited[i] && graph[currentCity][i] != 0) {
            visited[i] = 1;
            tsp(i, visitedCount + 1, costSoFar + graph[currentCity][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < NUM_CITIES; i++) {
        visited[i] = 0;
    }
    
    visited[0] = 1;
    tsp(0, 1, 0);
    
    printf("Minimum cost of the TSP: %d\n", minCost);
    
    return 0;
}
