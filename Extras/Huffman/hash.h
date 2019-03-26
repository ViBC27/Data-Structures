/* ->
// Data Structure: Hash
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#ifndef Hash_H
#define Hash_H

typedef struct hash hash_t;
struct hash {
  huff_t **huffTable;
};

hash_t* new_Hash();
void erase_Hash(hash_t *hash);
void put_Hash(hash_t *hash, unsigned char byte);
void show_Hash(hash_t *hash);

#endif
