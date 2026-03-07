#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Get the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        
        // Allocate memory for the new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself initially
            temp = head;
        } else {
            temp->next = newNode;
            newNode->next = head; // Maintain the circular link
            temp = newNode;       // Move temp to the last node
        }
    }

    // Traversal
    if (head != NULL) {
        struct Node* current = head;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }

    return 0;
}
