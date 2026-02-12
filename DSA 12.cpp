#include <stdio.h>

int main() {
    int m, n;

    // Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix[m][n];

    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Criterion 1: Must be a square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    // Criterion 2: Check if element[i][j] == element[j][i]
    int isSymmetric = 1; // Assume true initially
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) { // We only need to check one half (below diagonal)
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}
