#include <stdio.h>
#include <stdlib.h>

// Function to perform frequency sort
void frequencySort(int* arr, int n) {
    int max = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1];
    int output[n];

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Count occurrences of each element
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Build the output array based on frequency
    int index = 0;
    for (int i = 1; i <= max; ++i) {
        while (count[i] > 0) {
            output[index] = i;
            index++;
            count[i]--;
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; ++i) {
        printf("%d ", output[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    frequencySort(arr, n);

    free(arr);

    return 0;
}
