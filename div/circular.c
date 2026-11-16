#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void create() {
    struct node *newnode, *temp;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        if(head == NULL) {
            head = newnode;
            newnode->next = head;
        }
        else {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
        }
    }
}
void insertPosition() {
    struct node *newnode, *temp;
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos < 1) {
        printf("Invalid position\n");
        return;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if(pos == 1) {
        if(head == NULL) {
            head = newnode;
            newnode->next = head;
        }
        else {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            newnode->next = head;
            temp->next = newnode;
            head = newnode;
        }
        return;
    }
    temp = head;
    for(i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;
    if(head == NULL || i != pos - 1) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteNode() {
    struct node *temp, *prev;
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    if(head->data == value) {
        if(head->next == head) {
            free(head);
            head = NULL;
        }
        else {
            struct node *last = head;
            while(last->next != head)
                last = last->next;
            last->next = head->next;
            temp = head;
            head = head->next;
            free(temp);
        }
        printf("Node deleted\n");
        return;
    }
    prev = head;
    temp = head->next;
    while(temp != head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == head) {
        printf("Value not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted\n");
}
void display() {
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("(Back to Head)\n");
}
int main() {
    int ch;
    create();
    do {
        printf("\n1.Insert at position");
        printf("\n2.Delete a node");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insertPosition(); break;
            case 2: deleteNode(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    } while(ch != 4);
    return 0;
}
