/*
 * Last modified: Mon, 08 Apr 2013 21:31:27 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void removeNode(BinSTreeNode* root, const char* word, int delall) {
  int flag;
  flag = 
  printf("%s%sRemoving%s%s [%s][%d]\n", YELLOW, UNDER_LINE, FONT_DEFAULT, DEFAULT, word, (delall != 0) ? true : false);
  myArgs args;
  args.action = REMOVE_MATCH;
  args.result = 0;
  args.str = word;
  args.delall = delall;
  args.num_removed = 0;
  if (root == NULL) return;
  /* Should have to be postorder (won't work with preorder, inorder). */
  postorder(root, &args);
  return;
}
