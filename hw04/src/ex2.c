//Implement a C function called ex2 such that it achieves 
//the same functionality as the machine code of ex2_sol.o
//Note: you need to figure out ex2()'s function signature yourself; 
//the signature is not void ex2()
  
#include <assert.h>

int ex2(char * ptr) {
	/* a function with parameter a head pointer of string array
	   and iterate through the array to see how many times 'a'(97 in ASCII) appears
		 return the final count */
	int count = 0;
	char c;
	while ( (c=*ptr) != '\0' ) /* while not reaching the end of the string array */
	{
		if (c=='a') /* if found an 'a', increase the count*/
		{
			count += 1;
		}
		ptr += 1; /* read next character*/
	}
	return count;
}
