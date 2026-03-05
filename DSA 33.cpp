#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to return precedence of operators
int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix) {
    char stack[100];
    int top = -1;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // 1. If operand, print it
        if (isalnum(ch)) {
            printf("%c", ch);
        } 
        // 2. If '(', push to stack
        else if (ch == '(') {
            stack[++top] = ch;
        } 
        // 3. If ')', pop until '('
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--; // pop '('
        } 
        // 4. If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = ch;
        }
    }

    // Pop remaining operators
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    char exp[] = "A+B*C";
    infixToPostfix(exp);
    return 0;
}
