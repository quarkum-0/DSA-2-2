#include <stdio.h>

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    char arr1[n];
    char arr2[m];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    
    for (int j = 0; j < m; j++) {
        scanf("%d", &arr2[j]);
    }

    char arr[m + n];

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    
    while (j < m) {
        arr[k] = arr1[j];
        j++;
        k++;
    }

    for (int l = 0; l < n + m; l++) {
        printf("%d ", arr[l]);
    }
    
    return 0;
}