#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 256

typedef struct hash hash_t;
typedef struct huff huff_t;

struct huff {
  unsigned char byte;
  long int frequency;
  huff_t *left;
  huff_t *right;
};

struct hash {
  huff_t **huffTable;
};

// Hash
hash_t* new_Hash();
void erase_Hash(hash_t *hash);
void put_Hash(hash_t *hash, unsigned char byte);
void show_Hash(hash_t *hash);

int main() {
  hash_t *H1 = new_Hash();
  put_Hash(H1, 'a');
  put_Hash(H1, 'b');
  put_Hash(H1, 'c');
  show_Hash(H1);
  erase_Hash(H1);
  free(H1);
  return 0;
}

// Hash
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
