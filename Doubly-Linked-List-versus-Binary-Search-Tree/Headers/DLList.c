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
#include <limits.h>
#include "DLList.h"

list_t* new_DLList() {
  list_t *list = (list_t*) malloc(sizeof(list_t));
  list->front = list->rear = NULL;
  list->size = 0;
  return list;
}

void addFront_DLList(list_t *list, int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->previous = NULL;
  newNode->next = NULL;
  list->size += 1;
  if(list->front == NULL) {
    list->front = list->rear = newNode;
  }
  else {
    newNode->next = list->front;
    list->front = newNode;
  }  
}

void showListFront_DLList(list_t *list) {
  if(list->size == 0) {
    printf("Doubly Linked List Underflow\n");
  }
  else {
    node_t *nAux = list->front;
    while(nAux->next != NULL) {
      printf("%d ", nAux->value);
      nAux = nAux->next;
    }
    printf("%d\n", nAux->value);
  }
}

int getFront_DLList(list_t *list) {
 if(list->size == 0) {
    printf("Doubly Linked List Underflow\n");
    return INT_MIN;
  }
  else {
    return list->front->value;
  }
}

int getRear_DLList(list_t *list) {
 if(list->size == 0) {
    printf("Doubly Linked List Underflow\n");
    return INT_MIN;
  }
  else {
    return list->rear->value;
  }
}