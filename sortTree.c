/*
 * Last modified: Mon, 08 Apr 2013 19:21:55 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void sortBinSTree(BinSTreeNode* rootNode) {
  int i;
  BinSTreeNode *node = NULL, *newnode = NULL;
  myArgs* args;
  if (rootNode == NULL) return;
  /*
   * Do check and get unsorted nodes.
   * Unsorted nodes will be set in args.unsortedNodes[]
   */
  while(1) {
    args = create_myArgs_forCheck(rootNode);
    if (checkSortedWithArgs(rootNode, args)) {
      free_myArgs(args);
      break;
    }
    /* there exists unsorted nodes */
    if(DEBUG) printf("Unsorted nodes = %d\n", args->count);
    for (i = 0; i < args->count; i++) {
      node = args->unsortedNodes[i];
      if(DEBUG) printf("Re-sort: [%p] %s\n", node, node->str);
      newnode = createNode(node->str);
      /* remove unsorted node and sort tree */
      removeSort(node);
      /* add removed (unsorted) node */
      addNode(rootNode, newnode);
    }
    free_myArgs(args);
  }
  return;
}
