/*
 * Last modified: Tue, 19 Mar 2013 20:14:05 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void removeNode(BinSTreeNode* root, const char* word, int delall) {
  printf("Removing [%s]\n", word);
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
