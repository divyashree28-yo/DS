#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int value)
{
    struct node *newNode = createNode(value);
    if (head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}
void deleteByValue(int key)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *del = head;
    while (del != NULL && del->data != key)
        del = del->next;
    if (del == NULL)
    {
        printf("%d not found\n", key);
        return;
    }
    if (del->prev != NULL)
        del->prev->next = del->next;
    else
        head = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    printf("Deleted %d\n", del->data);
    free(del);
}
void display(void)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(void)
{
    insertAtBeginning(30);
    insertAtBeginning(20);
    printf("original list:");
    display();
    insertAtBeginning(10);
    printf("after inserting 10 at beginning:");
    display();
    deleteByValue(20);
    display();
    return 0;
}




