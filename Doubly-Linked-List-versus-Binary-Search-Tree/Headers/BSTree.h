/* ->
// Data Structure: Binary Search Tree
// Authors: 
-> Vitor Barcelos de Cerqueira
-> Ramon Basto Callado
-> Daniel melo de lima
-> Erick Pernambuco
<- */

#ifndef BSTree_H
#define BSTree_H

typedef struct nodeBst nodeBst_t;
typedef struct bTree bTree_t;
struct nodeBst {
  nodeBst_t* left;
  nodeBst_t* right;
  int value;
};
struct bTree {
  nodeBst_t *root;
  int t_search;
};

/* [00] -> Create a new structure. */
/* [01] -> Clean a structure. */
/* [02] -> Add element to the tree. */
/* [03] -> Remove the first occurrence of an element from the tree. * /
/* [04] -> Show tree in order. */
/* [05] -> Show tree in pre order. */
/* [06] -> Show tree in post order. */
/* [07] -> Search a element from the tree. */
/* [08] -> Check if the tree is empty. */

/* [00] */ bTree_t* new_BSTree();
/* [01] */ void erase_BSTree();
/* [02] */ void add_BSTree(bTree_t *bTree, int value);
/* [03] */ void remove_BSTree(bTree_t *bTree, int value);
/* [04] */ void showInOrder_BSTree(bTree_t *bTree);
/* [05] */ void showPreOrder_BSTree(bTree_t *bTree);
/* [06] */ void showPostOrder_BSTree(bTree_t *bTree);
/* [07] */ int search_BSTree(bTree_t *bTree, int value);
/* [08] */ int isEmpty_BSTree(bTree_t *bTree);

nodeBst_t* newNode_BSTree(int value, nodeBst_t *L, nodeBst_t *R);
nodeBst_t* addAux_BSTree(nodeBst_t *bt, int value);
void showInOrderAux_BSTree(nodeBst_t *bt);
void showPreOrderAux_BSTree(nodeBst_t *bt);
void showPostOrderAux_BSTree(nodeBst_t *bt);
nodeBst_t* searchAux_BSTree(nodeBst_t *bt, int value, int *t_search, int *found);
int isEmptyAux_BSTree(nodeBst_t *bt);

#endif