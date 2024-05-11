#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};


void deleteNode(struct Node* prev,struct Node* node){
    
    prev->next = node->next;
    node->next =NULL;
    
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

    int n, k, val;
    scanf("%d", &n);
    scanf("%d", &k);

    // Input values and create the linked list for head1
    for (int i = 0; i < n; i++) {
        add(&head, i+1); //linked list created from 1 to n
    }
    
    struct Node* temp = head;
    struct Node* first = head;
    
    while(temp->next!=NULL){
        temp = temp->next;
    }
    
    temp->next = head;
    temp= head;
    
    int p =k-1;
    while(n>1){
        if(p==1){
            deleteNode(temp,temp->next);
            p=k-1;
            temp = temp->next;
            n--;
        }
        else{
            temp = temp->next;
            p--;
        }
    }
    
    printf("%d",temp->data);
    return 0;
}