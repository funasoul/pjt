/*
 * Last modified: Sat, 16 Mar 2013 02:42:05 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void clearBinSTree(BinSTreeNode* rootNode) {
  myArgs args;
  args.action = REMOVE;
  postorder(rootNode, &args);
  return;
}

