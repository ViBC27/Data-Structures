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
void add_list_bTree( list_t *list, bTree_t *bTree, int quant);

int main() {
  list_t *L1 = new_DLList();
  bTree_t *B1 = new_BSTree();

  int quant;

  printf("Digite a quantidade de dados a ser comparada: \n");
  scanf("%d", &quant);

  DLList_vs_BSTree(L1, B1, quant);

  printf("Os dados da comparação foram amarzenado no arquivo \"lista_vs_ABB.txt\"\n");

  return 0;
}

void DLList_vs_BSTree(list_t *list, bTree_t *bTree, int quant){

  add_list_bTree(list, bTree, quant);

  FILE *lista_vs_ABB;
  lista_vs_ABB = fopen("lista_vs_ABB.txt", "w");

  if (lista_vs_ABB == NULL){
    printf("Erro ao criar o arquivo lista_vs_ABB.txt\n");
    exit(0);
  }

  FILE *numbers;
  numbers = fopen("numbers.txt", "r");

  if (numbers == NULL){
    printf("Erro ao abrir o arquivo numbers.txt\n");
    exit(0);
  }

  srand((unsigned)time(NULL));
  
  for (int i = 0; i < quant; ++i){
    int numero_aleatorio;

    fscanf(numbers,"%d\n", &numero_aleatorio);
    
    search_DLList(list, numero_aleatorio);
    search_BSTree(bTree, numero_aleatorio);

    fprintf(lista_vs_ABB, "%d %d\n", list->t_search, bTree->t_search);
  }

  fclose(numbers);
  fclose(lista_vs_ABB);
}

void  add_list_bTree( list_t *list, bTree_t *bTree, int quant){

  FILE *numbers;
  numbers = fopen( "numbers.txt", "w");

  if (numbers == NULL){
    printf("Erro ao criar arquivo numbers.txt\n");
    exit(0);
  }

  srand((unsigned)time(NULL));

  int cont = 0, n;
  
  while(cont < quant){
    n = rand();
    if (search_BSTree( bTree, n) != 1){
        
        addFront_DLList(list, n);
        add_BSTree(bTree, n);
        fprintf(numbers, "%d\n", n);
        cont++;
    }
  }

  fclose(numbers);
}
