#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency Matrix
int n;             // Number of vertices

bool isCyclicUtil(int v, bool visited[], bool recStack[]) {
    if (visited[v] == false) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all vertices adjacent to this vertex
        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    
    // Remove the vertex from recursion stack before returning
    recStack[v] = false;
    return false;
}

void isCyclic() {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < n; i++) {
        if (isCyclicUtil(i, visited, recStack)) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    // Example: A graph with 3 vertices and a cycle (0->1, 1->2, 2->0)
    n = 3;
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;

    isCyclic();

    return 0;
}
