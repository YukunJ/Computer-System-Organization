#include <stdio.h>
#include <assert.h>
#include <limits.h>

// Your task: implement functions incr and max

// Increment the value of the integer variable pointed to by p.
// The return value of incr should be the old value of the variable
// before the increment.
int incr(int* p) {
  // TODO: Replace the following with your code.
	int temp = *p; /* create a temporary for storing old value*/
	(*p)++; /* carefully using parenthesis */
	return temp;
}

// Return the maximum value stored in the given array. Assume that the array
// "arr" has "n" elements.
//
// Note that n can be 0. We define the maximum of an empty array as INT_MIN,
// which is the smallest integer representable by the type int.
int max(int *arr, int n)
{
  // TODO: Replace the following with your code.
  if (n==0) /* if empty array, return INT_MIN as instructed */
		return INT_MIN;
	
	// initialize counter and max
	int i;
	int max;
	for (i=0,max = *arr; i<n; i++)
	{
		if ( *(arr+i) > max )
			max = *(arr+i);
	}
	return max;
}
