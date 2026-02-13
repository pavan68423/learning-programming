#include <stdio.h>

int main() {
    int r, c;
    
    // Read dimensions
    if (scanf("%d %d", &r, &c) != 2) return 0;

    int matrix[r][c];

    // Read matrix elements
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {
        
        // 1. Move Right across the top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // 2. Move Down the right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // 3. Move Left across the bottom row (if row still exists)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. Move Up the left column (if column still exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    printf("\n");
    return 0;
}
