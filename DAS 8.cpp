#include <stdio.h>

// Recursive function to calculate power
long long power(int a, int b) {
    // Base case: if exponent is 0, return 1
    if (b == 0) {
        return 1;
    }
    // Recursive call: a * a^(b-1)
    else {
        return a * power(a, b - 1);
    }
}

int main() {
    int a, b;
    
    // Taking input from the user
    if (scanf("%d %d", &a, &b) == 2) {
        // Handling negative exponents (optional but good practice)
        if (b < 0) {
            printf("This specific logic handles non-negative exponents.\n");
        } else {
            printf("%lld\n", power(a, b));
        }
    }
    
    return 0;
}
