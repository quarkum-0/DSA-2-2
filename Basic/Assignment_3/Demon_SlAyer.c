#include <stdio.h>

int main() {

    char arr[100000];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n+1; i++) {
        scanf("%c", &arr[i]);
    }

    char arr_rev[n];
    arr_rev[0] = arr[n];

    for (int i = 0; i < n; i++) {
        arr_rev[n-i] = arr[i];
    }
    
    for (int i = 0; i < n+1; i++) {
        printf("%c", arr_rev[i]);
    }
}