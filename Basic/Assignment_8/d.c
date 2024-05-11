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

// Function to find maximum area of rectangle in histogram
long long maxRectangleArea(int heights[], int n) {
    long long maxArea = 0;
    Stack *stack = createStack(n);

    int i = 0;
    while (i < n) {
        if (isEmpty(stack) || heights[i] >= heights[stack->arr[stack->top]]) {
            push(stack, i);
            i++;
        } else {
            int top = pop(stack);
            long long area = heights[top] * (isEmpty(stack) ? i : i - stack->arr[stack->top] - 1);
            if (area > maxArea)
                maxArea = area;
        }
    }

    while (!isEmpty(stack)) {
        int top = pop(stack);
        long long area = heights[top] * (isEmpty(stack) ? i : i - stack->arr[stack->top] - 1);
        if (area > maxArea)
            maxArea = area;
    }

    // Free the memory allocated for stack
    free(stack->arr);
    free(stack);

    return maxArea;
}

int main() {
    int n;
    scanf("%d", &n);

    int heights[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &heights[i]);

    printf("%lld\n", maxRectangleArea(heights, n));

    return 0;
}
