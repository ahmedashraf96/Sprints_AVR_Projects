#include <stdio.h>
#include "Algorithm_1.h"

int main(void)
{
	int* ret_val = NULL;
	int size_val = 0;
	int  i = 0;
	
	int arr[] = {10,2,23,4,5};
	ret_val = twoSum(arr,5,6, &size_val);
	
	for(i = 0 ; i < size_val ; i++)
	{
		printf("%d ",ret_val[i]);	
	}
	
	return 0;
}