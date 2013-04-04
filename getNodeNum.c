/*
 * Last modified: Wed, 20 Mar 2013 20:40:04 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int getNodeNum(BinSTreeNode* root) {
  myArgs args;
  args.action = COUNT;
  args.result = 0;
  args.str = NULL;
  preorder(root, &args);
  return args.result;
}
