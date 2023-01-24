#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
int maxProduct(int *nums, int numsSize)
{
    bubbleSort(nums, numsSize);
    return (nums[numsSize - 1]-1) * (nums[numsSize-2]-1);
}

// Driver's code
int main()
{
    int arr[] = {3,4,5,2};
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("%d",maxProduct(arr,N));
}

// This code is contributed by _i_plus_plus_.
