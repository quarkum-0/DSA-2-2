#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

long long count_salaries(int n, int k, long long l, long long r, char digits[], int m, long long current, int pos) {
    if (pos == n) {
        if (current >= l && current <= r && k == 0)
            return 1;
        return 0;
    }
    
    long long count = 0;
    for (int i = 0; i <= 9; i++) {
        if (digits[pos] == '?' || (digits[pos] - '0') == i) {
            int new_k = k - i;
            if (new_k >= 0) {
                count += count_salaries(n, new_k, l, r, digits, m, current * 10 + i, pos + 1);
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    long long l, r;
    scanf("%d %d %lld %lld", &n, &k, &l, &r);
    char digits[n + 1];
    scanf("%s", digits);
    
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (digits[i] == '?') {
            m++;
        }
    }
    
    long long result = count_salaries(n, k, l, r, digits, m, 0, 0);
    printf("%lld\n", result);
    
    return 0;
}