#include <stdio.h>
#include <stdlib.h>
#include "descompress.h"
#include "shared.h"

typedef unsigned char byte_t;

void descompress(char *inputFile, char *outputFile) {
  FILE *inFile =  OpenInputFile(inputFile);
  FILE *newFile = fopen(outputFile, "wb");
  huff_t *root; int sTree, sTrash;
  DismountHeader(inFile, &sTree, &sTrash);
  MountHuffTree_Des(inFile, &root, sTree, 0);
  MountFile_Des(root, inFile, newFile, sTrash);
  fclose(inFile);
  fclose(newFile);
}

void DismountHeader(FILE *inputFile, int *sizeTree, int *sizeTrash) {
  byte_t byte;
  fscanf(inputFile, "%c", &byte);
  *sizeTrash = byte >> 5;
  *sizeTree = (byte << 3) >> 3;
  fscanf(inputFile, "%c", &byte);
  *sizeTree = (*sizeTree << 8) | byte;
}

void MountHuffTree_Des(FILE *inputFile, huff_t **tree, int sizeTree, int i) {
  if(i == sizeTree) return;
  byte_t byte;
  fscanf(inputFile, "%c", &byte);
  if(byte == '*') {
    (*tree) = newItem_Huff(byte);
    MountHuffTree_Des(inputFile, &(*tree)->left, sizeTree, i++); 
    MountHuffTree_Des(inputFile, &(*tree)->right, sizeTree, i++);
  }
  else if(byte == 92) {
    fscanf(inputFile, "%c", &byte);
    (*tree) = newItem_Huff(byte);
  }
  else {
    (*tree) = newItem_Huff(byte);
  }
}

void MountFile_Des(huff_t *tree, FILE *inputFile, FILE *outFile, int sizeTrash) {
  
  // Bit a bit de byte em byte;
  // Setado: Right, Não setado: Left;

  byte_t bytesPrint[10], byte; 
  int totalBytes = 0, i, j;
  huff_t *current = tree, *save;

  while(fscanf(inputFile, "%c", &byte) != EOF) {  
    save = current; // Não cheguei em nenhuma folha. Devo continuar de onde parei.
    for(j = 0; j < totalBytes; j++) {
      fprintf(outFile, "%c", bytesPrint[j]);
    }
    for(i = 7, totalBytes = 0; i >= 0; i--) {
      if(is_bit_i_set(byte, i)) {
        current = current->right;
      }
      else {
        current = current->left;
      }
      if(isLeaf_Huff(current)) {
        bytesPrint[totalBytes++] = current->byte;
        current = tree;
      }
    }
  }

  current = save; // Último byte
  for(i = 7, totalBytes = 0; i >= sizeTrash; i--) {
    if(is_bit_i_set(byte, i)) {
      current = current->right;
    }
    else {
      current = current->left;
    }
    if(isLeaf_Huff(current)) {
      bytesPrint[totalBytes ++] = current->byte;
      current = tree;
    }
  }

  for(j = 0; j < totalBytes; j++) {
    fprintf(outFile, "%c", bytesPrint[j]);
  }
}

bool is_bit_i_set(unsigned int byte, int i) {
  unsigned int mask = 1 << i;
  return(mask & byte);
}