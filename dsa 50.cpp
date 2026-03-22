#include <stdio.h>
#include <stdlib.h> // This fixes the 'NULL' error

// This fixes the 'incomplete type' error
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Now the function will work
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Check if root is null or if we found the value
    if (root == NULL || root->val == val) {
        return root;
    }

    // Binary Search Logic
    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}
