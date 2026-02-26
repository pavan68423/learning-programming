#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Doubly Linked List node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node and insert it at the end
void insertEnd(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update pointers for the new node and the previous last node
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print the list in forward order
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    // Input the number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Input elements and build the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    // Output the list
    displayList(head);

    return 0;
}
