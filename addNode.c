/*
 * Last modified: Sun, 07 Apr 2013 19:07:43 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void addNode(BinSTreeNode *rootNode, BinSTreeNode *node) {
  if (node == NULL) {
    return;
  }
  if (rootNode->str == NULL) { /* rootNode is empty! */
    rootNode->str = (char*)malloc(sizeof(char)*(mystrlen(node->str)+1));
    mystrcpy(rootNode->str, node->str);
    setNodeAsLeft(rootNode, node->left);
    setNodeAsRight(rootNode, node->right);
    node->left = NULL;
    node->right = NULL;
    deleteNode(node);
  } else {  /* Normal addNode() */
    if (isLeft(rootNode, node)) {   /* node should be left of root */
      if (rootNode->left == NULL) { /* There is no left child */
        setNodeAsLeft(rootNode, node);
        if(DEBUG) printf("Add  %s  <- [%s%s%s]\n", node->str, CYAN, rootNode->str, DEFAULT);
      } else {  /* search for left edge */
        addNode(rootNode->left, node);
      }
    } else {    /* root <= node */
      if (rootNode->right == NULL) { /* There is no right child */
        setNodeAsRight(rootNode, node);
        if(DEBUG) printf("Add [%s%s%s] ->  %s\n", CYAN, rootNode->str, DEFAULT, node->str);
      } else {  /* search for left edge */
        addNode(rootNode->right, node);
      }
    }
  }
  return;
}
