#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack *createStack (int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(sizeof(int)*stack->capacity);
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--]; 
    }
    return -1;
}

void push(Stack *stack, int value) {
    stack->arr[++stack->top] = value;
}

int main() {
    Stack *stack = createStack(100);
}