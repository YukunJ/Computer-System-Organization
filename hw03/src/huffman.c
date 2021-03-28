#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "minheap.h"
#define bit0 0b10000000 /* For going right, set up the first bit.*/
#define bit1 0b01000000
#define bit2 0b00100000
#define bit3 0b00010000
#define bit4 0b00001000
#define bit5 0b00000100
#define bit6 0b00000010
#define bit7 0b00000001
#define leftbit 0b00000000 /* For going left, always 0 bit*/
// A node in a Huffman code tree
struct code_tree_s {
  char data;
  int weight;
  struct code_tree_s* left;
  struct code_tree_s* right;
};

typedef struct code_tree_s code_tree;

// A code table entry
struct code_s {
  unsigned char bits[16];
  int len;
};

typedef struct code_s code;

// Count the number of occurrences of each ASCII character in the
// file plain_file_name and store them in the array weights.
// The size of weights should be 128 (the number of ASCII characters).
void count_occurrences(char* plain_file_name, int* weights) {
  // TODO: add your code here
	/* first initialize each entry in *weights for safety*/
	int i;
	int c;
	for (i=0;i<128;i++){
		weights[i] = 0;
	}
	
	/* open file and read char by char */
	FILE* file_ptr;
	file_ptr = fopen(plain_file_name,"r");
	if (file_ptr==NULL) /* Null pointer check */
	{
		printf("Error when opening file %s",plain_file_name);
		return;
	}
	while ( (c=fgetc(file_ptr)) != EOF )
	{ /* read the char and locate it in the weights array */
		weights[c] += 1;
	}
	
	fclose(file_ptr); /* close the file pointer */
	return;
}

// Write the weights out into the file weight_file_name.
// The size of weights should be 128 (the number of ASCII characters).
void write_weight_table(char* weight_file_name, int* weights) {
  // TODO: add your code here
	FILE * file_ptr = fopen(weight_file_name,"w");
	if (file_ptr == NULL) /* Null pointer check*/
	{
		printf("Error when opening file %s",weight_file_name);
		return;
	}
	for (int i=0;i<128;i++)
	{
		if (weights[i]>0) /* if has weight*/
		{
			fprintf(file_ptr,"%c:%d\n",(char)i,weights[i]);
		}
	}
	
	fclose(file_ptr); /* close the file pointer */
	return;
}

// Read the contents of file weight_file_name and write the result into
// the array weights.
// The size of weights should be 128 (the number of ASCII characters).
void read_weight_table(char* weight_file_name, int* weights) {
  // TODO: add your code here
	/* initialize the array weights */
	for (int i=0;i<128;i++)
	{
		weights[i] = 0;
	}
	FILE * file_ptr = fopen(weight_file_name,"r");
	if (file_ptr == NULL) /* Null pointer check */
	{
		printf("Error when opening file %s",weight_file_name);
		return;
	}
	char buff[50]; /* the buffer storage for each line read*/
	char index; /* the character */
	int weight; /* the weight */
	
	while (fgets(buff,50,file_ptr) != NULL)
	{
		if (strcmp((char*)&buff,"\n")!=0){ /* if the character is not '\n' */
			sscanf(buff,"%c:%d",&index,&weight);
		}
		else{ /* if character ='\n', then its weight is on next line */
			fgets(buff,50,file_ptr);
			index = '\n';
			sscanf(buff,":%d",&weight);
		}
		weights[(int)index] = weight; /* write into the array weights */
	}
	
	fclose(file_ptr); /* close the file pointer */
	return;
}
// Return the weight of the tree rooted at n
int weight_of_tree(code_tree* n) {
  // TODO: add your code here
	return n->weight;
}

// Create a new leaf node of a code tree.
code_tree* make_leaf(char c, int w) {
  // TODO: add your code here
	code_tree * leaf = (code_tree *)malloc(sizeof(code_tree));
	leaf->data = c;
	leaf->weight=w;
	leaf->left = NULL;
	leaf->right = NULL;
	return leaf;
}

// Create a new internal node of a code tree with
// left successor l and right successor r.
code_tree* make_fork(code_tree* l, code_tree* r) {
  // TODO: add your code here
	int left_weight = weight_of_tree(l);
	int right_weight = weight_of_tree(r);
	code_tree * root = (code_tree *)malloc(sizeof(code_tree));
	root->left=l;
	root->right=r;
	root->weight=left_weight +right_weight;
	return root;
}

// Create a code tree from the given table of weights.
// The size of weights should be 128 (the number of ASCII characters).
code_tree* create_code_tree(int* weights, int* char_1_flag) {
  // TODO: add your code here
	/* the extra parameter int * char_1_flag is for special case 1-character file */
	
	/* check how many characters appear */
	int count=0;
	int i;
	for (i=0;i<128;i++)
	{
		if (weights[i]>0)
			count++;
	}
	if (count==0) /* empty file, so bad*/
	{
		return NULL;
	}
	if (count==1) /* 1-character file, also bad */
	{
		for (i=0;i<128;i++)
			if (weights[i]>0)
			{
				*char_1_flag = i;
				return NULL;
			}
	}
	/* initialize the min-heap */
	minheap* heap_ptr = minheap_create((size_t)count);
	
	/* create leaf node for every character and add into min-heap */
	for (i=0;i<128;i++)
	{
		if (weights[i]>0)
		{
			code_tree * leaf = make_leaf((char)i, weights[i]);
			minheap_add(heap_ptr,leaf,leaf->weight); /* add to heap, with priority=weight */
		}
	}
	
	/* take out 2 trees with smallest weight and combine them */
	while (minheap_get_count(heap_ptr) >1 )
	{
		code_tree * left = (code_tree *)minheap_delete_min(heap_ptr);
		code_tree * right = (code_tree *)minheap_delete_min(heap_ptr);
		code_tree * combine =make_fork(left,right);
		minheap_add(heap_ptr,combine,combine->weight);
	}
	
	/* get the totally combined tree root and return */
	code_tree * root = minheap_delete_min(heap_ptr);
	return root;
}

// Free all nodes in the code tree rooted at node.
void delete_code_tree(code_tree* node) {
  // TODO: add your code here
	if (node->left != NULL) /* free left sub-tree */
		delete_code_tree(node->left);
	if (node->right != NULL) /* free right sub-tree */
		delete_code_tree(node->right);
	free(node);
}

// Populate the code table tbl with the codes represented by
// the code tree rooted at r.
int is_leaf(code_tree * node)
{ /* helper function: test if a node is a leaf node*/
	return (node->left==NULL && node->right==NULL);
}
void traversal(code_tree * node,int path,code * tbl,long first8b, long last8b)
{ /* the idea here is, I will keep track of how many step I have taken
	 so far, the direction of going left or right.
	 The step length is stored in "int path"
	 
	 Since there are at most depth 128. I decide to use 2 long integer to store the direction
	 Namely I will record the first 0-63 steps direction in "first 8b", last 64-127 steps "last8b"
	 
	 When I reach a leaf, I will use the pointer *tbl to store the len and the bit path, by using 2 pointers to copy char by char from the 2 long integers "first8b" and "last8b".
	 
	 During the process of update, I will calculate whether this step should be store in "first8b" or
	 "last8b", and which "byte" and which "bit" should it be stored by using a "switch" statement.
	 */
	
	
	/* the path start with 1. So the bit offset is really really really trick, be careful! */
	/* for example path==8, it should be in the first byte's 7-th(starting with 0-th) bit. */
	/* so we do: byte = (path-1)/8 to offset this offest 1*/
	/* and bit = path-byte*8-1 the minus 1 to offest the fact byte start with 0-th to 7-th, no 8-th*/
	if (node->left != NULL) /*left is not NULL*/
	{
		int left_path=path + 1; /* update the step length in advance*/
		if (left_path<=64) /* update the "first8b" */
		{
			long next_first8b=first8b;
			char * ptr = (char *)&next_first8b;
			int jump_offset= (left_path-1)/8;
			int bit_to_set = left_path - jump_offset*8-1; /* start with 0, so bias is -1 */
			switch(bit_to_set){ /* which bit to activate */
				case 0:
					ptr[jump_offset] |= leftbit;break;
				case 1:
					ptr[jump_offset] |= leftbit;break;
				case 2:
					ptr[jump_offset] |= leftbit;break;
				case 3:
					ptr[jump_offset] |= leftbit;break;
				case 4:
					ptr[jump_offset] |= leftbit;break;
				case 5:
					ptr[jump_offset] |= leftbit;break;
				case 6:
					ptr[jump_offset] |= leftbit;break;
				case 7:
					ptr[jump_offset] |= leftbit;break;
				default:
					printf("Something wrong with the left first8b.\n");
					break;
			}
			traversal(node->left,left_path,tbl,next_first8b,last8b);
			
			
		}
		else /* path >=64 , go the "last8b"*/
		{
			long next_last8b=last8b;
			char * ptr = (char *)&next_last8b;
			int jump_offset= (left_path-64-1)/8;
			int bit_to_set = (left_path-64) - jump_offset*8-1;
			switch(bit_to_set){
				case 0:
					ptr[jump_offset] |= leftbit;break;
				case 1:
					ptr[jump_offset] |= leftbit;break;
				case 2:
					ptr[jump_offset] |= leftbit;break;
				case 3:
					ptr[jump_offset] |= leftbit;break;
				case 4:
					ptr[jump_offset] |= leftbit;break;
				case 5:
					ptr[jump_offset] |= leftbit;break;
				case 6:
					ptr[jump_offset] |= leftbit;break;
				case 7:
					ptr[jump_offset] |= leftbit;break;
				default:
					printf("Something wrong with the left last8b.\n");
					break;
			}
			traversal(node->left,left_path,tbl,first8b,next_last8b);
			
		}
	}
	if (is_leaf(node)){/* already reach a leaf*/
		int c = (int)node->data;
		tbl[c].len = path;
		char * ptr = (char *)&tbl[c].bits;
		char * ptr1 = (char *)&first8b;
		char * ptr2 = (char *)&last8b;
		int i;
		/* use two pointers to completely copy 16 bytes from the 2 long integers */
		for (i=0;i<sizeof(long);i++)
			ptr[i] = ptr1[i];
		for (i=0;i<sizeof(long);i++)
			ptr[i+8] = ptr2[i];
		return;
	}
	if (node->right != NULL) /* similar as going left*/
	{
		int right_path=path + 1;
		if (right_path<=64)
		{
			long next_first8b2=first8b;
			char * ptr2 = (char *)&next_first8b2;
			int jump_offset= (right_path-1)/8;
			int bit_to_set = right_path - jump_offset*8-1;
			switch(bit_to_set){
				case 0:
					ptr2[jump_offset] |= bit0;break;
				case 1:
					ptr2[jump_offset] |= bit1;break;
				case 2:
					ptr2[jump_offset] |= bit2;break;
				case 3:
					ptr2[jump_offset] |= bit3;break;
				case 4:
					ptr2[jump_offset] |= bit4;break;
				case 5:
					ptr2[jump_offset] |= bit5;break;
				case 6:
					ptr2[jump_offset] |= bit6;break;
				case 7:
					ptr2[jump_offset] |= bit7;break;
				default:
					printf("Something wrong with the right first8b.\n");
					break;
			}
			traversal(node->right,right_path,tbl,next_first8b2,last8b);
			
			
		}
		else /* path >=64 */
		{
			long next_last8b2=last8b;
			char * ptr2 = (char *)&next_last8b2;
			int jump_offset= (right_path-64-1)/8;
			int bit_to_set = (right_path-64) - jump_offset*8-1;
			switch(bit_to_set){
				case 0:
					ptr2[jump_offset] |= bit0;break;
				case 1:
					ptr2[jump_offset] |= bit1;break;
				case 2:
					ptr2[jump_offset] |= bit2;break;
				case 3:
					ptr2[jump_offset] |= bit3;break;
				case 4:
					ptr2[jump_offset] |= bit4;break;
				case 5:
					ptr2[jump_offset] |= bit5;break;
				case 6:
					ptr2[jump_offset] |= bit6;break;
				case 7:
					ptr2[jump_offset] |= bit7;break;
				default:
					printf("Something wrong with the right last8b.\n");
					break;
			}
			traversal(node->right,right_path,tbl,first8b,next_last8b2);
			
		}
	}
	
	
}
void create_code_table(code_tree* r, code* tbl) {
  // TODO: add your code here
	traversal(r,0,tbl,0, 0);
}

// Encode the contents of the text file in_file_name into the file
// out_file_name using the code table tbl.
void encode(char* in_file_name, char* out_file_name, code* tbl) {
  // TODO: add your code here
	FILE * in_ptr = fopen(in_file_name,"r");
	FILE * out_ptr = fopen(out_file_name,"wb");
	if (in_ptr == NULL || out_ptr == NULL) /* NULL pointer check */
	{
		printf("Error when opening file.\n");
		return;
	}
	int c; /* the character */
	int len; /* the length read so far in a single character's bits[16] */
	int jump_offset; /* for jump byte to byte in bits[16] */
	int bit_to_set; /* for a single bit in one byte */
	char single_bit; /* a single bit we read */
	code curr;
	int count=0; /* count, once get to 8, then output to file and get down to 0 */
	char byte=0; /* the byte sequence we're creating at hand */
	while ((c=fgetc(in_ptr)) != EOF)
	{
		
		curr = tbl[c];
		len = 0;
		while (len<curr.len) /* the current character at hand is not finished reading */
		{
			jump_offset = len/8;
			bit_to_set = len-jump_offset*8;
			/* so the bit we should read from the bits[16] is bits[jump_offest]'s bit_to_set-th bit*/
			single_bit = (curr.bits[jump_offset]>>(7-bit_to_set)) & 0b1;
			
			if (count==8) /* full byte constructed already, output it*/
			{
				putc(byte,out_ptr);
				count=0;
				byte=0;
			}
			
			count += 1;
			if (single_bit == 0b1) /* the byte is initialize to 0, so only need to update when 1 appear */
			{
				byte |= (single_bit)<<(8-count);
			}
			len += 1;
			
		}
	}
	/* write out the rest unfinished byte and its length*/
	putc(byte,out_ptr);
	putc((char)count,out_ptr);
	
	/* close the file pointer for safety */
	fclose(in_ptr);
	fclose(out_ptr);
}

// Decode the contents of the file in_file_name using the given code tree
// and write the resulting plain text into the file out_file_name.
void decode_traversal(FILE * in_ptr, FILE * out_ptr, code_tree* curr,code_tree * root)
{
	/*
	 the procedure:
	 1. to read a byte from *in_ptr and iterate it bit by bit
	 2. if bit is 0, go left in *curr if bit is 1, go right in *curr
	 3. if meet a leaf, the write out to the *out_prt and reset the *curr to *root
	 4. when finish the byte, read the next byte
	 (in order to detect the end of the byte sequence, we will
	 keep 2 bytes: prev_b and curr_b.
	 if we know curr_b is not the final byte, then we can safely use all of prev_b
	 if the curr_b is the final byte, we will need to count how many bit to read from prev_b
	 */
	char prev_b,curr_b,next_b,single_bit;
	int count=0;
	int flag=0;
	fread((char *)&prev_b,1,1,in_ptr);
	flag = fread((char *)&curr_b,1,1,in_ptr);
	while (1)
	{	/* try read next byte, if fails, then the curr_b store the valid digit in prev_b*/
		flag = fread((char *)&next_b,1,1,in_ptr);
		if (flag==0)
			break;
		/* not break means we can totally process the bits in prev_b */
		while (count<8)
		{
			single_bit = (prev_b>>(7-count)) & 0b1;
			count += 1;
			if (single_bit==0b0) /* should go left in the tree */
			{
				curr = curr->left;
				if (is_leaf(curr)) /* is a leaf, need to out write the character */
				{
					fputc(curr->data,out_ptr);
					curr = root;
				}
				
			}
			else{ /* should go right in the tree */
				curr = curr->right;
				if (is_leaf(curr))
				{
					fputc(curr->data,out_ptr);
					curr = root;
				}
			}
		}
		/* go here means count=8 right now */
		count = 0; /* reset the count and ready to read next byte */
		strncpy(&prev_b,&curr_b,1);
		strncpy(&curr_b,&next_b,1);
	}
	/* go here means we are at the end of file already.
	 Then the curr_b store the valid number of digits we should use in prev_b */
	int remain = (int)curr_b;
	int i;
	for (i=0;i<remain;i++)
	{
		single_bit = (prev_b>>(7-i)) & 0b1;
		if (single_bit==0b0) /* should go left in the tree */
		{
			curr = curr->left;
			if (is_leaf(curr)) /* is a leaf, need to out write the character */
			{
				fputc(curr->data,out_ptr);
				curr = root;
			}
			
		}
		else{ /* should go right in the tree */
			curr = curr->right;
			if (is_leaf(curr))
			{
				fputc(curr->data,out_ptr);
				curr = root;
			}
			
		}
		
	}
	return;
}

void decode(char* in_file_name, char* out_file_name, code_tree* root) {
  // TODO: add your code here
	FILE * in_ptr = fopen(in_file_name,"rb");
	FILE * out_ptr = fopen(out_file_name,"w");
	if (in_ptr==NULL || out_ptr==NULL)
	{
		printf("Error when opening file.\n");
		return;
	}
	code_tree * curr = root;
	decode_traversal(in_ptr,out_ptr,curr,root);
	
	/* close file pointer for safety */
	fclose(in_ptr);
	fclose(out_ptr);
}

void encode_empty(char* out_file_name)
{
    /* special treatment for empty file
     just write out an empty binary file */
	FILE * out_ptr = fopen(out_file_name,"wb");
	if (out_ptr == NULL) /* NULL pointer check */
	{
		printf("Error when opening file.\n");
		return;
	}
	fclose(out_ptr);
}

void encode_1_character(char* out_file_name, int* char_1_flag)
{
	    /* special treatment for 1-character file
			   just write out to the binary file */
	FILE * out_ptr = fopen(out_file_name,"wb");
	if (out_ptr == NULL) /* NULL pointer check */
	{
		printf("Error when open file.\n");
		return ;
	}
	fputc(*char_1_flag,out_ptr);
	fclose(out_ptr);
}

void decode_1_character(char* out_file_name, int * char_1_flag)
{
	FILE * out_ptr = fopen(out_file_name,"w");
	if (out_ptr == NULL) /* NULL pointer check */
	{
		printf("Error when open file.\n");
		return;
	}
	fputc(*char_1_flag,out_ptr);
	fclose(out_ptr);
}

// The main function of the application.
int main(int argc, char** argv) {
  // TODO: add your code here
	int i,j;
	int weights[128]; /* initialize weights array */
	code tbl[128];
	for (i=0;i<128;i++) /* initialize the code table */
	{
		tbl[i].len=0;
		for (j=0;j<16;j++)
			tbl[i].bits[j]=0;
	}
	if (argc != 7)
	{ /* we expect 6 command inputs here, plus 1 original */
		printf("Sorry, wrong numbers of commands and parameters are passed in.\n");
		return 1;
	}
	
	char fileaddress1[100];
	char fileaddress2[100];
	char fileaddress3[100];
	char command1[10];
	char command2[10];
	char command3[10];
	int flag_encode,flag_decode, flag2, flag3;
	int char_1_flag=-1;
	strcpy(command1,argv[1]);
	strcpy(command2,argv[3]);
	strcpy(command3,argv[5]);
	strcpy(fileaddress1,argv[2]);
	strcpy(fileaddress2,argv[4]);
	strcpy(fileaddress3,argv[6]);
	flag_encode = strcmp(command1,"-e");
	flag_decode = strcmp(command1,"-d");
	flag2 = strcmp(command2,"-w");
	flag3 = strcmp(command3,"-o");
	
	if (flag2 !=0 || flag3 !=0 || (flag_encode !=0 && flag_decode !=0))
	{ /* test for wrong commands entered by user */
		printf("Sorry, wrong commands. Please check again.\n");
		return 1;
	}
	
	/* all the file pointer closing is done within each function */
	if (flag_encode==0) /* go encoding!!! */
	{
		count_occurrences((char *)&fileaddress1,(int *)&weights);
		write_weight_table((char *)&fileaddress2, (int *)&weights);
		code_tree * root = create_code_tree((int *)&weights,&char_1_flag);
		if (root==NULL) /* emtyp file or 1 character file encounter, special treatment */
		{
			if (char_1_flag==-1) /* emtpy file*/
			{
				encode_empty((char*)&fileaddress3);
				return 0;
			}
			else /* 1 character file*/
			{
				encode_1_character((char*)&fileaddress3,&char_1_flag);
				return 0;
			}
		}
		create_code_table(root,(code *)&tbl);
		encode((char *)&fileaddress1,(char *)&fileaddress3,(code *)tbl);
		if (root!=NULL)
			delete_code_tree(root); /* free the dynamically allocated memory */
		return 0;
	}
	else /* go decoding !!! */
	{
		read_weight_table(fileaddress2,(int *)&weights);
		code_tree * root = create_code_tree((int *)&weights,&char_1_flag);
		if (root==NULL && char_1_flag!=-1)
		{/* encounter 1-character file.
			 our implement could already deal with empty file, no worry */
			decode_1_character((char *)&fileaddress3,&char_1_flag);
			return 0;
		}
		decode((char *)&fileaddress1, (char *)&fileaddress3,root);
		if (root != NULL)
			delete_code_tree(root);/* free the dynamically allocated memory */
		return 0;
	}
	
	
  return 0;
}
