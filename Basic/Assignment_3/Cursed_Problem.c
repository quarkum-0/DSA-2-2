#include <stdio.h>

int main() {

    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);

    char arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = 0;
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    for (int i = k; i < n; i++) {
        if (sum/k >= x) {
            max++;
        }

        sum += arr[i] - arr[i - k];
    }

    printf("%d", max);
}