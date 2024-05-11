#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

// Function to add a new element to the end of the linked list
void add(struct Node** head, int val) {
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
    struct Node* last = NULL; // head 2 being the last element head
    struct Node* temp = NULL;
    
    int n, q;
    int val,val2;
    scanf("%d", &n);
    scanf("%d", &q);
    

    // Input values and create the linked list for head1
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        add(&head1, val);
    }
    
    
    last = head1;
    temp = head1;
    
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = NULL;
    head1->prev = NULL;
    
    
    // last points to the end head1 points to beginning
    
    for(int i=0;i<q; i++){
        
        scanf("%d",&val);
        
        if(val == 1){
            printf("%d ",temp->data);
        }        
        if(val == 2){
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));            scanf("%d",&val2);
            new_node->data = val2;
            new_node->next = temp->next;
            temp->next = new_node;
            new_node->prev = temp;
        }        
        if(val == 3){
            struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            scanf("%d", &val2);
            new_node->data = val2;
            new_node->prev = last;
            new_node->next = head1;
            last->next = new_node;
            last = new_node;
        }        
        if(val == 4){
            if(temp->next!=NULL){
            temp = temp->next;}
        }        
        if(val == 5){
            if(temp->prev!=NULL){
            temp = temp->prev;}
        }        
        if(val == 6){
            if(temp->prev!=NULL && temp->next!=NULL){
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            temp = temp->next;}
            
            else if(temp->prev == NULL){
                temp = temp->next;
                temp->prev =  NULL;
            }
            else if(temp->next==NULL){
                temp=temp->prev;
                temp->next =NULL;
            }
        }
        
        
    }
    
    
    return 0;
}