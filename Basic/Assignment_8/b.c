#include <stdio.h>

// Function to find maximum in each k-sized window using a simple queue
void findMaxInWindow(int arr[], int n, int k) {
    int queue[n], front = 0, rear = -1;

    // Process first k elements separately to initialize the queue
    for (int i = 0; i < k; i++) {
        while (rear >= front && arr[i] >= arr[queue[rear]])
            rear--;
        queue[++rear] = i;
    }

    // Process rest of the elements
    for (int i = k; i < n; i++) {
        printf("%d ", arr[queue[front]]);

        while (rear >= front && queue[front] <= i - k)
            front++;

        while (rear >= front && arr[i] >= arr[queue[rear]])
            rear--;
        queue[++rear] = i;
    }

    printf("%d\n", arr[queue[front]]);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    findMaxInWindow(arr, n, k);

    return 0;
}
