/* ->
// Data Structure: Heap
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#ifndef Heap_H
#define Heap_H
#define SIZE_HEAP 257
#include "huff.h"

typedef struct heap heap_t;
struct heap {
  int size;
  huff_t *data[SIZE_HEAP];
};

heap_t* new_Heap();
void enqueue(heap_t *heap, huff_t *item);
huff_t *dequeue(heap_t *heap);
int getParentIndex(int i);
int getLeftIndex(int i);
int getRightIndex(int i);
void minHeapify(heap_t *heap, int i);
int isEmpty_Heap(heap_t *heap);
void swap(huff_t *a, huff_t *b);
void show_Heap(heap_t *heap);

#endif
