#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rear = NULL;

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (rear == NULL) {
        rear = newNode;
        rear->next = rear; // Points to itself
    } else {
        newNode->next = rear->next; // New node points to Front
        rear->next = newNode;       // Old Rear points to new node
        rear = newNode;             // Update Rear pointer
    }
}

void dequeue() {
    if (rear == NULL) return;

    struct Node* front = rear->next;
    if (front == rear) { // Only one node in the queue
        free(front);
        rear = NULL;
    } else {
        rear->next = front->next; // Bypass the front node
        free(front);
    }
}

void display() {
    if (rear == NULL) return;

    struct Node* temp = rear->next; // Start from Front
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    printf("\n");
}

int main() {
    int n, m, val;

    // Input number of elements and enqueue them
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    // Input number of dequeue operations
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        // In a true circular queue, we often re-enqueue the dequeued value 
        // to maintain the "circular" output shown in your example.
        int dequeuedVal = rear->next->data;
        dequeue();
        enqueue(dequeuedVal);
    }

    display();

    return 0;
}
