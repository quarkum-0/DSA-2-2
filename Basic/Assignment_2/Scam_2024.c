#include <stdio.h>

int main() {

    int N;
    scanf("%d", &N);

    char prices[1000000];
    
	for (int i = 0; i < N; i++) {
        scanf("%d", &prices[i]);
    }

    int max = 0;
    int min = prices[0];

    for (int i = 1; i < N; i++) {
        if (prices[i] < min) {
            min = prices[i];
        }
		else if (prices[i] - min > max) {
            max = prices[i] - min;
        }
    }
    printf("%d\n", max);

    return 0;
}