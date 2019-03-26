// Huff
huff_t *newNode_Huff(unsigned char byte);
huff_t *agroupNodes_Huff(huff_t *left, huff_t *right);

huff_t *newNode_Huff(unsigned char byte) {
  huff_t *newNode = (huff_t*) malloc(sizeof(huff_t));
  newNode->byte = byte;
  newNode->frequency = 1;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

huff_t *agroupNodes_Huff(huff_t *left, huff_t *right) {
  huff_t *newNode = (huff_t*) malloc(sizeof(huff_t));
  newNode->frequency = left->frequency + right->frequency;
  newNode->left = left;
  newNode->right = right;
  newNode->byte = '*';
  return newNode;
}