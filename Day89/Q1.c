#include <stdio.h>
#include <stdlib.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > left)
            left = arr[i];
        right += arr[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);

    free(arr);
    return 0;
}