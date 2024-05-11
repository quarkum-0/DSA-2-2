#include <stdio.h>

int main() {

    int a, num;
    scanf("%d", &a);
    scanf("%d", &num);
    int matrix[a][a];
    int i, j;

    for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            if (matrix[i][j] == num) {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
}