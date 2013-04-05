/*
 * Last modified: Fri, 05 Apr 2013 09:14:29 +0900
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
  }
  return;
}
