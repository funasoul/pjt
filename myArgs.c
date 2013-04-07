/*
 * Last modified: Sun, 07 Apr 2013 15:05:30 +0900
 */
#include <stdio.h>
#include "mycommon.h"

myArgs* create_myArgs_forCheck(BinSTreeNode* root) {
  int i;
  myArgs* args = (myArgs*)malloc(sizeof(myArgs) * 1);
  args->action = CHECK;
  args->str = NULL;
  args->rstr = NULL;
  args->delall = false;
  args->num_removed = 0;
  args->result = true;
  args->unsort_len = getNodeNum(root);
  args->count = 0;
  args->is_unique = false;
  args->fp = NULL;
  /* Initialize unsortedNodes array */
  args->unsortedNodes = (BinSTreeNode**)malloc(sizeof(BinSTreeNode*) * args->unsort_len);
  for (i = 0; i < args->unsort_len; i++) {
    args->unsortedNodes[i] = NULL;
  }
  return args;
}
