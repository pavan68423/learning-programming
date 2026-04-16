#include <stdio.h>

struct Node {
    int sum;
    int index;
};

int findLongestZeroSumSubarray(int arr[], int n) {
    
    int max_len = 0;
    int prefix_sum = 0;

  
    
    for (int i = 0; i < n; i++) {
        prefix_sum = 0;
        for (int j = i; j < n; j++) {
            prefix_sum += arr[j];

            if (prefix_sum == 0) {
                int current_len = j - i + 1;
                if (current_len > max_len) {
                    max_len = current_len;
                }
            }
        }
    }
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findLongestZeroSumSubarray(arr, n);
    printf("%d\n", result);

    return 0;
}
