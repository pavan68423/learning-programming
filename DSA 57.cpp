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


void mirror(struct Node* node) {
    if (node == NULL) return;


    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}


void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}


struct Node* buildTree(int n) {
    if (n <= 0) return NULL;
    
    int val;
    scanf("%d", &val);
    struct Node* root = newNode(val);
    if (!root) return NULL;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    for (int i = 1; i < n; ) {
        struct Node* curr = queue[head++];
        

        scanf("%d", &val);
        if (val != -1) {
            curr->left = newNode(val);
            queue[tail++] = curr->left;
        }
        i++;
        if (i >= n) break;

        
        scanf("%d", &val);
        if (val != -1) {
            curr->right = newNode(val);
            queue[tail++] = curr->right;
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Node* root = buildTree(n);
    mirror(root);
    printInorder(root);
    printf("\n");

    return 0;
}
