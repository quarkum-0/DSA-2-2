#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) {
        char* result = (char*)malloc(sizeof(char) * 2);
        strcpy(result, "0");
        return result;
    }
    
    int* result = (int*)calloc(len1 + len2, sizeof(int));
    
    int i_n1 = 0;
    int i_n2 = 0;
    
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        
        i_n2 = 0;
        
        for (int j = len2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            
            carry = sum / 10;
            
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        
        if (carry > 0) {
            result[i_n1 + i_n2] += carry;
        }
        
        i_n1++;
    }
    
    int i = len1 + len2 - 1;
    while (i >= 0 && result[i] == 0) {
        i--;
    }
    
    if (i == -1) {
        char* resultStr = (char*)malloc(sizeof(char) * 2);
        strcpy(resultStr, "0");
        return resultStr;
    }
    
    char* resultStr = (char*)malloc(sizeof(char) * (i + 2));
    int j = 0;
    while (i >= 0) {
        resultStr[j++] = result[i--] + '0';
    }
    resultStr[j] = '\0';
    
    free(result);
    
    return resultStr;
}

int main() {
    char num1[1000];
    char num2[1000];

    int l1 = 0;
    int l2 = 0;

    scanf("%s", num1);
    scanf("%s", num2);

    for(int i = 0; num1[i] != '\0' ;i++){
        l1++;
    }

    for(int i = 0; num2[i] != '\0' ;i++){
        l2++;
    }
    
    char* result = multiply(num1, num2);
    printf("%s\n", result);
    free(result);
    
    return 0;
}