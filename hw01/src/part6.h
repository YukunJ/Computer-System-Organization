#pragma once

typedef struct tree_node Node;

struct tree_node {
  // TODO: complete struct declaration
	int data; /* data : integer type */
	struct tree_node * left; /* left : pointer to a struct tree_node */
	struct tree_node * right; /* right : pointer to a struct tree_node */
};

void init(Node** root);
Node* get_left(Node* n);
Node* get_right(Node* n);
int get_data(Node* n);
int insert(Node** root, int d);
Node* delete_min(Node* root, Node** min);
int delete(Node** root, int d);
void clear(Node *root);
