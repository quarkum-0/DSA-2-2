#include <stdio.h>

int main() {
    
    char arr[1000000];
    int N;
    char max[1000000];
    int ans = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int l, r;

    for (l = 0; l < N+1; l++) {
        for (r = l; r < N+1 && r >= l; r++) {
            int Revenue = 0;
            for (int i = l - 1; i < r; i++) {
                Revenue += arr[i];
                max[i] = Revenue;
            }

            for (int k = 0; k < 0.5*N*(N+1); k++) {
                if (max[k] > ans) {
                    ans = max[k];
                }
                else {
                    continue;
                }
            }
        }
    }
    printf("%d", ans);

    return 0;
}