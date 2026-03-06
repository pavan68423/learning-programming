#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for the linked list stack
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element to the stack
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Error\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i]; ++i) {
        // Skip whitespace
        if (exp[i] == ' ') continue;

        // If character is a digit, handle multi-digit numbers
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--; // Adjust for the outer loop increment
            push(&stack, num);
        } 
        // If character is an operator
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            
            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char exp[] = "2 3 1 * + 9 -";
    printf("Output: %d\n", evaluatePostfix(exp));
    return 0;
}
