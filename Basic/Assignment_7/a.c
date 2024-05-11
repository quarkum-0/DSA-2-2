#include <stdio.h>
#include <stdlib.h>

// Global variable to store the value of k
size_t global_k;

// Function to compare two strings based on the global_k index
int compareHexStrings(const void* a, const void* b) {
    return *((char*)a + global_k) - *((char*)b + global_k);
}

int main() {
    int size;

    // Input size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Input value of k
    printf("Enter the value of k: ");
    scanf("%zu", &global_k);

    // Input hexadecimal numbers into an array of strings
    char hexNumbers[size][50]; // Assuming a maximum length of 49 characters (plus null terminator)
    for (int i = 0; i < size; i++) {
        printf("Enter hexadecimal number %d: ", i + 1);
        scanf("%49s", hexNumbers[i]);
    }

    // Sort the array based on the kth index
    qsort(hexNumbers, size, sizeof(hexNumbers[0]), (int (*)(const void*, const void*))compareHexStrings);

    // Display the sorted array
    printf("\nSorted array based on the %zu-th index:\n", global_k);
    for (int i = 0; i < size; i++) {
        printf("%s ", hexNumbers[i]);
    }

    return 0;
}
