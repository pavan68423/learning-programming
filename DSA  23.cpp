#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    struct Node* head = NULL;
    if (l1->data <= l2->data) {
        head = l1;
        head->next = mergeLists(l1->next, l2);
    } else {
        head = l2;
        head->next = mergeLists(l1, l2->next);
    }
    return head;
}

int main() {
    int n, m, val;
    struct Node *list1 = NULL, *list2 = NULL, *temp = NULL;

    // Input first list
    if (scanf("%d", &n) && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            if (!list1) { list1 = newNode(val); temp = list1; }
            else { temp->next = newNode(val); temp = temp->next; }
        }
    }

    // Input second list
    if (scanf("%d", &m) && m > 0) {
        for (int i = 0; i < m; i++) {
            scanf("%d", &val);
            if (!list2) { list2 = newNode(val); temp = list2; }
            else { temp->next = newNode(val); temp = temp->next; }
        }
    }

    struct Node* result = mergeLists(list1, list2);

    // Output merged list
    while (result) {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}
