/* ->
// Data Structure: Binary Search Tree
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BSTree.h"

bTree_t* new_BSTree() {
  bTree_t *newBSTree = (bTree_t*) malloc(sizeof(bTree_t));
  newBSTree->root = NULL;
  newBSTree->t_search = 0;
  return newBSTree;
}

void add_BSTree(bTree_t *bTree, int value) {
  bTree->root = addAux_BSTree(bTree->root, value);
}

void showInOrder_BSTree(bTree_t *bTree) {
  showInOrderAux_BSTree(bTree->root);
  printf("\n");
}

void showPreOrder_BSTree(bTree_t *bTree) {
  showPreOrderAux_BSTree(bTree->root);
  printf("\n");
}

void showPostOrder_BSTree(bTree_t *bTree) {
  showPostOrderAux_BSTree(bTree->root);
  printf("\n");
}

int search_BSTree(bTree_t *bTree, int value) {
  if(isEmpty_BSTree(bTree)) {
    printf("Element not found\n");
    return INT_MIN;
  }
  else {
    int found = 0;
    bTree->t_search = 0;
    nodeBst_t *btAux = searchAux_BSTree(bTree->root, value, &bTree->t_search, &found);
    if(!found) {
      printf("Element not found\n");
      return 0;
    }
    else {
      return 1;
    }
  }
}

int isEmpty_BSTree(bTree_t *bTree) {
  return isEmptyAux_BSTree(bTree->root);
}

// Help functions. 
nodeBst_t* newNode_BSTree(int value, nodeBst_t *L, nodeBst_t *R) {
  nodeBst_t *newNodeBSTree = (nodeBst_t*) malloc(sizeof(nodeBst_t));
  newNodeBSTree->value = value;
  newNodeBSTree->left = L;
  newNodeBSTree->right = R;
  return newNodeBSTree;
}

nodeBst_t* addAux_BSTree(nodeBst_t *bt, int value) {
  if(bt == NULL) {
    bt = newNode_BSTree(value, NULL, NULL);
  }
  else if(bt->value > value) {
    bt->left = addAux_BSTree(bt->left, value);
  } 
  else {
    bt->right = addAux_BSTree(bt->right, value);
  }
  return bt;
}

void showInOrderAux_BSTree(nodeBst_t *bt) {
  if(!isEmptyAux_BSTree(bt)) {
    showInOrderAux_BSTree(bt->left);
    printf("%d ", bt->value);
    showInOrderAux_BSTree(bt->right);
  }
}

void showPreOrderAux_BSTree(nodeBst_t *bt) {
  if(!isEmptyAux_BSTree(bt)) {
    printf("(%d", bt->value);
    showPreOrderAux_BSTree(bt->left);
    showPreOrderAux_BSTree(bt->right);
    printf(")");
  }
  else {
    printf("()");
  }
}

void showPostOrderAux_BSTree(nodeBst_t *bt) {
  if(!isEmptyAux_BSTree(bt)) {
    showPostOrderAux_BSTree(bt->left);
    showPostOrderAux_BSTree(bt->right);
    printf("%d ", bt->value);
  }
}

nodeBst_t* searchAux_BSTree(nodeBst_t *bt, int value, int *t_search, int *found) {
  *t_search += 1;
  if(bt == NULL) {
    *found = 0;
    return bt;
  }
  else if(bt->value == value) {
    *found = 1;
    return bt;
  }
  else if(bt->value > value) {
    return searchAux_BSTree(bt->left, value, t_search, found);
  } 
  else {
    return searchAux_BSTree(bt->right, value, t_search, found);
  }
}

int isEmptyAux_BSTree(nodeBst_t *bt) {
  return (bt == NULL);
}