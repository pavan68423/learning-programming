#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void printRightView(struct Node* root, int n) {
    if (!root) return;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[head++];

            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* nodes[n];
    for (int i = 0; i < n; i++) nodes[i] = newNode(arr[i]);

    int childIdx = 1;
    for (int i = 0; i < n && childIdx < n; i++) {
        if (nodes[i] != NULL) {
            nodes[i]->left = nodes[childIdx++];
            if (childIdx < n)
                nodes[i]->right = nodes[childIdx++];
        }
    }

    printRightView(nodes[0], n);
    printf("\n");

    return 0;
}
