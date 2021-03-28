//Implement a C function called ex3 such that it achieves 
//the same functionality as the machine code of ex3_sol.o
//Note: you need to figure out ex3()'s function signature yourself; 
//the signature is not void ex3()
  
#include <assert.h>

void ex3(char * x, char * y, int n ) {
	/* this function parameters are 2 array head pointers and a number n
		 it exchange the first n elements in array x and array y */
	if (n<=0) /* bad input, just return */
		return;
	int i=0;
	int temp1,temp2; /* because of "movzbl, show it's 4 byte */
	while (i<n){ /* test condtion */
		/* swap the elements in x-array and y-array */
		temp1 = x[i];
		temp2 = y[i];
		x[i] = temp2;
		y[i] = temp1;
		i += 1;
	}
	
	return;
}
