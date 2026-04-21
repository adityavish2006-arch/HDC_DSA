#include <stdio.h>
#include <stdlib.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (curr + arr[i] <= maxTime) {
            curr += arr[i];
        } else {
            painters++;
            curr = arr[i];
        }
    }

    return painters <= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

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

        if (isPossible(arr, n, k, mid)) {
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