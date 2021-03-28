#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <assert.h>

#include "part5.h"

// Your task: implement functions length, reverse

void init(Node** head) {
  *head = NULL;
}

Node* get_next(Node* curr) {
  return curr->next;
}

int get_data(Node* curr) {
  return curr->data;
}

int has_next(Node* curr) {
  return curr != NULL;
}

void clear(Node** head) {
  Node* curr = *head;

  while (curr != NULL) {
    Node* tmp = curr;
    curr = curr->next;
    free(tmp);
  }
  
  *head = NULL; // not strictly necessary, but good practice
}

Node* new_node(int d, Node* n) {
  Node* node = malloc(sizeof(Node));
  if (node == NULL) assert(0); // insert meaningful error handling here

  node->data = d;
  node->next = n;

  return node;
}

void insert(Node** head, int d) {
  Node* node = new_node(d, *head);
  *head = node;
}

// Return the length of a linked list, starting from the
// given head pointer.
//
// As an example, consider the following linked list:
//
// |---------|      |---------|      |---------|
// |    0    |  /-> |    1    |  /-> |    2    |  
// |---------| /    |---------| /    |---------| 
// |       ----     |       ----     |   NULL  |
// |---------|      |---------|      |---------|
//
// If the head node pointer refers to the node with the value 0,
// length(head) should return 3.  If the head node pointer
// refers to the node with the value 1, length(head) should
// return 2, etc.
size_t length(Node* head)
{
  // TODO: Replace the following with your code
	size_t len=0;
	
	/* has_next means this node is not NULL , then count it */
	for (; has_next(head); head=get_next(head), len += 1)
		;
	return len;
}


// Return a pointer to the last node in a linked list, starting
// from the given head node.  If the list is empty, then
// simply return the head node pointer.
//
// As an example, consider the following linked list:
//
// |---------|      |---------|      |---------|
// |    0    |  /-> |    1    |  /-> |    2    |
// |---------| /    |---------| /    |---------|
// |       ----     |       ----     |  NULL   |
// |---------|      |---------|      |---------|
//
// If the head node pointer refers to the node with the value 0,
// last(head) should return a pointer to the node with the
// value of 2.
Node* last(Node* head)
{
  // TODO: Replace the following with your code
  if (head==NULL) /* handle boundary case */
		return head;
	
	Node * curr = head;
	while (curr->next != NULL) /* the last node means its descendent is NULL */
		curr = curr->next;
	return curr;
}


// Reverse a linked list, starting from the given head pointer.
//
// As an example, consider the following linked list:
//
// |---------|      |---------|      |---------|
// |    0    |  /-> |    1    |  /-> |    2    |  
// |---------| /    |---------| /    |---------| 
// |       ----     |       ----     |   NULL  |
// |---------|      |---------|      |---------|
//
// If the head node pointer refers to the node with the value 0,
// reverse(head) should return a pointer to the node with value 3 in a list:
//
// |---------|      |---------|      |---------|
// |    3    |  /-> |    2    |  /-> |    1    |  
// |---------| /    |---------| /    |---------| 
// |       ----     |       ----     |   NULL  |
// |---------|      |---------|      |---------|
//
// Your implementation should modify the input inplace list rather than allocate
// a new list.
Node* reverse(Node* head)
{
  // TODO: Replace the following with your code
  if (head ==NULL || head->next == NULL)
	/* boundary case, if NULL or 1-element list, then nothing to reverse, just return the head pointer */
		return head;
	
	/* return the list start at head->next,
	 it will return the header of the reversed list */
	Node * reverse_smaller = reverse(head->next);
	
	/* find the last node in the smaller reversed list*/
	Node * last_in_smaller = last(reverse_smaller);
	/* the head now becomes the tail */
	last_in_smaller->next = head;
	head->next = NULL; /* signal the end of the list */
	return reverse_smaller; /* return the head of the reversed list */
}
