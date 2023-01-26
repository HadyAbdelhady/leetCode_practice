#include <stdio.h>
int minStartValue(int *nums, int numsSize)
{
    int sum = 0;
    int startValue = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum = i==0?startValue + nums[i]: sum+nums[i];
        if (sum < 1)
        {
            i = -1;
            sum = 0;
            startValue++;
        }
    }
    return startValue==0? ++startValue:startValue;
}
void main()
{
    int arr[] = {1,-2,-3};
    printf("%d", minStartValue(arr, 3));
}