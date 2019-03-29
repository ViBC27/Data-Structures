#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "heap.h"
#include "compress.h"
#include "temp.h"

void compress(char *pathFile, char *outputFile) {
  FILE *File;
  File = fopen (pathFile,"rb");
  if(File == NULL) {
    printf("Not open file.\n");
    exit(1);
  }

  heap_t *heap = new_Heap();
  hash_t *hash = new_Hash();
  unsigned char byte;
  while(fscanf(File, "%c", &byte) != EOF) {
    put_Hash(hash, byte);
  }
  HashToHeap(hash, heap);
  huff_t *root = MountHuffTree(heap);
  showHuffman(root);
}