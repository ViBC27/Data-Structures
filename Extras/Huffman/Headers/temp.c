/* ->
// Data Structure: Temp
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#include <stdio.h>
#include <stdlib.h>
#include "temp.h"

FILE* OpenInputFile(char *inputFile) {
  FILE *inFile= fopen(inputFile, "rb");
  if(inFile == NULL) {
    printf("Not open file.\n");
    exit(1);
  }
  return inFile;
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

byte_t* MountHeader(int treeSize, int trashSize) {
  byte_t *bytes = (byte_t*) malloc(3 * sizeof(byte_t));
  bytes[0] = trashSize << 5 | treeSize >> 8;
  bytes[1] = treeSize;
  return bytes;
}

void MountNewFile(huff_t *tree, info_t *bInfo, char *pathFile, char *outputFile, byte_t *header) {
  FILE *pFile = fopen(pathFile, "rb");
  FILE *newFile = fopen(outputFile, "wb");
  fprintf(newFile, "%c%c", header[0], header[1]);
  
  PrintTree_Huff(tree, newFile);

  byte_t byte = 0, newByte = 0; int pos = 0;
  while(fscanf(pFile, "%c", &byte) != EOF) {
    for(int i = 0; i < bInfo->table[byte]->totalBits; i++, pos++) {
      pos %= 8;
      if(bInfo->table[byte]->bits[i]) {
        newByte = setBit(newByte, 7 - pos);
      }
      if ((pos + 1) % 8 == 0) {
        fprintf(newFile, "%c", newByte);
        newByte = 0;
      }
    }
  }

  if(header[0] >> 5 != 0) {
    fprintf(newFile, "%c", newByte);
  }
  fclose(pFile);
  fclose(newFile);
}

unsigned int setBit(unsigned int byte, int i) {
  unsigned int mask = 1 << i;
  return(mask | byte);
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