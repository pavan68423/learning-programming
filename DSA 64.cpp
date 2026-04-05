#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure for Adjacency List Node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the Graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

// Queue Implementation
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item;
    if (q->front == -1) return -1;
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to perform BFS
void bfs(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();

    graph->visited[startVertex] = true;
    enqueue(q, startVertex);

    printf("BFS Traversal: ");

    while (q->front != -1) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int n, edges, src, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = malloc(n * sizeof(struct Node*));
    graph->visited = malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        // Adding edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = graph->adjLists[u];
        graph->adjLists[u] = newNode;
        
        // For undirected graph, add v -> u as well:
        /*
        newNode = createNode(u);
        newNode->next = graph->adjLists[v];
        graph->adjLists[v] = newNode;
        */
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    bfs(graph, src);

    return 0;
}
