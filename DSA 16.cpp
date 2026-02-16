#include <stdio.h>

int main() {
    int n;

    // 1. Get the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    int visited[n]; // Array to keep track of elements already counted

    // 2. Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize visited status as 0 (false)
    }

    // 3. Logic to count frequencies
    for (int i = 0; i < n; i++) {
        // Skip this element if it has already been processed
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1; // Mark the duplicate as visited
                count++;
            }
        }

        // 4. Print the result for this distinct element
        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
