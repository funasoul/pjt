/*
 * Last modified: Wed, 20 Mar 2013 23:38:04 +0900
 */
#include <stdio.h>
#include "mycommon.h"

void free_myArgs(myArgs* args) {
  free_unsortedNodes(args);
  free(args);
}

void free_unsortedNodes(myArgs* args) {
  /*
  int i;
  for (i = 0; i < args->unsort_len; i++) {
    free(args->unsortedNodes[i]);
  }
  */
  free(args->unsortedNodes);
}
