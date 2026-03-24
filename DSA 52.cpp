#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If either n1 or n2 matches the root's key, report the presence
    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    // If both return non-NULL, this node is the LCA
    if (leftLCA && rightLCA) return root;

    // Otherwise return the non-NULL child
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}


struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    struct Node* root = newNode(arr[0]);
    queue[0] = root;
    
    int head = 0, tail = 1, i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[tail++] = curr->left;
        }
        i++;
        
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[tail++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

int main() {
    int n, n1, n2;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, n1, n2);

    if (lca) printf("%d\n", lca->data);

    return 0;
}
