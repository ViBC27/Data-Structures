/* ->
// Data Structure: Shared
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#include <stdio.h>
#include <stdlib.h>
#include "shared.h"

FILE* OpenInputFile(char *inputFile) {
  FILE *inFile= fopen(inputFile, "rb");
  if(inFile == NULL) {
    printf("Not open file.\n");
    exit(1);
  }
  return inFile;
}