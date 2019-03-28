#include <stdio.h>
#include <stdlib.h>
#define typeof(var) _Generic((var),\
node2_t *: 2,\
node3_t *: 3,\
node4_t *: 4,\
default: 0)

typedef struct tree234 tree234_t;
typedef struct node2 node2_t;
typedef struct node3 node3_t;
typedef struct node4 node4_t;
struct tree234 {
  void *root;
};
struct node2 {
  int data;
  void *left;
  void *right;
};
struct node3 {
  int data1;
  int data2;
  void *left;
  void *middle;
  void *right;
};
struct node4 {
  int data1;
  int data2;
  int data3;
  void *left;
  void *middle1;
  void *middle2;
  void *right;
};

tree234_t* new_Tree234();
void add_Tree234(tree234_t *tree, int data);
void show_Tree234(tree234_t *tree);
node2_t* new2Node(int data, void *left, void *right);
node3_t* new3Node(int data1, int data2, void *left, void *middle, void *right);
node4_t* new4Node(int data1, int data2, int data3, void *left, void *middle1, void *middle2, void *right);
void addAux_Tree234(void *root, int data);
void showAux_Tree234(void *root);

int main() {
  tree234_t *tree = new_Tree234();
  add_Tree234(tree, 10);
  tree->root = new2Node(9, new3Node(2,3, NULL, NULL, NULL), new4Node(10, 11, 12, NULL, NULL, NULL, NULL));
  show_Tree234(tree);
  return 0;
}

tree234_t* new_Tree234() {
  tree234_t *newTree234 = (tree234_t*) malloc(sizeof(tree234_t));
  newTree234->root = NULL;
  return newTree234;
}

// Add: It's not complete. 
void add_Tree234(tree234_t *tree, int data) {
  addAux_Tree234(tree->root, data);
}

void addAux_Tree234(void *root, int data) {
  if(typeof(root) == 0) {}
}

// New Node
node2_t* new2Node(int data, void *left, void *right) {
  node2_t *newNode = (node2_t*) malloc(sizeof(node2_t));
  newNode->data = data;
  newNode->left = left;
  newNode->right = right;
  return newNode;
}

node3_t* new3Node(int data1, int data2, void *left, void *middle, void *right) {
  node3_t *newNode = (node3_t*) malloc(sizeof(node3_t));
  newNode->data1 = data1;
  newNode->data2 = data2;
  newNode->left = left;
  newNode->middle = middle;
  newNode->right = right;
  return newNode;
}

node4_t* new4Node(int data1, int data2, int data3, void *left, void *middle1, void *middle2, void *right) {
  node4_t *newNode = (node4_t*) malloc(sizeof(node4_t));
  newNode->data1 = data1;
  newNode->data2 = data2;
  newNode->data3 = data3;
  newNode->left = left;
  newNode->middle1 = middle1;
  newNode->middle2 = middle2;
  newNode->right = right;
  return newNode;
}

// Show Tree
void show_Tree234(tree234_t *tree) {
  showAux_Tree234(tree->root);
}

void showAux_Tree234(void *root) {
  if(root == NULL) return;
  if(typeof(root) == 2) {
    node2_t *nAux = (node2_t*) root;
    printf("%d\n", (int)(nAux->data));
    showAux_Tree234(nAux->left);
    showAux_Tree234(nAux->right);
  }
}
/*
void showAux_Tree234(void *root) {
  if(typeof(root) == 0) return;
  if(typeof(root) == 2) {
    node2_t *nAux = (node2_t*) root;
    printf("%d\n", (int)(nAux->data));
    showAux_Tree234(nAux->left);
    showAux_Tree234(nAux->right);
  }
  if(typeof(root) == 3) {
    node3_t *nAux = (node3_t*) root;
    printf("%d\n", (int)(nAux->data1));
    printf("%d\n", (int)(nAux->data2));
    showAux_Tree234(nAux->left);
    showAux_Tree234(nAux->middle);
    showAux_Tree234(nAux->right);
  }
  if(typeof(root) == 4) {
    node4_t *nAux = (node4_t*) root;
    printf("%d\n", (int)(nAux->data1));
    printf("%d\n", (int)(nAux->data2));
    printf("%d\n", (int)(nAux->data3));
    showAux_Tree234(nAux->left);
    showAux_Tree234(nAux->middle1);
    showAux_Tree234(nAux->middle2);
    showAux_Tree234(nAux->right);
  }
}
*/
