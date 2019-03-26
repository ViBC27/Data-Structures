#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "huff.h"
#define MAX_SIZE 256

hash_t* new_Hash() {
  hash_t *newHash = (hash_t*) malloc(sizeof(hash_t));
  newHash->huffTable = (huff_t**) malloc(MAX_SIZE * sizeof(huff_t));
  int i;
  for(i = 0; i < MAX_SIZE; i++) {
    newHash->huffTable[i] = NULL;
  }
  return newHash;
}

void erase_Hash(hash_t *hash) {
  int i;
  for(i = 0; i < MAX_SIZE; i++) {
    if(hash->huffTable[i] != NULL) {
      hash->huffTable[i] = NULL;
    }
  }
}

void put_Hash(hash_t *hash, unsigned char byte) {
  if(hash->huffTable[byte] == NULL) {
    hash->huffTable[byte] = newNode_Huff(byte);
  }
  else {
    hash->huffTable[byte]->frequency += 1;
  }
}

void show_Hash(hash_t *hash) {
  int i;
  for(i = 0; i < MAX_SIZE; i++) {
    if(hash->huffTable[i] != NULL) {
      printf("%c", hash->huffTable[i]->byte);
    }
  }
}
