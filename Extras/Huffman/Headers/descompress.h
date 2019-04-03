/* ->
// Data Structure: Huffman
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#ifndef Descompress_H
#define Descompress_H
#include <stdio.h>
#include <stdbool.h>
#include "huff.h"

typedef unsigned char byte_t;

void descompress(char *inputFile, char *outputFile);
void DismountHeader(FILE *inputFile, int *sizeTree, int *sizeTrash);
void MountHuffTree_Des(FILE *inputFile, huff_t **tree, int sizeTree, int i);
void MountFile_Des(huff_t *tree, FILE *inFile, FILE *outFile, int sizeTrash);
void PrintInFile(FILE *outFile, byte_t *printBytes, int maxBytes);
bool is_bit_i_set(unsigned int byte, int i);

#endif