#include <stdio.h>

int main() {
    int n, i;

    // Read the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1; // Exit if input is invalid or size is 0
    }

    int arr[n];

    // Read n integers into the array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min with the first element
    int max = arr[0];
    int min = arr[0];

    // Iterate through the array to find max and min
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Output the results
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
