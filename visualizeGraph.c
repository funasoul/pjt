/*
 * Last modified: Sun, 07 Apr 2013 20:56:49 +0900
 */
#include <stdio.h>
#include <unistd.h>
#include "mycommon.h"

int hasGraphviz(void) {
  if (access(DOT_PATH, R_OK | X_OK) != 0) return false;
  return true;
}

int visualizeGraph(BinSTreeNode* root, const char* file, myOption* opt) {
  myArgs args;
  FILE *fp;
  char command[256];

  if (!opt->is_graphviz) { /* Don't have Graphviz */
    return true;
  }
  if (root->str == NULL) { /* take care of empty root node */
    return true;
  }
  fp = fopen("out.dot", "w");
  if (fp == NULL) {
    return false;
  }
  args.action = GRAPH_PRINT;
  args.fp = fp;
  fprintf(fp, "digraph G {\n");
  preorder(root, &args);
  fprintf(fp, "}\n");
  fclose(fp);

  sprintf(command, "%s -Tpdf out.dot -o %s && open -g %s", DOT_PATH, file, file);
  system(command);
  if (opt->is_verbose) {
    printf("Visualize graph in %s\n", file);
  }
  return true;
}
