#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "heap.h"
#include "compress.h"
#include "temp.h"

typedef unsigned char byte_t;

void compress(char *inputFile, char *outputFile) {
  FILE *inFile =  OpenInputFile(inputFile);
  
  hash_t *hash = new_Hash();
  heap_t *heap = new_Heap();
  info_t *bInfo = new_Info();
  huff_t *root; bool bits[256];
  byte_t *header;

  ReadInputFile(inFile, hash);  
  HashToHeap(hash, heap);
  root = MountHuffTree(heap);
  MountInfoTable(root, bInfo, bits, 0);
  int sTree = size_Huff(root);
  int sTrash = size_Trash(bInfo);
  header = MountHeader(sTree, sTrash);
  MountNewFile(root, bInfo, inputFile, outputFile, header);
  printf("Done\n");
}