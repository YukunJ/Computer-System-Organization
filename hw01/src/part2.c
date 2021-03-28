#include <assert.h>

// Your task: implement functions swap and insertion_sort

// Swap the values of the integer variables pointed to by p1 and
// p2.  After the function returns, the variable pointed to by p1
// should have the value once pointed to by p2, and vice-versa.
void swap(int *p1, int *p2)
{
  assert(p1 != 0);
  assert(p2 != 0);
  
  // TODO: Replace the following with your code.
	int temp = *p1; /* temporary store for *p1 */
	*p1 = *p2; /* copy *p2 to *p1 */
	*p2 = temp; /* copy *p1 to *p2 */
	
}

// insertion_sort implements the insertion sort algorithm.
// https://en.wikipedia.org/wiki/Insertion_sort
// It is given an integer array "arr" of "n" elements. 
// Upon return, the integer array should contain the sorted numbers
// in increasing order. 
// You should use the previous swap function when implementing insertion_sort
void insertion_sort(int *arr, int n)
{
  // TODO: Replace the following with your code.
	int i;
	int j;
	for (i=1; i<n; i++)
	/* the outer loop start from index 1, because 0 is already sorted*/
	{
		j = i-1; /* go left and check if it's in right order */
		while ( j>=0 && *(arr+j)>*(arr+j+1))
		{
			swap(arr+j,arr+j+1); /* pass in pointers */
			j--;
		}
	}
}
