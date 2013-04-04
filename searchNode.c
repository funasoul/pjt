/*
 * Last modified: Tue, 19 Mar 2013 21:24:18 +0900
 */
#include <stdio.h>
#include "mycommon.h"

BinSTreeNode* getMinNode(BinSTreeNode* root) {
  if (root == NULL) return NULL;
  if (root->left == NULL) return root;
  return getMinNode(root->left);
}

BinSTreeNode* getMaxNode(BinSTreeNode* root) {
  if (root == NULL) return NULL;
  if (root->right == NULL) return root;
  return getMaxNode(root->right);
}
