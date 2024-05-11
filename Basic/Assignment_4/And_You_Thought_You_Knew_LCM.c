#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lcm(int a, int b) {
    int p = 1, q = 1;

    while (a != b) {
        if (a > b) {
            b /= q;
            b *= ++q;
        } else if (a < b) {
            a /= p;
            a *= ++p;
        }
    }
    return a;
}

void mult(char str[], int n) {
    int p = strlen(str);
    int i = 0;
    char *temp = malloc(p * n + 1);

    if (temp == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < p; k++) {
            temp[i++] = str[k];
        }
    }

    temp[i] = '\0';
    strcpy(str, temp);
    free(temp);
}

int main() {
    char str1[1000000];
    char str2[1000000];

    // Read input strings using fgets to handle spaces
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    // Remove newline characters from the input strings
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int lcm1 = lcm(len1, len2);

    int p = lcm1 / len1;
    int q = lcm1 / len2;

    mult(str1, p);
    mult(str2, q);

    if (strcmp(str1, str2) == 0) {
        printf("%s", str1);
    } else {
        printf("%d", -1);
    }

    return 0;
}