#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Node;

void merge(Node arr[], int left, int mid, int right, int count[]) {
    int n = right - left + 1;
    Node *temp = (Node*)malloc(n * sizeof(Node));

    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < n; p++)
        arr[left + p] = temp[p];

    free(temp);
}

void mergeSort(Node arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *nums = (int*)malloc(n * sizeof(int));
    Node *arr = (Node*)malloc(n * sizeof(Node));
    int *count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    free(nums);
    free(arr);
    free(count);
    return 0;
}