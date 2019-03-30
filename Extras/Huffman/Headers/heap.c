/* ->
// Data Structure: Heap
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

heap_t* new_Heap() {
  heap_t *heap = (heap_t*) malloc(sizeof(heap_t));
  heap->size = 0;
  return heap;
}

void enqueue(heap_t *heap, huff_t *item) {
  if(heap->size >= SIZE_HEAP) {
    printf("Heap overflow\n");
  } 
  else {
    heap->data[++heap->size] = item;
    int key_index = heap->size;
    int parent_index = getParentIndex(heap->size);
    while(parent_index >= 1 && heap->data[key_index]->frequency <= heap->data[parent_index]->frequency) {
      swap(heap->data[key_index], heap->data[parent_index]);
      key_index = parent_index;
      parent_index = getParentIndex(key_index);
    }
  }
}

huff_t *dequeue(heap_t *heap) {
  if(isEmpty_Heap(heap)) {
    printf("Heap underflow\n");
    return NULL;
  } 
  else {
    huff_t *item = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size--;
    minHeapify(heap, 1);
    return item;
  }
}

void minHeapify(heap_t *heap, int i) {
  int smaller;
  int left_index = getLeftIndex(i);
  int right_index = getRightIndex(i);
  if(left_index <= heap->size && heap->data[left_index]->frequency <= heap->data[i]->frequency) {
    smaller = left_index;
  }
  else {
    smaller = i;
  }
  if(right_index <= heap->size && heap->data[right_index]->frequency <= heap->data[smaller]->frequency) {
    smaller = right_index; 
  }
  if(heap->data[i]->frequency != heap->data[smaller]->frequency) {
    swap(heap->data[i], heap->data[smaller]);
    minHeapify(heap, smaller);
  }
}

void swap(huff_t *a, huff_t *b) {
  huff_t c = *a;
  *a = *b;
  *b = c;
}

void show_Heap(heap_t *heap) {
  int i;
  for(i = 1; i <= heap->size; i++) {
    printf("%c", heap->data[i]->byte);
  }
  printf("\n");
}

int getParentIndex(int i) {
  return i >> 1;
}
int getLeftIndex(int i) {
  return i << 1;
} 
int getRightIndex(int i) {
  return (i << 1) + 1;
}

int isEmpty_Heap(heap_t *heap) {
  return (heap->size == 0);
}
