#include <stdio.h>
#include <time.h>

void mergesort(int a[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = 0, b[50];
    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= ub) {
        b[k++] = a[j++];
    }
    for (k = 0; k <= ub - lb; k++) {
        a[k + lb] = b[k];
    }
}

void merge(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge(a, low, mid);
        merge(a, mid + 1, high);
        mergesort(a, low, mid, high);
    }
}

int main() {
    int i, a[30], n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Before sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    start = clock(); // Start measuring time
    merge(a, 0, n - 1);
    end = clock(); // End measuring time

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n\nAfter sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nTime taken to sort the elements: %f seconds\n", cpu_time_used);

    return 0;
}
