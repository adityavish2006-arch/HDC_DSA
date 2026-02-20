#include <stdio.h>

int main() {
    int n, pos, x;
    scanf("%d", &n);

    int a[n + 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &pos);
    scanf("%d", &x);

    for (int i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos - 1] = x;

    for (int i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}