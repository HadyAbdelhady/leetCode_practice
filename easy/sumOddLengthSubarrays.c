#include <stdio.h>
int sumOddLengthSubarrays(int *arr, int arrSize)
{
    int running_sum = 0;

    for (int i = 0; i < arrSize; i++)
        running_sum += ((i + 1) * (arrSize - i) + 1) / 2 * arr[i];
    return running_sum;
}
void main()
{
    int array[] = {1, 4, 2, 5, 3};
    printf("%d", sumOddLengthSubarrays(array, 5));
}