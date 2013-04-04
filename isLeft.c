/*
 * Last modified: Fri, 22 Mar 2013 03:24:56 +0900
 */
#include <stdio.h>
#include "mycommon.h"

/*
 * Rule of left and right
 *  left:  node < root
 *  left:  root == node
 *  right: root > node
 * This rule is defined in isLeft().
 */
int isLeft(BinSTreeNode *r, BinSTreeNode *n) {
  if (mystrcmp(r->str, n->str) >= 0) {
    return true;
  }
  return false;
}
