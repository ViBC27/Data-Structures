/* ->
// Data Structure: Huffman
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#include <stdio.h>
#include <stdlib.h>
#include "huff.h"

huff_t *newItem_Huff(byte_t byte) {
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

bool isEmpty_Huff(huff_t *tree) {
  return (tree == NULL);
}

bool isLeaf_Huff(huff_t *tree) {
  return (tree->left == NULL && tree->right == NULL);
}

int size_Huff(huff_t *tree) {
  int size = 0;
  if(!isEmpty_Huff(tree)) {
    if(isLeaf_Huff(tree) && (tree->byte == '*' || tree->byte == 92))
      size = 1;
    size += 1 + size_Huff(tree->left);
    size += size_Huff(tree->right);
  }
  return(size);
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

void PrintTree_Huff(huff_t *tree, FILE *newFile) {
  if(!isEmpty_Huff(tree)) {
    if(isLeaf_Huff(tree) && (tree->byte == '*' || tree->byte == 92)) {
      fprintf(newFile, "%c", 92);
    }
    fprintf(newFile, "%c", tree->byte);
    PrintTree_Huff(tree->left, newFile);
    PrintTree_Huff(tree->right, newFile);
  }
}