/*
 * Last modified: Fri, 22 Mar 2013 03:25:10 +0900
 */
#include <stdio.h>
#include "mycommon.h"

myArgs* create_myArgs_forCheck(BinSTreeNode* root) {
  int i;
  myArgs* args = (myArgs*)malloc(sizeof(myArgs) * 1);
  args->action = CHECK;
  args->result = true;
  args->str = NULL;
  args->unsort_len = getNodeNum(root);
  args->count = 0;
  /* Initialize unsortedNodes array */
  args->unsortedNodes = (BinSTreeNode**)malloc(sizeof(BinSTreeNode*) * args->unsort_len);
  for (i = 0; i < args->unsort_len; i++) {
    args->unsortedNodes[i] = NULL;
  }
  return args;
}
