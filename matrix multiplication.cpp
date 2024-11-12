#include <stdio.h>
#define ROW1 2
#define COL1 2
#define ROW2 2
#define COL2 2
void multiplyMatrices(int mat1[ROW1][COL1], int mat2[ROW2][COL2], int result[ROW1][COL2]) {
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COL1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int main() {
    int mat1[ROW1][COL1] = {{1, 2}, {3, 4}};
    int mat2[ROW2][COL2] = {{1, 0}, {0, 1}};
    int result[ROW1][COL2];
    multiplyMatrices(mat1, mat2, result);
    printf("Result of Matrix Multiplication:\n");
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

