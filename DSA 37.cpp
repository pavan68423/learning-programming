#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Essential for strcmp

#define MAX_SIZE 1001

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void bubbleDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        bubbleDown(smallest);
    }
}

void insert(int x) {
    if (size < MAX_SIZE) {
        heap[size] = x;
        bubbleUp(size);
        size++;
    }
}

void deleteMin() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
        heap[0] = heap[size - 1];
        size--;
        bubbleDown(0);
    }
}

void peek() {
    if (size == 0) printf("-1\n");
    else printf("%d\n", heap[0]);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[20];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            deleteMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    return 0;
}
