/* *****************************************************************
 *  Algorithm_1.c
 *
 *  Author: Ahmed Nofal, Instructor at Sprints LLC.
 ******************************************************************/

/******************************************************************
 * Given an array of integers, return indices of
 * the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 ***********
 * example *
 ***********
 * 		input: [10,2,23,4,5], target = 6
 * 		output: [1,3]
 *
 * *****************************************************************/

#include "Algorithm_1.h" 
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i = 0;
	int target_check = 0;
	int return_index = 0;
	int ret_flag = 0;
	static int ret_arr[2] = {0};
	
	for(i = 0 ; i < numsSize ; i++)
	{
		if(nums[i] <= target)
		{
			target_check += nums[i];
			ret_arr[return_index] = i;
			return_index++;
		}
		
		if(target_check == target)
		{
			ret_flag = 1;
			break;	
		}
		
		if(return_index == 2)
		{
			target_check = 0;
			return_index = 0;
		}
	}
	
	if(ret_flag != 1)
	{
		ret_arr[0] = 0;
		ret_arr[1] = 0;
	}
	
	*returnSize = 2;
	return ret_arr;
}