#include <stdio.h>
#include <stdlib.h>


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


void printRightView(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
       
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct Node* current = queue[front++];

            if (i == levelSize - 1) {
                printf("%d ", current->data);
            }

           
            if (current->left != NULL) queue[rear++] = current->left;
            if (current->right != NULL) queue[rear++] = current->right;
        }
    }
}

struct Node* buildTree(int n, int arr[]) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(n, arr);
    printRightView(root);

    return 0;
}
