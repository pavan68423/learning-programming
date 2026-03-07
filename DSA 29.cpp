#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate the list
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // 1. Find length and last node
    struct Node* last = head;
    int length = 1;
    while (last->next != NULL) {
        last = last->next;
        length++;
    }

    // 2. Adjust k
    k = k % length;
    if (k == 0) return head;

    // 3. Make the list circular
    last->next = head;

    // 4. Find the new tail: (length - k) steps from head
    struct Node* newTail = head;
    for (int i = 1; i < length - k; i++) {
        newTail = newTail->next;
    }

    // 5. Break the circle
    head = newTail->next;
    newTail->next = NULL;

    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, k, val;
    struct Node *head = NULL, *tail = NULL;

    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);
    printList(head);

    return 0;
}
