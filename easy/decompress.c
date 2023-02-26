#include <stdio.h>
#include <malloc.h>
int *decompressRLElist(int *nums, int numsSize, int *returnSize)
{
    int *newarr = (int *)malloc(numsSize * sizeof(int));
    int j = 0;
    for (int i = 0; i < numsSize; i += 2)
    {
        int element = nums[i];
        while (element != 0)
        {
            newarr[j] = nums[i + 1];
            j++;
            element--;
        }
    }
    *returnSize = j;
    return newarr;
}
int main()
{
    int nums[] = {42, 39};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int *newarr = decompressRLElist(nums, numsSize, &returnSize);
    if (newarr == NULL) {
        printf("Error: failed to allocate memory for new array.\n");
        return 1;
    }

    printf("Input array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("Decompressed array: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", newarr[i]);
    }
    printf("\n");

    free(newarr);

    return 0;
}