//Implement a C function called ex1 such that it achieves 
//the same functionality as the machine code of ex1_sol.o
//Note: you need to figure out ex1()'s function signature yourself; 
//the signature is not void ex1()
  
#include <assert.h>

int ex1(long x, long y, long z) {
	/* a simple function, 3 parameters x,y,z
	   return 1(True) if x+y==z, else return 0(False) */
  if (x+y==z)
		return 1;
	else
		return 0;
}
