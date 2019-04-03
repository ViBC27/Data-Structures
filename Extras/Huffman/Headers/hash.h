/* ->
// Data Structure: Hash
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#ifndef Hash_H
#define Hash_H
#define SIZE_HASH 256
#include "huff.h"

typedef unsigned char byte_t;

typedef struct hash hash_t;
struct hash {
  huff_t **huffTable;
};

hash_t* new_Hash();
void put_Hash(hash_t *hash, byte_t byte);

#endif