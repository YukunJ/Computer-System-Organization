#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "part4.h"

// Your task: implement functions set_zip, set_first_name, and compare_addresses

// Free the heap-allocated strings owned by the address structure pointed
// to by addr.
void free_address(struct address* addr) {
  free(addr->first_name);
  free(addr->last_name);
  free(addr->city);
}

// Set the zip field of the address structure pointed to by addr
// to the new_zip value passed in as argument.  The address structure
// is defined in the part4.h header file.
void set_zip(struct address* addr, int new_zip) {
  // TODO: Replace the following with your code
	addr->zip = new_zip; /* since zip is int, just copy by value */
}

// Set the city field of the address structure pointed to by addr
// to the same string as new_city. To that end, allocate a new string
// on the heap that can hold new_city and then make a copy of new_city.
//
// Hint: you can use strcpy(..) to copy a NULL-terminated C string and
// strlen(..) to get the length of a C string.
// Type "man strcpy" respectively "man strlen" to learn how to use these.
void set_city(struct address* addr, char* new_city) {
  // TODO: Replace the following with your code
	/* the size of char needed is length(new_city)+1  "+1" for "\0" */
	char * copy_city = malloc(   (strlen(new_city)+1) * sizeof(char) );
	strcpy(copy_city, new_city); /* call the built-in function for string copy */
	addr->city = copy_city;
}

// Compare two addresses lexicographically by name. That is,
// compare_addresses should return a negative integer if the last_name of
// addr1 is smaller than last_name of addr2, or they are equal and the
// first_name of addr1 is smaller than the first_name of addr2. If both
// last_name and first_name are equal, compare_addresses should return 0.
// In all other cases, it should return a positive value.
//
// Hint: you can use strcmp(..) to compare two NULL-terminated C strings
// type "man strcmp" to learn how to use it.
int compare_addresses(struct address* addr1, struct address* addr2) {
  // TODO: Replace the following with your code
	int result;
	result = strcmp(addr1->last_name, addr2->last_name);
	/* first compart their last names*/
	if (result < 0) /* Last name is smaller */
		return -1;
	else if (result > 0) /* Last name is bigger*/
		return 1;
	else /* if last names are equal, check first name */
	{
		result = strcmp(addr1->first_name, addr2->first_name);
		if (result<0)
			return -1;
		else if (result == 0) /* both last/first names are equal, return 0 */
			return 0;
		else
			return 1;
	}
}
