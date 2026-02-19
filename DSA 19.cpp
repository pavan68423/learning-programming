#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestToZero(int arr[], int n) {
    if (n < 2) return;

    // 1. Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int res_l = 0, res_r = n - 1;

    // 2. Two-pointer approach
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Check if this pair is closer to zero than the previous best
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            res_l = left;
            res_r = right;
        }

        // Move pointers based on sum
        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    printf("%d %d\n", arr[res_l], arr[res_r]);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findClosestToZero(arr, n);

    return 0;
}
