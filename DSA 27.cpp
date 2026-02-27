#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to get the length of a list
int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find the intersection
void findIntersection(struct Node* head1, struct Node* head2) {
    int n1 = getCount(head1);
    int n2 = getCount(head2);
    int d;

    struct Node *ptr1 = head1, *ptr2 = head2;

    // Shift the pointer of the longer list
    if (n1 > n2) {
        d = n1 - n2;
        for (int i = 0; i < d; i++) ptr1 = ptr1->next;
    } else {
        d = n2 - n1;
        for (int i = 0; i < d; i++) ptr2 = ptr2->next;
    }

    // Traverse both until a match is found
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    // Input List 1
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head1) head1 = tail1 = temp;
        else { tail1->next = temp; tail1 = temp; }
    }

    // Input List 2
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head2) head2 = tail2 = temp;
        else { tail2->next = temp; tail2 = temp; }
    }

    findIntersection(head1, head2);

    return 0;
}
