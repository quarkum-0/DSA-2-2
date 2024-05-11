#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char arr[n];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }

    int num[26] = {0};

    for (int i = 0; i < n; i++) {
        num[arr[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (num[i] > num[j]) {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 26 && k > 0; i++) {
        if (num[i] > 0) {
            int freq = (num[i] >= k) ? k : num[i];
            count += freq * freq;
            k -= freq;
        }
    }

    printf("%d\n", count);
    return 0;
}
