#include <stdio.h>

// Recursive function to print string in mirror format
void mirror(char *str) {
    // Base case: if the character is the null terminator, return
    if (*str == '\0') {
        return;
    }

    // Recursive call: move to the next character
    mirror(str + 1);

    // This line executes as the recursion "unwinds"
    printf("%c", *str);
}

int main() {
    char codeName[100];

    // Read the string input
    if (scanf("%s", codeName) == 1) {
        mirror(codeName);
        printf("\n"); // Print a newline for clean output
    }

    return 0;
}
