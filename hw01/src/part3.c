#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Your task: implement functions initialize_array, mark_multiples,
// prime_number_sieves, and find_smallest_divisor

// initialize_array is given an array "arr" of "n" elements.
// It initializes the array by setting all elements to be "true" (any non-zero value).
void initialize_array(int *arr, int n)
{
  // TODO: Your code here.
	int i;
	for (i=0; i<n; i++)
		*(arr+i) = 1; /* set every entry to be 1 for "True" */
	
}

// mark_multiples is given an array "arr" of size n and a (prime) number "p" less than "n" 
// It assigns "false" (the zero value) to elements at array indexes 2*p, 3*p, 4*p,.., x*p (where x*p <= n-1)
// For example, given arr=[1, 1, 1, 1, 1, 1], n = 6  and p = 2
// mark_multiples set arr=[1, 1, 1, 1, 0, 1]
void mark_multiples(int *arr, int n, int p) 
{
  // TODO: Replace the following with your code.
	int curr;  /* initialize the counter to be 2*p */
	for (curr = 2*p; curr <= n-1; curr += p )
		*(arr+curr) = 0;

}

// prime_number_sieves finds all prime numbers less than n by constructing a "sieve of Eratosthenes"
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// A pre-allocated, un-initialized, array "arr" of "n" elements is passed to the function 
// When the function returns, the element at index i of "arr" should be "true" (any non-zero value) if i is a prime, 
// and "false" (the zero value) if i is a composite number
// You need not care about the values of the 0-th and 1-st elements.
// You are expected to use the previous two functions, initialize_array and mark_multiples
// 
// For example, given arr with n=6, the resulting sieve should be arr=[*, *, 1, 1, 0, 1] 
// "*" means the corresponding element can be either 0 or 1. The seive at indexes 2,3,5 are marked "1" 
// because 2,3,5 are primes
void prime_number_sieves(int *arr, int n)
{
  // TODO: Replace the following with your code.
	initialize_array(arr,n); /* initialize the array all be "True" */
	int i;
	for (i=2; i<n; i++) /* start with the smallest prime 2 */
	{
		if ( *(arr+i) == 1 ) /* if this is a prime, mark all its multiples */
			mark_multiples(arr,n,i);
	}
	
}

/* find_smallest_divisor finds the smallest prime divisor (>1) of "n". It assigns the value 
 * of the smallest divisor to the integer variable pointed to by "divisor".  
 * If "n" is composite, the function returns true.  Otherwise (i.e. "n" is a prime number), 
 * the function returns false.  For example, in the following code snippet:
 int d;
 ret = find_smallest_divisor(21, &d)
 //ret should contains "true" and d should be 3

 You are expected to first use prime_number_sieves to first find all primes smaller than n. 
 Then, test if any prime found by prime_number_sieves divide n and return the smallest one.
 Note that you'll need to allocate the integer array to pass to prime_number_sieves.
*/
int find_smallest_divisor(int n, int *divisor)
{
  // TODO: Replace the following with your code.
	if (n<2)
		return -1; /* bounary case , return -1 indicating find-failure*/
	
	int array[n]; /* allocate the int array of size n */
	int i;
	int * ptr = &array[0];
	
	prime_number_sieves(ptr, n); /* prime-finder */
	for (i=2; i<n; i++){
		if (array[i] == 1 && n%i==0 ) /* if i is a prime and divides n*/
		{
			*divisor=i; /* store it in divisor*/
			return 1; /* return 1 indicating find-success*/
			
		}
	}
	*divisor = n; /* if n is prime , then the smallest prime divisor is itself */
	return 0; /* return 0 indicating n is prime */
}


