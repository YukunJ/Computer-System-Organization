//Implement a C function called ex4 such that it achieves 
//the same functionality as the machine code of ex4_sol.o
//Note: you need to figure out ex4()'s function signature yourself; 
//the signature is not void ex4()
  
#include <assert.h>

int ex4(int n) {
/* this function computes the n-th Fibonacc number using recursion */
	if (n<2) /* if n<2, return n0=0, n1=1 */
		return n;
	else /* call recursion with formula f_{n}= f_{n-1} + f_{n-2} */
		return ex4(n-1) + ex4(n-2);
}
