/*
 * Last modified: Sun, 07 Apr 2013 19:36:08 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void removeNode(BinSTreeNode* root, const char* word, int delall) {
  printf("%s%sRemoving%s%s [%s]\n", YELLOW, UNDER_LINE, FONT_DEFAULT, DEFAULT, word);
  myArgs args;
  args.action = REMOVE_MATCH;
  args.result = 0;
  args.str = word;
  args.delall = delall;
  args.num_removed = 0;
  /* Should have to be postorder (won't work with preorder, inorder). */
  postorder(root, &args);
  return;
}
