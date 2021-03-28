# Part 7
#include <stdio.h>

void foo() {
  int i;
  printf("%d ", i++);
}

int main() {
  int j = 1;
  while (j <= 10) {
    foo();
    j = j + 1;
  }
}

### The stack starts at some address in memory and then grows and shrinks linearly with each function call. In the main(),when we call function foo(), this is a nested function call. We allocate a function frame for foo(), in which the memory sets a certain space for the int i.
### However since the i is not initialized, its value happens to be 0 in our case.  When we do printf("%d",i++), it prints and increases the value at that space where the memory sets aside for the int i, now the value there is 1. When the foo() function terminates, the whole foo() frame is poped out along with the storage for int i. So now there is no other function frame on top of the main() function frame. But the Stack space that was used by the "foo()" stack frame still contain the most recent value that were stored there when "foo()" executed. That chunk of space could be reused when we call "foo()" agiain.
### Next iteration, we call the foo() again, it allocate a new function frame again. Because there is no other allocation for memory in between, this time the memory allocates exactly the same space for this time's int i,  the space which has just got freed from last function frame foo(). Then when we again do printf("%d",i++) , it again prints and increases the value at that particular memory, now it becomes 2.
### And as our iteration continues, the process repeats. That's why we print out 0 1 2 3 4 5 6 7 8 9.


# Part 8
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node Node;

struct list_node {
  int data;
  Node* next;
};

void foo(Node* n) {
  free(n->next);
}

Node* create(int x, Node* n) {
  Node* n1 = malloc(sizeof(Node));
  n1->data = x;
  n1->next = n;
  
  return n1;
}

int main() {
  Node* n1 = create(1, NULL);
  Node* n2 = create(2, n1);
  
  foo(n2);
  Node* n3 = create(3, NULL);
  
  n1->data = 42;
  
  printf("%d\n", n3->data);
  free(n2);
  free(n3);
 
  return 0;
}

# 1.
### The problem of this program lies in the line  "foo(n2)". In that function, it actually free the memory allocation for the Node sturcture after n2. In our case, the memory allocation space for n1 is freed by this calling . So afterwards the command "n1->data = 42" is dangerous because the n1 structure is no longer there. 
### The reason why when we run this function, it still print out 42 is that, after we free the space of n1, we immediately do "Node * n3 = create(3,NULL) " This Node n3 is allocated the space where n1 originally lived. So next command "n1->data=42", the n1->data actually points to the place for n3->data and change n3->data to be 42. Then that's why later we run " printf("%d\n", n3->data) ", it would print out 42.

# 2.
### If we switch "foo(n2)" and "Node * n3", Then it would print out 3 ( as I experimented). The reason is that, we first allocated the memory space for Node1, Node2, Node3. Even if we do "foo(n2)" which freed the allocation space for Node1, the space for Node 3 is not invaded, so we are good to print the data for Node3, which is 3.

