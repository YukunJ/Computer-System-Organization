#include <stdio.h>
#include <assert.h>
// Convert an int value from little endian to big endian (and vice versa).
// For example, if x is 0x12345678, then convert_endian should return 0x78563412.
// Make sure that your code does not hard-code the size of the type int.
// 3 Points
int convert_endian(int x)
{
  // TOOD: Replace the following with your code
	int convert;
	int i,j; /* two pointers for switch position*/
	unsigned char * pt1= (unsigned char*) &x;
	unsigned char * pt2= (unsigned char*) &convert;
	for (i=0,j=sizeof(int)-1; i<sizeof(int);i++,j--)
		/* put head part of x to the end part of convert */
		/* x:        12|34|56|78 */
		/* convert:  78|56|34|12 */
		/* namely switch the position in x per hexadecimal */
		pt2[j] = pt1[i];
	return convert;
}

//Extract the 8-bit exponent field of the single precision floating point number f 
//and return it as an unsigned byte
//Example: get_exponent_field(15213.0) should return 140.
// 3 Points
unsigned char get_exponent_field(float f)
{
  //TODO: Replace the following with your code
	unsigned char result;
	int same_bit = *((int*) &f); /* preserve the same bit representation */
	result = (same_bit & 0x7f800000)>>23; /* mask and preserve only the exponent part */
	return result;
}

/* In the remainder of this part, we will implement a set data structures that 
 * uses unsigned integer values to represent sets of bounded integers as bit 
 * vectors. For example, using a 4 byte unsigned integer value x, we can represent sets
 * of integer values in the range 0..31. A value i, 0 <= i <= 31, is in the set
 * represented by x iff the i-th bit of x is set to 1.
 * Use bit-level operations to implement the following set operations on such sets.
 */

// Return the empty set
// 1 Point
unsigned int sempty() {
  //TODO: Replace the following with your code
	return (unsigned int)0;
	/*
	 just return a 0 because no i can be contained in the bit representation 0B00000000
	 so 0 is the empty set
	 */
}

// Return true iff the set represented by x contains i.
// 2 Points
int scontains(unsigned int x, int i) {
  //TODO: Replace the following with your code
	/* transport the signal to the i-th bit and do bitwise-and with x */
	return (x & 1<<i);
}

// Return the set obtained by inserting integer i into the set represented by x.
// 2 Points
unsigned int sinsert(unsigned int x, int i) {
  assert (0 <= i && i < sizeof(int)*8);
  //TODO: Replace the following with your code
	/* transport the signal to the i-th bit and do bitwise-or with x */
	return (x | 1<<i);
}

// Return the set obtained by removing integer i from the set represented by x.
// 2 Points
unsigned int sdelete(unsigned int x, int i) {
  //TODO: Replace the following with your code
  /* make the i-th bit to be 0 and do bitwise-and with x */
	return ~(1 << i) & x;
}

// Return the set obtained by taking the union of the sets represented by x and y.
// 2 Points
unsigned int sunion(unsigned int x, unsigned int y) {
  //TODO: Replace the following with your code
	/* simply do bitwise-or of the bit-representations of x and y */
	return x|y;
}
  
// Return the set obtained by taking the intersection of the sets represented by x and y.
// 2 Points
unsigned int sinter(unsigned int x, unsigned int y) {
  //TODO: Replace the following with your code
	/* simply do bitwise-and of the bit-represenetation of x and y*/
	return x&y;
}
