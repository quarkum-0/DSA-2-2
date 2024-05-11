#include <stdio.h>

const char ones[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char teens[][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char tens[][10] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char thousands[][10] = {"", "thousand", "million", "billion", "trillion"};

void num_to_words(int n) {
    
    if (n == 0) {
        printf("zero");
        return;
    }

    int i = 0, num_digits = 0;
    int temp = n;
    while (temp > 0) {
        temp /= 10;
        num_digits++;
    }

    for (int j = num_digits - 1; j >= 0; j--) {
        int group = n % 1000;
        n /= 1000;

        if (group != 0) {
            if (i > 0) {
                printf(" ");
            }

            int hundreds_digit = group / 100;
            
            if (hundreds_digit != 0) {
                printf("%s", ones[hundreds_digit]);
                printf(" hundred");
            }

            int tens_and_ones = group % 100;
            
            if (tens_and_ones != 0) {
                if (tens_and_ones < 20) {
                    printf(" %s", teens[tens_and_ones - 10]);
                }
                else {
                    int tens_digit = tens_and_ones / 10;
                    printf(" %s", tens[tens_digit - 2]);
                    int ones_digit = tens_and_ones % 10;
                    
                    if (ones_digit != 0) {
                        printf("-%s", ones[ones_digit]);
                    }
                }
            }

            if (i > 0 && n > 0) {
                printf(" %s", thousands[i]);
            }
        }
        i++;
    }
}

int main() {
    
    int n;
    scanf("%d", &n);
    num_to_words(n);
    printf("\n");
    return 0;
}