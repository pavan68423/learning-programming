#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int n; 

bool isCyclicUtil(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(i, v))
                    return true;
            }
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic() {
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    n = 3;
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][0] = adj[0][2] = 1;

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
