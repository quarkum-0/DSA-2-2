#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int nomIndex = 0;
    int psyIndex = n - 1;
    int nomWeight = 0;
    int psyWeight = 0;
    int maxWeight = 0;


    while (nomIndex <= psyIndex) {
        if (nomWeight <= psyWeight) {
            nomWeight += a[nomIndex++];
        } 

        else {
            psyWeight += a[psyIndex--];
        }

        if (nomWeight == psyWeight) {
            maxWeight = nomWeight;
        }
    }

    printf("%d\n", maxWeight);

    return 0;
}