#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Stack
typedef struct {
    char *arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, char item) {
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return '\0';
}

// Function to check if parentheses are balanced
char* isValidParentheses(char *s) {
    int len = strlen(s);
    Stack *stack = createStack(len);
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(stack, s[i]);
        } else {
            if (isEmpty(stack)) {
                free(stack->arr);
                free(stack);
                return "NO";
            }
            char top = pop(stack);
            if ((s[i] == ')' && top != '(') || 
                (s[i] == ']' && top != '[') || 
                (s[i] == '}' && top != '{')) {
                free(stack->arr);
                free(stack);
                return "NO";
            }
        }
    }

    if (!isEmpty(stack)) {
        free(stack->arr);
        free(stack);
        return "NO";
    }

    free(stack->arr);
    free(stack);
    return "YES";
}

int main() {
    char s[1000001];
    scanf("%s", s);
    printf("%s\n", isValidParentheses(s));
    return 0;
}
