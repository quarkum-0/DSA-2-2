#include <stdio.h>
#include <stdlib.h>

// Bucket Node Structure
typedef struct Node {
    double value;
    struct Node* next;
} Node;

// Function to insert a value into the bucket
void insert(Node** bucket, double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*bucket == NULL) {
        *bucket = newNode;
    } else {
        newNode->next = *bucket;
        *bucket = newNode;
    }
}

// Function to sort a bucket using insertion sort
void insertionSort(Node* bucket) {
    if (bucket == NULL || bucket->next == NULL) {
        return;
    }

    Node* sorted = NULL;
    Node* current = bucket;

    while (current != NULL) {
        Node* next = current->next;

        if (sorted == NULL || sorted->value >= current->value) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->value < current->value) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    // Update the bucket with the sorted values
    current = sorted;
    while (current != NULL) {
        printf("%.1f ", current->value);
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to perform bucket sort
void bucketSort(double* arr, int n) {
    int numBuckets = n;
    Node** buckets = (Node**)malloc(numBuckets * sizeof(Node*));

    for (int i = 0; i < numBuckets; ++i) {
        buckets[i] = NULL;
    }

    // Distribute values into buckets
    for (int i = 0; i < n; ++i) {
        int index = (int)(arr[i] * numBuckets);
        insert(&buckets[index], arr[i]);
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < numBuckets; ++i) {
        insertionSort(buckets[i]);
        free(buckets[i]);
    }

    free(buckets);
}

int main() {
    int n;
    scanf("%d", &n);

    double* arr = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; ++i) {
        scanf("%lf", &arr[i]);
    }

    bucketSort(arr, n);

    free(arr);

    return 0;
}
