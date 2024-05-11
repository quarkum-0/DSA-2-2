#include <stdio.h>

int main() {
    char arr[100000];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }

    char final[100000];
    final[0] = arr[0];

    for (int j = 1; j < n; j++) {
        int k;
        for (k = 0; k < j; k++) {
            if (arr[k] == arr[j]) {
                break;
            }
        }

        if (k == j) {
            final[j] = arr[j];
        } else {
            printf("%d\n", j);
            return 0;
        }
    }

    printf("%d\n", n);

    return 0;
}