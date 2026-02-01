#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000]; // assuming max size
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    scanf("%d", &pos); // 1-based position
    scanf("%d", &x);

    // Shift elements to the right from the end
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert x at position (convert to 0-based index)
    arr[pos - 1] = x;

    // Print updated array (size n+1)
    for (int i = 0; i <= n; i++) {
        printf("%d", arr[i]);
        if (i < n) printf(" ");
    }
    printf("\n");

    return 0;
}

