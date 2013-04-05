/*
 * Last modified: Sat, 06 Apr 2013 03:42:27 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void free_myArgs(myArgs* args) {
  free_unsortedNodes(args);
  free(args);
}

void free_unsortedNodes(myArgs* args) {
  /*
  int i;
  for (i = 0; i < args->unsort_len; i++) {
    free(args->unsortedNodes[i]);
  }
  */
  free(args->unsortedNodes);
}

void free_myObjects(BinSTreeNode* root, myOption* opt) {
  if (root != NULL) {
    clearBinSTree(root);
  }
  if (opt != NULL) {
    free_myOption(opt);
  }
}
