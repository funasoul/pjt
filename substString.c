/*
 * Last modified: Mon, 08 Apr 2013 19:21:16 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int substString(BinSTreeNode *root, const char* str, const char* rstr) {
  myArgs args;
  args.action = SUBST;
  args.result = 0;
  args.str = str;
  args.rstr = rstr;
  printf("%s%sSubst%s%s [%s] -> [%s]\n", YELLOW, UNDER_LINE, FONT_DEFAULT, DEFAULT, args.str, args.rstr);
  if (root == NULL) return args.result;
  postorder(root, &args);
  sortBinSTree(root);
  return args.result;
}
