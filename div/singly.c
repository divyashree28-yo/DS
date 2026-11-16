#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertBegin(int value)
{
    struct Node *newNode=createNode(value);
    newNode->next=head;
    head=newNode;
}
void insertEnd(int value)
{
    struct Node *newNode=createNode(value);
    struct Node *temp;
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}
void insertAfter(int pos, int value)
{
    struct Node *newNode, *temp = head;
    int i;
    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
void display(void)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(void)
{
    insertEnd(20);
    insertEnd(30);
    printf("original list:");
    display();
    insertBegin(10);
    printf("after inserting 10 at beginning:");
    display();
    insertEnd(40);
    printf("after inserting 40 at end:");
    display();
    insertAfter(2,25);
    printf("after inserting 25 after position 2:");
    display();
    return 0;
}
