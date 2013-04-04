/*
 * Last modified: Wed, 20 Mar 2013 01:27:49 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void setNodeAsLeft(BinSTreeNode *node, BinSTreeNode *left) {
  if (node == NULL || left == NULL) return;
  node->left = left;
  left->parent = node;
}

void setNodeAsRight(BinSTreeNode *node, BinSTreeNode *right) {
  if (node == NULL || right == NULL) return;
  node->right = right;
  right->parent = node;
}

void setNodeAsOrphan(BinSTreeNode *node) {
  if (node == NULL) return;
  node->left = NULL;
  node->right = NULL;
  if (isLeftChild(node->parent, node)) {
    node->parent->left = NULL;
  } else if (isRightChild(node->parent, node)) {
    node->parent->right = NULL;
  }
}
