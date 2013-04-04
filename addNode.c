/*
 * Last modified: Fri, 22 Mar 2013 03:06:25 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void addNode(BinSTreeNode *rootNode, BinSTreeNode *node) {
  if (node == NULL) {
    return;
  }
  if (isLeft(rootNode, node)) {   /* node should be left of root */
    if (rootNode->left == NULL) { /* There is no left child */
      setNodeAsLeft(rootNode, node);
      printf("Add  %s  <- [%s]\n", node->str, rootNode->str);
    } else {  /* search for left edge */
      addNode(rootNode->left, node);
    }
  } else {    /* root <= node */
    if (rootNode->right == NULL) { /* There is no right child */
      setNodeAsRight(rootNode, node);
      printf("Add [%s] ->  %s\n", rootNode->str, node->str);
    } else {  /* search for left edge */
      addNode(rootNode->right, node);
    }
  }
  return;
}
