#pragma once

// An entry in the binary heap data structure.
struct entry_s {
  int prio;
  void* elem;
};

typedef struct entry_s entry;

// The actual binary heap.
struct minheap_s {
  entry* arr;
  size_t count;
  size_t capacity;
};

typedef struct minheap_s minheap;

// Create a new binary heap of the given maximal capacity.
minheap* minheap_create(size_t capacity);

// Delete all resources used by the binary heap h.
void minheap_delete(minheap *h);

// Get the number of entries in the binary heap h.
size_t minheap_get_count(minheap* h);

// Insert element elem with priority prio into binary heap h.
void minheap_add(minheap *h, void* elem, int prio);

// Remove from h the element with minimal priorty and return it.
void* minheap_delete_min(minheap* h);
