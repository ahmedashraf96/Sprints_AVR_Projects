/*********************************************************************************
 *
 *  problem_two.c
 *  Author: Ahmed Nofal, Instructor at Sprints LLC 
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * Modify the Binary Search algorithm to find an element in a circularly sorted
 * array.
 * The array is sorted in an ascending order and rotated in clockwise
 *
 * Sample Input: arr = [8, 9, 10, 2, 5, 6]
 * 				 target = 10
 * Sample Output: The number is found at index 2
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_two.h"

/*********************************************************************************
 *
 * Function: circularArraySearch
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: element_to_be_found, The elment to be searcher for
 * @return: int, the index of the element to be found
 *
 * Description: Function to find the number of times the array is rotated, if the
 * element was not found it should return -1
 *
 ********************************************************************************/
int circularArraySearch(int arr[], int arr_size, int element_to_be_found)
{
	int max_idx = arr_size - 1;
	int min_idx = 0;
	int mid_idx = 0;
	
	int element_idx = -1;
	
	while(max_idx >= min_idx)
	{
		mid_idx = (max_idx + min_idx)/2;
		if(element_to_be_found == arr[max_idx])
		{
			element_idx = max_idx;
			max_idx = -1;
		}
		else if(element_to_be_found == arr[min_idx])
		{
			element_idx = min_idx;
			max_idx = -1;
		}
		else if(element_to_be_found == arr[mid_idx])
		{
			element_idx = mid_idx;
			max_idx = -1;	
		}
		
		if(element_to_be_found > arr[min_idx] && element_to_be_found > arr[mid_idx] && element_to_be_found > arr[max_idx])
		{
			if(arr[min_idx] > arr[mid_idx])
			{
				max_idx = mid_idx - 1;
			}
			else
			{
				min_idx = mid_idx + 1;
			}
		}
		else if(element_to_be_found > arr[min_idx] && element_to_be_found > arr[mid_idx])
		{
			min_idx = mid_idx + 1;
		}
		else if(element_to_be_found > arr[min_idx] && element_to_be_found < arr[mid_idx])
		{
			max_idx = mid_idx - 1;
		}
		else if(element_to_be_found < arr[min_idx])
		{
			min_idx = mid_idx + 1;
		}
		else
		{
			/*Do nothing*/
		}
	}
	return element_idx;
}

/* circularArraySearch_test */
void circularArraySearch_test(void)
{
	int A[] = {5,8,9,10,2,4};
	int target = 10;
	int n = sizeof(A)/sizeof(A[0]);
	int index = circularArraySearch(A, n, target);
	if(index != -1){
		printf("Element found at index %d", index);
	}
	else{
		printf("Element not found in the array");
	}

}
