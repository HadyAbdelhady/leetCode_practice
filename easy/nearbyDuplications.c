#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nearbyDuplications
{
    int value;
    int indexes;
} DUPS;

void swap(DUPS *xp, DUPS *yp)
{
    DUPS temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void heapify(DUPS arr[], int N, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left].value > arr[largest].value)
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right].value > arr[largest].value)
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(DUPS arr[], int N)
{
 
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
 
        heapify(arr, N, i);
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}


bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{

    DUPS *h_m = (DUPS *)calloc(numsSize + 2, sizeof(DUPS));

    for (int i = 0; i < numsSize; i++)
    {
        h_m[i].value = nums[i];
        h_m[i].indexes = i;
    }
    heapSort(h_m, numsSize);
    // for (size_t i = 0; i < numsSize; i++)
    // {
    // printf("%d - %d \n",h_m[i].value ,h_m[i].indexes);
    //     /* code */
    // }
    for (int i = 1; i < numsSize ; i++)
    {
        if (h_m[i].value == h_m[i - 1].value)
        {
            if (abs(h_m[i].indexes - h_m[i - 1].indexes) <= k)
            {
                return true;
            }
        }
    }
    free(h_m);
    return false;
}
void main()
{
    int arr[] = {1,2,3,1,2,3}, k = 2, size = sizeof(arr) / sizeof(arr[0]);
    printf("%d", containsNearbyDuplicate(arr, size, k));
}