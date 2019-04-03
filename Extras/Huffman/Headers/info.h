/* ->
// Data Structure: Hash: infoBytes
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
<- */

#ifndef InfoBytes_H
#define InfoBytes_H
#define SIZE_INFO 256
#include <stdbool.h>

typedef unsigned char byte_t;
typedef struct info info_t;
typedef struct infoBytes infoBytes_t;
struct info {
  infoBytes_t **table;
};
struct infoBytes {
  bool bits[16];
  int totalBits;
  long int frequency;
};

info_t* new_Info();
void put_Info(info_t *bInfo, byte_t byte, long int frequency, int depth);
void newItem_Info(info_t *bInfo, byte_t byte);
bool isEmptyItem_Info(info_t *bInfo, byte_t byte);
void show_Info(info_t *bInfo); // Temp.

#endif