/*
 * Last modified: Sun, 07 Apr 2013 17:06:15 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void sortBinSTree(BinSTreeNode* rootNode) {
  BinSTreeNode *child = NULL, *parent = NULL, *left = NULL, *right = NULL;
  BinSTreeNode *node = NULL, *min = NULL, *minRight = NULL;
  BinSTreeNode *newnode = NULL;
  int i;
  /*
   * Do check and get unsorted nodes.
   * Unsorted nodes will be set in args.unsortedNodes[]
   */
  myArgs* args = create_myArgs_forCheck(rootNode);
  /* if (!checkSortedWithArgs(rootNode, args)) {  [> if there exists unsorted nodes <] */
  while (!checkSortedWithArgs(rootNode, args)) {  /* if there exists unsorted nodes */
    printf("DEBUG: unsorted nodes = %d\n", args->count);
    for (i = 0; i < args->count; i++) {
      node = args->unsortedNodes[i];
      printf("Re-sort: [%p] %s\n", node, node->str);
      newnode = createNode(node->str);
      parent = node->parent;
      left   = node->left;
      right  = node->right;
      if (parent == NULL) {  /* node is root node */
        printf("Found [%s][%p][%p] (root node)\n", node->str, node->left, node->right);
        /* root node is unsorted. check left and right children,
         * and if it breaks the rule (unsorted), let them set as sorted
         * with addNode()
         */
        parent = node;       /* set parent as "node" for addNode() */
        free(node->str);
        node->str = NULL;    /* just set nodeName as NULL. addNode() will take care of it. */
        /* debug
        if (!isLeft(node, left)) {
          unlinkParent(left);
          addNode(node, left);
        } else if (isLeft(node, right)) {
          unlinkParent(right);
          addNode(node, right);
        }
        */
      } else {
        printf("Found [%s][%p][%p] <- [%s]\n", node->str, node->left, node->right, node->parent->str);
        deleteNode(node);
        /* debug
        setNodeAsOrphan(node);
        addNode(rootNode, node);
        */
      }
      if (left == NULL && right == NULL) {
      } else if (left  == NULL) {  /* We only have right node */
        child = right;
      } else if (right == NULL) {  /* We only have left  node */
        child = left;
      } else {  /* We have both left and right nodes */
        /* Replace this node with Min node under right node */
        min = getMinNode(right);
        minRight = min->right;
        /* printf("  Found Min [%s]\n", min->str); */
        /* printf("  Parent    [%s]\n", parent->str); */
        unlinkParent(min);
        setNodeAsLeft(min, left); /* Min only have right node */
        if (min != right) {
          addNode(min, right);
        }
        child = min;
      }
      /* No need to check NULL for left node (addNode() takes care of it) */
      addNode(parent, child);
      /* debug */
      addNode(rootNode, newnode);
    }
    /* debug */
    args->count = 0;
    args->str = NULL;
    args->result = true;
  }
  free_myArgs(args);
  return;
}
