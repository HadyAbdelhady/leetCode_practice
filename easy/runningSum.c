#include <stdio.h>
#include <malloc.h>
int *runningSum(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize; // This is the size of the runningSum array. It does not matter for our solution
                            // but our code will fail if we do not set this.
    for (int i = 0; i < numsSize; ++i)
    {
        nums[i] = i ? nums[i] + nums[i - 1] : nums[i];
    }
    return nums;
}
void main()
{
    int nums[] = {1, 2, 3, 4, 5};
    int *returnSize;
    int *return_array = runningSum(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", return_array[i]);
    }
    free(return_array);
    return 0;
}
