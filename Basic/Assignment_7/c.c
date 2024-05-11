#include <stdio.h>
#include <stdlib.h>

// Function to perform stable counting sort
void countingSort(int* arr, int* index, int n) {
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

    // Update count array to store cumulative counts
    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array in stable manner
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        index[count[arr[i]] - 1] = i + 1;
        count[arr[i]]--;
    }

    // Copy the sorted elements to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int index[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, index, n);

    // Print the sorted array
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Print the index of corresponding elements
    for (int i = 0; i < n; ++i) {
        printf("%d ", index[i]);
    }

    free(arr);
    free(index);

    return 0;
}
