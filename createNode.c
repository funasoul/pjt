/*
 * Last modified: Tue, 19 Mar 2013 03:30:34 +0900
 */
#include <stdio.h>
#include "mycommon.h"

BinSTreeNode* createNode(const char *word) {
  BinSTreeNode* r = (BinSTreeNode*)malloc(sizeof(BinSTreeNode));
  r->str = (char*)malloc(sizeof(char)*(mystrlen(word)+1));
  mystrcpy(r->str, word);
  r->left = NULL;
  r->right = NULL;
  r->parent = NULL;
  return r;
}
