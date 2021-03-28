//Implement a C function called ex5 such that it achieves 
//the same functionality as the machine code of ex5_sol.o
//Note: you need to figure out ex5()'s function signature yourself; 
//the signature is not void ex5(node *n). However, as a hint, 
//ex5 does take node * as an argument.

#include <assert.h>
#include "ex5.h"

int ex5(node * curr) {
	/* this function parameter is a head node * pointer
	   it test if a linked list is increasing in value
		 if is increasing return 1(True) (including case of empty list or single node list
		 if not increasing, then return 0(False) */
	
	while (curr != 0 && curr->next != 0)
	{
		if (curr->value > curr->next->value) /* non-increasing detected, return 0(False) */
			return 0;
		
		curr = curr->next;
	}
	
	return 1; /* increasing guaranteed, return 1(True) */
}
