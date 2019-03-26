#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 257

typedef struct heap heap_t;
typedef struct huff huff_t;
struct heap {
  int size;
  huff_t *data[MAX_SIZE];
};

struct huff {
  unsigned char item;
  int frequency;
  huff_t *left;
  huff_t *right;
};

// Heap
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

// Huff
huff_t *newNode_Huff(unsigned char item);
huff_t *agroupNodes_Huff(huff_t *left; huff_t *right);

int main() {
  heap_t *heap = newHeap();
  huff_t* a = newNode_Huff('a');
  huff_t* b = newNode_Huff('a');
  huff_t* c = newNode_Huff('b');
  enqueue(heap, a);
  enqueue(heap, b);
  enqueue(heap, c);
  showHeap(heap);
  return 0;
}

heap_t* newHeap() {
  heap_t *heap = (heap_t*) malloc(sizeof(heap_t));
  heap->size = 0;
  return heap;
}

void enqueue(heap_t *heap, huff_t *item) {
  if(heap->size >= MAX_SIZE) {
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
  if(isEmpty(heap)) {
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

int isEmpty(heap_t *heap) {
  return (heap->size == 0);
}

void swap(huff_t *a, huff_t *b) {
  huff_t c = *a;
  *a = *b;
  *b = c;
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

void showHeap(heap_t *heap) {
  int i;
  for(i = 1; i <= heap->size; i++) {
    printf("%c ", heap->data[i]->item);
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

huff_t *newNode_Huff(unsigned char item) {
  huff_t *newNode = (huff_t*) malloc(sizeof(huff_t));
  newNode->item = item;
  newNode->frequency = 1;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

huff_t *agroupNodes_Huff(huff_t *left; huff_t *right) {
  huff_t *newNode = (huff_t*) malloc(sizeof(huff_t));
  newNode->frequency = left->frequency + right->frequency;
  newNode->left = left;
  newNode->right = right;
  newNode->item = '*';
  return newNode;
}
