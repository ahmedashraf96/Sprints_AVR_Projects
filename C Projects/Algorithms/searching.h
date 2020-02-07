#ifndef __SEARCHING_H__
#define __SEARCHING_H__

#include<stdio.h>

typedef unsigned char   uint8_t;
typedef signed char 	sint8_t;

typedef unsigned short  uint16_t;
typedef signed short 	sint16_t;

typedef unsigned long 	uint32_t;
typedef signed long		sint32_t;

typedef float			f32_t;
typedef double 			f64_t;

/*Searching functions parameter types*/
#define ARR_TYPE	uint32_t
#define RET_TYPE	sint32_t

/*Status of the passed key*/
#define ITEM_FOUND		(  1 )
#define ITEM_NOT_FOUND	( -1 )

/*Searching functions prototypes*/

/*Function that uses binary search algorithm and returns 1 if item is found and -1 if item isn't found*/
RET_TYPE binarySearch(ARR_TYPE arr[],uint32_t arr_size,sint32_t key);

/*Function that uses binary search algorithm and returns 1 if item is found and -1 if item isn't found*/
RET_TYPE linearSearch(ARR_TYPE arr[],uint32_t arr_size,sint32_t key);

#endif