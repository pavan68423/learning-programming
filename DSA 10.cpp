#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int left, right, isPalindrome = 1;

    // Reading the input string
    if (scanf("%s", s) != 1) return 0;

    left = 0;
    right = strlen(s) - 1;

    // Two-pointer comparison
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0; // Found a mismatch
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
