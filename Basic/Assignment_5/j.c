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

void printLL(struct Node * head)
{ 
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}



//1
void nowPlaying(struct Node * playing)
{
    printf("%d\n", playing->data);
}

//2
void addSong(struct Node * playing, int data)
{
    struct Node * toAdd = (struct Node *)malloc(sizeof(struct Node));
    toAdd -> data = data;
    toAdd -> next = playing -> next;
    toAdd -> pre = playing;
    playing -> next = toAdd;
    (toAdd -> next) -> pre = toAdd;
}

//3
void insertAtTail(struct Node * head, int data)
{
    if(head -> data == 0)
    {
        head -> data = data;
        return;
    }
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp -> next;
    }
    struct Node * toAdd = (struct Node *)malloc(sizeof(struct Node));
    toAdd -> data = data;
    toAdd -> next = NULL;
    toAdd -> pre = temp;
    temp -> next = toAdd;
}

//4
struct Node * playNext(struct Node * playing)
{
    if(playing->next == NULL)
    {
        return playing;
    }
    else
    {
        return (playing->next);
    }
}

//5
struct Node * playPrev(struct Node * playing)
{
    if(playing->pre == NULL)
    {
        return playing;
    }
    else
    {
        return (playing->pre);
    }
}

//6
struct Node * deleteAndNext(struct Node * playing, struct Node * head)
{
    if(playing -> data == 0)
    {
        return playing;
    }
    if(playing -> next == NULL)
    {
        if(playing->pre == NULL)
        {
            playing -> data = 0;
            return playing;
        }
        else
        {
            (playing -> pre) -> next = NULL;
            playing = head;
            return playing;
        }
    }
    else
    {
        if(playing -> pre == NULL)
        {
            playing = playing->next;
            playing->pre = NULL;
            return playing;
        }
        else
        {
            (playing->pre)-> next = (playing->next);
            (playing->next)->pre = playing->pre;
            playing = playing -> next; 
            return playing;
        }
    }
}


int main()
{
    int n, q;
    scanf("%d",&n);
    scanf("%d",&q);
    
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * playing = (struct Node *)malloc(sizeof(struct Node));
    int temp;
    scanf("%d", &temp);
    makeNode(head, temp);
    playing = head;
    for(int i = 0; i<n-1 ;i++)
    {
        scanf("%d", &temp);
        insertAtTail(head, temp);
    }

    

    for(int i = 0; i<q ;i++)
    {
        int a;
        scanf("%d",&a);

        if(a == 1)
        {
            nowPlaying(playing);
        }
        else if(a == 2)
        {
            int b;
            scanf("%d",&b);
            addSong(playing, b);
        }
        else if(a == 3)
        {
            int b;
            scanf("%d",&b);
            insertAtTail(head, b);
        }
        else if(a == 4)
        {
            playing = playNext(playing);
        }
        else if(a == 5)
        {
            playing = playPrev(playing);
        }
        else if(a == 6)
        {
            playing = deleteAndNext(playing, head);
        }
        
    }
}