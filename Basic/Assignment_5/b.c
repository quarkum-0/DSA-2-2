#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add a new element to the end of the linked list
void add(struct Node** head, int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node; // If the list is empty, make the new node the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = new_node; // Add the new node at the end
    }
}

int main() {
    struct Node* head = NULL;  // Head of the combined linked list
    struct Node* head1 = NULL; // Head of the first linked list
    struct Node* head2 = NULL; // Head of the second linked list

    int n, m, val;
    scanf("%d", &n);
    scanf("%d", &m);

    // Input values and create the linked list for head1
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        add(&head1, val);
    }

    // Input values and create the linked list for head2
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        add(&head2, val);
    }

    // Merge the two linked lists
    if (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            head = head1;
            head1 = head1->next;
        } else {
            head = head2;
            head2 = head2->next;
        }

        struct Node* temp = head;

        while (head1 != NULL && head2 != NULL) {
            if (head1->data <= head2->data) {
                temp->next = head1;
                temp = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
        }

        // Add the remaining nodes, if any
        if (head1 != NULL) {
            temp->next = head1;
        } else if (head2 != NULL) {
            temp->next = head2;
        }
    }

    // Print the final combined linked list
    printf("Combined Linked List: ");
    printList(head);
    
    return 0;
}