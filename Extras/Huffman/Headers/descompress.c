#include <stdio.h>
#include <stdlib.h>
#include "descompress.h"
#include "shared.h"

typedef unsigned char byte_t;

void descompress(char *inputFile, char *outputFile) {
  FILE *inFile =  OpenInputFile(inputFile);
  FILE *newFile = fopen(outputFile, "wb");
  
  huff_t *root; 
  int sTree, sTrash;
  getHeader(inFile, &sTree, &sTrash);
  MountHuffTree_Des(inFile, &root, sTree, 0);
  
  MountFile_Des(root, inFile, newFile, sTrash);
  fclose(inFile);
  fclose(newFile);
}

void getHeader(FILE *inputFile, int *sizeTree, int *sizeTrash) {
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
  else {
    if(byte == 92) {
      fscanf(inputFile, "%c", &byte);
      (*tree) = newItem_Huff(byte);
    }
    else {
      (*tree) = newItem_Huff(byte);
    }
  }
}

void MountFile_Des(huff_t *tree, FILE *inputFile, FILE *newFile, int sizeTrash) {
  byte_t stringToPrint[10], byte; 
  int done = 0, i, j;
  huff_t *curr = tree, *save;
  while(fscanf(inputFile, "%c", &byte) != EOF) {  
    save = curr;
    for(j = 0; j < done; j++) {
      fprintf(newFile, "%c", stringToPrint[j]);
    }

    for(i = 7, done = 0; i >= 0; i --) {
      if (isBitiSet(byte, i)) {
        curr = curr->right;
      }
      else {
        curr = curr->left;
      }
      if(isLeaf_Huff(curr)) {
        stringToPrint[done ++] = curr->byte;
        curr = tree;
      }
    }
  }

  curr = save;
  for(i = 7, done = 0; i >= sizeTrash; i --) {
    if(isBitiSet(byte, i)) {
      curr = curr->right;
    }
    else {
      curr = curr->left;
    }
    if(isLeaf_Huff(curr)) {
      stringToPrint[done ++] = curr->byte;
      curr = tree;
    }
  }

  for (j = 0; j < done; j ++) {
    fprintf(newFile, "%c", stringToPrint[j]);
  }
}

bool isBitiSet(unsigned int byte, int i) {
  unsigned int mask = 1 << i;
  return(mask & byte);
}