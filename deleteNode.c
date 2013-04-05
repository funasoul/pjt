/*
 * Last modified: Fri, 05 Apr 2013 08:05:38 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void deleteNode(BinSTreeNode* node) {
  unlinkParent(node);
  unlinkParent(node->left);
  unlinkParent(node->right);
  free(node->str);
  node->str = NULL;
  free(node);
}
