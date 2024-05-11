#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to maintain min heap property
void Heapify(int* a, int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;

    // Compare with left child
    if (left < n && a[left] < a[i]) {
        min = left;
    }

    // Compare with right child
    if (right < n && a[right] < a[min]) {
        min = right;
    }

    // Swap if needed and recursively heapify the affected subtree
    if (i != min) {
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        Heapify(a, min, n);
    }
}

// Function to build min heap
void buildMinHeap(int* a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(a, i, n);
    }
}

// Merge K Sorted Arrays function
void mergeKSortedArrays(int k, int **arrays, int *sizes) {
    // Create a heap to store the smallest elements from each array
    int *heap = malloc(k * sizeof(int));

    // Allocate memory for indices to keep track of the current element in each array
    int *indices = malloc(k * sizeof(int));

    // Initialize the heap with the first element from each array and update indices
    for (int i = 0; i < k; i++) {
        heap[i] = arrays[i][0];
        indices[i] = 1;
    }

    // Build the initial min heap
    buildMinHeap(heap, k);

    // Output the sorted array
    while (1) {
        // Print the smallest element in the heap
        printf("%d ", heap[0]);

        int minIndex = 0;
        for (int i = 1; i < k; i++) {
            // Find the index of the smallest element among all arrays
            if (indices[i] < sizes[i] && arrays[i][indices[i]] < arrays[minIndex][indices[minIndex]]) {
                minIndex = i;
            }
        }

        // Move to the next element in the corresponding array
        indices[minIndex]++;

        // If the array has more elements, replace the root with the next element from the same array
        if (indices[minIndex] <= sizes[minIndex]) {
            heap[0] = arrays[minIndex][indices[minIndex] - 1];
        } else {
            // If the array is exhausted, replace the root with a large value to maintain heap property
            heap[0] = INT_MAX;
        }

        // Heapify to maintain the min heap property
        Heapify(heap, 0, k);

        // Check if all arrays are exhausted
        int allExhausted = 1;
        for (int i = 0; i < k; i++) {
            if (indices[i] <= sizes[i]) {
                allExhausted = 0;
                break;
            }
        }

        // Exit the loop if all arrays are exhausted
        if (allExhausted) {
            break;
        }
    }

    // Free the allocated memory
    free(heap);
    free(indices);
}

int main() {
    int k;
    scanf("%d", &k);

    // Allocate memory for arrays and sizes
    int **arrays = malloc(k * sizeof(int *));
    int *sizes = malloc(k * sizeof(int));

    // Input arrays and their sizes
    for (int i = 0; i < k; i++) {
        scanf("%d", &sizes[i]);
        arrays[i] = malloc(sizes[i] * sizeof(int));

        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    // Merge and print the sorted array
    mergeKSortedArrays(k, arrays, sizes);

    // Free the allocated memory
    for (int i = 0; i < k; i++) {
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);

    return 0;
}
