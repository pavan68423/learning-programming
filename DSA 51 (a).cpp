#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Standard BST insertion to build the tree from input
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// The Core LCA Logic
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    while (root != NULL) {
        // If both p and q are smaller than root, LCA is in left
        if (p < root->val && q < root->val) {
            root = root->left;
        }
        // If both p and q are larger than root, LCA is in right
        else if (p > root->val && q > root->val) {
            root = root->right;
        }
        // We found the split point
        else {
            return root;
        }
    }
    return NULL;
}

int main() {
    int n, val, p, q;
    struct TreeNode* root = NULL;

    // Input: Number of nodes
    if (scanf("%d", &n) != 1) return 0;

    // Input: N space-separated integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input: The two nodes to find LCA for
    scanf("%d %d", &p, &q);

    struct TreeNode* lca = findLCA(root, p, q);

    if (lca != NULL) {
        printf("%d\n", lca->val);
    }

    return 0;
}
