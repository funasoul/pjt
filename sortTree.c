/*
 * Last modified: Fri, 22 Mar 2013 02:48:20 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void sortBinSTree(BinSTreeNode* rootNode) {
  BinSTreeNode *child = NULL, *parent = NULL, *left = NULL, *right = NULL;
  BinSTreeNode *node = NULL, *min = NULL;
  int i;
  /*
   * Do check and get unsorted nodes.
   * Unsorted nodes will be set in args.unsortedNodes[]
   */
  myArgs* args = create_myArgs_forCheck(rootNode);
  if (!checkSortedWithArgs(rootNode, args)) {
    for (i = 0; i < args->count; i++) {
      node = args->unsortedNodes[i];
      printf("Re-sort: [%p] %s\n", node, node->str);
      parent = node->parent;
      left   = node->left;
      right  = node->right;
      if (node == rootNode) {  /* if node is root node */
        if (!isLeft(node, left)) {
          addNode(node, left);
        } else if (isLeft(node, right)) {
          addNode(node, right);
        }
      } else {
        setNodeAsOrphan(node);
        if (node->left == NULL && node->right == NULL) {
        } else if (node->left  == NULL) {  /* We only have right node */
          child = right;
        } else if (node->right == NULL) {  /* We only have left  node */
          child = left;
        } else {  /* We have both left and right nodes */
          /* Replace this node with Min node under right node */
          min = getMinNode(right);
          /* printf("  Found Min [%s]\n", min->str); */
          /* printf("  Parent    [%s]\n", parent->str); */
          setNodeAsLeft(min->parent, min->right); /* Min only have right node */
          setNodeAsOrphan(min);
          setNodeAsRight(min, right);
          setNodeAsLeft(min, left);
          child = min;
        }
        /* No need to check NULL for left node (addNode() takes care of it) */
        addNode(parent, child);
        addNode(rootNode, node);
      }
    }
  }
  free_myArgs(args);
  return;
}
