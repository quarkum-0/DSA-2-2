#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void printForward(struct Node* head) {
    if(head==NULL){
        printf("-1");
        return;
    }
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

void printBack(struct Node* head) {
    if(head==NULL){
        printf("-1");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->prev != NULL) {
            printf(" ");
        }
        current = current->prev;
    }
    printf("\n");
}

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
            if (head1==NULL){
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&val2);
            new_node->data = val2;
            new_node->next = NULL;
            new_node->prev =NULL;
                head1= new_node;
            }
            else{
            
                struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
                scanf("%d",&val2);
                new_node->data = val2;
                new_node->next = head1;
                new_node->prev =NULL;
                head1->prev = new_node;
                head1= new_node;
                
            }
        }        
        if(val == 2){
            if (last==NULL){
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&val2);
            new_node->data = val2;
            new_node->next = NULL;
            new_node->prev =NULL;
                last= new_node;
            }
            else{
            
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&val2);
            new_node->data = val2;
            new_node->next = NULL;
            last->next = new_node;
            new_node->prev = last;
            last =new_node;}
        }        
        if(val == 3){
            if(head1==last){head1=NULL;
                last=NULL;}
            else{
            head1 =head1->next;
            head1->prev= NULL;}
        }        
        if(val == 4){
            if(head1==last){head1=NULL;
                last=NULL;
            }
            else{            last =last->prev;
            last->next= NULL;}
        }        
        if(val == 5){
            printForward(head1);
        }        
        if(val == 6){
            printBack(last);
        }
        
        
    }
    
    
    return 0;
}