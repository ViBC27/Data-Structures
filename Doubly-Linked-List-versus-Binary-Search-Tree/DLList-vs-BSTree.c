/* ->
// Data Structure: Doubly Linked List
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#include <stdio.h>
#include <stdlib.h>
#include "/Headers/DLList.h"

// Global variable.
int LAST_SEARCH = 0;

int main() {
  list_t *L1 = new_DLList();
  addFront_DLList(L1, 10);
  addFront_DLList(L1, 20);
  printf("%d\n", getFront_DLList(L1));
  printf("%d\n", getRear_DLList(L1));
  showListFront_DLList(L1);
  return 0;
}