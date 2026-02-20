#Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    return (x > y) - (x < y);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long *arr = (long long *)malloc(sizeof(long long) * n);
    long long *prefix_sums = (long long *)malloc(sizeof(long long) * (n + 1));

    prefix_sums[0] = 0;
    long long current_sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        current_sum += arr[i];
        prefix_sums[i + 1] = current_sum;
    }

    // Sort prefix sums to easily find duplicates
    qsort(prefix_sums, n + 1, sizeof(long long), compare);

    long long count = 0;
    long long freq = 1;

    // Use Combinatorics: If a sum appears 'f' times, 
    // it forms fC2 (f * (f-1) / 2) zero-sum subarrays.
    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            freq++;
        } else {
            count += (freq * (freq - 1)) / 2;
            freq = 1;
        }
    }
    // Add the last group
    count += (freq * (freq - 1)) / 2;

    printf("%lld\n", count);

    free(arr);
    free(prefix_sums);
    return 0;
}
