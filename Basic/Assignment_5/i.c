#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
};

// Function to add a new element to the end of the linked list
void add(struct Node** head, char val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev =NULL;

    if (*head == NULL) {
        *head = new_node; // If the list is empty, make the new node the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = new_node; // Add the new node at the end
        new_node->prev = temp;
    }
}

int main() {
    struct Node* head1 = NULL; // Head of the first linked list
    struct Node* head2 = NULL; // head 2 being the last element head

    int n, m;
    char val;
    scanf("%d", &n);
    
    getchar();//this takes away the whitespace
    
    // Input values and create the linked list for head1
    for (int i = 0; i < n; i++) {
        scanf("%c", &val);
        add(&head1, val);
    }
    
    
    head2 = head1;
    
    while(head2->next!=NULL){
        head2 = head2->next;
    }
    // head2 points to the end head1 points to beginning

    int c =1;
    
    while(head1!=head2){
        if(head1->data != head2->data){
            c=0;
            break;
        }
        head1 = head1->next;
        head2 = head2->prev;
    }
    
    if(c){
        printf("YES");
    }
    else{
        printf("NO");
    }

    
    return 0;
}