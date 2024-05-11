#include <stdio.h>

int main() {
    
    int N;
    scanf("%d", &N);

    char matrix[1000][1000];
    int num = 1, top = 0, bottom = N - 1, left = 0, right = N - 1;

    while (num <= N * N) {
        for (int i = left; i <= right; i++)
        matrix[top][i] = num++;
        top++;

        for (int i = top; i <= bottom; i++)
        matrix[i][right] = num++;
        right--;

        for (int i = right; i >= left; i--)
        matrix[bottom][i] = num++;
        bottom--;

        for (int i = bottom; i >= top; i--)
        matrix[i][left] = num++;
        left++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
