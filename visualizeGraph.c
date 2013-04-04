/*
 * Last modified: Fri, 05 Apr 2013 02:38:10 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int visualizeGraph(BinSTreeNode* root, const char* file) {
  myArgs args;
  FILE *fp;
  char command[256];

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
  printf("Visualize graph in %s\n", file);
  return true;
}
