/* ->
// Data Structure: Huffman
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#ifndef Huff_H
#define Huff_H
#include <stdio.h>
#include <stdbool.h>

typedef struct huff huff_t;
struct huff {
  unsigned char byte;
  long int frequency;
  huff_t *left;
  huff_t *right;
};

huff_t *newItem_Huff(unsigned char byte);
huff_t *agroupItems_Huff(huff_t *left, huff_t *right);
bool isEmpty_Huff(huff_t *tree);
bool isLeaf_Huff(huff_t *tree);
int size_Huff(huff_t *tree);
void showHuffman(huff_t* root);
void PrintTree_Huff(huff_t *tree, FILE *newFile);

#endif