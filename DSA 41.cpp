#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the Queue structure to keep track of Front and Rear
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* newNode(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int k) {
    struct Node* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;

    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'e') { // "enqueue"
            int val;
            scanf("%d", &val);
            enqueue(q, val);
        } else if (op[0] == 'd') { // "dequeue"
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}
