#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Merge two sorted arrays
void merge(int *arr, int *left, int left_size, int *right, int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size)
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < left_size)
        arr[k++] = left[i++];
    while (j < right_size)
        arr[k++] = right[j++];
}

// Recursive merge sort
void merge_sort(int *arr, int size) {
    if (size <= 1)
        return;

    int mid = size / 2;
    int left[mid], right[size - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}

// Partition for quicksort
int partition(int *arr, int low, int high, int depth) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot)
            arr[++i] = (arr[i] == arr[j]) ? arr[j] : (arr[i] += arr[j] - (arr[j] = arr[i]));

    arr[++i] = (arr[i] == arr[high]) ? arr[high] : (arr[i] += arr[high] - (arr[high] = arr[i]));

    return i;
}

// Recursive quicksort with a fallback to mergesort for large partitions
void quick_sort(int *arr, int low, int high, int depth, int max_depth) {
    if (depth == 0) {
        merge_sort(arr + low, high - low + 1);
        return;
    }

    if (low < high) {
        int pi = partition(arr, low, high, depth);
        quick_sort(arr, low, pi - 1, depth - 1, max_depth);
        quick_sort(arr, pi + 1, high, depth - 1, max_depth);
    }
}

// Nomki sort implementation
void nomki_sort(int *arr, int size) {
    int max_depth = (int)(2 * log2(size));
    quick_sort(arr, 0, size - 1, max_depth, max_depth);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    nomki_sort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
