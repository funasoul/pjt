/*
 * Last modified: Fri, 05 Apr 2013 09:19:13 +0900
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
 * sort tree           if action == SORT
 * remove matched node if action == REMOVE_MATCH
 */
void doNode(BinSTreeNode* node, myArgs *args) {
  char* s;
  BinSTreeNode *child = NULL, *parent = NULL, *left = NULL, *right = NULL;
  BinSTreeNode *min = NULL, *minRight = NULL;
  if (args->action == PRINT) {
    printf("%s ", node->str);
  } else if (args->action == GRAPH_PRINT) {
    fprintf(args->fp, "  node%p[label=%s];\n", node, node->str);
    if (node->left != NULL) {
      fprintf(args->fp, "  node%p -> node%p;\n", node, node->left);
    } else {
      fprintf(args->fp, "  null%p[shape=point];\n", (node+101));
      fprintf(args->fp, "  node%p -> null%p;\n", node, (node+101));
    }
    if (node->right != NULL) {
      fprintf(args->fp, "  node%p -> node%p;\n", node, node->right);
    } else {
      fprintf(args->fp, "  null%p[shape=point];\n", (node+102));
      fprintf(args->fp, "  node%p -> null%p;\n", node, (node+102));
    }
  } else if (args->action == DEBUG_PRINT) {
    printf("[%-10s][%p][%p][%p]:[%p]\n", node->str, node, node->left, node->right, node->str);
  } else if (args->action == REMOVE) {
    deleteNode(node);
  } else if (args->action == CHECK) {
    if (args->str != NULL) {
      if (mystrcmp(node->str, args->str) < 0) {
        args->result = false;
        printf("HIT: [%p][%s]\n", node, node->str);
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
        parent = node->parent;
        left   = node->left;
        right  = node->right;
        if (parent == NULL) {  /* node is root node */
          printf("Found [%s][%p][%p] (root node)\n", node->str, node->left, node->right);
          parent = node;       /* set parent as "node" for addNode() */
          free(node->str);
          node->str = NULL;    /* just set nodeName as NULL */
        } else {
          printf("Found [%s][%p][%p] <- [%s]\n", node->str, node->left, node->right, node->parent->str);
          deleteNode(node);
        }
        if (left == NULL && right == NULL) {
        } else if (left  == NULL) {  /* We only have right node */
          child = right;
        } else if (right == NULL) {  /* We only have left  node */
          child = left;
        } else {  /* We have both left and right nodes */
          /* Replace this node with Min node under right node */
          min = getMinNode(right);
          minRight = min->right;
          /* printf("  Found Min [%s]\n", min->str); */
          /* printf("  Parent    [%s]\n", parent->str); */
          unlinkParent(min);
          setNodeAsLeft(min, left); /* Min only have right node */
          if (min != right) {
            addNode(min, right);
          }
          child = min;
        }
        /* No need to check NULL for node (addNode() takes care of it) */
        addNode(parent, child);
        args->num_removed++;
      }
    }
  }
  return;
}
