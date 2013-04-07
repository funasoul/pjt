/*
 * Last modified: Sun, 07 Apr 2013 19:08:32 +0900
 */
#include <stdio.h>
#include "mycommon.h"

/*
 * print node name     if action == PRINT
 * debug print node    if action == DEBUG_PRINT
 * print node as graph if action == GRAPH_PRINT
 * remove node         if action == REMOVE
 * check sorted        if action == CHECK
 * count node num      if action == COUNT
 * subst string        if action == SUBST
 * remove matched node if action == REMOVE_MATCH
 * sort tree           if action == SORT (not used)
 */
void doNode(BinSTreeNode* node, myArgs *args) {
  char* s;
  if (args->action == PRINT) {
    if (!args->is_unique || isUnique(node)) {
      if (node->str != NULL) {
        printf("%s ", node->str);
      }
    }
  } else if (args->action == GRAPH_PRINT) {
    fprintf(args->fp, "  node%p[label=%s];\n", node, node->str);
    if (node->left != NULL) {
      fprintf(args->fp, "  node%p -> node%p;\n", node, node->left);
    } else {
      fprintf(args->fp, "  nulll%p[shape=point];\n", (node+101));
      fprintf(args->fp, "  node%p -> nulll%p;\n", node, (node+101));
    }
    if (node->right != NULL) {
      fprintf(args->fp, "  node%p -> node%p;\n", node, node->right);
    } else {
      fprintf(args->fp, "  nullr%p[shape=point];\n", (node+102));
      fprintf(args->fp, "  node%p -> nullr%p;\n", node, (node+102));
    }
  } else if (args->action == DEBUG_PRINT) {
    printf("[%-10s][%p][%p][%p]:[%p]\n", node->str, node, node->left, node->right, node->str);
  } else if (args->action == REMOVE) {
    deleteNode(node);
  } else if (args->action == CHECK) {
    if (args->str != NULL) {
      if (mystrcmp(node->str, args->str) < 0) {  /* XXX have to be consistent with isLeft() */
        args->result = false;
        if(DEBUG) printf("Unsorted: [%p][%s]\n", node, node->str);
        args->unsortedNodes[args->count] = node;
        args->count++;
      }
    }
    args->str = node->str;
  } else if (args->action == COUNT) {
    if (node->str != NULL) args->result++;
  } else if (args->action == SUBST) {
    s = mystrsubst(node->str, args->str, args->rstr);
    if (mystrcmp(node->str, s) != 0) {
      free(node->str);
      node->str = s;
      args->result++;
    } else {
      free(s);
    }
  } else if (args->action == REMOVE_MATCH) {
    if (!mystrcmp(args->str, node->str)) {  /* If matched */
      if (args->delall || args->num_removed == 0) { /* remove node */
        /* remove this node and sort tree */
        removeSort(node);
        args->num_removed++;
      }
    }
  }
  return;
}
