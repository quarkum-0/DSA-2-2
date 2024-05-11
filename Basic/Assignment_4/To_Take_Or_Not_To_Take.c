#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? a : b)

int maxRatings(int ratings[], int times[], int n, int k, int idx, int remainingTime) {
    if (idx == n || remainingTime == 0) {
        return 0;
    }
    if (times[idx] > remainingTime) {
        return maxRatings(ratings, times, n, k, idx + 1, remainingTime);
    }
    return max(maxRatings(ratings, times, n, k, idx + 1, remainingTime),
                ratings[idx] + maxRatings(ratings, times, n, k, idx + 1, remainingTime - times[idx]));
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int ratings[n], times[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ratings[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &times[i]);
    }
    int result = maxRatings(ratings, times, n, k, 0, k);
    printf("%d\n", result);
    return 0;
}