#include <stdio.h>
#define MAX 100 // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function to add an element to the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Function to remove and return the top element
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

// Function to print stack elements from top to bottom
void display() {
    if (top == -1) {
        return; // Stack is empty
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, value;
    
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        }
    }

    return 0;
}
