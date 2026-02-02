#include <stdio.h>

int main() {
    int n, pos;

    // Input the size of the array
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];

    // Input the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the 1-based position to delete
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || pos > n) {
        // If position is invalid, we print nothing or the original array
        // Based on typical competitive programming, we assume pos is valid.
        return 0;
    }

    // Shifting elements to the left
    // We start from the index to be deleted (pos - 1)
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print the updated array (n-1 elements)
    for (int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i < n - 2) {
            printf(" "); // Print space between elements
        }
    }
    printf("\n");

    return 0;
}
