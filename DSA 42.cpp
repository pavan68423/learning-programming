#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

// Queue structure
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int val) {
    queue[++rear] = val;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, val;

    // Input N
    if (scanf("%d", &n) != 1) return 0;

    // Input N integers and Enqueue them
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    // Step 1: Dequeue from Queue and Push to Stack
    while (front <= rear) {
        push(dequeue());
    }

    // Step 2: Pop from Stack and Enqueue back to Queue
    // (In this simple array version, we'll reset indices for clarity)
    front = 0; rear = -1;
    while (top != -1) {
        enqueue(pop());
    }

    // Output the reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d%s", queue[i], (i == rear ? "" : " "));
    }
    printf("\n");

    return 0;
}
