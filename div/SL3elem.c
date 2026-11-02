#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *first, *second, *third, *temp;
    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    first->data = 10;
    second->data = 20;
    third->data = 30;
    first->next = second;
    second->next = third;
    third->next = NULL;
    printf("first node=%d\n", first->data);
    printf("second node=%d\n", second->data);
    printf("third node=%d\n", third->data);
    printf("the linked list:\n");
    temp = first;
    if (temp == NULL) {
        printf("empty list\n");
    } else {
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    free(first);
    free(second);
    free(third);
    return 0;
}
