#include <stdio.h>
#include <stdlib.h>

// Function to calculate the Goodness of the optimal team
int calculateGoodness(int* dps, int* synergy, int n, int k) {
    int goodness = 0;

    // Sort characters based on their synergy
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (synergy[j] < synergy[j + 1]) {
                // Swap synergy values
                int tempSynergy = synergy[j];
                synergy[j] = synergy[j + 1];
                synergy[j + 1] = tempSynergy;

                // Swap corresponding DPS values
                int tempDPS = dps[j];
                dps[j] = dps[j + 1];
                dps[j + 1] = tempDPS;
            }
        }
    }

    // Calculate the Goodness
    for (int i = 0; i < k; ++i) {
        goodness += dps[i] + synergy[i];
    }

    return goodness;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* dps = (int*)malloc(n * sizeof(int));
    int* synergy = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &dps[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &synergy[i]);
    }

    int result = calculateGoodness(dps, synergy, n, k);
    printf("%d\n", result);

    free(dps);
    free(synergy);

    return 0;
}
