#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

void count(FILE** file_pointer, int * character, int * word, int * newline);

int main(int argc, char** argv) {
  // TODO: add your code here. Feel free to introduce helper functions.
	
	/* initialize empty char array for storing the command and the address of file */
	char fileaddress[100];
	char command[10];
	
	int flag1, flag2, flag3;
	strcpy(command,argv[1]); /* copy the command */
	strcpy(fileaddress, argv[2]); /* copy the address of file */
	flag1 = strcmp(command, "-c"); /* to count character? */
	flag2 = strcmp(command, "-w"); /* to count word? */
	flag3 = strcmp(command, "-l"); /* to count newline? */
	
	/* if bad command input */
	if (flag1 != 0 && flag2 !=0 && flag3 !=0)
	{
		printf("Sorry, your command is unknown.\n");
		return 1;
	}
	
	FILE * file_pointer;
	file_pointer = fopen(fileaddress,"r");
	
	/* if cannot open the file*/
	if (file_pointer==NULL)
	{
		printf("Sorry, Failed to open the file %s", fileaddress);
		return 1;
	}
	
	int character,word,newline;
	count(&file_pointer, &character, &word, &newline);
	
	if (flag1 == 0)
		printf("%d %s", character,fileaddress);
	else if (flag2==0)
		printf("%d %s", word, fileaddress);
	else if (flag3==0)
		printf("%d %s", newline, fileaddress);
	
	fclose(file_pointer); /* remember to close the file for safety */
  return 0;
}

void count(FILE** file_pointer, int * character, int * word, int * newline)
{
	int c=0; /* character count */
	int w=0; /* word count */
	int n=0; /* newline count */
	int curr;
	int state=OUT;
	while ( (curr=fgetc(*file_pointer)) != EOF )
	{
		c++;
		if (curr =='\n')
			n++;
		if (curr==' ' || curr=='\n' || curr=='\t') /* get out of a word */
			state=OUT;
		else if (state==OUT)
		{/* enter a new word, increment the count */
			state = IN;
			w++;
		}
	}
	/* store back the value to the main() function */
	*character = c;
	*word = w;
	*newline = n;
}
