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
    struct Node* head1 = NULL; // Head of the first linked list

    int n, a,b;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);

    // Input values and create the linked list for head1
    for (int i = 0; i < n; i++) {
        add(&head1, i+1);
    }
    
    struct Node* temp = head1;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = head1; // create a circle
        
    struct Node* jim =head1;
    struct Node* dwight=head1;
    
    while (jim->data != b) {
            jim = jim->next; 
        }
    
    while (dwight->data != a) {
            dwight = dwight->next; 
        }
        
    while(dwight != jim){
        dwight = (dwight->next)->next;
        jim = jim->next;
    }

    printf("%d",dwight->data);
    return 0;
}