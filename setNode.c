/*
 * Last modified: Fri, 05 Apr 2013 08:00:21 +0900
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

void unlinkParent(BinSTreeNode *node) {
  if (node == NULL) return;
  if (isLeftChild(node->parent, node)) {
    node->parent->left = NULL;
  } else if (isRightChild(node->parent, node)) {
    node->parent->right = NULL;
  }
  node->parent = NULL;
}

void setNodeAsOrphan(BinSTreeNode *node) {
  if (node == NULL) return;
  unlinkParent(node);
  node->left = NULL;
  node->right = NULL;
}
