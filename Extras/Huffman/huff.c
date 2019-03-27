/* ->
// Data Structure: Huffman
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#include <stdio.h>
#include <stdlib.h>
#include <huff.h>

huff_t *newItem_Huff(unsigned char byte) {
  huff_t *newNode = (huff_t*) malloc(sizeof(huff_t));
  newNode->byte = byte;
  newNode->frequency = 1;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

huff_t *agroupItems_Huff(huff_t *left, huff_t *right) {
  huff_t *newNode = (huff_t*) malloc(sizeof(huff_t));
  newNode->frequency = left->frequency + right->frequency;
  newNode->left = left;
  newNode->right = right;
  newNode->byte = '*';
  return newNode;
}

void showHuffman(huff_t* root) {
  if(root != NULL) {
    printf("(%u", root->byte);
    showHuffman(root->left);
    showHuffman(root->right);
    printf(")");
  }
  else {
    printf("()");
  }
}
