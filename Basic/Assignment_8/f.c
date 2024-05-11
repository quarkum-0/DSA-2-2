#include <stdio.h>
#include <stdlib.h>

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

// Function to find the next greater element indices
void nextGreaterElements(int arr[], int n, int result[]) {
    Stack *stack = createStack(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(stack) && arr[i] >= arr[stack->arr[stack->top]]) {
            pop(stack);
        }
        result[i] = isEmpty(stack) ? 0 : stack->arr[stack->top] - i;
        push(stack, i);
    }

    // Free memory allocated for stack
    free(stack->arr);
    free(stack);
}

// Function to find the next smaller element indices
void nextSmallerElements(int arr[], int n, int result[]) {
    Stack *stack = createStack(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(stack) && arr[i] <= arr[stack->arr[stack->top]]) {
            pop(stack);
        }
        result[i] = isEmpty(stack) ? 0 : stack->arr[stack->top] - i;
        push(stack, i);
    }

    // Free memory allocated for stack
    free(stack->arr);
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);

    int jars[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &jars[i]);

    int nextGreater[n];
    nextGreaterElements(jars, n, nextGreater);

    int nextSmaller[n];
    nextSmallerElements(jars, n, nextSmaller);

    // Output next greater elements
    for (int i = 0; i < n; i++) {
        printf("%d ", nextGreater[i]);
    }
    printf("\n");

    // Output next smaller elements
    for (int i = 0; i < n; i++) {
        printf("%d ", nextSmaller[i]);
    }
    printf("\n");

    return 0;
}
