#include <stdio.h>
#include <stdlib.h>

// Definition of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Standard Queue implementation for Tree Nodes
struct Queue {
    int front, rear, size;
    int capacity;
    struct Node** array;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Helper functions for Queue management
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

void enqueue(struct Queue* queue, struct Node* item) {
    if (item == NULL) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

struct Node* dequeue(struct Queue* queue) {
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Core Function: Level Order Traversal
void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue(100); // Adjust capacity as needed

    enqueue(queue, root);

    while (queue->size > 0) {
        struct Node* tempNode = dequeue(queue);

        printf("%d ", tempNode->data);

        if (tempNode->left != NULL)
            enqueue(queue, tempNode->left);

        if (tempNode->right != NULL)
            enqueue(queue, tempNode->right);
    }
    
    free(queue->array);
    free(queue);
}

int main() {
    // Constructing a sample tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    printLevelOrder(root);
    printf("\n");

    return 0;
}
