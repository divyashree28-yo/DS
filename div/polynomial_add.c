#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int c, int p) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int c, int p) {
    struct Node* newNode = createNode(c, p);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* readPolynomial() {
    struct Node* poly = NULL;
    int c, p;
    printf("Enter coefficient and power (enter -1 -1 to end)\n");
    printf("Enter terms in descending order of power: ");
    while (1) {
        scanf("%d %d", &c, &p);
        if (c == -1 && p == -1) break;
        insertEnd(&poly, c, p);
    }
    return poly;
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            insertEnd(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insertEnd(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            insertEnd(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertEnd(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertEnd(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%d %d", poly->coeff, poly->pow);
        if (poly->next != NULL) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    printf("First polynomial\n");
    struct Node* p1 = readPolynomial();

    printf("\nSecond polynomial\n");
    struct Node* p2 = readPolynomial();

    struct Node* sum = addPolynomials(p1, p2);

    printf("\nP1 = ");
    printPolynomial(p1);
    printf("P2 = ");
    printPolynomial(p2);
    printf("P1 + P2 = ");
    printPolynomial(sum);

    return 0;
}
