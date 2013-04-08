/*
 * Last modified: Mon, 08 Apr 2013 19:38:11 +0900
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

void verbosePrint(BinSTreeNode* r, myOption* opt, int mode) {
  char msg[256];
  char filename[256];
  switch(mode) {
    case START:
    mystrcpy(msg, "== Start =========================");
    mystrcpy(filename, "start.pdf");
    break;
    case END:
    mystrcpy(msg, "== End ===========================");
    mystrcpy(filename, "end.pdf");
    break;
    case REMOVE_MATCH:
    mystrcpy(msg, "== Remove ========================");
    mystrcpy(filename, "remove.pdf");
    break;
    case SUBST:
    mystrcpy(msg, "== Subst =========================");
    mystrcpy(filename, "subst.pdf");
    break;
    default:
    mystrcpy(msg, "== Unknown =======================");
    mystrcpy(filename, "unknown.pdf");
    break;
  }
  if (opt->is_verbose || mode == START || mode == END) {
    printf("%s\n", msg);
    checkPrint(r);
    printTree(r, opt->print_order);
    if (opt->is_verbose) {
      visualizeGraph(r, filename, opt);
    }
  }
  return;
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
