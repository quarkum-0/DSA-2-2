#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the deque
typedef struct Node {
    int data;
    int index;  // Add index to store element position
    struct Node* next;
} Node;

// Define the deque structure
typedef struct Deque {
    Node* head;
    Node* tail;
} Deque;

// Function to create a new node
Node* createNode(int data, int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->head = dq->tail = NULL;
    return dq;
}

// Function to check if the deque is empty
int isEmpty(Deque* dq) {
    return dq->head == NULL;
}

// Function to insert an element at the front of the deque
void pushFront(Deque* dq, int data, int index) {
    Node* newNode = createNode(data, index);
    if (isEmpty(dq)) {
        dq->head = dq->tail = newNode;
    } else {
        newNode->next = dq->head;
        dq->head = newNode;
    }
}

// Function to remove an element from the front of the deque
int popFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        exit(1);
    }
    Node* temp = dq->head;
    int data = temp->data;
    dq->head = dq->head->next;
    if (dq->head == NULL) {
        dq->tail = NULL;
    }
    free(temp);
    return data;
}

// Function to count valid subarrays
unsigned long long countSubarrays(int arr[], int n, int k) {
    Deque* dq = createDeque();
    unsigned long long count = 0;
    int window_start = 0;

    for (int i = 0; i < n; i++) {
        // Maintain a deque with elements in non-decreasing order
        while (!isEmpty(dq) && arr[i] > arr[dq->tail->index]) {
            popFront(dq);
        }
        pushFront(dq, arr[i], i);

        // Remove elements from the front of the deque if the difference exceeds k
        while (!isEmpty(dq) && dq->head->index < window_start) {
            popFront(dq);
            window_start++;
        }

        while (!isEmpty(dq) && abs(arr[i] - arr[dq->head->index]) > k) {
            popFront(dq);
            window_start++;
        }

        // Count the number of valid subarrays based on the current window size
        count += (unsigned long long)(i - window_start + 1);
    }

    free(dq);  // Free the allocated memory for the deque
    return count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    unsigned long long count = countSubarrays(arr, n, k);
    printf("%llu\n", count);
    return 0;
}
