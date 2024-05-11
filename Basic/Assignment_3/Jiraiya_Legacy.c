#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char str[100001];
    scanf(" %[^\n]s", str);

    int start = 0, end = n - 1;

    while (start < end) {
        while (start < end && !(str[start] == 'a' || str[start] == 'e' || str[start] == 'i' || str[start] == 'o' || str[start] == 'u')) {
            start++;
        }

        while (start < end && !(str[end] == 'a' || str[end] == 'e' || str[end] == 'i' || str[end] == 'o' || str[end] == 'u')) {
            end--;
        }

        if (start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;

            start++;
            end--;
        }
    }

    printf("%s\n", str);

    return 0;
}
