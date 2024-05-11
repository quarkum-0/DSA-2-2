#include <stdio.h>

int main() {
    
    char arr[1000000];
    int N, Q;

    scanf("%d %d", &N, &Q);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int q = 0; q < Q; q++) {
        int l, r;
        scanf("%d %d", &l, &r);

        int cumulativeRevenue = 0;
        for (int i = l - 1; i < r; i++) {
            cumulativeRevenue += arr[i];
        }

        printf("%d\n", cumulativeRevenue);
    }

    return 0;
}