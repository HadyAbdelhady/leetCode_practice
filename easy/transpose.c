#include <stdio.h>
#include <malloc.h>
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int row = matrixSize, col = matrixColSize[0];
    
    // allocate memory for the transposed matrix
    int** newarr = (int**)malloc(col * sizeof(int*));
    for (int i = 0; i < col; i++) {
        newarr[i] = (int*)malloc(row * sizeof(int));
    }
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            newarr[j][i] = matrix[i][j];
        }
    }
    
    // set the return values
    *returnSize = col;
    *returnColumnSizes = (int*)malloc(col * sizeof(int));
    for (int i = 0; i < col; i++) {
        (*returnColumnSizes)[i] = row;
    }
    
    return newarr;
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixSize = 3;
    int matrixColSize[] = {3};
    int returnSize;
    int *returnColumnSizes;

    int **transposedMatrix = transpose((int **)matrix, matrixSize, matrixColSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", transposedMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < matrixColSize[0]; i++)
    {
        free(transposedMatrix[i]);
    }
    free(transposedMatrix);
    free(returnColumnSizes);

    return 0;
}
