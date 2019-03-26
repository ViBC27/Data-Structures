/* ->
// Data Structure: Binary Search Tree
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#ifndef Heap_H
#define Heap_H

typedef struct heap heap_t;
struct heap {
  int size;
  huff_t *data[MAX_SIZE];
};

heap_t* newHeap();
void enqueue(heap_t *heap, huff_t *item);
huff_t *dequeue(heap_t *heap);
int getParentIndex(int i);
int getLeftIndex(int i);
int getRightIndex(int i);
void minHeapify(heap_t *heap, int i);
int isEmpty(heap_t *heap);
void swap(huff_t *a, huff_t *b);
void showHeap(heap_t *heap);

#endif
