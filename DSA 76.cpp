#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dfs(int v) {
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }

    printf("%d\n", components);

    return 0;
}
