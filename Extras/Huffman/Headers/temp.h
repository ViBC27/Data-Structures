/* ->
// Data Structure: Huffman
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#ifndef Temp_H
#define Temp_H
#include "hash.h"
#include "heap.h"

huff_t* MountHuffTree(heap_t *heap);
void HashToHeap(hash_t * hash, heap_t *heap);

#endif