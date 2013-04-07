/*
 * Last modified: Sun, 07 Apr 2013 16:07:15 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int checkSorted(BinSTreeNode* root) {
  int rtn;
  myArgs* args;
  args = create_myArgs_forCheck(root);
  rtn = checkSortedWithArgs(root, args);
  free_myArgs(args);
  return rtn;
}

int checkSortedWithArgs(BinSTreeNode* root, myArgs* args) {
  int rtn;
  inorder(root, args);
  rtn = args->result;
  return rtn;
}
