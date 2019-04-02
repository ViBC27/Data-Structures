/* ->
// Data Structure: Temp
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#ifndef Temp_H
#define Temp_H
#include <stdio.h>
#include "hash.h"
#include "heap.h"
#include "info.h"

FILE* OpenInputFile(char *inputFile);
void ReadInputFile(FILE *inFile, hash_t *hash);
void HashToHeap(hash_t * hash, heap_t *heap);
huff_t* MountHuffTree(heap_t *heap);
void MountInfoTable(huff_t *tree, info_t *bInfo, bool bits[], int totalBits);
byte_t* MountHeader(int treeSize, int trashSize);
void MountNewFile(huff_t *tree, info_t *bInfo, char *pathFile, char *outputFile, byte_t *header);
unsigned int setBit(unsigned int byte, int i);
int size_Trash(info_t *bInfo);


#endif