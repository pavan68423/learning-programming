#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = preorder[(*preIndex)++];
    newNode->left = newNode->right = NULL;

    if (inStart == inEnd) return newNode;

    int inIndex = findIndex(inorder, inStart, inEnd, newNode->data);

    newNode->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    newNode->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return newNode;
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printPostorder(root);
    printf("\n");

    return 0;
}
