#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *newnode, *temp;
    newnode = malloc(sizeof(struct Node));
    newnode->data = 50;
    newnode->next = NULL;
    printf("Data of node=%d\n",newnode->data);
    if(newnode->next==NULL)
        printf("NULL\n");
    return 0;
}
