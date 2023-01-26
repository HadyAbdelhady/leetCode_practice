#include <stdio.h>
#include <stdlib.h>

int **shiftGrid(int **grid, int gridSize, int *gridColSize, int k, int *returnSize, int **returnColumnSizes)
{
    int RowSize = gridSize, ColSize = gridColSize[0], totalSize = RowSize * ColSize;
    // int temp[totalSize];
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    int *temp = (int *)malloc(sizeof(int[*returnSize][**returnColumnSizes]));
    int a = 0;
    for (int i = 0; i < RowSize; i++)
    {
        for (int j = 0; j < (ColSize); j++)
        {
            temp[a] = grid[i][j];
            a++;
        }
    }
    int b = 0; // index of temp after switching data k times
    while (k>=totalSize)
    {
        k-=totalSize;
    }
    
    for (int i = 0; i < RowSize; i++)
    {
        for (int j = 0; j < (ColSize); j++)
        {
            if (k)
            {
                grid[i][j] = temp[abs(totalSize - k)];
                k--;
            }
            else
            {
                grid[i][j] = temp[b];
                b++;
            }
        }
    }
    free(temp);
    return grid;
}
// creating 2d array using pointer to be able to return and deal with it
int **createArray(int m, int n)
{
    int *values = calloc(m * n, sizeof(int));
    int **rows = malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i)
    {
        rows[i] = values + i * n;
    }
    return rows;
}
// free memory
void destroyArray(int **arr)
{
    free(*arr);
    free(arr);
}
int main()
{
    int **grid;
    grid = createArray(3, 3);
    int nums[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int SIZE = 3;
    // Initialize each element.
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            grid[row][col] = nums[row][col]; // or whatever value you want
        }
    }

    int **grid1;
    grid1 = createArray(3, 3);
    int k = 20;
    int lol = 3;
    int *colsize = &lol;
    int **colsizee = &colsize;
    grid1 = shiftGrid(grid, 3, colsize, k, colsize, colsizee);
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            printf("%d ", grid1[row][col]); // or whatever value you want
        }
        printf("\n");
    }
    destroyArray(grid);
    destroyArray(grid1);

    return 0;
}