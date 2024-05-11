#include <stdio.h>

// Function to check if there exist two missing integers whose sum is k
char* existTwoMissing(int* arr, int n, int k) {
    for (int i = 1; i <= n; ++i) {
        int complement = k - i;

        if (arr[i] > 0 && complement >= 1 && complement <= n && arr[complement] > 0) {
            return "yes";
        }
    }

    return "no";
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* arr = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    char* result = existTwoMissing(arr, n, k);
    printf("%s\n", result);

    free(arr);

    return 0;
}
