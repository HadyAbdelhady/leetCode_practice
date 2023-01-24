#include <stdio.h>
#define max(x, y) x = x > y ? x : y
int maximumWealth(int **accounts, int accountsSize, int *accountsColSize)
{
    int sum = 0, maxaccount = 0;
    for (int i = 0; i < accountsSize; i++)
    {
        for (int j = 0; j < *accountsColSize; j++)
        {
            sum += accounts[i][j];
        }
        maxaccount = max(sum, maxaccount);
        sum = 0;
    }
    return maxaccount;
}
void main()
{
}