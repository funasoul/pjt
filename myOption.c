/*
 * Last modified: Mon, 08 Apr 2013 21:48:54 +0900
 */
#include <stdio.h>
#include "mycommon.h"

myOption* create_myOption(void) {
  myOption* opt = (myOption*)malloc(sizeof(myOption) * 1);
  opt->print_order = INORDER;
  opt->do_subst = false;
  opt->sub_match = NULL;
  opt->sub_replace = NULL;
  opt->do_remove = false;
  opt->rm_match = NULL;
  opt->rm_delall = false;
  opt->is_unique = false;
  opt->is_verbose = false;
  opt->is_subst_first = false;
  opt->is_help = false;
  opt->is_graphviz = false;
  opt->count_subst = 0;
  opt->count_remove = 0;
  opt->next = NULL;
  return opt;
}

void free_myOption(myOption* opt) {
  if (opt->next != NULL) {
    free_myOption(opt->next);
  }
  free(opt->sub_match);
  free(opt->sub_replace);
  free(opt->rm_match);
  free(opt);
  return;
}
