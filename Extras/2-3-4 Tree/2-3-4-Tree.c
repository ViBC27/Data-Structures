#include <stdio.h>
#include <stdlib.h>

typedef struct tree234 tree234;

struct tree234{
	int item[3];
	int type;
	tree234 *parent;
	tree234 *childers[4];
};

tree234* newNode(int item, tree234 *parent, tree234 *left, tree234 *right);
int searchTree234(tree234 *tree);

int main(void) {

	tree234 *tree = (tree234*) malloc(sizeof(tree234));
	tree = newNode(3, NULL, NULL, NULL);

	return 0;
}

tree234* newNode(int item, tree234 *parent, tree234 *left, tree234 *right){
	
	tree234 *newNode = (tree234*) malloc(sizeof(tree234));

	newNode->type = 2;
	newNode->item[0] = item;
	newNode->parent = parent;
	newNode->childers[0] = left;
	newNode->childers[1] = right;

	return newNode;
}

int searchTree234(tree234 *tree, int item){

  if(tree == NULL){
    return 0;
  }
//2-nó
  else if(tree->type == 2){
    if(tree->item[0] == item){
      return 1;
    }
    else if(tree->item[0] > item){
      return searchTree234(tree->childers[0], item);
    }
    else{
      return searchTree234(tree->childers[1], item);
    }
  }
//3-nó
  else if(tree->type == 3){
    if(tree->item[0] == item || tree->item[1] == item){
      return 1;
    }
    else if(tree->item[0] > item){
      return searchTree234(tree->childers[0], item);
    }
    else if(tree->item[1] > item){
      return searchTree234(tree->childers[1], item);
    }
    else{
      return searchTree234(tree->childers[2], item);
    }
  }
//4-nó
  else{
    if(tree->item[0] == item || tree->item[1] == item || tree->item[2] == item){
      return 1;
    }
    else if(tree->item[0] > item){
      return searchTree234(tree->childers[0], item);
    }
    else if(tree->item[1] > item){
      return searchTree234(tree->childers[1], item);
    }
    else if(tree->item[2] > item){
      return searchTree234(tree->childers[2], item);
    }
    else{
      return searchTree234(tree->childers[3], item);
    }
  }

}