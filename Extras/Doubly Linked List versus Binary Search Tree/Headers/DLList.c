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
  list->t_search = 0;
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
    list->front->previous = newNode;
    newNode->next = list->front;
    list->front = newNode;
  }  
}

void addRear_DLList(list_t *list, int value){  
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->previous = NULL;
  newNode->next = NULL;
  list->size += 1;
  if (list->rear == NULL){
    list->front = newNode;
    list->rear = newNode; 
  }
  else{
    list->rear->next = newNode;
    newNode->previous = list->rear;
    list->rear = newNode;
  }
}

void showListFront_DLList(list_t *list) {
  if(isEmpty_DLList(list)) {
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

void showListRear_DLList(list_t *list) {
  if(isEmpty_DLList(list)) {
    printf("Doubly Linked List Underflow\n");
  }
  else {
    node_t *nAux = list->rear;
    while(nAux->previous != NULL) {
      printf("%d ", nAux->value);
      nAux = nAux->previous;
    }
    printf("%d\n", nAux->value);
  }
}

int getFront_DLList(list_t *list) {
 if(isEmpty_DLList(list)) {
    printf("Doubly Linked List Underflow\n");
    return INT_MIN;
  }
  else {
    return list->front->value;
  }
}

int getRear_DLList(list_t *list) {
 if(isEmpty_DLList(list)) {
    printf("Doubly Linked List Underflow\n");
    return INT_MIN;
  }
  else {
    return list->rear->value;
  }
}

int search_DLList(list_t *list, int value) {
  if(isEmpty_DLList(list)) {
    printf("Doubly Linked List Underflow\n");
    return INT_MIN;
  }
  else {
    node_t *nAux = list->front;
    list->t_search = 0;

    while(nAux != NULL) {
      list->t_search += 1;
      if(nAux->value == value) {
        return 1;
      }
      nAux = nAux->next;
    }
    printf("Element not found\n");
    printf("Attempts: %d\n", list->t_search);
    return 0;
  }
}

int isEmpty_DLList(list_t *list) {
  return (list->size == 0);
}
