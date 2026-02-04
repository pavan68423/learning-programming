#include <stdio.h>

void reverseArray(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int temp;

    while (left < right) {
        // Standard swap logic using a temporary variable
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move the pointers
        left++;
        right--;
    }
}

int main() {
    int n;

    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Read n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform the in-place reversal
    reverseArray(arr, n);

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
