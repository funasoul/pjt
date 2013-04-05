/*
 * Last modified: Sat, 06 Apr 2013 06:07:12 +0900
 */
#include <stdio.h>
#include <unistd.h>
#include "mycommon.h"

int main2(int argc, char* argv[])
{
  int i, rest_args;
  FILE *fp;
  char *myname = argv[0];
  BinSTreeNode *r = NULL;
  myOption *opt = create_myOption();

  /* Option handling */
  rest_args = parseOption(--argc, ++argv, opt);
  if (rest_args == -1 || opt->is_help) {
    usage(myname);
    free_myObjects(r, opt);
    return -1;
  }
  /* Create tree from input */
  argv += argc - rest_args;
  if (rest_args == 0) {  /* read from command line */
    fp = stdin;
    r = readNode(fp, r);
  } else {               /* read from files */
    for (i = 0; i < rest_args; i++) {
      fp = fopen(argv[i], "r");
      if (fp == NULL) {
        fprintf(stderr, "Can't open input file [%s]\n", argv[i]);
        free_myObjects(r, opt);
        return -1;
      }
      r = readNode(fp, r);
      fclose(fp);
    }
  }
  /* Here we go! */
  if (opt->is_verbose) {
    printTree(r, opt->print_order);
    visualizeGraph(r, "start.pdf", opt);
  }
  /* SubstString and Remove */
  if (opt->is_subst_first) {    /* do_subst == true && do_remove == true */
    substString(r, opt->sub_match, opt->sub_replace);
    opt->do_subst = false;
    if (opt->is_verbose) printTree(r, opt->print_order);
    removeNode(r, opt->rm_match, opt->rm_delall);
    opt->do_remove = false;
    if (opt->is_verbose) printTree(r, opt->print_order);
  } else if (opt->do_remove) {
    removeNode(r, opt->rm_match, opt->rm_delall);
    opt->do_remove = false;
    if (opt->is_verbose) printTree(r, opt->print_order);
  } else if (opt->do_subst) {
    substString(r, opt->sub_match, opt->sub_replace);
    opt->do_subst = false;
    if (opt->is_verbose) printTree(r, opt->print_order);
  }
  /* Print Tree */
  printTree(r, opt->print_order);
  visualizeGraph(r, "end.pdf", opt);
  free_myObjects(r, opt);

  return 0;
}

int main(int argc, char** argv)
{
  int ret = main2(argc, argv);
  char buf[256];
  sprintf(buf, "leaks %d | tail -1", getpid());
  /* sprintf(buf, "leaks %d", getpid()); */
  system(buf);
  return ret;
}
