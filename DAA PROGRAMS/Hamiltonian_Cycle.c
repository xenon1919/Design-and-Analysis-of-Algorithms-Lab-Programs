#include <stdio.h>
#include <string.h>

#define NODE 5

int graph[NODE][NODE] = {
  {0, 1, 0, 1, 0},
  {1, 0, 1, 1, 1},
  {0, 1, 0, 0, 1},
  {1, 1, 0, 0, 1},
  {0, 1, 1, 1, 0},
};

int path[NODE];

void displayCycle() {
  printf("Cycle Found: ");
  for (int i = 0; i < NODE; i++) printf("%d ", path[i]);
  printf("%d\n", path[0]);
}

int isValid(int v, int k) {
  return graph[path[k - 1]][v] && !memchr(path, v, k); // Combined check for edge and visited
}

int cycleFound(int k) {
  if (k == NODE) {
    return graph[path[k - 1]][path[0]];
  }

  for (int v = 1; v < NODE; v++) {
    if (isValid(v, k)) {
      path[k] = v;
      if (cycleFound(k + 1)) return 1;
      path[k] = -1; // Backtrack
    }
  }

  return 0;
}

int hamiltonianCycle() {
  for (int i = 0; i < NODE; i++) path[i] = -1;
  path[0] = 0;

  if (!cycleFound(1)) {
    printf("Solution does not exist\n");
    return 0;
  }

  displayCycle();
  return 1;
}

int main() {
  hamiltonianCycle();
  return 0;
}
