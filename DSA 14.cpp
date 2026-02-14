#Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <stdio.h>

int main() {
    int n, i, j;
    int isIdentity = 1; // Assume it is identity until proven otherwise

    // Get matrix size
    if (scanf("%d", &n) != 1) return 0;

    int matrix[n][n];

    // Read matrix and check conditions simultaneously
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);

            // Check Identity Matrix logic
            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                }
            } else {
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                }
            }
        }
    }

    // Output the result
    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}
