#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "minheap.h"

minheap* minheap_create(size_t capacity){
  minheap* heap = (minheap *) malloc(sizeof(minheap));
  
  if(heap == NULL){
    fprintf(stderr, "Failed to create minheap.");
    abort();
  }

  heap->count = 0;
  heap->capacity = capacity;
  heap->arr = (entry *) malloc(capacity*sizeof(entry));
  
  if (heap->arr == NULL) {
    printf("Failed to create minheap.");
    abort();
  }
  
  return heap;
}

void minheap_delete(minheap* heap) {
  assert(heap);

  free(heap->arr);
  free(heap);
}

size_t minheap_get_count(minheap* heap) {
  assert(heap);
  return heap->count;
}

void heapify_bottom_top(minheap* heap, int index) {
  entry temp;
  int parent_node = (index - 1) / 2;

  if (heap->arr[parent_node].prio > heap->arr[index].prio) {
    temp = heap->arr[parent_node];
    heap->arr[parent_node] = heap->arr[index];
    heap->arr[index] = temp;
    heapify_bottom_top(heap, parent_node);
  }
}

void heapify_top_bottom(minheap *heap, int parent_node){
  int left = parent_node*2 + 1;
  int right = parent_node*2 + 2;
  int min;
  entry temp;

  if (left >= heap->count || left < 0) {
    left = -1;
  }

  if (right >= heap->count || right < 0) {
    right = -1;
  }
  
  if (left != -1 && heap->arr[left].prio < heap->arr[parent_node].prio) {
    min = left;
  } else {
    min = parent_node;
  }

  if (right != -1 && heap->arr[right].prio < heap->arr[min].prio) {
    min = right;
  }
  
  if(min != parent_node) {
    temp = heap->arr[min];
    heap->arr[min] = heap->arr[parent_node];
    heap->arr[parent_node] = temp;    
    heapify_top_bottom(heap, min);
  }
}

void minheap_add(minheap *heap, void* elem, int prio){
  assert(heap);
  assert(heap->count < heap->capacity);

  heap->arr[heap->count].prio = prio;
  heap->arr[heap->count].elem = elem;
  
  heapify_bottom_top(heap, heap->count);
  heap->count++;
}

void* minheap_delete_min(minheap* heap) {
  assert(heap);
	assert(heap->count > 0);

  void* min = heap->arr[0].elem;
  
  heap->arr[0] = heap->arr[heap->count-1];
  heap->count--;
  heapify_top_bottom(heap, 0);
  
  return min;
}
