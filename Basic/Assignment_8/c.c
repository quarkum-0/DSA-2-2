#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

// Structure for Stack
typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int item) {
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1; // Assuming -1 represents an invalid value in the array
}

// Function to find sum of all min(a) where a is every possible contiguous subarray
long long sumOfMin(int arr[], int n) {
    long long sum = 0;
    Stack *stack = createStack(n);

    for (int i = 0; i < n; i++) {
        while (!isEmpty(stack) && arr[i] < arr[stack->arr[stack->top]]) {
            int top = pop(stack);
            long long left = isEmpty(stack) ? top + 1 : top - stack->arr[stack->top];
            long long right = i - top;
            sum = (sum + arr[top] * left * right) % MOD;
        }
        push(stack, i);
    }

    while (!isEmpty(stack)) {
        int top = pop(stack);
        long long left = isEmpty(stack) ? top + 1 : top - stack->arr[stack->top];
        long long right = n - top;
        sum = (sum + arr[top] * left * right) % MOD;
    }

    // Free the memory allocated for stack
    free(stack->arr);
    free(stack);

    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%lld\n", sumOfMin(arr, n));

    return 0;
}
