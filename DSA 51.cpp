#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert nodes into the BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

// Function to find the LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller than root, LCA is in left
    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);

    // If both n1 and n2 are greater than root, LCA is in right
    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);

    // We have found the split point
    return root;
}

int main() {
    int n, val, n1, n2;
    struct Node* root = NULL;

    // Input handling
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);
    
    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}
