/* ->
// Data Structure: Doubly Linked List
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#ifndef DLLIST_H
#define DLLIST_H

typedef struct node node_t;
typedef struct list list_t;
struct node {
  node_t *previous;
  node_t *next;
  int value;
};
struct list {
  node_t *front;
  node_t *rear;
  int size;
};

/* [00] -> Create a new structure. */
/* [01] -> Clean a structure. */
/* [02] -> Add the element at the top from the list. */
/* [03] -> Add the element at the bottom from the list. */
/* [04] -> Remove the first occurrence of an element from the list. */
/* [05] -> Show list from start until end. */
/* [06] -> Show list from end until start. */
/* [07] -> Get the first element from the list. */
/* [08] -> Get the last element from the list. */
/* [09] -> Search a element from the list. */
/* [10] -> Check if the list is empty. */

/* [00] */ list_t* new_DLList();
/* [01] */ void erase_DLList(list_t *list);
/* [02] */ void addFront_DLList(list_t *list, int value);
/* [03] */ void addRear_DLList(list_t *list, int value);
/* [04] */ void remove_DLList(list_t *list, int value);
/* [05] */ void showListFront_DLList(list_t *list);
/* [06] */ void showListRear_DLList(list_t *list);
/* [07] */ int getFront_DLList(list_t *list);
/* [08] */ int getRear_DLList(list_t *list);
/* [09] */ int search_DLList(list_t *list, int value);
/* [10] */ int isEmpty_DLList(list_t *list);

#endif