#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int adj[MAX][MAX];
int degree[MAX];
bool visited[MAX];
int nodes_reached = 0;

void dfs(int u, int n) {
    visited[u] = true;
    nodes_reached++;
    
    for (int i = 0; i < degree[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v, n);
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; i++) degree[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }

    if (n == 0) {
        printf("CONNECTED\n");
        return 0;
    }

    dfs(1, n);

    if (nodes_reached == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
