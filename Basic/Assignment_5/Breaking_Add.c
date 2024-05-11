#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

struct Node* addLists(struct Node* head1, struct Node* head2) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int carry = 0;

    while (head1 || head2 || carry) {
        int sum = carry;

        if (head1) {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2) {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10;
        struct Node* newNode = createNode(sum % 10);

        // To Understand...
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    for (int i = 0; i < n; i++) {
        int digit;
        scanf("%d", &digit);
        insertAtBeginning(&head1, digit);
    }

    for (int i = 0; i < m; i++) {
        int digit;
        scanf("%d", &digit);
        insertAtBeginning(&head2, digit);
    }

    reverseList(&head1);
    reverseList(&head2);
    struct Node* headSum = addLists(head1, head2);
    printList(headSum);

    return 0;
}