#include <stdio.h>
#include <stdlib.h>

// Definition of a BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* node, int value) {
    // 1. If the tree/subtree is empty, return a new node
    if (node == NULL) return newNode(value);

    // 2. Otherwise, recur down the tree
    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    // Return the (unchanged) node pointer
    return node;
}

// Function for In-order traversal to verify the tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    
    // Example insertions
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST: ");
    inorder(root);

    return 0;
}
