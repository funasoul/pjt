/*
 * Last modified: Wed, 20 Mar 2013 20:51:08 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void deleteNode(BinSTreeNode* node) {
  if (isLeftChild(node->parent, node)) {
    node->parent->left = NULL;
  } else if (isRightChild(node->parent, node)) {
    node->parent->right = NULL;
  }
  free(node->str);
  node->str = NULL;
  free(node);
}
