/* ->
// Data Structure: Hash
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
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

void erase_Hash(hash_t *hash) {
  int i;
  for(i = 0; i < SIZE_HASH; i++) {
    if(hash->huffTable[i] != NULL) {
      hash->huffTable[i] = NULL;
    }
  }
}

void put_Hash(hash_t *hash, unsigned char byte) {
  if(hash->huffTable[byte] == NULL) {
    hash->huffTable[byte] = newItem_Huff(byte);
  }
  else {
    hash->huffTable[byte]->frequency += 1;
  }
}

void show_Hash(hash_t *hash) {
  int i;
  for(i = 0; i < SIZE_HASH; i++) {
    if(hash->huffTable[i] != NULL) {
      printf("%u", hash->huffTable[i]->byte);
    }
  }
}
