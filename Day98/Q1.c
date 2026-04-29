#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval *arr = (Interval*)malloc(n * sizeof(Interval));

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(Interval), cmp);

    int idx = 0;

    for (int i = 1; i < n; i++) {
        if (arr[idx].end >= arr[i].start) {
            if (arr[i].end > arr[idx].end)
                arr[idx].end = arr[i].end;
        } else {
            idx++;
            arr[idx] = arr[i];
        }
    }

    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", arr[i].start, arr[i].end);
    }

    free(arr);
    return 0;
}