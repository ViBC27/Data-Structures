#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hash.h>
#include <heap.h>

huff_t* MountHuffTree(heap_t *heap) {
  huff_t *item1, *item2, *item3;
  while(heap->size > 1) {
    item1 = dequeue(heap);
    item2 = dequeue(heap);
    item3 = agroupItems_Huff(item1, item2);
    enqueue(heap, item3);
  }
  return dequeue(heap);
}

void HashToHeap(hash_t * hash, heap_t *heap) {
  int i;
  for(i = 0; i < SIZE_HASH; i++) {
    if(hash->huffTable[i] != NULL) {
      enqueue(heap, hash->huffTable[i]);
    }
  }
}

void compress(FILE *pathFile) {
  heap_t *heap = new_Heap();
  hash_t *hash = new_Hash();
  unsigned char byte;
  while(fscanf(pathFile, "%c", &byte) != EOF) {
    put_Hash(hash, byte);
  }
  HashToHeap(hash, heap);
  huff_t *root = MountHuffTree(heap);
  showHuffman(root);

}

void readFile(int file) {
  char path[100];
  scanf(" %s", path);
  FILE *pathFile;
  pathFile = fopen (path,"rb");
  if(pathFile == NULL) {
    printf("Not open file.\n");
    exit(27);
  }
  else {
    if(file == 1) {
      compress(pathFile);
    }
    else {
      printf("Descompress\n");
      strcat(path, ".huff");
    }
    fclose (pathFile);
  }
}

int main() {
  int file;
  scanf("%d", &file);
  readFile(file);
  return 0;
}
