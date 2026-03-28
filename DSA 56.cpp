#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node *left, *right;
};


struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}


bool isMirror(struct Node* root1, struct Node* root2) {
    
    if (root1 == NULL && root2 == NULL)
        return true;

    
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right) && 
               isMirror(root1->right, root2->left);

    return false;
}


bool isSymmetric(struct Node* root) {
    return isMirror(root, root);
}


int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n == 0) {
        printf("YES\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }

    int childIdx = 1;
    for (int i = 0; i < n && childIdx < n; i++) {
        if (nodes[i] != NULL) {
            nodes[i]->left = nodes[childIdx++];
            if (childIdx < n)
                nodes[i]->right = nodes[childIdx++];
        }
    }

    if (isSymmetric(nodes[0])) printf("YES\n");
    else printf("NO\n");

    return 0;
}
