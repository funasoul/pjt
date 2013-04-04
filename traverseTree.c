/*
 * Last modified: Sat, 16 Mar 2013 02:45:08 +0900
 */
#include <stdio.h>
#include "mycommon.h"

BinSTreeNode* preorder(BinSTreeNode* node, myArgs* args) {
  doNode(node, args);
  if (node->left != NULL)  preorder(node->left, args);
  if (node->right != NULL) preorder(node->right, args);
  return node;
}

BinSTreeNode* inorder(BinSTreeNode* node, myArgs* args) {
  if (node->left != NULL)  inorder(node->left, args);
  doNode(node, args);
  if (node->right != NULL) inorder(node->right, args);
  return node;
}

BinSTreeNode* postorder(BinSTreeNode* node, myArgs* args) {
  if (node->left != NULL)  postorder(node->left, args);
  if (node->right != NULL) postorder(node->right, args);
  doNode(node, args);
  return node;
}
