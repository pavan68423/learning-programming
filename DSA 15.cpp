#include <stdio.h>

int main() {
    int m, n;
    
    // Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 1;

    int matrix[m][n];
    long sum = 0;

    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    // A primary diagonal exists where row index == column index
    int limit = (m < n) ? m : n; 
    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    printf("%ld\n", sum);

    return 0;
}
