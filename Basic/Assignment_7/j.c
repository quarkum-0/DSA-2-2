#include <stdio.h>
#include <stdlib.h>

// Function to find the indices of chosen characters
void findChosenCharacters(int* hp, int n, int x) {
    int chosenIndices[n];
    int k = 0;

    // Check and store indices of characters with HP less than x
    for (int i = 0; i < n; ++i) {
        if (hp[i] < x) {
            chosenIndices[k++] = i + 1;
        }
    }

    // Print the number of characters and their indices
    printf("%d\n", k);
    for (int i = 0; i < k; ++i) {
        printf("%d ", chosenIndices[i]);
    }
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int* hp = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &hp[i]);
    }

    findChosenCharacters(hp, n, x);

    free(hp);

    return 0;
}
