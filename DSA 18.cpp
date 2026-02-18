#include <stdio.h#>
// Helper function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
      
	    start++;
        end--;
    }
}

int main() {
    int n, k;

    // Input size of array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input rotation steps
    scanf("%d", &k);

    // Optimization: if k > n, k % n gives the effective rotations
    k = k % n;

    if (k > 0) {
        // Step 1: Reverse the entire array
        // [1, 2, 3, 4, 5] -> [5, 4, 3, 2, 1]
        reverse(arr, 0, n - 1);

        // Step 2: Reverse the first k elements
        // [5, 4, 3, 2, 1] -> [4, 5, 3, 2, 1]
        reverse(arr, 0, k - 1);

        // Step 3: Reverse the rest
        // [4, 5, 3, 2, 1] -> [4, 5, 1, 2, 3]
        reverse(arr, k, n - 1);
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
