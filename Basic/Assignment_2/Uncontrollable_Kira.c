#include <stdio.h>

int main() {

    char prices[1000000];
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &prices[i]);
    }

    int max = 0;

    for (int i = 1; i < N; i++) {
        if (prices[i] > prices[i - 1]) {
            max += prices[i] - prices[i - 1];
        }
    }

    printf("%d\n", max);

    return 0;
}