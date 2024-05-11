#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Target not found
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Target %d found at index %d\n", target, result);
    else
        printf("Target %d not found in the array\n", target);

    return 0;
}
