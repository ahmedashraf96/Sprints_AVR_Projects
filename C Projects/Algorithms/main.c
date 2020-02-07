#include "searching.h"

ARR_TYPE arr[5] = {1,2,3,4,5};

int main(void)
{
	RET_TYPE ret = 0;
	ret = binarySearch(arr,5,0);
	printf("%d",ret);	
	return 0;
}