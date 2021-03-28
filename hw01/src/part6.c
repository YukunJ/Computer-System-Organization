#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "part6.h"

/* In part6.c you will implement a sorted binary tree
 A binary tree is a tree in which each node has 
 at most two children (referred to as left and right).
 Each node also holds a user value (which is an int value in 
 this exercise).  In a sorted binary tree, for each node n, the values stored
 in the nodes of the left subtree of n are smaller than n's value and the
 values stored in the nodes of the right subtree of n are greater. Note
 that the ordering is strict, i.e., we do not allow duplicate values in
 the tree.

 Binary trees can be complicated if one is to keep them balanced.
 They are much simpler if we don't care about balancing. You will 
 implement the simple, unbalanced binary in this exercise.
 Specifically, after inserting 3, 7, 5, 8 (in the order specified),
 your binary tree will look like this simplified representation:
       3
        \
	       7
	     /   \
			5     8

Your task:
* complete the struct declaration in part6.h 
* implement functions get_left, get_right, get_data, insert, delete, delete_min, and clear
*/

void init(Node** root) {
  *root = NULL;
}

// get_left returns a pointer to the left child node of the node pointed to by n
Node* get_left(Node* n) {
  if (n==NULL) /* meaningful guard test */
		assert(0);
	return n->left;
}

// get_right returns a pointer to the right child node of the node pointed to by n
Node* get_right(Node* n) {
  if (n==NULL) /* meaningful guard test */
		assert(0);
	return n->right;
}

// get_data returns the int value stored at the node pointed to by n
int get_data(Node* n) {
  if (n==NULL) /* meaningful guard test */
		assert(0);
	return n->data;
}


// new_node allocates a new tree node and initializes its fields properly.
// In particular, it will store the given value d in the new node.
// Note: before implementing this function, you must decide what 
// fields the tree node should contain and complete the 
// type definition of tree_node in part6.h
static Node* new_node(int d) 
{
  // TODO: Replace the following with your code.
	Node * new = malloc(sizeof(Node)); /* allocate the storage for the new node on the heap */
	new->data = d;
	new->left = new->right = NULL; /* initialize the left and right children to be NULL */
	return new; /* return the pointer for manipulation */
}

// insert stores a value d in the sorted binary tree,
// specified by its root (*root).
// It returns 1 if d has been successfully inserted 
// (i.e. d was not already present in the tree)
// It returns 0 if d has not been inserted (because it was already present).
// If the tree was empty before insertion, *root is set to the new root node.
int insert(Node** root, int d)
{
  // TODO: Replace the following with your code.
  if (*root == NULL)
	{ /* if the tree is empty right now, initialize the root to be new node you create */
		*root = new_node(d);
		return 1;
	}
	
	Node * curr = *root;
	while (curr->data !=d )
	{
		if ( (curr->data)< d )
		/* if data<d we want to go to right child */
		{ if (curr->right != NULL)
				curr = curr->right;
			else /* if right child is empty, then this is the place to insert */
				break;
	  }
		else{ /* if data>d we want to go to left child*/
			if (curr->left != NULL)
				curr = curr->left;
			else /* if left child is empty, then this is the place to insert */
				break;}
	}
	
	if (curr->data == d)
	/* d already present, insertion failed */
		return 0;
	
	else if (curr->data < d)
	{
		curr->right = new_node(d);
		return 1; /*success*/
	}
	else
	{
		curr->left = new_node(d);
		return 1; /*success*/
	}
		
}

// delete_min removes the node with the minimum value from the tree rooted at root.
// It returns a pointer to the root of the new tree after the removal
// Additionally, it sets the value of the variable pointed to by min to the
// removed node.
//
// delete_min assumes that root is not NULL (i.e. the tree is non-empty).
//
// For example, for the tree below
//      3
//       \
//	      7
//	    /   \
//      5    8
//
// delete_min will return a pointer to the root of the new tree
//	     7
//	   /   \
//     5   8
// and sets min to point to the node storing 3.
//
// Here is another example:
//       7
//      / \
//     5   8
//    /
//   3
// In this case, delete_min will again return a pointer to the root of the tree
//       7
//      / \
//     5   8
// and set min to point to the node storing 3.
// If the input tree only contains a single node, delete_min should return
// NULL and set min to root.
Node* delete_min(Node* root, Node** min)
{
  // TODO: Replace the following with your code.
	if (root->left == NULL && root->right == NULL){ /* boundary case: if is a single node */
		*min = root;
		return NULL;}
	
	Node * parent = NULL;
	Node * curr = root;
	
	while (curr->left != NULL) /* keep walking left finding minimum*/
	{
		parent = curr;
		curr = curr->left;
	}
	*min=curr;
	if (parent == NULL) /* the minimum is the root, then update the root */
		return curr->right;
	else
	{
		parent->left = curr->right; /* for sure curr has no left child, connect the right-child of curr to the left child of curr's parent */
		return root;
	}
	
	
}

// delete searches for and removes the value d from the sorted binary tree,
// specified by its root (*root).
// It returns 1 if d was present in the tree and 0 otherwise.
// Additionally, it sets *root to the new root of the tree obtained after deletion.
//
// For example, for the tree below
//      3
//       \
//	      7
//	     / \
//      5   8
//
// A call to delete with value 2 will return 0 and leave the tree
// and *root unchanged.
// A call to delete with value 3 will return 1, modify the tree to
//	      7
//	    /  \
//      5   8
// and set *root to the node storing 7.
// A call to delete with value 7 on the original tree will return 1
// and modify the tree to
//      3
//       \
//	      5
//	       \
//          8
// but leave *root unchanged.
//
// Do not forget to free the removed node.
// Hint: use delete_min to handle one of the cases.
int delete(Node** root, int d) {
  // TODO: Replace the following with your code
	
	if (*root ==NULL) /* boundary case: empty tree */
		return 0;
	
	if ( (*root)->data==d) /* if the root is to be deleted */
	{
		if ( (*root)->left==NULL && (*root)->right==NULL)
		{ /* if is a single node tree */
			Node * temp = *root;
			*root = NULL;
			free(temp);
			return 1;
		}
		else if ( (*root)->left!=NULL && (*root)->right != NULL)
		{ /* both children present*/
			Node * min;
			Node * temp;
			Node * right_subtree;
			temp = *root;
			right_subtree = delete_min((*root)->right, &min); /* take out the smallest in the right sub-tree */
			min->left = (*root)->left;
			min->right = right_subtree;
			*root = min;
			free(temp);
			return 1;
			
		}
		else if ( (*root)->left == NULL)
		{ /* only right child present, update the root to be right child */
			Node * temp = *root;
			*root = (*root)->right;
			free(temp);
			return 1;
		}
		else if ( (*root)->right == NULL)
		{/* only left child present, update the root to be left child */
			Node * temp = *root;
			*root = (*root)->left;
			free(temp);
			return 1;
		}
		
	}
	
	/* Now is the case: root.data!=d
	 so we need to go searching for the node */
	Node * curr = *root;
	Node * parent = NULL;
	int failure_flag=0;  /* flag indicating d not found */
	
	while ( curr != NULL && curr->data !=d )
	{
		if (curr->data > d)
		{/* try go left */
			if (curr->left == NULL) /* no left any more, then search failed */
			{
				failure_flag = 1;
				break;
			}
			parent = curr;
			curr = curr->left;
		}
		else if (curr->data <d)
		{/* try go right */
			if (curr->right == NULL) /* no right any more, then search failed */
			{
				failure_flag = 1;
				break;
			}
			parent = curr;
			curr = curr->right;
		}
	}
	
	if (failure_flag == 1) /* if value d not found in the tree, then return 0 */
		return 0;
  
	if (curr->left != NULL && curr->right != NULL) /* the node-to-be-deleted has 2 children */
	{
		Node * min;
		Node * subtree;
		subtree = delete_min(curr->right,&min); /* take the smallest in the right sub-tree */
		if (parent->left == curr) /* curr is the left child of its parent */
		{
			parent->left = min;
			min->left = curr->left;
			min->right = subtree;
			free(curr);
		}
		else
		{ /* curr is the right child of its parent */

			parent->right = min;
			min->left =curr->left;
			min->right = subtree;
			free(curr);
		}
	}
	else if (curr->left == NULL) /* curr only has right child */
	{
		if (parent->left == curr)
			parent->left = curr->right;
		else
			parent->right = curr->right;
		free(curr);
	}
	else if (curr->right == NULL) /* curr only has left child */
	{
		if (parent->left == curr)
			parent->left = curr->left;
		else
			parent->right = curr->left;
		free(curr);
	}
	return 1;
		
	
		
	
}

// clear de-allocates all nodes in the tree rooted at the node pointed to by root
void clear(Node *root)
{
  // TODO: Replace the following with your code.
	if (root==NULL) /* already NULL pointer, nothing to free() */
		return;
	/* use recursive approach, first free all children */
  if (root->left != NULL)
		clear(root->left);
	if (root->right != NULL)
		clear(root->right);
	free(root);
}
