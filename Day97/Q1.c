#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmpStart(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] <= heap[idx]) break;
        swap(&heap[parent], &heap[idx]);
        idx = parent;
    }
}

void heapifyDown(int heap[], int size, int idx) {
    while (1) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == idx) break;

        swap(&heap[idx], &heap[smallest]);
        idx = smallest;
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    heapifyUp(heap, *size);
    (*size)++;
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

int peek(int heap[]) {
    return heap[0];
}

int main() {
    int n;
    scanf("%d", &n);

    Interval *arr = (Interval*)malloc(n * sizeof(Interval));

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(Interval), cmpStart);

    int *heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    push(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= peek(heap)) {
            pop(heap, &size);
        }
        push(heap, &size, arr[i].end);
    }

    printf("%d\n", size);

    free(arr);
    free(heap);
    return 0;
}