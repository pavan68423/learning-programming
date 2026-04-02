#include <stdio.h>

#define MAX 100

void buildMatrix() {
    int n, m, i, j, u, v, isDirected;
    int adj[MAX][MAX] = {0}; 

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    printf("Enter %d pairs of edges (u v):\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
       
        adj[u-1][v-1] = 1;
        
        if (!isDirected) {
            adj[v-1][u-1] = 1; 
        }
    }

    
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    buildMatrix();
    return 0;
}
