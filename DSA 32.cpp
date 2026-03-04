#include <stdio.h>

int main() {
    int n, m;

    // Read number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    int stack[n];
    int top = -1; // Stack is initially empty

    // Push operations
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        stack[++top] = value; // Increment top and add value
    }

    // Read number of pops
    if (scanf("%d", &m) != 1) return 0;

    // Pop operations
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--; // Simply decrement the top pointer
        }
    }

    // Print remaining elements from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }

    return 0;
}
