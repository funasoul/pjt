/*
 * Last modified: Mon, 08 Apr 2013 19:25:52 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void printTree(BinSTreeNode *rootNode, int order) {
  myArgs args;
  args.action = PRINT;
  if (rootNode == NULL) {
    printf("\n");
    return;
  }
  if (order >= UNIQUE_OFFSET) {
    args.is_unique = true;
    order -= UNIQUE_OFFSET;
  } else {
    args.is_unique = false;
  }
  switch(order) {
    case PREORDER:  /* 前順走査 (preorder) */
      preorder(rootNode, &args);
      printf("\n");
      break;
    case INORDER:  /* 間順走査 (inorder) */
      inorder(rootNode, &args);
      printf("\n");
      break;
    case POSTORDER:  /* 後順走査 (postorder) */
      postorder(rootNode, &args);
      printf("\n");
      break;
    default:
      break;
  }
  return;
}

void debug_printTree(BinSTreeNode *rootNode, int order) {
  myArgs args;
  args.action = DEBUG_PRINT;
  args.is_unique = false;
  switch(order) {
    case PREORDER:  /* 前順走査 (preorder) */
      preorder(rootNode, &args);
      printf("\n");
      break;
    case INORDER:  /* 間順走査 (inorder) */
      inorder(rootNode, &args);
      printf("\n");
      break;
    case POSTORDER:  /* 後順走査 (postorder) */
      postorder(rootNode, &args);
      printf("\n");
      break;
    default:
      break;
  }
  return;
}

void verbosePrint(BinSTreeNode* r, myOption* opt, char* msg) {
  if (opt->is_verbose) {
    printf("== Remove =======================\n");
    checkPrint(r);
    printTree(r, opt->print_order);
    visualizeGraph(r, "remove.pdf", opt);
  }
}

void checkPrint(BinSTreeNode* root) {
  int rtn;
  myArgs* args;
  if (root == NULL) return;
  args = create_myArgs_forCheck(root);
  rtn = checkSortedWithArgs(root, args);
  if (rtn) {
    printf("[%s%s Sorted! %s%s] ", UNDER_LINE, GREEN, DEFAULT, FONT_DEFAULT);
  } else {
    printf("[%s%sUnsorted.%s%s] ", UNDER_LINE, RED, DEFAULT, FONT_DEFAULT);
  }
  free_myArgs(args);
}
