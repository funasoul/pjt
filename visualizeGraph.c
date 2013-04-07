/*
 * Last modified: Sun, 07 Apr 2013 18:00:46 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int visualizeGraph(BinSTreeNode* root, const char* file, myOption* opt) {
  myArgs args;
  FILE *fp;
  char command[256];

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

  sprintf(command, "/opt/local/bin/dot -Tpdf out.dot -o %s && open %s", file, file);
  system(command);
  if (opt->is_verbose) {
    printf("Visualize graph in %s\n", file);
  }
  return true;
}
