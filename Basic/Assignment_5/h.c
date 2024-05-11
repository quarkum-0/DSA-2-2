#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    struct Node * pre;
};
void makeNode(struct Node * head, int data)
{
    head -> data = data;
    head -> next = NULL;
    head -> pre = NULL;
}
void insertAtTail(struct Node * head, int data)
{
    if(head -> data == -1)
    {
        head -> data = data;
        return;
    }
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp->next;
    }
    struct Node * toAdd = (struct Node *)malloc(sizeof(struct Node));
    toAdd -> data = data;
    toAdd -> next = NULL;
    toAdd -> pre = temp;
    temp -> next = toAdd;
}
struct Node * insertAtHead(struct Node * head, int data)
{
    if(head -> data == -1)
    {
        head -> data = data;
        return head;
    }
    struct Node * toAdd = (struct Node *)malloc(sizeof(struct Node));
    toAdd -> data = data;
    toAdd -> next = head;
    toAdd -> pre = NULL;
    head -> pre = toAdd;
    return toAdd;  
}

void printLL(struct Node * head)
{
    if(head->data == -1)
    {
        printf("-1\n");
        return;
    }
    
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void printLLrev(struct Node * head)
{
    if(head->data == -1)
    {
        printf("-1\n");
        return;
    }
    
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp -> pre;
    }
    printf("\n");
}
struct Node * deleteHead(struct Node * head)
{
    if(head -> next == NULL)
    {
        head -> data = -1;
        return head;
    }
    else
    {
        (head -> next) -> pre = NULL;
        return head->next;
    }
}
void deleteTail(struct Node * head)
{
    if(head -> next == NULL)
    {
        head -> data = -1;
        return;
    }
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while((temp->next)->next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = NULL;
}

int main()
{   
    int n, q;
    scanf("%d %d",&n, &q);
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    int temp;
    scanf("%d", &temp);
    makeNode(head, temp);
    for(int i = 0; i<n-1 ;i++)
    {
        scanf("%d", &temp);
        insertAtTail(head, temp);
    }

    // printLL(head);   

    for(int i = 0; i<q ;i++)
    {
        int opr;
        scanf("%d",&opr);

        if(opr == 1)
        {
            int data;
            scanf("%d", &data);
            head = insertAtHead(head, data);
        }
        else if(opr == 2)
        {
            int data;
            scanf("%d", &data);
            insertAtTail(head, data);
        }
        else if(opr == 3)
        {
            head = deleteHead(head);
        }
        else if(opr == 4)
        {
            deleteTail(head);
        }
        else if(opr == 5)
        {
            printLL(head);
        }
        else if(opr == 6)
        {
            printLLrev(head);
        }
    }
 


    return 0;
}