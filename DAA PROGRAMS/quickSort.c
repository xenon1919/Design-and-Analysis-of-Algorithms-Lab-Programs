#include <stdio.h>
#include <time.h>

void QuickSort(int [], int, int);

int main() {
    int i, n, list[20];
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n > 20) {
        printf("Error: Maximum number of elements exceeded (maximum: 20).\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    start = clock(); // Start the clock

    QuickSort(list, 0, n - 1);

    end = clock(); // End the clock
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    printf("\nTime taken for sorting: %f seconds\n", cpu_time_used);

    return 0;
}

void QuickSort(int list[], int first, int last) {
    int pivot, i, j, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (list[i] <= list[pivot] && i < last)
                i++;
            while (list[j] > list[pivot])
                j--;
            if (i < j) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[pivot];
        list[pivot] = list[j];
        list[j] = temp;
        QuickSort(list, first, j - 1);
        QuickSort(list, j + 1, last);
    }
}
