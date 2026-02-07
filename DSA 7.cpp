#include <stdio.h>

// Recursive function to find the n-th Fibonacci number
int fib(int n) {
    // Base cases: if n is 0 or 1, return n
    if (n <= 1) {
        return n;
    }
    // Recursive step: sum of the two preceding numbers
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    
    // Taking input from the user
    if (scanf("%d", &n) == 1) {
        printf("%d\n", fib(n));
    }

    return 0;
}
