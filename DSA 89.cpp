#include <stdio.h>
#include <stdbool.h>

// Function to check if a middle value 'mid' is a feasible maximum
bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            // If students exceed m or a single book is larger than mid
            if (studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1; // Not enough books for each student

    int sum = 0;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int start = maxVal; // Minimum possible max is the largest single book
    int end = sum;      // Maximum possible max is the sum of all books
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1; // Try to find a smaller maximum
        } else {
            start = mid + 1; // Increase the allowed maximum
        }
    }
    return ans;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", allocateBooks(arr, n, m));

    return 0;
}
