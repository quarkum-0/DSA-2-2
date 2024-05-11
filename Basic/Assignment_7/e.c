#include <stdio.h>
#include <stdlib.h>

// Define a structure for pairs
typedef struct {
    int first;
    int second;
} Pair;

// Function to compare pairs for sorting
int comparePairs(const void *a, const void *b) {
    return ((Pair*)a)->first - ((Pair*)b)->first;
}

int main() {
    int n;
    scanf("%d", &n);

    Pair* pairs = (Pair*)malloc(n * sizeof(Pair));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &pairs[i].first);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &pairs[i].second);
    }

    // Sort the array of pairs
    qsort(pairs, n, sizeof(Pair), comparePairs);

    // Print the sorted array
    for (int i = 0; i < n; ++i) {
        printf("%d ", pairs[i].first);
    }

    printf("\n");

    for (int i = 0; i < n; ++i) {
        printf("%d ", pairs[i].second);
    }

    free(pairs);

    return 0;
}
