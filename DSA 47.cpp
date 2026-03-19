#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the height of the tree
int getHeight(struct Node* node) {
    if (node == NULL) {
        // Return -1 for an empty tree (edges count)
        // Return 0 if you want to count nodes instead
        return -1; 
    } else {
        // Compute the height of each subtree
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        // Use the larger one
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

int main() {
    // Constructing a sample tree:
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    printf("Height of the tree is: %d", getHeight(root));

    return 0;
}
