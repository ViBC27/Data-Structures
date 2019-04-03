/* ->
// Data Structure: Hash
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


hash_t* new_Hash() {
  hash_t *newHash = (hash_t*) malloc(sizeof(hash_t));
  newHash->huffTable = (huff_t**) malloc(SIZE_HASH * sizeof(huff_t));
  int i;
  for(i = 0; i < SIZE_HASH; i++) {
    newHash->huffTable[i] = NULL;
  }
  return newHash;
}

void put_Hash(hash_t *hash, unsigned char byte) {
  if(hash->huffTable[byte] == NULL) {
    hash->huffTable[byte] = newItem_Huff(byte);
  }
  else {
    hash->huffTable[byte]->frequency += 1;
  }
}