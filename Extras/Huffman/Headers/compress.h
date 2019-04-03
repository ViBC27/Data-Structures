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
void MountHuffTree_Comp(heap_t *heap, huff_t **root);
void MountInfoTable(huff_t *tree, info_t *bInfo, bool bits[], int totalBits);
void MountHeader(byte_t**bytes, int treeSize, int trashSize);
void MountFile_Comp(huff_t *tree, info_t *bInfo, char *inputFile, char *outputFile, byte_t *bytes);
int size_Trash(info_t *bInfo);
unsigned int set_bit(unsigned int byte, int i);

#endif