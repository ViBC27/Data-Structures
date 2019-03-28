#include <stdio.h>
#include <hash.h>
#include <heap.h>

void HashToHeap(hash_t * hash, heap_t *heap) {
  int i;
  for(i = 0; i < SIZE_HASH; i++) {
    if(hash->huffTable[i] != NULL) {
      enqueue(heap, hash->huffTable[i]);
    }
  }
}

void MountHuffTree(heap_t *heap) {
  huff_t *item1, *item2, *item3;
  while(heap->size > 1) {
    item1 = dequeue(heap);
    item2 = dequeue(heap);
    item3 = agroupItems_Huff(item1, item2);
    enqueue(heap, item3);
  }
  
  printf("Aqui\n");
}

/*
void showHuffman() {
  if(!isEmptyAux_BSTree(bt)) {
    printf("(%d", bt->value);
    showPreOrderAux_BSTree(bt->left);
    showPreOrderAux_BSTree(bt->right);
    printf(")");
  }
  else {
    printf("()");
  }
}
*/

int main() {
  heap_t *HP = new_Heap();
  hash_t *H1 = new_Hash();
  put_Hash(H1, 'a');
  put_Hash(H1, 'a');
  put_Hash(H1, 'a');
  put_Hash(H1, 'b');
  put_Hash(H1, 'b');
  put_Hash(H1, 'c');
  HashToHeap(H1, HP);
  MountHuffTree(HP);
  return 0;
}
