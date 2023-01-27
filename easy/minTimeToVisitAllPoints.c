#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int minTimeToVisitAllPoints(int **points, int pointsSize, int *pointsColSize)
{
    // // point size is the number of the rows
    // // col size is unnessesary cuz it's always 2
    // int steps = 0, sec = 0;
    // for (int i = 1; i < pointsSize; i++)
    // {
    //     /*
    //         x1= i-1 ,0
    //         y1= i-1 ,1
    //         x2= i ,0
    //         y2= i ,1
    //         if y2>x2 then steps will be x2-x1 + y2-x2
    //         if not y2-y1 + x2-y2
    //     */

    //     if ((points[i][1]) == (points[i - 1][1]))           // y1==y2
    //         steps += fabs(points[i - 1][0] - points[i][0]); // abs of x1-x2
    //     else
    //     {
    //         steps = fabs(points[i - 1][0] - points[i][0]); // abs of x1-x2

    //         if (fabs(points[i][1]) - fabs(points[i - 1][1]) > 0) // y2>y1
    //             steps += points[i][1] - steps - points[i - 1][0];
    //         else // y2<y1
    //             steps += points[i - 1][1] - steps - points[i - 1][0];
    //     }
    //     printf("%d\n", steps);
    //     sec += fabs(steps);
    // }

    int sum = 0;
    int max = 0;

    for (int i = 0; i < pointsSize - 1; i++)
    {

        max = abs(points[i][0] - points[i + 1][0]) > abs(points[i][1] - points[i + 1][1]) ? abs(points[i][0] - points[i + 1][0]) : abs(points[i][1] - points[i + 1][1]);

        sum = sum + max;
    }
    return sum;
}
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
int fillarray(int **arr, int r, int c) {}
// free memory
void destroyArray(int **arr)
{
    free(*arr);
    free(arr);
}

void main()
{
    int **grid;
    int r = 2;
    int c = 2;
    int *ptr = &c;
    grid = createArray(r, c);
    //{1,1},{3,4},{-1,0}
    //{ 559, 511 }, { 932, 618 }, { -623, -443 }, { 431, 91 }, { 838, -127 }, { 773, -917 }, { -500, -910 }, { 830, -417 }, { -870, 73 }, { -864, -600 }, { 450, 535 }, { -479, -370 }, { 856, 573 }, { -549, 369 }, { 529, -462 }, { -839, -856 }, { -515, -447 }, { 652, 197 }, { -83, 345 }, { -69, 423 }, { 310, -737 }, { 78, -201 }, { 443, 958 }, { -311, 988 }, { -477, 30 }, { -376, -153 }, { -272, 451 }, { 322, -125 }, { -114, -214 }, { 495, 33 }, { 371, -533 }, { -393, -224 }, { -405, -633 }, { -693, 297 }, { 504, 210 }, { -427, -231 }, { 315, 27 }, { 991, 322 }, { 811, -746 }, { 252, 373 }, { -737, -867 }, { -137, 130 }, { 507, 380 }, { 100, -638 }, { -296, 700 }, { 341, 671 }, { -944, 982 }, { 937, -440 }, { 40, -929 }, { -334, 60 }, { -722, -92 }, { -35, -852 }, { 25, -495 }, { 185, 671 }, { 149, -452 }
    int nums[][2] = {{-5, -9}, {-4, -3}};
    // Initialize each element.
    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            grid[row][col] = nums[row][col]; // or whatever value you want
        }
    }
    printf("%d ", minTimeToVisitAllPoints(grid, r, ptr));

    destroyArray(grid);
}