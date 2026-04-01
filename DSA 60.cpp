#include <stdio.h>
#include <stdbool.h>


bool isMinHeap(int arr[], int n) {
    
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        int leftChild = 2 * i + 1;
        if (leftChild < n && arr[i] > arr[leftChild]) {
            return false;
        }

        int rightChild = 2 * i + 2;
        if (rightChild < n && arr[i] > arr[rightChild]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
