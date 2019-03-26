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

huff_t *newNode_Huff(unsigned char byte);
huff_t *agroupNodes_Huff(huff_t *left, huff_t *right);

#endif
