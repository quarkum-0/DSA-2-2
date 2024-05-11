#include <stdio.h>

int isPal(char arr[], int start, int end) {

    while (start < end) {
        if (arr[start] != arr[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int longest(char arr[], int n) {

    int max = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPal(arr, i, j) && (j - i + 1 > max)) {
                max = j - i + 1;
            }
        }
    }
    return max;
}

int main() {

    int n;
    scanf("%d", &n);
    char arr[3000];
    scanf("%s", &arr);

    int result = longest(arr,n);
    printf("%d", result);

    return 0;
}