#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create()
 {
    struct node *head = NULL, *newnode, *temp;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
            head = newnode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    return head;
}
void display(struct node *head) {
    struct node *temp = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void sort(struct node *head) {
    struct node *i, *j;
    int temp;
    for(i = head; i != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next){
            if(i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Sorted list: ");
    display(head);
}
struct node* reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp;
    if(head1 == NULL)
        return head2;
    temp = head1;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}
int main() {
    struct node *head1, *head2, *head3;
    int ch;
    printf("\nCreate First Linked List\n");
    head1 = create();
    printf("\nCreate Second Linked List\n");
    head2 = create();
    do {
        printf("\n1. Sort Linked List");
        printf("\n2. Reverse Linked List");
        printf("\n3. Concatenate Two Linked Lists");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                sort(head1);
                break;
            case 2:
                head1 = reverse(head1);
                printf("Reversed list: ");
                display(head1);
                break;
            case 3:
                head3 = concatenate(head1, head2);
                printf("Concatenated list: ");
                display(head3);
                break;
            case 4:
                printf("First list: ");
                display(head1);
                printf("Second list: ");
                display(head2);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(ch != 5);
    return 0;
}
