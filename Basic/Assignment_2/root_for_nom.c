#include <stdio.h>

int main() {
    int num;
    double ans, epsilon;

    scanf("%d", &num);

    if (num < 0) {
        printf("Cannot calculate square root of a negative num.\n");
        return 1;
    }

    ans = num / 2.0;
    epsilon = 1e-9;

    while (ans * ans - num > epsilon || ans * ans - num < -epsilon) {
        ans = 0.5 * (ans + num / ans);
    }

    printf("%.6lf\n", ans);

    return 0;
}
