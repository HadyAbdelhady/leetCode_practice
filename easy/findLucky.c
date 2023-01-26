#include <stdio.h>
int findLucky(int* arr, int arrSize){
    int hash[501]={0};
    int i,dst=-1;
	
    for(i=0; i<arrSize; i++)
        hash[arr[i]]++;
	
    for(i=1; i<501; i++)
        if(hash[i]==i) dst=i;
		
    return dst;
}
void main()
{
    int arr[] = {1,2,5,8,2};
    int size = (sizeof(arr)) / (sizeof(arr[0]));
    printf("%d", findLucky(arr, size));
}