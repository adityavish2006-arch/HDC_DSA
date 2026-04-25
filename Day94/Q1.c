#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int max = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int *count = (int*)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int *output = (int*)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", output[i]);

    free(arr);
    free(count);
    free(output);

    return 0;
}