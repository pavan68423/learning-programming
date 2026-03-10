#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void push_front(int value) {
    if (front == 0) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = value;
}

void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }
    if (rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}

void pop_front() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Removed from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void pop_back() {
    if (rear == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Removed from rear: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

void get_front() {
    if (front == -1)
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void get_back() {
    if (rear == -1)
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

void size() {
    if (front == -1)
        printf("Size: 0\n");
    else
        printf("Size: %d\n", rear - front + 1);
}

void empty() {
    if (front == -1)
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    display();

    pop_front();
    pop_back();

    display();

    get_front();
    get_back();

    size();
    empty();

    return 0;
}
