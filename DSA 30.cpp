#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(struct Node** head, int c, int e) {
    struct Node* newNode = createNode(c, e);
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

// Function to display the polynomial
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        // Handle coefficient and x^exp
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // Print " + " only if there's a next term
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly = NULL;
    int n, c, e;

    // Input number of terms
    if (scanf("%d", &n) != 1) return 0;

    // Input each term
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        insertNode(&poly, c, e);
    }

    // Output the result
    display(poly);

    return 0;
}
