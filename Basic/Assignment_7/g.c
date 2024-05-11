#include <stdio.h>
#include <stdlib.h>

// Function to find k closest targets to Ganyu
void findClosestTargets(int* targets, int n, int k, int x) {
    // Calculate the absolute differences from Ganyu's position
    int diffs[n];
    for (int i = 0; i < n; ++i) {
        diffs[i] = abs(targets[i] - x);
    }

    // Perform k rounds of selection sort to find k closest targets
    for (int i = 0; i < k; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (diffs[j] < diffs[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the closest target to the front
        int tempDiff = diffs[i];
        diffs[i] = diffs[minIndex];
        diffs[minIndex] = tempDiff;

        int tempTarget = targets[i];
        targets[i] = targets[minIndex];
        targets[minIndex] = tempTarget;
    }

    // Print the k closest targets
    for (int i = 0; i < k; ++i) {
        printf("%d ", targets[i]);
    }
}

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);

    int* targets = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &targets[i]);
    }

    findClosestTargets(targets, n, k, x);

    free(targets);

    return 0;
}
