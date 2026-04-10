#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure for an adjacency list node
struct Node {
    int target, weight;
    struct Node* next;
};

// Structure for Min-Heap node
struct HeapNode {
    int v, dist;
};

// Structure for Min-Heap
struct MinHeap {
    int size;
    int capacity;
    struct HeapNode** array;
};

// --- Utility Functions for Graph ---
struct Node* createNode(int target, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->target = target;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// --- Min-Heap Functions ---
struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    struct HeapNode* root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void push(struct MinHeap* minHeap, int v, int dist) {
    minHeap->array[minHeap->size] = newHeapNode(v, dist);
    int i = minHeap->size;
    minHeap->size++;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// --- Dijkstra's Algorithm ---
void dijkstra(int V, struct Node* adj[], int src) {
    int dist[V];
    for (int i = 0; i < V; ++i) dist[i] = INF;

    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->capacity = V * V; // Rough estimate for simplicity
    minHeap->size = 0;
    minHeap->array = (struct HeapNode**)malloc(minHeap->capacity * sizeof(struct HeapNode*));

    dist[src] = 0;
    push(minHeap, src, dist[src]);

    while (minHeap->size != 0) {
        struct HeapNode* minNode = extractMin(minHeap);
        int u = minNode->v;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->target;
            if (dist[u] != INF && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                push(minHeap, v, dist[v]);
            }
            temp = temp->next;
        }
        free(minNode);
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i) printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V = 5;
    struct Node* adj[V];
    for (int i = 0; i < V; i++) adj[i] = NULL;

    addEdge(adj, 0, 1, 9);
    addEdge(adj, 0, 2, 6);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 1, 3, 11);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 3, 4, 2);

    dijkstra(V, adj, 0);

    return 0;
}
