#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printZigZag(struct Node* root) {
    if (!root) return;

    struct Node* s1[1000]; 
    struct Node* s2[1000];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 >= 0 || top2 >= 0) {
        while (top1 >= 0) {
            struct Node* curr = s1[top1--];
            printf("%d ", curr->data);

            if (curr->left) s2[++top2] = curr->left;
            if (curr->right) s2[++top2] = curr->right;
        }

        while (top2 >= 0) {
            struct Node* curr = s2[top2--];
            printf("%d ", curr->data);

            if (curr->right) s1[++top1] = curr->right;
            if (curr->left) s1[++top1] = curr->left;
        }
    }
}

struct Node* buildTree(int n, int arr[]) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* queue[1000];
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(n, arr);
    printZigZag(root);

    return 0;
}
