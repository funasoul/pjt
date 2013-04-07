/*
 * Last modified: Sun, 07 Apr 2013 13:27:00 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int substString(BinSTreeNode *root, const char* str, const char* rstr) {
  myArgs args;
  args.action = SUBST;
  args.result = 0;
  args.str = str;
  args.rstr = rstr;
  printf("Subst [%s] -> [%s]\n", args.str, args.rstr);
  postorder(root, &args);
  printTree(root, INORDER); /*debug*/
  sortBinSTree(root);
  return args.result;
}
