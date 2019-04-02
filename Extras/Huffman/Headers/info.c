/* ->
// Data Structure: Hash: infoBytes
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#include <stdio.h>
#include <stdlib.h>
#include "info.h"

info_t* new_Info() {
  info_t *bInfo = (info_t*) malloc(sizeof(info_t));
  bInfo->table = (infoBytes_t**) malloc(SIZE_INFO * sizeof(infoBytes_t));
  for(int i = 0; i < SIZE_INFO; i++) {
    bInfo->table[i] = NULL;
  }
  return bInfo;
}

void put_Info(info_t *bInfo, byte_t byte, long int frequency, int depth) {  
  if(isEmptyItem_Info(bInfo, byte)) {
    newItem_Info(bInfo, byte);
  }
  bInfo->table[byte]->totalBits = depth;
  bInfo->table[byte]->frequency = frequency;
}

bool isEmptyItem_Info(info_t *bInfo, byte_t byte) {
  return (bInfo->table[byte] == NULL);
}

void newItem_Info(info_t *bInfo, byte_t byte) {
  infoBytes_t *newItem = (infoBytes_t*) malloc(sizeof(infoBytes_t));
  bInfo->table[byte] = newItem;
  bInfo->table[byte]->totalBits = 0;
  bInfo->table[byte]->frequency = 0;
}

void show_Info(info_t *bInfo) {
  for(int i = 0; i < SIZE_INFO; i++) {
    if(bInfo->table[i] != NULL) {
      printf("%d", bInfo->table[i]->totalBits);
      printf(" -- Freq.: %ld\n", bInfo->table[i]->frequency);
      for(int j = 0; j < bInfo->table[i]->totalBits; j++) {
        printf("%d",bInfo->table[i]->bits[j]);
      }
      printf("\n");
    }
  }
}
