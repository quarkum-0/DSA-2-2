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

    int n, m, val;
    scanf("%d", &n);
    //scanf("%d", &m);

    // Input values and create the linked list for head1
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        add(&head1, val);
    }
    
    struct Node* prev = head1;
    struct Node* current = head1->next;
    struct Node* nextt = current->next ;
    
    
    while(current!=nextt){
        
        if(prev ==head1){
            prev->next =NULL;
        }
        
        current->next = prev;
        
        prev = current;
        
        current = nextt;
        
        if(nextt->next!=NULL){
        nextt= nextt->next;}
        
    }
    
    current->next = prev;
    
    printList(current);


    return 0;
}