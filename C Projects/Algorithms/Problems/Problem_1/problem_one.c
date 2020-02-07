/*********************************************************************************
 *
 *  problem_one.c
 *  Author: Ahmed Nofal, Instructor at Sprints LLC 
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_one.h"

/****************************[Problem Description]*********************************
 *
 * Given an array that is circularly rotated and sorted in an ascending order and
 * the rotation is clock wise, find the number of rotations in the array.
 *
 * Sample Input:  arr = [8, 9, 10, 2, 5, 6]
 * Sample Output: The Array is rotated 3 times
 *
 * Sample Input:  arr = [2, 5, 6, 8, 9, 10]
 * Sample Output: The array is rotated 0 times
 *
 ********************************************************************************/

/*********************************************************************************
 *
 * Function: findRotationCount
 * @param: arr[], Array that the function should find the number of rotations in.
 * @param: arr_size, Size of the array
 * Description: Function to find the number of times the array is rotated
 *
 ********************************************************************************/
int findRotationCount(int arr[], int arr_size) 
{
	/* Your code goes here  */
	int max_idx = arr_size - 1;
	int mid_idx = 0;
	int min_idx = 0;
	
	int min_num = arr[min_idx];
	
	int rot_idx = 0;
	
	while(max_idx >= min_idx)
	{
		mid_idx = (max_idx + min_idx)/2;
		
		if(arr[mid_idx] > min_num)
		{
			min_idx = mid_idx + 1; 
		}
		else if (arr[mid_idx] < min_num)
		{
			min_num = arr[mid_idx];
			min_idx = mid_idx + 1;
			rot_idx = mid_idx;	
		}
		else
		{
			rot_idx = mid_idx;
			min_idx = mid_idx + 1; 
		}
	}
	return rot_idx;
}


/*********************************************************************************
 *
 * findRotationCount_Test function to test your code
 *
 ********************************************************************************/
void findRotationCount_Test(void)
{
	int arr[] = { 6 , 5 , 4 , 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	int count = findRotationCount(arr, n);
	printf("The array is rotated %d times\n", count);
}
