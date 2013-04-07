/*
 * Last modified: Sun, 07 Apr 2013 19:35:27 +0900
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
  postorder(root, &args);
  sortBinSTree(root);
  return args.result;
}
