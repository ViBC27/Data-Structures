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
#include <time.h>
#include "Headers/BSTree.h"
#include "Headers/DLList.h"

void DLList_vs_BSTree(list_t *list, bTree_t *bTree, int n);
void add_List_bTree( list_t *list, bTree_t *bTree, int quant);

int main() {
  list_t *L1 = new_DLList();
  bTree_t *B1 = new_BSTree();

  int quant;
  printf("Digite o número de dados: ");
  scanf("%d", &quant);
  DLList_vs_BSTree(L1, B1, quant);
  return 0;
}

void DLList_vs_BSTree(list_t *list, bTree_t *bTree, int quant) {
  add_List_bTree(list, bTree, quant);
  FILE *LISTxABB, *NUMBERS;
  LISTxABB = fopen("LISTxABB.txt", "w");
  
  if(LISTxABB == NULL) {
    printf("Error, LISTxABB.txt was not created.\n");
    exit(1);
  }

  NUMBERS = fopen("NUMBERS.txt", "r");
  if(NUMBERS == NULL) {
    printf("Error, NUMBERS.txt was not opened.\n");
    exit(1);
  }

  int n; 
  while(fscanf(NUMBERS, "%d\n", &n) != EOF) {
    search_DLList(list, n);
    search_BSTree(bTree, n);
    fprintf(LISTxABB, "%d %d\n", list->t_search, bTree->t_search);
  }

  printf("The comparisons are in \"LISTxABB.txt\".\n");

  fclose(NUMBERS);
  fclose(LISTxABB);
}

void add_List_bTree(list_t *list, bTree_t *bTree, int quant){
  int n;
  srand(time(NULL));
  FILE *NUMBERS;
  NUMBERS = fopen("NUMBERS.txt", "w");
  
  if(NUMBERS == NULL) {
    printf("Error, NUMBERS.txt was not created.\n");
    exit(1);
  }
  
  for(int i = 0; i < quant; i++) {
    n = rand() % quant;
    if(search_BSTree(bTree, n) != 1) {
      addFront_DLList(list, n);
      add_BSTree(bTree, n);
      fprintf(NUMBERS, "%d\n", n);
    }
  }
  fclose(NUMBERS);
}
