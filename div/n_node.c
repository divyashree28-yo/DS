#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *head=NULL, *tail=NULL, *newNode, *temp;
    int i,n,value;
    printf("enter the value of n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("enter the value %d:",i);
        scanf("%d",&value);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
          tail->next = newNode;
          tail = newNode;
        }
    }
    temp=head;
    while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    return 0;
}
