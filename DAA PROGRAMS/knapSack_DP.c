#include <stdio.h>
#include <string.h>

int findMax(int n1, int n2) {
    return (n1 > n2) ? n1 : n2;
}

int knapsack(int W, int wt[], int val[], int n) {
    int K[n+1][W+1];
    
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0) {
                K[i][w] = 0;
            } else if(wt[i-1] <= w) {
                K[i][w] = findMax(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            } else {
                K[i][w] = K[i-1][w];
            }
        }
    }
    
    return K[n][W];
}

int main() {
    int val[] = {70, 20, 50};
    int wt[] = {11, 12, 13};
    int W = 30;
    int len = sizeof(val) / sizeof(val[0]);
    
    printf("Maximum Profit achieved with this knapsack: %d\n", knapsack(W, wt, val, len));
    return 0;
}