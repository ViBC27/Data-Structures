/* ->
// Data Structure: Huffman
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#ifndef Compress_H
#define Compress_H
#include "hash.h"
#include "heap.h"
#include "info.h"

void compress(char *inputFile, char *outputFile);
void ReadInputFile(FILE *inFile, hash_t *hash);
void HashToHeap(hash_t * hash, heap_t *heap);
huff_t* MountHuffTree_Comp(heap_t *heap, huff_t **root);
void MountInfoTable(huff_t *tree, info_t *bInfo, bool bits[], int totalBits);
void MountHeader(huff_t *tree, char *outputFile, int treeSize, int trashSize, byte_t *oneByte);
void MountFile_Comp(huff_t *tree, info_t *bInfo, char *inputFile, char *outputFile, byte_t oneByte);
unsigned int setBit(unsigned int byte, int i);
int size_Trash(info_t *bInfo);

#endif
