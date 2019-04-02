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

void descompress(char *inputFile, char *outputFile);
void getHeader(FILE *inputFile, int *sizeTree, int *sizeTrash);
void MountHuffTree_Des(FILE *inputFile, huff_t **tree, int sizeTree, int i);
void MountFile_Des(huff_t *tree, FILE *inputFile, FILE *newFile, int sizeTrash);
bool isBitiSet(unsigned int byte, int i);


#endif