#include "searching.h"

RET_TYPE binarySearch(ARR_TYPE arr[],uint32_t arr_size,sint32_t key)
{
	RET_TYPE ret_report = 0;
	
	sint32_t max = arr_size-1;
	sint32_t mid = 0;
	sint32_t min = 0;
	
	while(max >= min)
	{
		mid = (max + min)/2;
		
		if(arr[mid] == key)
		{
			ret_report = ITEM_FOUND;
			printf("Item found!\n");
			break;
		}
		else if (arr[mid] > key)
		{
			max = mid-1;
		}
		else if (arr[mid] < key)
		{
			min = mid +1;
		}
	}
	
	if(ret_report != ITEM_FOUND)
	{
		printf("Item not found!\n");
		ret_report = ITEM_NOT_FOUND;
	}
	else
	{
		/*Do nothing*/
	}	
	return ret_report;
}

RET_TYPE linearSearch(ARR_TYPE arr[],uint32_t arr_size,sint32_t key)
{
	RET_TYPE ret_report = 0;
	
	for(uint32_t i = 0 ; i < arr_size ; i++)
	{
		if(arr[i] == key)
		{
			ret_report = ITEM_FOUND;
			printf("Item found!\n");
			break;
		}
		else
		{
			/*Do nothing*/
		}
	}
	
	if(ret_report != ITEM_FOUND)
	{
		printf("Item not found!\n");
		ret_report = ITEM_NOT_FOUND;
	}
	else
	{
		/*Do nothing*/
	}
	return ret_report;	
}