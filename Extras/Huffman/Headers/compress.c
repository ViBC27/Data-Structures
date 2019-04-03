/* ->
// Data Structure: Huffman
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "heap.h"
#include "compress.h"
#include "shared.h"

void compress(char *inputFile, char *outputFile) {
  FILE *inFile =  OpenInputFile(inputFile);
  
  hash_t *hash = new_Hash();
  heap_t *heap = new_Heap();
  info_t *bInfo = new_Info();
  huff_t *root; bool bits[16];
  byte_t *bytes;

  ReadInputFile(inFile, hash);  
  HashToHeap(hash, heap);
  MountHuffTree_Comp(heap, &root);
  MountInfoTable(root, bInfo, bits, 0);
  int sTree = size_Huff(root);
  int sTrash = size_Trash(bInfo);
  MountHeader(&bytes, sTree, sTrash);
  MountFile_Comp(root, bInfo, inputFile, outputFile, bytes);
  printf("Done\n");
}


void ReadInputFile(FILE *inFile, hash_t *hash) {
  byte_t byte;
  while(fscanf(inFile, "%c", &byte) != EOF) {
    put_Hash(hash, byte);
  }
}

void HashToHeap(hash_t * hash, heap_t *heap) {
  int i;
  for(i = 0; i < SIZE_HASH; i++) {
    if(hash->huffTable[i] != NULL) {
      enqueue(heap, hash->huffTable[i]);
    }
  }
}

void MountHuffTree_Comp(heap_t *heap, huff_t **root) {
  huff_t *item1, *item2, *item3;
  while(heap->size > 1) {
    item1 = dequeue(heap);
    item2 = dequeue(heap);
    item3 = agroupItems_Huff(item1, item2);
    enqueue(heap, item3);
  }
  *root = dequeue(heap);
}

void MountInfoTable(huff_t *tree, info_t *bInfo, bool bits[], int totalBits) {
  if(!isEmpty_Huff(tree)) {
    if(isLeaf_Huff(tree)) {
      put_Info(bInfo, tree->byte, tree->frequency, totalBits);
      for(int i = 0; i < totalBits; i++) {
        bInfo->table[tree->byte]->bits[i] = bits[i];
      }
    }
    else {
      bits[totalBits] = 0;
      MountInfoTable(tree->left, bInfo, bits, totalBits + 1);
      bits[totalBits] = 1;
      MountInfoTable(tree->right, bInfo, bits, totalBits + 1);
    }
  }
}

void MountHeader(byte_t**bytes, int treeSize, int trashSize) {
  byte_t *bytesAux = (byte_t*) malloc(2 * sizeof(byte_t));
  bytesAux[0] = trashSize << 5 | treeSize >> 8;
  bytesAux[1] = treeSize;
  *bytes = bytesAux;
}

void MountFile_Comp(huff_t *tree, info_t *bInfo, char *inputFile, char *outputFile, byte_t *bytes) {
  FILE *inFile = fopen(inputFile, "rb");
  FILE *newFile = fopen(outputFile, "wb");
  
  fprintf(newFile, "%c%c", bytes[0], bytes[1]);
  PrintTree_Huff(tree, newFile);

  byte_t byte = 0, newByte = 0; int position = 0;
  while(fscanf(inFile, "%c", &byte) != EOF) {
    for(int i = 0; i < bInfo->table[byte]->totalBits; i++, position++) {
      position %= 8;
      if(bInfo->table[byte]->bits[i]) {
        newByte = set_bit(newByte, 7 - position);
      }
      if((position + 1) % 8 == 0) {
        fprintf(newFile, "%c", newByte);
        newByte = 0;
      }
    }
  }

  if(bytes[0] >> 5 != 0) {
    fprintf(newFile, "%c", newByte);
  }
  fclose(inFile);
  fclose(newFile);
}

int size_Trash(info_t *bInfo) {
	long int trashSize = 0;
	for(int i = 0; i < 256; i++) {
    if(bInfo->table[i] != NULL) {
      if(bInfo->table[i]->frequency != 0) {
        trashSize += (bInfo->table[i]->totalBits * bInfo->table[i]->frequency) % 8;
      }
    }
  }
	trashSize = 8 - (trashSize % 8);
  return(trashSize);
}

unsigned int set_bit(unsigned int byte, int i) {
  unsigned int mask = 1 << i;
  return(mask | byte);
}
