#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;

    char* result = (char*)malloc((maxLen + 2) * sizeof(char));
    result[maxLen + 1] = '\0';

    int carry = 0;
    int i, j, k;

    for (i = len1 - 1, j = len2 - 1, k = maxLen; i >= 0 || j >= 0 || carry > 0; i--, j--, k--) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        result[k] = sum % 10 + '0';
        carry = sum / 10;
    }

    return result + (result[0] == '0' ? 1 : 0);
}

char* Multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (len1 == 0 || len2 == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }

    if (len1 == 1 || len2 == 1) {
        int product = (num1[0] - '0') * (num2[0] - '0');
        char* result = (char*)malloc(20 * sizeof(char));  // Assuming the product can be represented in 20 characters
        sprintf(result, "%d", product);
        return result;
    }

    int m = (len1 > len2 ? len1 : len2) / 2;

    char* high1 = num1;
    char* low1 = num1 + m;
    char* high2 = num2;
    char* low2 = num2 + m;

    char* z0 = Multiply(low1, low2);
    char* z1 = Multiply(addStrings(low1, high1), addStrings(low2, high2));
    char* z2 = Multiply(high1, high2);

    char* term1 = (char*)malloc((2 * m + 2) * sizeof(char));
    strcpy(term1, z2);

    char* term2 = (char*)malloc((m + 2) * sizeof(char));
    strcpy(term2, addStrings(z1, z0));

    char* result = addStrings(term1, term2);
    free(term1);
    free(term2);
    free(z0);
    free(z1);
    free(z2);

    return result;
}

int main() {
    char num1[1000001];  // Assuming maximum length is 1000000
    char num2[1000001];

    // Input
    scanf("%s", num1);
    scanf("%s", num2);

    char* result = Multiply(num1, num2);

    // Output
    printf("%s\n", result);

    // Free allocated memory
    free(result);

    return 0;
}
