//COPIED

#include <stdio.h>

int countWays(int weights[], int n, int k) {
    // Base case: If the target weight is 0, there is one way (no selection)
    if (k == 0) {
        return 1;
    }

    // Base case: If the target weight is negative or no jars left, no valid selection
    if (k < 0 || n <= 0) {
        return 0;
    }

    // Recursive call without including the current jar and including the current jar
    return countWays(weights, n - 1, k) + countWays(weights, n, k - weights[n - 1]);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int weights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int ways = countWays(weights, n, k);

    printf("%d\n", ways);
    return 0;
}