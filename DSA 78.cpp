#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 1000
#define INF INT_MAX

int graph[MAX][MAX];
int minWeight[MAX];
bool visited[MAX];

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize graph with Infinity
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
        minWeight[i] = INF;
        visited[i] = false;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Handle multiple edges between same nodes by picking minimum
        if (w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    int totalWeight = 0;
    minWeight[1] = 0; // Start from vertex 1

    for (int count = 0; count < n; count++) {
        int u = -1;

        // Pick the minimum weight vertex not yet included in MST
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (u == -1 || minWeight[i] < minWeight[u])) {
                u = i;
            }
        }

        if (minWeight[u] == INF) break; // Graph is disconnected

        visited[u] = true;
        totalWeight += minWeight[u];

        // Update minWeight of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && !visited[v] && graph[u][v] < minWeight[v]) {
                minWeight[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}
