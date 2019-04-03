#include <stdio.h>
#include <stdlib.h>
#include "descompress.h"
#include "shared.h"

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

void MountFile_Des(huff_t *tree, FILE *inFile, FILE *outFile, int sizeTrash) {
  // Bit a bit de byte em byte;
  huff_t *nAux, *current = tree;
  byte_t printBytes[10], byte;
  int maxBytes = 0, i;

  while(fscanf(inFile, "%c", &byte) != EOF) {  
    
    // Não cheguei em nenhuma folha.
    // Devo continuar de onde parei.
    nAux = current;

    // Printa os bytes no arquivo de saída.
    PrintInFile(outFile, printBytes, maxBytes);

    // Percorro a árvore de huffman.
    // Setado: Right, Não setado: Left;
    for(i = 7, maxBytes = 0; i >= 0; i--) {
      if(is_bit_i_set(byte, i)) {
        current = current->right;
      }
      else {
        current = current->left;
      }
      if(isLeaf_Huff(current)) {
        printBytes[maxBytes++] = current->byte;
        current = tree;
      }
    }
  }

  current = nAux; // Último byte
  for(i = 7, maxBytes = 0; i >= sizeTrash; i--) {
    if(is_bit_i_set(byte, i)) {
      current = current->right;
    }
    else {
      current = current->left;
    }
    if(isLeaf_Huff(current)) {
      printBytes[maxBytes++] = current->byte;
      current = tree;
    }
  }

  // Printa os últimos bytes no arquivo de saída.
  PrintInFile(outFile, printBytes, maxBytes);
}

void PrintInFile(FILE *outFile, byte_t *printBytes, int maxBytes) {
  for(int i = 0; i < maxBytes; i++) {
    fprintf(outFile, "%c", printBytes[i]);
  }
}

bool is_bit_i_set(unsigned int byte, int i) {
  unsigned int mask = 1 << i;
  return(mask & byte);
}