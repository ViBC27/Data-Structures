/* ->
// Data Structure: Doubly Linked List and Binary Search Tree
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#include <stdio.h>
#include <stdlib.h>
#include "/Headers/BSTree.h"
#include "/Headers/DLList.h"

int main() {
  list_t *L1 = new_DLList();
  addFront_DLList(L1, 10);
  addFront_DLList(L1, 20);
  addFront_DLList(L1, 30);
  addFront_DLList(L1, 40);
  addFront_DLList(L1, 50);
  printf("%d\n", getFront_DLList(L1));
  printf("%d\n", getRear_DLList(L1));
  showListFront_DLList(L1);
  showListRear_DLList(L1);
  printf("%d\n", search_DLList(L1, 40));
  showListFront_DLList(L1);
  showListRear_DLList(L1);
  printf("%d\n", search_DLList(L1, 60));
  
  bTree_t *B1 = new_BSTree();
  add_BSTree(B1, 10);
  add_BSTree(B1, 8);
  add_BSTree(B1, 12);
  add_BSTree(B1, 9);
  add_BSTree(B1, 7);
  add_BSTree(B1, 11);
  add_BSTree(B1, 13);
  showPreOrder_BSTree(B1);
  printf("Existe: %d\n", search_BSTree(B1, 16));
  printf("Ten: %d\n", B1->t_search);

  return 0;
}