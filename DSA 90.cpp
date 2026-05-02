#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Helper function to check if a valid partition is possible for a given maximum time
bool isPossible(int* boards, int n, int k, long long max_time) {
    long long current_time = 0;
    int painters_count = 1;

    for (int i = 0; i < n; i++) {
        // If a single board length exceeds the maximum time, it's invalid
        if (boards[i] > max_time) {
            return false;
        }

        if (current_time + boards[i] > max_time) {
            painters_count++;
            current_time = boards[i]; // Start with the new board for the next painter
        } else {
            current_time += boards[i];
        }
    }

    return painters_count <= k;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int* boards = (int*)malloc(n * sizeof(int));
    long long low = 0;
    long long high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > low) {
            low = boards[i]; // Max board length
        }
        high += boards[i]; // Sum of all board lengths
    }

    long long ans = high;

    // Binary search for the minimum possible maximum time
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid; // Found a valid time, try for a smaller time
            high = mid - 1;
        } else {
            low = mid + 1; // Time is too small, increase it
        }
    }

    printf("%lld\n", ans);

    free(boards);
    return 0;
}
