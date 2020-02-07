/* *****************************************************************
 *  Algorithm_3.c
 *  Write a code that gets the 5th floor Root of a number
 *  Input: Linear_floorRoot5(32)
 *  Output: 2
 *  Author: Ahmed Nofal, Instructor at Sprints LLC.
 ******************************************************************/

int Linear_floorRoot5(int n)
{
	int v=0;

	while(n >= 5)
	{
		n = n / 5;
		v++;
	}
	return v;
}

