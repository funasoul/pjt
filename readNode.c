/*
 * Last modified: Fri, 05 Apr 2013 21:55:00 +0900
 */
#include <stdio.h>
#include "mycommon.h"

BinSTreeNode* readNode(FILE *fp, BinSTreeNode *root) {
  char str[256];
  char *p, *head;
  while (fgets(str, sizeof(str), fp) != NULL) {
    chomp(str);
    head = str;
    do {
      p = findSpace(head);
      if (p != NULL) *p = '\0';
      if (*head != '\0') {
        if (root == NULL) {
          root = createNode(head);
        } else {
          addNode(root, createNode(head));
        }
      }
      head = p+1;
    } while (p != NULL);
  }
  return root;
}

