#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void PrintList(struct Node* head) {
    while (head != NULL) {
        printf("Element: %d\n", head->data);
        head = head->next;
    }
}

InsertAtFirst(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = head;
    newNode->data = data;
    return newNode;
}

InsertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* value = head;

    while (value->next != NULL) {
        value = value->next;
    }
    value->next = newNode;
    newNode->next = NULL;
    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;

    printf("before");
    PrintList(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    head = InsertAtEnd(head, 56);
    // head = insertAfterNode(head, second, 56);
    printf("after");
    PrintList(head);

    return 0;
}