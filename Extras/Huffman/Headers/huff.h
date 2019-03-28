/* ->
// Data Structure: Huffman
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#ifndef Huff_H
#define Huff_H

typedef struct huff huff_t;
struct huff {
  unsigned char byte;
  long int frequency;
  huff_t *left;
  huff_t *right;
};

huff_t *newItem_Huff(unsigned char byte);
huff_t *agroupItems_Huff(huff_t *left, huff_t *right);
//huff_t* MountHuffTree(heap_t *heap);
//void HashToHeap(hash_t * hash, heap_t *heap);
void showHuffman(huff_t* root);

#endif
