#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    struct Node* mergedHead = NULL;
    struct Node** tail = &mergedHead;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            *tail = head1;
            head1 = head1->next;
        }
        else {
            *tail = head2;
            head2 = head2->next;
        }
        tail = &((*tail)->next);
    }

    if (head1 != NULL) {
        *tail = head1;
    }
    else {
        *tail = head2;
    }
    return mergedHead;
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

    struct Node* mergedList = mergeLists(head1, head2);
    printList(mergedList);

    return 0;
}