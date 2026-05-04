#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the value and its original index
typedef struct {
    int val;
    int index;
} Element;

// Compare function for qsort to sort elements by value
int compare(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    if (e1->val != e2->val) {
        return e1->val - e2->val;
    }
    return e1->index - e2->index;
}

// Fenwick Tree update operation
void update(int* bit, int index, int val, int n) {
    for (; index <= n; index += index & -index) {
        bit[index] += val;
    }
}

// Fenwick Tree prefix sum operation
int query(int* bit, int index) {
    int sum = 0;
    for (; index > 0; index -= index & -index) {
        sum += bit[index];
    }
    return sum;
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize == 0) {
        return NULL;
    }

    int* counts = (int*)malloc(numsSize * sizeof(int));
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    // Sort the array to map values to ranks
    qsort(arr, numsSize, sizeof(Element), compare);

    // Coordinate compression
    int* ranks = (int*)malloc(numsSize * sizeof(int));
    int rank = 1;
    ranks[arr[0].index] = 1;

    for (int i = 1; i < numsSize; i++) {
        if (arr[i].val != arr[i - 1].val) {
            rank++;
        }
        ranks[arr[i].index] = rank;
    }

    // Initialize Fenwick Tree
    int* bit = (int*)calloc(rank + 1, sizeof(int));

    // Iterate backwards and populate counts
    for (int i = numsSize - 1; i >= 0; i--) {
        // Query elements strictly smaller than ranks[i] (i.e., ranks[i] - 1)
        counts[i] = query(bit, ranks[i] - 1);
        // Add current element rank to the BIT
        update(bit, ranks[i], 1, rank);
    }

    // Clean up allocated memory
    free(arr);
    free(ranks);
    free(bit);

    return counts;
}
