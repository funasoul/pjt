/*
 * Last modified: Sat, 06 Apr 2013 04:01:54 +0900
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
  /* Here we go */
  /*
  debug_printTree(r, PREORDER);
  print_test(r, ans1, ans2, ans3);
  subst_test(r);
  visualizeGraph(r, "out.pdf");
  remove_test(r);
  */
  visualizeGraph(r, "out.pdf");
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
