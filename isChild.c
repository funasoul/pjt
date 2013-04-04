/*
 * Last modified: Fri, 22 Mar 2013 03:24:47 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int isLeftChild(BinSTreeNode *p, BinSTreeNode *n) {
  if (p == NULL || p->left == NULL) return false;
  /* if (!mystrcmp(p->left->str, n->str)) { */
  if (p->left ==  n) {
    return true;
  }
  return false;
}

int isRightChild(BinSTreeNode *p, BinSTreeNode *n) {
  if (p == NULL || p->right == NULL) return false;
  /* if (!mystrcmp(p->right->str, n->str)) { */
  if (p->right ==  n) {
    return true;
  }
  return false;
}
