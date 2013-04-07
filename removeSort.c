/*
 * Last modified: Sun, 07 Apr 2013 17:23:04 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void removeSort(BinSTreeNode* node) {
  BinSTreeNode *child = NULL, *parent = NULL, *left = NULL, *right = NULL;
  BinSTreeNode *min = NULL, *minRight = NULL;
  parent = node->parent;
  left   = node->left;
  right  = node->right;
  if (parent == NULL) {  /* node is root node */
    printf("Found [%s][%p][%p] (root node)\n", node->str, node->left, node->right);
    parent = node;       /* set parent as "node" for addNode() */
    free(node->str);
    node->str = NULL;    /* just set nodeName as NULL. addNode() will take care of it. */
  } else {
    printf("Found [%s][%p][%p] <- [%s]\n", node->str, node->left, node->right, node->parent->str);
    deleteNode(node);
  }
  if (left == NULL && right == NULL) {
  } else if (left  == NULL) {  /* We only have right node */
    child = right;
  } else if (right == NULL) {  /* We only have left  node */
    child = left;
  } else {  /* We have both left and right nodes */
    /* Replace this node with Min node under right node */
    min = getMinNode(right);
    minRight = min->right;
    /* printf("  Found Min [%s]\n", min->str); */
    /* printf("  Parent    [%s]\n", parent->str); */
    unlinkParent(min);
    setNodeAsLeft(min, left); /* Min only have right node */
    if (min != right) {
      addNode(min, right);
    }
    child = min;
  }
  /* No need to check NULL for node (addNode() takes care of it) */
  addNode(parent, child);
}

