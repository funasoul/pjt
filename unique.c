/*
 * Last modified: Sun, 07 Apr 2013 12:04:27 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int isUnique(BinSTreeNode* node) {
  BinSTreeNode* parent = node->parent;
  while(parent != NULL) {  /* look until root node */
    if (!mystrcmp(node->str, parent->str)) {  /* found a node which has the same name */
      return false;
    }
    parent = parent->parent;
  }
  return true;
}
